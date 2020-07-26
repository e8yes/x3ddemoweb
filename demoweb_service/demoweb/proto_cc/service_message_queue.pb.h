// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: service_message_queue.proto

#ifndef PROTOBUF_INCLUDED_service_5fmessage_5fqueue_2eproto
#define PROTOBUF_INCLUDED_service_5fmessage_5fqueue_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "real_time_message.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_service_5fmessage_5fqueue_2eproto 

namespace protobuf_service_5fmessage_5fqueue_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_service_5fmessage_5fqueue_2eproto
namespace e8 {
class DequeueMessageRequest;
class DequeueMessageRequestDefaultTypeInternal;
extern DequeueMessageRequestDefaultTypeInternal _DequeueMessageRequest_default_instance_;
class DequeueMessageResponse;
class DequeueMessageResponseDefaultTypeInternal;
extern DequeueMessageResponseDefaultTypeInternal _DequeueMessageResponse_default_instance_;
class EnqueueMessageRequest;
class EnqueueMessageRequestDefaultTypeInternal;
extern EnqueueMessageRequestDefaultTypeInternal _EnqueueMessageRequest_default_instance_;
class EnqueueMessageResponse;
class EnqueueMessageResponseDefaultTypeInternal;
extern EnqueueMessageResponseDefaultTypeInternal _EnqueueMessageResponse_default_instance_;
}  // namespace e8
namespace google {
namespace protobuf {
template<> ::e8::DequeueMessageRequest* Arena::CreateMaybeMessage<::e8::DequeueMessageRequest>(Arena*);
template<> ::e8::DequeueMessageResponse* Arena::CreateMaybeMessage<::e8::DequeueMessageResponse>(Arena*);
template<> ::e8::EnqueueMessageRequest* Arena::CreateMaybeMessage<::e8::EnqueueMessageRequest>(Arena*);
template<> ::e8::EnqueueMessageResponse* Arena::CreateMaybeMessage<::e8::EnqueueMessageResponse>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace e8 {

// ===================================================================

class EnqueueMessageRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:e8.EnqueueMessageRequest) */ {
 public:
  EnqueueMessageRequest();
  virtual ~EnqueueMessageRequest();

  EnqueueMessageRequest(const EnqueueMessageRequest& from);

