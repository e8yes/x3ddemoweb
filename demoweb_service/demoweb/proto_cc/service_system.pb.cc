// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: service_system.proto

#include "service_system.pb.h"

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

namespace e8 {
class VersionResponseDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<VersionResponse>
      _instance;
} _VersionResponse_default_instance_;
class VersionResquestDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<VersionResquest>
      _instance;
} _VersionResquest_default_instance_;
}  // namespace e8
namespace protobuf_service_5fsystem_2eproto {
static void InitDefaultsVersionResponse() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::e8::_VersionResponse_default_instance_;
    new (ptr) ::e8::VersionResponse();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::e8::VersionResponse::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_VersionResponse =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsVersionResponse}, {}};

static void InitDefaultsVersionResquest() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::e8::_VersionResquest_default_instance_;
    new (ptr) ::e8::VersionResquest();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::e8::VersionResquest::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_VersionResquest =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsVersionResquest}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_VersionResponse.base);
  ::google::protobuf::internal::InitSCC(&scc_info_VersionResquest.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::VersionResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::VersionResponse, version_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::VersionResquest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::e8::VersionResponse)},
  { 6, -1, sizeof(::e8::VersionResquest)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::e8::_VersionResponse_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::e8::_VersionResquest_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "service_system.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\024service_system.proto\022\002e8\"\"\n\017VersionRes"
      "ponse\022\017\n\007version\030\001 \001(\t\"\021\n\017VersionResques"
      "t2D\n\rSystemService\0223\n\007Version\022\023.e8.Versi"
      "onResquest\032\023.e8.VersionResponseb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 159);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "service_system.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_service_5fsystem_2eproto
namespace e8 {

// ===================================================================

void VersionResponse::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int VersionResponse::kVersionFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

VersionResponse::VersionResponse()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_service_5fsystem_2eproto::scc_info_VersionResponse.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:e8.VersionResponse)
}
VersionResponse::VersionResponse(const VersionResponse& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  version_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.version().size() > 0) {
    version_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.version_);
  }
  // @@protoc_insertion_point(copy_constructor:e8.VersionResponse)
}

void VersionResponse::SharedCtor() {
  version_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

VersionResponse::~VersionResponse() {
  // @@protoc_insertion_point(destructor:e8.VersionResponse)
  SharedDtor();
}

void VersionResponse::SharedDtor() {
  version_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void VersionResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* VersionResponse::descriptor() {
  ::protobuf_service_5fsystem_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_service_5fsystem_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const VersionResponse& VersionResponse::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_service_5fsystem_2eproto::scc_info_VersionResponse.base);
  return *internal_default_instance();
}


void VersionResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:e8.VersionResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  version_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool VersionResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:e8.VersionResponse)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string version = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_version()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->version().data(), static_cast<int>(this->version().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "e8.VersionResponse.version"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:e8.VersionResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:e8.VersionResponse)
  return false;
#undef DO_
}

void VersionResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:e8.VersionResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string version = 1;
  if (this->version().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->version().data(), static_cast<int>(this->version().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "e8.VersionResponse.version");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->version(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:e8.VersionResponse)
}

::google::protobuf::uint8* VersionResponse::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:e8.VersionResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string version = 1;
  if (this->version().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->version().data(), static_cast<int>(this->version().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "e8.VersionResponse.version");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->version(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:e8.VersionResponse)
  return target;
}

size_t VersionResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:e8.VersionResponse)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string version = 1;
  if (this->version().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->version());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void VersionResponse::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:e8.VersionResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const VersionResponse* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const VersionResponse>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:e8.VersionResponse)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:e8.VersionResponse)
    MergeFrom(*source);
  }
}

void VersionResponse::MergeFrom(const VersionResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:e8.VersionResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.version().size() > 0) {

    version_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.version_);
  }
}

void VersionResponse::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:e8.VersionResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VersionResponse::CopyFrom(const VersionResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:e8.VersionResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VersionResponse::IsInitialized() const {
  return true;
}

void VersionResponse::Swap(VersionResponse* other) {
  if (other == this) return;
  InternalSwap(other);
}
void VersionResponse::InternalSwap(VersionResponse* other) {
  using std::swap;
  version_.Swap(&other->version_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata VersionResponse::GetMetadata() const {
  protobuf_service_5fsystem_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_service_5fsystem_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void VersionResquest::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

VersionResquest::VersionResquest()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_service_5fsystem_2eproto::scc_info_VersionResquest.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:e8.VersionResquest)
}
VersionResquest::VersionResquest(const VersionResquest& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:e8.VersionResquest)
}

void VersionResquest::SharedCtor() {
}

VersionResquest::~VersionResquest() {
  // @@protoc_insertion_point(destructor:e8.VersionResquest)
  SharedDtor();
}

void VersionResquest::SharedDtor() {
}

void VersionResquest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* VersionResquest::descriptor() {
  ::protobuf_service_5fsystem_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_service_5fsystem_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const VersionResquest& VersionResquest::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_service_5fsystem_2eproto::scc_info_VersionResquest.base);
  return *internal_default_instance();
}


void VersionResquest::Clear() {
// @@protoc_insertion_point(message_clear_start:e8.VersionResquest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_metadata_.Clear();
}

bool VersionResquest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:e8.VersionResquest)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, _internal_metadata_.mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:e8.VersionResquest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:e8.VersionResquest)
  return false;
#undef DO_
}

void VersionResquest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:e8.VersionResquest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:e8.VersionResquest)
}

::google::protobuf::uint8* VersionResquest::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:e8.VersionResquest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:e8.VersionResquest)
  return target;
}

size_t VersionResquest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:e8.VersionResquest)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void VersionResquest::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:e8.VersionResquest)
  GOOGLE_DCHECK_NE(&from, this);
  const VersionResquest* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const VersionResquest>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:e8.VersionResquest)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:e8.VersionResquest)
    MergeFrom(*source);
  }
}

void VersionResquest::MergeFrom(const VersionResquest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:e8.VersionResquest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

}

void VersionResquest::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:e8.VersionResquest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VersionResquest::CopyFrom(const VersionResquest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:e8.VersionResquest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VersionResquest::IsInitialized() const {
  return true;
}

void VersionResquest::Swap(VersionResquest* other) {
  if (other == this) return;
  InternalSwap(other);
}
void VersionResquest::InternalSwap(VersionResquest* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata VersionResquest::GetMetadata() const {
  protobuf_service_5fsystem_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_service_5fsystem_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace e8
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::e8::VersionResponse* Arena::CreateMaybeMessage< ::e8::VersionResponse >(Arena* arena) {
  return Arena::CreateInternal< ::e8::VersionResponse >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::e8::VersionResquest* Arena::CreateMaybeMessage< ::e8::VersionResquest >(Arena* arena) {
  return Arena::CreateInternal< ::e8::VersionResquest >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
