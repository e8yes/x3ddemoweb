/**
 * e8yes demo web server.
 *
 * <p>Copyright (C) 2020 Yichen Ma {yichenm2@uci.edu}, Chifeng Wen {daviesx66@gmail.com}
 *
 * <p>This program is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * <p>This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * <p>You should have received a copy of the GNU General Public License along with this program. If
 * not, see <http://www.gnu.org/licenses/>.
 */
package org.e8yes.sql;

import java.lang.reflect.InvocationTargetException;
import java.sql.SQLException;
import java.util.List;
import org.e8yes.sql.connection.BasicConnectionReservoir;
import org.e8yes.sql.connection.ConnectionFactory;
import org.e8yes.sql.connection.ConnectionInterface;
import org.e8yes.sql.connection.ConnectionReservoirInterface;
import org.e8yes.sql.primitive.SqlInt;
import org.e8yes.sql.primitive.SqlStr;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SqlRunnerTest {

  public static class UserHasManyCreditCards {
    public static class User {
      public SqlInt id = new SqlInt();
      public SqlStr userName = new SqlStr();

      @Override
      public boolean equals(Object o) {
        return id.equals(((User) o).id);
      }

      @Override
      public int hashCode() {
        return id.hashCode();
      }
    }

    public static class Cards {
      public SqlInt id = new SqlInt();
      public SqlStr number = new SqlStr();
      public SqlInt userId = new SqlInt();
    }

    public User userInfo;
    public Cards[] cards;

    @Override
    public boolean equals(Object o) {
      return userInfo.equals(((UserHasManyCreditCards) o).userInfo);
    }

    @Override
    public int hashCode() {
      return userInfo.hashCode();
    }
  }

  private static ConnectionFactory connectionFactory() {
    ConnectionFactory factory =
        new ConnectionFactory(
            ConnectionFactory.ConnectionType.JDBC,
            /*hostName=*/ "localhost",
            /*port=*/ 5432,
            /*dbName=*/ "demowebtest",
            /*userName=*/ "postgres",
            /*password=*/ "password");
    return factory;
  }

  private static void dropSchema(ConnectionInterface conn) throws SQLException {
    String dropUserTable = "DROP TABLE IF EXISTS QueryRunnerTestUser";
    String dropCardTable = "DROP TABLE IF EXISTS QueryRunnerTestCard";
    conn.runUpdate(dropCardTable, new ConnectionInterface.QueryParams());
    conn.runUpdate(dropUserTable, new ConnectionInterface.QueryParams());
  }

  private static void createSchema(ConnectionInterface conn) throws SQLException {
    String createUserTable =
        "CREATE TABLE QueryRunnerTestUser("
            + " id INTEGER NOT NULL,"
            + " userName CHARACTER VARYING NOT NULL,"
            + " PRIMARY KEY (id))";
    conn.runUpdate(createUserTable, new ConnectionInterface.QueryParams());
    String createCardTable =
        "CREATE TABLE QueryRunnerTestCard("
            + " id INTEGER NOT NULL,"
            + " userId INTEGER NOT NULL,"
            + " number CHARACTER VARYING NOT NULL,"
            + " PRIMARY KEY (id),"
            + " FOREIGN KEY (userId) REFERENCES QueryRunnerTestUser (id) ON DELETE CASCADE)";
    conn.runUpdate(createCardTable, new ConnectionInterface.QueryParams());
  }

  @Test
  public void testRunUpdateAndQuery()
      throws SQLException, NoSuchMethodException, InstantiationException, IllegalAccessException,
          IllegalArgumentException, InvocationTargetException {
    ConnectionFactory factory = SqlRunnerTest.connectionFactory();
    ConnectionInterface conn = factory.create();
    ConnectionReservoirInterface reservoir = new BasicConnectionReservoir(factory);

    // Prepare schema.
    SqlRunnerTest.dropSchema(conn);
    SqlRunnerTest.createSchema(conn);

    // Run update.
    UserHasManyCreditCards.User user = new UserHasManyCreditCards.User();
    user.id.assign(1);
    user.userName.assign("user0");
    int nRows =
        SqlRunner.runUpdate(
            user,
            /*tableName=*/ "QueryRunnerTestUser",
            UserHasManyCreditCards.User.class,
            /*replace=*/ true,
            reservoir);
    Assertions.assertEquals(1, nRows);

    UserHasManyCreditCards.Cards card0 = new UserHasManyCreditCards.Cards();
    card0.id.assign(10);
    card0.number.assign("1234");
    card0.userId.assign(1);
    UserHasManyCreditCards.Cards card1 = new UserHasManyCreditCards.Cards();
    card1.id.assign(11);
    card1.number.assign("2234");
    card1.userId.assign(1);

    nRows =
        SqlRunner.runUpdate(
            card0,
            /*tableName=*/ "QueryRunnerTestCard",
            UserHasManyCreditCards.Cards.class,
            /*replace=*/ true,
            reservoir);
    Assertions.assertEquals(1, nRows);

    nRows =
        SqlRunner.runUpdate(
            card1,
            /*tableName=*/ "QueryRunnerTestCard",
            UserHasManyCreditCards.Cards.class,
            /*replace=*/ true,
            reservoir);
    Assertions.assertEquals(1, nRows);

    // Run query.
    List<UserHasManyCreditCards> results =
        SqlRunner.runQuery(
            new SqlQueryBuilder()
                .queryPiece(
                    "QueryRunnerTestUser userInfo "
                        + "JOIN "
                        + "QueryRunnerTestCard cards "
                        + "ON cards.userId = userInfo.id "
                        + "ORDER BY cards.id DESC"),
            UserHasManyCreditCards.class,
            reservoir);

    Assertions.assertEquals(1, results.size());
    UserHasManyCreditCards record = results.get(0);
    Assertions.assertEquals((Integer) 1, record.userInfo.id.value());
    Assertions.assertEquals("user0", record.userInfo.userName.value());

    Assertions.assertEquals(2, record.cards.length);
    Assertions.assertEquals((Integer) 11, record.cards[0].id.value());
    Assertions.assertEquals("2234", record.cards[0].number.value());
    Assertions.assertEquals((Integer) 10, record.cards[1].id.value());
    Assertions.assertEquals("1234", record.cards[1].number.value());

    // Clean up.
    SqlRunnerTest.dropSchema(conn);
    conn.close();
  }

  @Test
  public void testRunDelete() throws SQLException, IllegalAccessException {
    ConnectionFactory factory = SqlRunnerTest.connectionFactory();
    ConnectionInterface conn = factory.create();
    ConnectionReservoirInterface reservoir = new BasicConnectionReservoir(factory);

    // Prepare schema.
    SqlRunnerTest.dropSchema(conn);
    SqlRunnerTest.createSchema(conn);

    // Prepare test data.
    UserHasManyCreditCards.User user = new UserHasManyCreditCards.User();
    user.id.assign(1);
    user.userName.assign("user0");
    int nRows =
        SqlRunner.runUpdate(
            user,
            /*tableName=*/ "QueryRunnerTestUser",
            UserHasManyCreditCards.User.class,
            /*replace=*/ true,
            reservoir);
    Assertions.assertEquals(1, nRows);

    // Delete nothing.
    nRows =
        SqlRunner.runDelete(
            /*tableName=*/ "QueryRunnerTestUser",
            new SqlQueryBuilder().queryPiece("WHERE id != 1"),
            reservoir);
    Assertions.assertEquals(0, nRows);

    // Delete the user.
    nRows =
        SqlRunner.runDelete(
            /*tableName=*/ "QueryRunnerTestUser",
            new SqlQueryBuilder().queryPiece("WHERE id = 1"),
            reservoir);
    Assertions.assertEquals(1, nRows);

    // Clean up.
    SqlRunnerTest.dropSchema(conn);
    conn.close();
  }

  @Test
  public void testRunExists() throws SQLException, IllegalAccessException {
    ConnectionFactory factory = SqlRunnerTest.connectionFactory();
    ConnectionInterface conn = factory.create();
    ConnectionReservoirInterface reservoir = new BasicConnectionReservoir(factory);

    // Prepare schema.
    SqlRunnerTest.dropSchema(conn);
    SqlRunnerTest.createSchema(conn);

    // Prepare test data.
    UserHasManyCreditCards.User user = new UserHasManyCreditCards.User();
    user.id.assign(1);
    user.userName.assign("user0");
    int nRows =
        SqlRunner.runUpdate(
            user,
            /*tableName=*/ "QueryRunnerTestUser",
            UserHasManyCreditCards.User.class,
            /*replace=*/ true,
            reservoir);
    Assertions.assertEquals(1, nRows);

    // Run "exists" query.
    boolean shouldNotExist =
        !SqlRunner.runExists(
            new SqlQueryBuilder().queryPiece("QueryRunnerTestUser WHERE id=2"), reservoir);
    Assertions.assertTrue(shouldNotExist);

    boolean shouldExist =
        SqlRunner.runExists(
            new SqlQueryBuilder().queryPiece("QueryRunnerTestUser WHERE id=1"), reservoir);
    Assertions.assertTrue(shouldExist);

    // Clean up.
    SqlRunnerTest.dropSchema(conn);
    conn.close();
  }
}
