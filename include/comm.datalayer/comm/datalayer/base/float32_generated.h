// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_FLOAT32_COMM_DATALAYER_H_
#define FLATBUFFERS_GENERATED_FLOAT32_COMM_DATALAYER_H_

#include "flatbuffers/flatbuffers.h"

namespace comm {
namespace datalayer {

struct Float32;
struct Float32Builder;
struct Float32T;

struct Float32T : public flatbuffers::NativeTable {
  typedef Float32 TableType;
  float value = 0.0f;
};

struct Float32 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef Float32T NativeTableType;
  typedef Float32Builder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VALUE = 4
  };
  float value() const {
    return GetField<float>(VT_VALUE, 0.0f);
  }
  bool mutate_value(float _value) {
    return SetField<float>(VT_VALUE, _value, 0.0f);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<float>(verifier, VT_VALUE) &&
           verifier.EndTable();
  }
  Float32T *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(Float32T *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Float32> Pack(flatbuffers::FlatBufferBuilder &_fbb, const Float32T* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct Float32Builder {
  typedef Float32 Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_value(float value) {
    fbb_.AddElement<float>(Float32::VT_VALUE, value, 0.0f);
  }
  explicit Float32Builder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Float32> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Float32>(end);
    return o;
  }
};

inline flatbuffers::Offset<Float32> CreateFloat32(
    flatbuffers::FlatBufferBuilder &_fbb,
    float value = 0.0f) {
  Float32Builder builder_(_fbb);
  builder_.add_value(value);
  return builder_.Finish();
}

flatbuffers::Offset<Float32> CreateFloat32(flatbuffers::FlatBufferBuilder &_fbb, const Float32T *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline Float32T *Float32::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<Float32T>(new Float32T());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void Float32::UnPackTo(Float32T *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = value(); _o->value = _e; }
}

inline flatbuffers::Offset<Float32> Float32::Pack(flatbuffers::FlatBufferBuilder &_fbb, const Float32T* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateFloat32(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Float32> CreateFloat32(flatbuffers::FlatBufferBuilder &_fbb, const Float32T *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const Float32T* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _value = _o->value;
  return comm::datalayer::CreateFloat32(
      _fbb,
      _value);
}

inline const comm::datalayer::Float32 *GetFloat32(const void *buf) {
  return flatbuffers::GetRoot<comm::datalayer::Float32>(buf);
}

inline const comm::datalayer::Float32 *GetSizePrefixedFloat32(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<comm::datalayer::Float32>(buf);
}

inline Float32 *GetMutableFloat32(void *buf) {
  return flatbuffers::GetMutableRoot<Float32>(buf);
}

inline bool VerifyFloat32Buffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::Float32>(nullptr);
}

inline bool VerifySizePrefixedFloat32Buffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::Float32>(nullptr);
}

inline void FinishFloat32Buffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<comm::datalayer::Float32> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedFloat32Buffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<comm::datalayer::Float32> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::Float32T> UnPackFloat32(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::Float32T>(GetFloat32(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::Float32T> UnPackSizePrefixedFloat32(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::Float32T>(GetSizePrefixedFloat32(buf)->UnPack(res));
}

}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_FLOAT32_COMM_DATALAYER_H_
