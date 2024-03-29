// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ARRAYOFINT8_COMM_DATALAYER_H_
#define FLATBUFFERS_GENERATED_ARRAYOFINT8_COMM_DATALAYER_H_

#include "flatbuffers/flatbuffers.h"

namespace comm {
namespace datalayer {

struct ArrayOfInt8;
struct ArrayOfInt8Builder;
struct ArrayOfInt8T;

struct ArrayOfInt8T : public flatbuffers::NativeTable {
  typedef ArrayOfInt8 TableType;
  std::vector<int8_t> value{};
};

struct ArrayOfInt8 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ArrayOfInt8T NativeTableType;
  typedef ArrayOfInt8Builder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VALUE = 4
  };
  const flatbuffers::Vector<int8_t> *value() const {
    return GetPointer<const flatbuffers::Vector<int8_t> *>(VT_VALUE);
  }
  flatbuffers::Vector<int8_t> *mutable_value() {
    return GetPointer<flatbuffers::Vector<int8_t> *>(VT_VALUE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyVector(value()) &&
           verifier.EndTable();
  }
  ArrayOfInt8T *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(ArrayOfInt8T *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<ArrayOfInt8> Pack(flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfInt8T* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct ArrayOfInt8Builder {
  typedef ArrayOfInt8 Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_value(flatbuffers::Offset<flatbuffers::Vector<int8_t>> value) {
    fbb_.AddOffset(ArrayOfInt8::VT_VALUE, value);
  }
  explicit ArrayOfInt8Builder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<ArrayOfInt8> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ArrayOfInt8>(end);
    return o;
  }
};

inline flatbuffers::Offset<ArrayOfInt8> CreateArrayOfInt8(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<int8_t>> value = 0) {
  ArrayOfInt8Builder builder_(_fbb);
  builder_.add_value(value);
  return builder_.Finish();
}

inline flatbuffers::Offset<ArrayOfInt8> CreateArrayOfInt8Direct(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<int8_t> *value = nullptr) {
  auto value__ = value ? _fbb.CreateVector<int8_t>(*value) : 0;
  return comm::datalayer::CreateArrayOfInt8(
      _fbb,
      value__);
}

flatbuffers::Offset<ArrayOfInt8> CreateArrayOfInt8(flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfInt8T *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline ArrayOfInt8T *ArrayOfInt8::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<ArrayOfInt8T>(new ArrayOfInt8T());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void ArrayOfInt8::UnPackTo(ArrayOfInt8T *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = value(); if (_e) { _o->value.resize(_e->size()); std::copy(_e->begin(), _e->end(), _o->value.begin()); } }
}

inline flatbuffers::Offset<ArrayOfInt8> ArrayOfInt8::Pack(flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfInt8T* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateArrayOfInt8(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<ArrayOfInt8> CreateArrayOfInt8(flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfInt8T *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const ArrayOfInt8T* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _value = _o->value.size() ? _fbb.CreateVector(_o->value) : 0;
  return comm::datalayer::CreateArrayOfInt8(
      _fbb,
      _value);
}

inline const comm::datalayer::ArrayOfInt8 *GetArrayOfInt8(const void *buf) {
  return flatbuffers::GetRoot<comm::datalayer::ArrayOfInt8>(buf);
}

inline const comm::datalayer::ArrayOfInt8 *GetSizePrefixedArrayOfInt8(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<comm::datalayer::ArrayOfInt8>(buf);
}

inline ArrayOfInt8 *GetMutableArrayOfInt8(void *buf) {
  return flatbuffers::GetMutableRoot<ArrayOfInt8>(buf);
}

inline bool VerifyArrayOfInt8Buffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::ArrayOfInt8>(nullptr);
}

inline bool VerifySizePrefixedArrayOfInt8Buffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::ArrayOfInt8>(nullptr);
}

inline void FinishArrayOfInt8Buffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<comm::datalayer::ArrayOfInt8> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedArrayOfInt8Buffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<comm::datalayer::ArrayOfInt8> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::ArrayOfInt8T> UnPackArrayOfInt8(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ArrayOfInt8T>(GetArrayOfInt8(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::ArrayOfInt8T> UnPackSizePrefixedArrayOfInt8(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ArrayOfInt8T>(GetSizePrefixedArrayOfInt8(buf)->UnPack(res));
}

}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_ARRAYOFINT8_COMM_DATALAYER_H_
