// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user_relation.proto

#include "user_relation.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_user_5frelation_2eproto {
void InitDefaults() {
}

const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];
const ::google::protobuf::uint32 TableStruct::offsets[1] = {};
static const ::google::protobuf::internal::MigrationSchema* schemas = NULL;
static const ::google::protobuf::Message* const* file_default_instances = NULL;

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "user_relation.proto", schemas, file_default_instances, TableStruct::offsets,
      NULL, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\023user_relation.proto*\213\001\n\014UserRelation\022\021"
      "\n\rURL_UNRELATED\020\000\022\027\n\023URL_INVITATION_SENT"
      "\020\001\022\033\n\027URL_INVITATION_RECEIVED\020\002\022\017\n\013URL_C"
      "ONTACT\020\003\022\020\n\014URL_BLOCKING\020\004\022\017\n\013URL_BLOCKE"
      "D\020\005b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 171);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "user_relation.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_user_5frelation_2eproto
const ::google::protobuf::EnumDescriptor* UserRelation_descriptor() {
  protobuf_user_5frelation_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_user_5frelation_2eproto::file_level_enum_descriptors[0];
}
bool UserRelation_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
