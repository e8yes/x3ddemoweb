/**
 * e8yes demo web server.
 *
 * <p>Copyright (C) 2020 Chifeng Wen {daviesx66@gmail.com}
 *
 * <p>This program is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * <p>This program is distributed in the hope that it will be useful, b ut WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * <p>You should have received a copy of the GNU General Public License along with this program. If
 * not, see <http://www.gnu.org/licenses/>.
 */
package org.e8yes.service.file;

import com.auth0.jwt.exceptions.JWTVerificationException;
import java.sql.SQLException;
import java.util.HashSet;
import java.util.Optional;
import org.e8yes.environment.EnvironmentContextInterface;
import org.e8yes.environment.Initializer;
import org.e8yes.exception.AccessDeniedException;
import org.e8yes.fsprovider.FileAccessLocation;
import org.e8yes.service.EncryptionSource;
import org.e8yes.service.FileAccessMode;
import org.e8yes.service.identity.Identity;
import org.e8yes.service.identity.UserCreation;
import org.e8yes.service.identity.UserEntity;
import org.e8yes.service.identity.UserGroup;
import org.e8yes.service.identity.UserGroupEntity;
import org.e8yes.sql.connection.ConnectionReservoirInterface;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class FileAccessValidatorTest {

  @BeforeEach
  public void setUp() throws Exception {
    Initializer.init(EnvironmentContextInterface.Environment.Test);
  }

  @AfterEach
  public void tearDown() throws Exception {
    Initializer.cleanUp();
  }

  @Test
  public void signAndValidateTokenAccessTest()
      throws JWTVerificationException, AccessDeniedException {
    Identity viewer = new Identity(/*userId=*/ 1L, /*groupNames=*/ null);
    FileAccessLocation location = new FileAccessLocation("avatar/a.jpeg");
    FileAccessValidator.FileAccessToken token =
        FileAccessValidator.signAccessToken(
            viewer,
            location,
            FileAccessMode.FAM_READ,
            Initializer.environmentContext().authorizationJwtProvider().algorithm());

    // Valid usage of the token.
    FileAccessLocation decodedLocation =
        FileAccessValidator.validateTokenAccess(
            viewer,
            FileAccessMode.FAM_READ,
            token,
            Initializer.environmentContext().authorizationJwtProvider().jwtverifier());
    Assertions.assertEquals(location, decodedLocation);

    // Invalid access mode.
    try {
      FileAccessValidator.validateTokenAccess(
          viewer,
          FileAccessMode.FAM_WRITE,
          token,
          Initializer.environmentContext().authorizationJwtProvider().jwtverifier());
      Assertions.fail();
    } catch (AccessDeniedException ex) {
      Assertions.assertTrue(true);
    }
    try {
      FileAccessValidator.validateTokenAccess(
          viewer,
          FileAccessMode.FAM_READWRITE,
          token,
          Initializer.environmentContext().authorizationJwtProvider().jwtverifier());
      Assertions.fail();
    } catch (AccessDeniedException ex) {
      Assertions.assertTrue(true);
    }

    // Impersonate identity.
    Identity badViewer = new Identity(/*userId=*/ 2L, /*groupNames=*/ null);
    try {
      FileAccessValidator.validateTokenAccess(
          badViewer,
          FileAccessMode.FAM_READ,
          token,
          Initializer.environmentContext().authorizationJwtProvider().jwtverifier());
      Assertions.fail();
    } catch (AccessDeniedException ex) {
      Assertions.assertTrue(true);
    }
  }

  @Test
  public void validateDirectAcessTest()
      throws SQLException, IllegalAccessException, AccessDeniedException {
    ConnectionReservoirInterface dbConn =
        Initializer.environmentContext().demowebDbConnections().connectionReservoir();

    // Create file.
    FileAccessLocation location = new FileAccessLocation("/avatar/user_avatar.jpeg");
    FileMetaData.addMetaDataForFile(location, EncryptionSource.ESRC_NONE, dbConn);

    // Create users.
    UserGroupEntity group =
        UserGroup.createUserGroup("file_group", new HashSet(), /*replace*=*/ true, dbConn);
    UserEntity user =
        UserCreation.createBaselineUser("PASS".getBytes(), /*userId=*/ Optional.of(1L), dbConn);
    UserEntity impersonatedUser =
        UserCreation.createBaselineUser("PASS".getBytes(), /*userId=*/ Optional.of(2L), dbConn);

    // Create user file group.
    FileMetaData.addFileLocationToGroup(location, group, FileAccessMode.FAM_READ, dbConn);

    // Valid access.
    FileAccessValidator.validateDirectAccess(
        new Identity(user.id.value(), new String[] {"file_group"}),
        location,
        FileAccessMode.FAM_READ,
        dbConn);

    // Bad location.
    try {
      FileAccessLocation badLocation = new FileAccessLocation("/avatar/bad_file.jpeg");
      FileAccessValidator.validateDirectAccess(
          new Identity(user.id.value(), new String[] {"file_group"}),
          badLocation,
          FileAccessMode.FAM_READ,
          dbConn);
      Assertions.fail();
    } catch (AccessDeniedException ex) {
      Assertions.assertTrue(true);
    }

    // Impersonate access.
    try {
      FileAccessValidator.validateDirectAccess(
          new Identity(impersonatedUser.id.value(), new String[] {}),
          location,
          FileAccessMode.FAM_READ,
          dbConn);
      Assertions.fail();
    } catch (AccessDeniedException ex) {
      Assertions.assertTrue(true);
    }

    // Bad access mode.
    try {
      FileAccessValidator.validateDirectAccess(
          new Identity(user.id.value(), new String[] {"file_group"}),
          location,
          FileAccessMode.FAM_WRITE,
          dbConn);
      Assertions.fail();
    } catch (AccessDeniedException ex) {
      Assertions.assertTrue(true);
    }
  }
}
