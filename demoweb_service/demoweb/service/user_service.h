/**
 * e8yes demo web.
 *
 * <p>Copyright (C) 2020 Chifeng Wen {daviesx66@gmail.com}
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

#ifndef USER_SERVICEL_H
#define USER_SERVICEL_H

#include <grpcpp/grpcpp.h>

#include "proto_cc/service_user.grpc.pb.h"
#include "proto_cc/service_user.pb.h"

namespace e8 {

/**
 * @brief The UserServiceImpl class Service for user management.
 */
class UserServiceImpl : public UserService::Service {
  public:
    UserServiceImpl() = default;
    ~UserServiceImpl() override = default;

    grpc::Status Register(grpc::ServerContext *context, RegistrationRequest const *request,
                          RegistrationResponse *response) override;

    grpc::Status Authorize(grpc::ServerContext *context, AuthorizationRequest const *request,
                           AuthorizationResponse *response) override;

    grpc::Status GetPublicProfile(grpc::ServerContext *context,
                                  GetPublicProfileRequest const *request,
                                  GetPublicProfileResponse *response) override;

    grpc::Status UpdatePublicProfile(grpc::ServerContext *context,
                                     UpdatePublicProfileRequest const *request,
                                     UpdatePublicProfileResponse *response) override;

    grpc::Status Search(grpc::ServerContext *context, SearchUserRequest const *request,
                        SearchUserResponse *response) override;

    grpc::Status PrepareNewAvatar(grpc::ServerContext *context,
                                  PrepareNewAvatarRequest const *request,
                                  PrepareNewAvatarResponse *response) override;
};

} // namespace e8

#endif // USER_SERVICEL_H
