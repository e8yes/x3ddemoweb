/**
 * e8yes demo web server.
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

#ifndef MESSAGEQUEUESERVICEIMPL_H
#define MESSAGEQUEUESERVICEIMPL_H

#include <grpcpp/grpcpp.h>

#include "message_queue/message_queue/module/message_queue_store.h"
#include "proto_cc/service_message_queue.grpc.pb.h"
#include "proto_cc/service_message_queue.pb.h"

namespace e8 {

/**
 * @brief The MessageQueueServiceImpl class
 */
class MessageQueueServiceImpl : public MessageQueueService::Service {
  public:
    MessageQueueServiceImpl() = default;
    ~MessageQueueServiceImpl() override = default;

    grpc::Status EnqueueMessage(grpc::ServerContext *context, EnqueueMessageRequest const *request,
                                EnqueueMessageResponse *response) override;

    grpc::Status DequeueMessage(grpc::ServerContext *context, DequeueMessageRequest const *request,
                                DequeueMessageResponse *response) override;
};

} // namespace e8

#endif // MESSAGEQUEUESERVICEIMPL_H
