// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service_node_state.proto

#include "service_node_state.pb.h"
#include "service_node_state.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace e8 {

static const char* NodeStateService_method_names[] = {
  "/e8.NodeStateService/ReviseNodeState",
  "/e8.NodeStateService/GetCurrentRevisionEpoch",
  "/e8.NodeStateService/AddPeers",
  "/e8.NodeStateService/DeletePeers",
  "/e8.NodeStateService/GetNodeStates",
};

std::unique_ptr< NodeStateService::Stub> NodeStateService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< NodeStateService::Stub> stub(new NodeStateService::Stub(channel));
  return stub;
}

NodeStateService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_ReviseNodeState_(NodeStateService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetCurrentRevisionEpoch_(NodeStateService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AddPeers_(NodeStateService_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DeletePeers_(NodeStateService_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetNodeStates_(NodeStateService_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status NodeStateService::Stub::ReviseNodeState(::grpc::ClientContext* context, const ::e8::ReviseNodeStateRequest& request, ::e8::ReviseNodeStateResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_ReviseNodeState_, context, request, response);
}

void NodeStateService::Stub::experimental_async::ReviseNodeState(::grpc::ClientContext* context, const ::e8::ReviseNodeStateRequest* request, ::e8::ReviseNodeStateResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ReviseNodeState_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::ReviseNodeStateResponse>* NodeStateService::Stub::AsyncReviseNodeStateRaw(::grpc::ClientContext* context, const ::e8::ReviseNodeStateRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::ReviseNodeStateResponse>::Create(channel_.get(), cq, rpcmethod_ReviseNodeState_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::ReviseNodeStateResponse>* NodeStateService::Stub::PrepareAsyncReviseNodeStateRaw(::grpc::ClientContext* context, const ::e8::ReviseNodeStateRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::ReviseNodeStateResponse>::Create(channel_.get(), cq, rpcmethod_ReviseNodeState_, context, request, false);
}

::grpc::Status NodeStateService::Stub::GetCurrentRevisionEpoch(::grpc::ClientContext* context, const ::e8::GetCurrentRevisionEpochRequest& request, ::e8::GetCurrentRevisionEpochResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetCurrentRevisionEpoch_, context, request, response);
}

void NodeStateService::Stub::experimental_async::GetCurrentRevisionEpoch(::grpc::ClientContext* context, const ::e8::GetCurrentRevisionEpochRequest* request, ::e8::GetCurrentRevisionEpochResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetCurrentRevisionEpoch_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::GetCurrentRevisionEpochResponse>* NodeStateService::Stub::AsyncGetCurrentRevisionEpochRaw(::grpc::ClientContext* context, const ::e8::GetCurrentRevisionEpochRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::GetCurrentRevisionEpochResponse>::Create(channel_.get(), cq, rpcmethod_GetCurrentRevisionEpoch_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::GetCurrentRevisionEpochResponse>* NodeStateService::Stub::PrepareAsyncGetCurrentRevisionEpochRaw(::grpc::ClientContext* context, const ::e8::GetCurrentRevisionEpochRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::GetCurrentRevisionEpochResponse>::Create(channel_.get(), cq, rpcmethod_GetCurrentRevisionEpoch_, context, request, false);
}

::grpc::Status NodeStateService::Stub::AddPeers(::grpc::ClientContext* context, const ::e8::AddPeersRequest& request, ::e8::AddPeersResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_AddPeers_, context, request, response);
}

void NodeStateService::Stub::experimental_async::AddPeers(::grpc::ClientContext* context, const ::e8::AddPeersRequest* request, ::e8::AddPeersResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_AddPeers_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::AddPeersResponse>* NodeStateService::Stub::AsyncAddPeersRaw(::grpc::ClientContext* context, const ::e8::AddPeersRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::AddPeersResponse>::Create(channel_.get(), cq, rpcmethod_AddPeers_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::AddPeersResponse>* NodeStateService::Stub::PrepareAsyncAddPeersRaw(::grpc::ClientContext* context, const ::e8::AddPeersRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::AddPeersResponse>::Create(channel_.get(), cq, rpcmethod_AddPeers_, context, request, false);
}

::grpc::Status NodeStateService::Stub::DeletePeers(::grpc::ClientContext* context, const ::e8::DeletePeersRequest& request, ::e8::DeletePeersResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_DeletePeers_, context, request, response);
}

void NodeStateService::Stub::experimental_async::DeletePeers(::grpc::ClientContext* context, const ::e8::DeletePeersRequest* request, ::e8::DeletePeersResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_DeletePeers_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::DeletePeersResponse>* NodeStateService::Stub::AsyncDeletePeersRaw(::grpc::ClientContext* context, const ::e8::DeletePeersRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::DeletePeersResponse>::Create(channel_.get(), cq, rpcmethod_DeletePeers_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::DeletePeersResponse>* NodeStateService::Stub::PrepareAsyncDeletePeersRaw(::grpc::ClientContext* context, const ::e8::DeletePeersRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::DeletePeersResponse>::Create(channel_.get(), cq, rpcmethod_DeletePeers_, context, request, false);
}

::grpc::Status NodeStateService::Stub::GetNodeStates(::grpc::ClientContext* context, const ::e8::GetNodeStatesRequest& request, ::e8::GetNodeStatesResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetNodeStates_, context, request, response);
}

void NodeStateService::Stub::experimental_async::GetNodeStates(::grpc::ClientContext* context, const ::e8::GetNodeStatesRequest* request, ::e8::GetNodeStatesResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetNodeStates_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::GetNodeStatesResponse>* NodeStateService::Stub::AsyncGetNodeStatesRaw(::grpc::ClientContext* context, const ::e8::GetNodeStatesRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::GetNodeStatesResponse>::Create(channel_.get(), cq, rpcmethod_GetNodeStates_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::GetNodeStatesResponse>* NodeStateService::Stub::PrepareAsyncGetNodeStatesRaw(::grpc::ClientContext* context, const ::e8::GetNodeStatesRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::GetNodeStatesResponse>::Create(channel_.get(), cq, rpcmethod_GetNodeStates_, context, request, false);
}

NodeStateService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      NodeStateService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< NodeStateService::Service, ::e8::ReviseNodeStateRequest, ::e8::ReviseNodeStateResponse>(
          std::mem_fn(&NodeStateService::Service::ReviseNodeState), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      NodeStateService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< NodeStateService::Service, ::e8::GetCurrentRevisionEpochRequest, ::e8::GetCurrentRevisionEpochResponse>(
          std::mem_fn(&NodeStateService::Service::GetCurrentRevisionEpoch), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      NodeStateService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< NodeStateService::Service, ::e8::AddPeersRequest, ::e8::AddPeersResponse>(
          std::mem_fn(&NodeStateService::Service::AddPeers), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      NodeStateService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< NodeStateService::Service, ::e8::DeletePeersRequest, ::e8::DeletePeersResponse>(
          std::mem_fn(&NodeStateService::Service::DeletePeers), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      NodeStateService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< NodeStateService::Service, ::e8::GetNodeStatesRequest, ::e8::GetNodeStatesResponse>(
          std::mem_fn(&NodeStateService::Service::GetNodeStates), this)));
}

NodeStateService::Service::~Service() {
}

::grpc::Status NodeStateService::Service::ReviseNodeState(::grpc::ServerContext* context, const ::e8::ReviseNodeStateRequest* request, ::e8::ReviseNodeStateResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status NodeStateService::Service::GetCurrentRevisionEpoch(::grpc::ServerContext* context, const ::e8::GetCurrentRevisionEpochRequest* request, ::e8::GetCurrentRevisionEpochResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status NodeStateService::Service::AddPeers(::grpc::ServerContext* context, const ::e8::AddPeersRequest* request, ::e8::AddPeersResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status NodeStateService::Service::DeletePeers(::grpc::ServerContext* context, const ::e8::DeletePeersRequest* request, ::e8::DeletePeersResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status NodeStateService::Service::GetNodeStates(::grpc::ServerContext* context, const ::e8::GetNodeStatesRequest* request, ::e8::GetNodeStatesResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace e8

