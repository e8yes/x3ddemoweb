// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: node.proto

#include "node.pb.h"

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
class NodeStateDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<NodeState>
      _instance;
} _NodeState_default_instance_;
}  // namespace e8
namespace protobuf_node_2eproto {
static void InitDefaultsNodeState() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::e8::_NodeState_default_instance_;
    new (ptr) ::e8::NodeState();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::e8::NodeState::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_NodeState =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsNodeState}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_NodeState.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::NodeState, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::NodeState, clock_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::NodeState, ip_address_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::NodeState, name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::NodeState, types_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::NodeState, ports_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::e8::NodeState)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::e8::_NodeState_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "node.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\nnode.proto\022\002e8\"h\n\tNodeState\022\r\n\005clock\030\001"
      " \001(\003\022\022\n\nip_address\030\002 \001(\014\022\014\n\004name\030\003 \001(\t\022\033"
      "\n\005types\030\004 \003(\0162\014.e8.NodeType\022\r\n\005ports\030\005 \003"
      "(\005*]\n\010NodeType\022\017\n\013NDT_INVALID\020\000\022\022\n\016NDT_F"
      "ILE_STORE\020\001\022\025\n\021NDT_MESSAGE_STORE\020\002\022\025\n\021ND"
      "T_TASK_EXECUTOR\020\003b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 225);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "node.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_node_2eproto
namespace e8 {
const ::google::protobuf::EnumDescriptor* NodeType_descriptor() {
  protobuf_node_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_node_2eproto::file_level_enum_descriptors[0];
}
bool NodeType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void NodeState::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int NodeState::kClockFieldNumber;
const int NodeState::kIpAddressFieldNumber;
const int NodeState::kNameFieldNumber;
const int NodeState::kTypesFieldNumber;
const int NodeState::kPortsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

NodeState::NodeState()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_node_2eproto::scc_info_NodeState.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:e8.NodeState)
}
NodeState::NodeState(const NodeState& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      types_(from.types_),
      ports_(from.ports_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ip_address_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.ip_address().size() > 0) {
    ip_address_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.ip_address_);
  }
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.name().size() > 0) {
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  clock_ = from.clock_;
  // @@protoc_insertion_point(copy_constructor:e8.NodeState)
}

void NodeState::SharedCtor() {
  ip_address_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clock_ = GOOGLE_LONGLONG(0);
}

NodeState::~NodeState() {
  // @@protoc_insertion_point(destructor:e8.NodeState)
  SharedDtor();
}

void NodeState::SharedDtor() {
  ip_address_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void NodeState::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* NodeState::descriptor() {
  ::protobuf_node_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_node_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const NodeState& NodeState::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_node_2eproto::scc_info_NodeState.base);
  return *internal_default_instance();
}


void NodeState::Clear() {
// @@protoc_insertion_point(message_clear_start:e8.NodeState)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  types_.Clear();
  ports_.Clear();
  ip_address_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clock_ = GOOGLE_LONGLONG(0);
  _internal_metadata_.Clear();
}

bool NodeState::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:e8.NodeState)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // int64 clock = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &clock_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bytes ip_address = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_ip_address()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string name = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->name().data(), static_cast<int>(this->name().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "e8.NodeState.name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .e8.NodeType types = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          ::google::protobuf::uint32 length;
          DO_(input->ReadVarint32(&length));
          ::google::protobuf::io::CodedInputStream::Limit limit = input->PushLimit(static_cast<int>(length));
          while (input->BytesUntilLimit() > 0) {
            int value;
            DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
            add_types(static_cast< ::e8::NodeType >(value));
          }
          input->PopLimit(limit);
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          add_types(static_cast< ::e8::NodeType >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated int32 ports = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_ports())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 42u, input, this->mutable_ports())));
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
  // @@protoc_insertion_point(parse_success:e8.NodeState)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:e8.NodeState)
  return false;
#undef DO_
}

void NodeState::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:e8.NodeState)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 clock = 1;
  if (this->clock() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->clock(), output);
  }

  // bytes ip_address = 2;
  if (this->ip_address().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->ip_address(), output);
  }

  // string name = 3;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "e8.NodeState.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->name(), output);
  }

  // repeated .e8.NodeType types = 4;
  if (this->types_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(
      4,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      output);
    output->WriteVarint32(
        static_cast< ::google::protobuf::uint32>(_types_cached_byte_size_));
  }
  for (int i = 0, n = this->types_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteEnumNoTag(
      this->types(i), output);
  }

  // repeated int32 ports = 5;
  if (this->ports_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(5, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(static_cast< ::google::protobuf::uint32>(
        _ports_cached_byte_size_));
  }
  for (int i = 0, n = this->ports_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(
      this->ports(i), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:e8.NodeState)
}

::google::protobuf::uint8* NodeState::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:e8.NodeState)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 clock = 1;
  if (this->clock() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->clock(), target);
  }

  // bytes ip_address = 2;
  if (this->ip_address().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->ip_address(), target);
  }

  // string name = 3;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "e8.NodeState.name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->name(), target);
  }

  // repeated .e8.NodeType types = 4;
  if (this->types_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      4,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(      static_cast< ::google::protobuf::uint32>(
            _types_cached_byte_size_), target);
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumNoTagToArray(
      this->types_, target);
  }

  // repeated int32 ports = 5;
  if (this->ports_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      5,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
        static_cast< ::google::protobuf::int32>(
            _ports_cached_byte_size_), target);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32NoTagToArray(this->ports_, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:e8.NodeState)
  return target;
}

size_t NodeState::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:e8.NodeState)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .e8.NodeType types = 4;
  {
    size_t data_size = 0;
    unsigned int count = static_cast<unsigned int>(this->types_size());for (unsigned int i = 0; i < count; i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::EnumSize(
        this->types(static_cast<int>(i)));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
            static_cast< ::google::protobuf::int32>(data_size));
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _types_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // repeated int32 ports = 5;
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      Int32Size(this->ports_);
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
            static_cast< ::google::protobuf::int32>(data_size));
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _ports_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // bytes ip_address = 2;
  if (this->ip_address().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->ip_address());
  }

  // string name = 3;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  // int64 clock = 1;
  if (this->clock() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->clock());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void NodeState::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:e8.NodeState)
  GOOGLE_DCHECK_NE(&from, this);
  const NodeState* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const NodeState>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:e8.NodeState)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:e8.NodeState)
    MergeFrom(*source);
  }
}

void NodeState::MergeFrom(const NodeState& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:e8.NodeState)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  types_.MergeFrom(from.types_);
  ports_.MergeFrom(from.ports_);
  if (from.ip_address().size() > 0) {

    ip_address_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.ip_address_);
  }
  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.clock() != 0) {
    set_clock(from.clock());
  }
}

void NodeState::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:e8.NodeState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NodeState::CopyFrom(const NodeState& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:e8.NodeState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NodeState::IsInitialized() const {
  return true;
}

void NodeState::Swap(NodeState* other) {
  if (other == this) return;
  InternalSwap(other);
}
void NodeState::InternalSwap(NodeState* other) {
  using std::swap;
  types_.InternalSwap(&other->types_);
  ports_.InternalSwap(&other->ports_);
  ip_address_.Swap(&other->ip_address_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  name_.Swap(&other->name_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(clock_, other->clock_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata NodeState::GetMetadata() const {
  protobuf_node_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_node_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace e8
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::e8::NodeState* Arena::CreateMaybeMessage< ::e8::NodeState >(Arena* arena) {
  return Arena::CreateInternal< ::e8::NodeState >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)