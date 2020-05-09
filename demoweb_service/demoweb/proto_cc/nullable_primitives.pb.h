// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: nullable_primitives.proto

#ifndef PROTOBUF_INCLUDED_nullable_5fprimitives_2eproto
#define PROTOBUF_INCLUDED_nullable_5fprimitives_2eproto

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
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_nullable_5fprimitives_2eproto 

namespace protobuf_nullable_5fprimitives_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[5];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_nullable_5fprimitives_2eproto
namespace e8 {
class NullableDouble;
class NullableDoubleDefaultTypeInternal;
extern NullableDoubleDefaultTypeInternal _NullableDouble_default_instance_;
class NullableFloat;
class NullableFloatDefaultTypeInternal;
extern NullableFloatDefaultTypeInternal _NullableFloat_default_instance_;
class NullableInt32;
class NullableInt32DefaultTypeInternal;
extern NullableInt32DefaultTypeInternal _NullableInt32_default_instance_;
class NullableInt64;
class NullableInt64DefaultTypeInternal;
extern NullableInt64DefaultTypeInternal _NullableInt64_default_instance_;
class NullableString;
class NullableStringDefaultTypeInternal;
extern NullableStringDefaultTypeInternal _NullableString_default_instance_;
}  // namespace e8
namespace google {
namespace protobuf {
template<> ::e8::NullableDouble* Arena::CreateMaybeMessage<::e8::NullableDouble>(Arena*);
template<> ::e8::NullableFloat* Arena::CreateMaybeMessage<::e8::NullableFloat>(Arena*);
template<> ::e8::NullableInt32* Arena::CreateMaybeMessage<::e8::NullableInt32>(Arena*);
template<> ::e8::NullableInt64* Arena::CreateMaybeMessage<::e8::NullableInt64>(Arena*);
template<> ::e8::NullableString* Arena::CreateMaybeMessage<::e8::NullableString>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace e8 {

// ===================================================================

class NullableInt32 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:e8.NullableInt32) */ {
 public:
  NullableInt32();
  virtual ~NullableInt32();

  NullableInt32(const NullableInt32& from);

