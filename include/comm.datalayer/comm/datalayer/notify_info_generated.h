// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_NOTIFYINFO_COMM_DATALAYER_H_
#define FLATBUFFERS_GENERATED_NOTIFYINFO_COMM_DATALAYER_H_

#include "flatbuffers/flatbuffers.h"

namespace comm {
namespace datalayer {

struct NotifyInfo;
struct NotifyInfoBuilder;
struct NotifyInfoT;

enum NotifyType : int32_t {
  NotifyType_Data = 0,
  NotifyType_Browse = 1,
  NotifyType_Metadata = 2,
  NotifyType_MIN = NotifyType_Data,
  NotifyType_MAX = NotifyType_Metadata
};

inline const NotifyType (&EnumValuesNotifyType())[3] {
  static const NotifyType values[] = {
    NotifyType_Data,
    NotifyType_Browse,
    NotifyType_Metadata
  };
  return values;
}

inline const char * const *EnumNamesNotifyType() {
  static const char * const names[4] = {
    "Data",
    "Browse",
    "Metadata",
    nullptr
  };
  return names;
}

inline const char *EnumNameNotifyType(NotifyType e) {
  if (flatbuffers::IsOutRange(e, NotifyType_Data, NotifyType_Metadata)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesNotifyType()[index];
}

struct NotifyInfoT : public flatbuffers::NativeTable {
  typedef NotifyInfo TableType;
  std::string node{};
  uint64_t timestamp = 0;
  comm::datalayer::NotifyType notifyType = comm::datalayer::NotifyType_Data;
};

struct NotifyInfo FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef NotifyInfoT NativeTableType;
  typedef NotifyInfoBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NODE = 4,
    VT_TIMESTAMP = 6,
    VT_NOTIFYTYPE = 8
  };
  const flatbuffers::String *node() const {
    return GetPointer<const flatbuffers::String *>(VT_NODE);
  }
  flatbuffers::String *mutable_node() {
    return GetPointer<flatbuffers::String *>(VT_NODE);
  }
  uint64_t timestamp() const {
    return GetField<uint64_t>(VT_TIMESTAMP, 0);
  }
  bool mutate_timestamp(uint64_t _timestamp) {
    return SetField<uint64_t>(VT_TIMESTAMP, _timestamp, 0);
  }
  comm::datalayer::NotifyType notifyType() const {
    return static_cast<comm::datalayer::NotifyType>(GetField<int32_t>(VT_NOTIFYTYPE, 0));
  }
  bool mutate_notifyType(comm::datalayer::NotifyType _notifyType) {
    return SetField<int32_t>(VT_NOTIFYTYPE, static_cast<int32_t>(_notifyType), 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NODE) &&
           verifier.VerifyString(node()) &&
           VerifyField<uint64_t>(verifier, VT_TIMESTAMP) &&
           VerifyField<int32_t>(verifier, VT_NOTIFYTYPE) &&
           verifier.EndTable();
  }
  NotifyInfoT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(NotifyInfoT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<NotifyInfo> Pack(flatbuffers::FlatBufferBuilder &_fbb, const NotifyInfoT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct NotifyInfoBuilder {
  typedef NotifyInfo Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_node(flatbuffers::Offset<flatbuffers::String> node) {
    fbb_.AddOffset(NotifyInfo::VT_NODE, node);
  }
  void add_timestamp(uint64_t timestamp) {
    fbb_.AddElement<uint64_t>(NotifyInfo::VT_TIMESTAMP, timestamp, 0);
  }
  void add_notifyType(comm::datalayer::NotifyType notifyType) {
    fbb_.AddElement<int32_t>(NotifyInfo::VT_NOTIFYTYPE, static_cast<int32_t>(notifyType), 0);
  }
  explicit NotifyInfoBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<NotifyInfo> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<NotifyInfo>(end);
    return o;
  }
};

inline flatbuffers::Offset<NotifyInfo> CreateNotifyInfo(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> node = 0,
    uint64_t timestamp = 0,
    comm::datalayer::NotifyType notifyType = comm::datalayer::NotifyType_Data) {
  NotifyInfoBuilder builder_(_fbb);
  builder_.add_timestamp(timestamp);
  builder_.add_notifyType(notifyType);
  builder_.add_node(node);
  return builder_.Finish();
}

inline flatbuffers::Offset<NotifyInfo> CreateNotifyInfoDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *node = nullptr,
    uint64_t timestamp = 0,
    comm::datalayer::NotifyType notifyType = comm::datalayer::NotifyType_Data) {
  auto node__ = node ? _fbb.CreateString(node) : 0;
  return comm::datalayer::CreateNotifyInfo(
      _fbb,
      node__,
      timestamp,
      notifyType);
}

flatbuffers::Offset<NotifyInfo> CreateNotifyInfo(flatbuffers::FlatBufferBuilder &_fbb, const NotifyInfoT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline NotifyInfoT *NotifyInfo::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<NotifyInfoT>(new NotifyInfoT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void NotifyInfo::UnPackTo(NotifyInfoT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = node(); if (_e) _o->node = _e->str(); }
  { auto _e = timestamp(); _o->timestamp = _e; }
  { auto _e = notifyType(); _o->notifyType = _e; }
}

inline flatbuffers::Offset<NotifyInfo> NotifyInfo::Pack(flatbuffers::FlatBufferBuilder &_fbb, const NotifyInfoT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateNotifyInfo(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<NotifyInfo> CreateNotifyInfo(flatbuffers::FlatBufferBuilder &_fbb, const NotifyInfoT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const NotifyInfoT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _node = _o->node.empty() ? 0 : _fbb.CreateString(_o->node);
  auto _timestamp = _o->timestamp;
  auto _notifyType = _o->notifyType;
  return comm::datalayer::CreateNotifyInfo(
      _fbb,
      _node,
      _timestamp,
      _notifyType);
}

inline const comm::datalayer::NotifyInfo *GetNotifyInfo(const void *buf) {
  return flatbuffers::GetRoot<comm::datalayer::NotifyInfo>(buf);
}

inline const comm::datalayer::NotifyInfo *GetSizePrefixedNotifyInfo(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<comm::datalayer::NotifyInfo>(buf);
}

inline NotifyInfo *GetMutableNotifyInfo(void *buf) {
  return flatbuffers::GetMutableRoot<NotifyInfo>(buf);
}

inline bool VerifyNotifyInfoBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::NotifyInfo>(nullptr);
}

inline bool VerifySizePrefixedNotifyInfoBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::NotifyInfo>(nullptr);
}

inline void FinishNotifyInfoBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<comm::datalayer::NotifyInfo> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedNotifyInfoBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<comm::datalayer::NotifyInfo> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::NotifyInfoT> UnPackNotifyInfo(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::NotifyInfoT>(GetNotifyInfo(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::NotifyInfoT> UnPackSizePrefixedNotifyInfo(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::NotifyInfoT>(GetSizePrefixedNotifyInfo(buf)->UnPack(res));
}

}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_NOTIFYINFO_COMM_DATALAYER_H_