  inline EnqueueMessageRequest& operator=(const EnqueueMessageRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  EnqueueMessageRequest(EnqueueMessageRequest&& from) noexcept
    : EnqueueMessageRequest() {
    *this = ::std::move(from);
  }

  inline EnqueueMessageRequest& operator=(EnqueueMessageRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const EnqueueMessageRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const EnqueueMessageRequest* internal_default_instance() {
    return reinterpret_cast<const EnqueueMessageRequest*>(
               &_EnqueueMessageRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(EnqueueMessageRequest* other);
  friend void swap(EnqueueMessageRequest& a, EnqueueMessageRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline EnqueueMessageRequest* New() const final {
    return CreateMaybeMessage<EnqueueMessageRequest>(NULL);
  }

  EnqueueMessageRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<EnqueueMessageRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const EnqueueMessageRequest& from);
  void MergeFrom(const EnqueueMessageRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(EnqueueMessageRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .e8.RealTimeMessage messages = 2;
  int messages_size() const;
  void clear_messages();
  static const int kMessagesFieldNumber = 2;
  ::e8::RealTimeMessage* mutable_messages(int index);
  ::google::protobuf::RepeatedPtrField< ::e8::RealTimeMessage >*
      mutable_messages();
  const ::e8::RealTimeMessage& messages(int index) const;
  ::e8::RealTimeMessage* add_messages();
  const ::google::protobuf::RepeatedPtrField< ::e8::RealTimeMessage >&
      messages() const;

  // int64 user_id = 1;
  void clear_user_id();
  static const int kUserIdFieldNumber = 1;
  ::google::protobuf::int64 user_id() const;
  void set_user_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:e8.EnqueueMessageRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::e8::RealTimeMessage > messages_;
  ::google::protobuf::int64 user_id_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_service_5fmessage_5fqueue_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class EnqueueMessageResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:e8.EnqueueMessageResponse) */ {
 public:
  EnqueueMessageResponse();
  virtual ~EnqueueMessageResponse();

  EnqueueMessageResponse(const EnqueueMessageResponse& from);

  inline EnqueueMessageResponse& operator=(const EnqueueMessageResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  EnqueueMessageResponse(EnqueueMessageResponse&& from) noexcept
    : EnqueueMessageResponse() {
    *this = ::std::move(from);
  }

  inline EnqueueMessageResponse& operator=(EnqueueMessageResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const EnqueueMessageResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const EnqueueMessageResponse* internal_default_instance() {
    return reinterpret_cast<const EnqueueMessageResponse*>(
               &_EnqueueMessageResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(EnqueueMessageResponse* other);
  friend void swap(EnqueueMessageResponse& a, EnqueueMessageResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline EnqueueMessageResponse* New() const final {
    return CreateMaybeMessage<EnqueueMessageResponse>(NULL);
  }

  EnqueueMessageResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<EnqueueMessageResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const EnqueueMessageResponse& from);
  void MergeFrom(const EnqueueMessageResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(EnqueueMessageResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:e8.EnqueueMessageResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_service_5fmessage_5fqueue_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class DequeueMessageRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:e8.DequeueMessageRequest) */ {
 public:
  DequeueMessageRequest();
  virtual ~DequeueMessageRequest();

  DequeueMessageRequest(const DequeueMessageRequest& from);

  inline DequeueMessageRequest& operator=(const DequeueMessageRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DequeueMessageRequest(DequeueMessageRequest&& from) noexcept
    : DequeueMessageRequest() {
    *this = ::std::move(from);
  }

  inline DequeueMessageRequest& operator=(DequeueMessageRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DequeueMessageRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DequeueMessageRequest* internal_default_instance() {
    return reinterpret_cast<const DequeueMessageRequest*>(
               &_DequeueMessageRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(DequeueMessageRequest* other);
  friend void swap(DequeueMessageRequest& a, DequeueMessageRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DequeueMessageRequest* New() const final {
    return CreateMaybeMessage<DequeueMessageRequest>(NULL);
  }

  DequeueMessageRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<DequeueMessageRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const DequeueMessageRequest& from);
  void MergeFrom(const DequeueMessageRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DequeueMessageRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int64 user_id = 1;
  void clear_user_id();
  static const int kUserIdFieldNumber = 1;
  ::google::protobuf::int64 user_id() const;
  void set_user_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:e8.DequeueMessageRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int64 user_id_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_service_5fmessage_5fqueue_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class DequeueMessageResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:e8.DequeueMessageResponse) */ {
 public:
  DequeueMessageResponse();
  virtual ~DequeueMessageResponse();

  DequeueMessageResponse(const DequeueMessageResponse& from);

  inline DequeueMessageResponse& operator=(const DequeueMessageResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DequeueMessageResponse(DequeueMessageResponse&& from) noexcept
    : DequeueMessageResponse() {
    *this = ::std::move(from);
  }

  inline DequeueMessageResponse& operator=(DequeueMessageResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DequeueMessageResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DequeueMessageResponse* internal_default_instance() {
    return reinterpret_cast<const DequeueMessageResponse*>(
               &_DequeueMessageResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(DequeueMessageResponse* other);
  friend void swap(DequeueMessageResponse& a, DequeueMessageResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DequeueMessageResponse* New() const final {
    return CreateMaybeMessage<DequeueMessageResponse>(NULL);
  }

  DequeueMessageResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<DequeueMessageResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const DequeueMessageResponse& from);
  void MergeFrom(const DequeueMessageResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DequeueMessageResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .e8.RealTimeMessage messages = 2;
  int messages_size() const;
  void clear_messages();
  static const int kMessagesFieldNumber = 2;
  ::e8::RealTimeMessage* mutable_messages(int index);
  ::google::protobuf::RepeatedPtrField< ::e8::RealTimeMessage >*
      mutable_messages();
  const ::e8::RealTimeMessage& messages(int index) const;
  ::e8::RealTimeMessage* add_messages();
  const ::google::protobuf::RepeatedPtrField< ::e8::RealTimeMessage >&
      messages() const;

  // @@protoc_insertion_point(class_scope:e8.DequeueMessageResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::e8::RealTimeMessage > messages_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_service_5fmessage_5fqueue_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// EnqueueMessageRequest

// int64 user_id = 1;
inline void EnqueueMessageRequest::clear_user_id() {
  user_id_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 EnqueueMessageRequest::user_id() const {
  // @@protoc_insertion_point(field_get:e8.EnqueueMessageRequest.user_id)
  return user_id_;
}
inline void EnqueueMessageRequest::set_user_id(::google::protobuf::int64 value) {
  
  user_id_ = value;
  // @@protoc_insertion_point(field_set:e8.EnqueueMessageRequest.user_id)
}

// repeated .e8.RealTimeMessage messages = 2;
inline int EnqueueMessageRequest::messages_size() const {
  return messages_.size();
}
inline ::e8::RealTimeMessage* EnqueueMessageRequest::mutable_messages(int index) {
  // @@protoc_insertion_point(field_mutable:e8.EnqueueMessageRequest.messages)
  return messages_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::e8::RealTimeMessage >*
EnqueueMessageRequest::mutable_messages() {
  // @@protoc_insertion_point(field_mutable_list:e8.EnqueueMessageRequest.messages)
  return &messages_;
}
inline const ::e8::RealTimeMessage& EnqueueMessageRequest::messages(int index) const {
  // @@protoc_insertion_point(field_get:e8.EnqueueMessageRequest.messages)
  return messages_.Get(index);
}
inline ::e8::RealTimeMessage* EnqueueMessageRequest::add_messages() {
  // @@protoc_insertion_point(field_add:e8.EnqueueMessageRequest.messages)
  return messages_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::e8::RealTimeMessage >&
EnqueueMessageRequest::messages() const {
  // @@protoc_insertion_point(field_list:e8.EnqueueMessageRequest.messages)
  return messages_;
}

// -------------------------------------------------------------------

// EnqueueMessageResponse

// -------------------------------------------------------------------

// DequeueMessageRequest

// int64 user_id = 1;
inline void DequeueMessageRequest::clear_user_id() {
  user_id_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 DequeueMessageRequest::user_id() const {
  // @@protoc_insertion_point(field_get:e8.DequeueMessageRequest.user_id)
  return user_id_;
}
inline void DequeueMessageRequest::set_user_id(::google::protobuf::int64 value) {
  
  user_id_ = value;
  // @@protoc_insertion_point(field_set:e8.DequeueMessageRequest.user_id)
}

// -------------------------------------------------------------------

// DequeueMessageResponse

// repeated .e8.RealTimeMessage messages = 2;
inline int DequeueMessageResponse::messages_size() const {
  return messages_.size();
}
inline ::e8::RealTimeMessage* DequeueMessageResponse::mutable_messages(int index) {
  // @@protoc_insertion_point(field_mutable:e8.DequeueMessageResponse.messages)
  return messages_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::e8::RealTimeMessage >*
DequeueMessageResponse::mutable_messages() {
  // @@protoc_insertion_point(field_mutable_list:e8.DequeueMessageResponse.messages)
  return &messages_;
}
inline const ::e8::RealTimeMessage& DequeueMessageResponse::messages(int index) const {
  // @@protoc_insertion_point(field_get:e8.DequeueMessageResponse.messages)
  return messages_.Get(index);
}
inline ::e8::RealTimeMessage* DequeueMessageResponse::add_messages() {
  // @@protoc_insertion_point(field_add:e8.DequeueMessageResponse.messages)
  return messages_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::e8::RealTimeMessage >&
DequeueMessageResponse::messages() const {
  // @@protoc_insertion_point(field_list:e8.DequeueMessageResponse.messages)
  return messages_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace e8

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_service_5fmessage_5fqueue_2eproto