  inline NullableInt32& operator=(const NullableInt32& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  NullableInt32(NullableInt32&& from) noexcept
    : NullableInt32() {
    *this = ::std::move(from);
  }

  inline NullableInt32& operator=(NullableInt32&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const NullableInt32& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NullableInt32* internal_default_instance() {
    return reinterpret_cast<const NullableInt32*>(
               &_NullableInt32_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(NullableInt32* other);
  friend void swap(NullableInt32& a, NullableInt32& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline NullableInt32* New() const final {
    return CreateMaybeMessage<NullableInt32>(NULL);
  }

  NullableInt32* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<NullableInt32>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const NullableInt32& from);
  void MergeFrom(const NullableInt32& from);
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
  void InternalSwap(NullableInt32* other);
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

  // int32 value = 1;
  void clear_value();
  static const int kValueFieldNumber = 1;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:e8.NullableInt32)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 value_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_nullable_5fprimitives_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class NullableInt64 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:e8.NullableInt64) */ {
 public:
  NullableInt64();
  virtual ~NullableInt64();

  NullableInt64(const NullableInt64& from);

  inline NullableInt64& operator=(const NullableInt64& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  NullableInt64(NullableInt64&& from) noexcept
    : NullableInt64() {
    *this = ::std::move(from);
  }

  inline NullableInt64& operator=(NullableInt64&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const NullableInt64& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NullableInt64* internal_default_instance() {
    return reinterpret_cast<const NullableInt64*>(
               &_NullableInt64_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(NullableInt64* other);
  friend void swap(NullableInt64& a, NullableInt64& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline NullableInt64* New() const final {
    return CreateMaybeMessage<NullableInt64>(NULL);
  }

  NullableInt64* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<NullableInt64>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const NullableInt64& from);
  void MergeFrom(const NullableInt64& from);
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
  void InternalSwap(NullableInt64* other);
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

  // int64 value = 1;
  void clear_value();
  static const int kValueFieldNumber = 1;
  ::google::protobuf::int64 value() const;
  void set_value(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:e8.NullableInt64)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int64 value_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_nullable_5fprimitives_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class NullableFloat : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:e8.NullableFloat) */ {
 public:
  NullableFloat();
  virtual ~NullableFloat();

  NullableFloat(const NullableFloat& from);

  inline NullableFloat& operator=(const NullableFloat& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  NullableFloat(NullableFloat&& from) noexcept
    : NullableFloat() {
    *this = ::std::move(from);
  }

  inline NullableFloat& operator=(NullableFloat&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const NullableFloat& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NullableFloat* internal_default_instance() {
    return reinterpret_cast<const NullableFloat*>(
               &_NullableFloat_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(NullableFloat* other);
  friend void swap(NullableFloat& a, NullableFloat& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline NullableFloat* New() const final {
    return CreateMaybeMessage<NullableFloat>(NULL);
  }

  NullableFloat* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<NullableFloat>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const NullableFloat& from);
  void MergeFrom(const NullableFloat& from);
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
  void InternalSwap(NullableFloat* other);
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

  // float value = 1;
  void clear_value();
  static const int kValueFieldNumber = 1;
  float value() const;
  void set_value(float value);

  // @@protoc_insertion_point(class_scope:e8.NullableFloat)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  float value_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_nullable_5fprimitives_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class NullableDouble : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:e8.NullableDouble) */ {
 public:
  NullableDouble();
  virtual ~NullableDouble();

  NullableDouble(const NullableDouble& from);

  inline NullableDouble& operator=(const NullableDouble& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  NullableDouble(NullableDouble&& from) noexcept
    : NullableDouble() {
    *this = ::std::move(from);
  }

  inline NullableDouble& operator=(NullableDouble&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const NullableDouble& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NullableDouble* internal_default_instance() {
    return reinterpret_cast<const NullableDouble*>(
               &_NullableDouble_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(NullableDouble* other);
  friend void swap(NullableDouble& a, NullableDouble& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline NullableDouble* New() const final {
    return CreateMaybeMessage<NullableDouble>(NULL);
  }

  NullableDouble* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<NullableDouble>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const NullableDouble& from);
  void MergeFrom(const NullableDouble& from);
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
  void InternalSwap(NullableDouble* other);
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

  // double value = 1;
  void clear_value();
  static const int kValueFieldNumber = 1;
  double value() const;
  void set_value(double value);

  // @@protoc_insertion_point(class_scope:e8.NullableDouble)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  double value_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_nullable_5fprimitives_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class NullableString : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:e8.NullableString) */ {
 public:
  NullableString();
  virtual ~NullableString();

  NullableString(const NullableString& from);

  inline NullableString& operator=(const NullableString& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  NullableString(NullableString&& from) noexcept
    : NullableString() {
    *this = ::std::move(from);
  }

  inline NullableString& operator=(NullableString&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const NullableString& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NullableString* internal_default_instance() {
    return reinterpret_cast<const NullableString*>(
               &_NullableString_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    4;

  void Swap(NullableString* other);
  friend void swap(NullableString& a, NullableString& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline NullableString* New() const final {
    return CreateMaybeMessage<NullableString>(NULL);
  }

  NullableString* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<NullableString>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const NullableString& from);
  void MergeFrom(const NullableString& from);
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
  void InternalSwap(NullableString* other);
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

  // string value = 1;
  void clear_value();
  static const int kValueFieldNumber = 1;
  const ::std::string& value() const;
  void set_value(const ::std::string& value);
  #if LANG_CXX11
  void set_value(::std::string&& value);
  #endif
  void set_value(const char* value);
  void set_value(const char* value, size_t size);
  ::std::string* mutable_value();
  ::std::string* release_value();
  void set_allocated_value(::std::string* value);

  // @@protoc_insertion_point(class_scope:e8.NullableString)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr value_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_nullable_5fprimitives_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// NullableInt32

// int32 value = 1;
inline void NullableInt32::clear_value() {
  value_ = 0;
}
inline ::google::protobuf::int32 NullableInt32::value() const {
  // @@protoc_insertion_point(field_get:e8.NullableInt32.value)
  return value_;
}
inline void NullableInt32::set_value(::google::protobuf::int32 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:e8.NullableInt32.value)
}

// -------------------------------------------------------------------

// NullableInt64

// int64 value = 1;
inline void NullableInt64::clear_value() {
  value_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 NullableInt64::value() const {
  // @@protoc_insertion_point(field_get:e8.NullableInt64.value)
  return value_;
}
inline void NullableInt64::set_value(::google::protobuf::int64 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:e8.NullableInt64.value)
}

// -------------------------------------------------------------------

// NullableFloat

// float value = 1;
inline void NullableFloat::clear_value() {
  value_ = 0;
}
inline float NullableFloat::value() const {
  // @@protoc_insertion_point(field_get:e8.NullableFloat.value)
  return value_;
}
inline void NullableFloat::set_value(float value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:e8.NullableFloat.value)
}

// -------------------------------------------------------------------

// NullableDouble

// double value = 1;
inline void NullableDouble::clear_value() {
  value_ = 0;
}
inline double NullableDouble::value() const {
  // @@protoc_insertion_point(field_get:e8.NullableDouble.value)
  return value_;
}
inline void NullableDouble::set_value(double value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:e8.NullableDouble.value)
}

// -------------------------------------------------------------------

// NullableString

// string value = 1;
inline void NullableString::clear_value() {
  value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& NullableString::value() const {
  // @@protoc_insertion_point(field_get:e8.NullableString.value)
  return value_.GetNoArena();
}
inline void NullableString::set_value(const ::std::string& value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:e8.NullableString.value)
}
#if LANG_CXX11
inline void NullableString::set_value(::std::string&& value) {
  
  value_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:e8.NullableString.value)
}
#endif
inline void NullableString::set_value(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:e8.NullableString.value)
}
inline void NullableString::set_value(const char* value, size_t size) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:e8.NullableString.value)
}
inline ::std::string* NullableString::mutable_value() {
  
  // @@protoc_insertion_point(field_mutable:e8.NullableString.value)
  return value_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* NullableString::release_value() {
  // @@protoc_insertion_point(field_release:e8.NullableString.value)
  
  return value_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NullableString::set_allocated_value(::std::string* value) {
  if (value != NULL) {
    
  } else {
    
  }
  value_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set_allocated:e8.NullableString.value)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace e8

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_nullable_5fprimitives_2eproto
