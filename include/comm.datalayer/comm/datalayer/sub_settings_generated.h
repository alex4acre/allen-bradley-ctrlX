// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SUBSETTINGS_COMM_DATALAYER_H_
#define FLATBUFFERS_GENERATED_SUBSETTINGS_COMM_DATALAYER_H_

#include "flatbuffers/flatbuffers.h"

namespace comm {
namespace datalayer {

struct SubscriptionSettings;
struct SubscriptionSettingsBuilder;
struct SubscriptionSettingsT;

struct SubscriptionSettingsT : public flatbuffers::NativeTable {
  typedef SubscriptionSettings TableType;
  uint32_t minimumPublishInterval = 100;
  uint64_t minimumSampleInterval = 100000ULL;
  uint32_t maximumBufferSize = 50;
  uint32_t minimumErrorInterval = 10000;
};

struct SubscriptionSettings FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef SubscriptionSettingsT NativeTableType;
  typedef SubscriptionSettingsBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_MINIMUMPUBLISHINTERVAL = 4,
    VT_MINIMUMSAMPLEINTERVAL = 6,
    VT_MAXIMUMBUFFERSIZE = 8,
    VT_MINIMUMERRORINTERVAL = 10
  };
  uint32_t minimumPublishInterval() const {
    return GetField<uint32_t>(VT_MINIMUMPUBLISHINTERVAL, 100);
  }
  bool mutate_minimumPublishInterval(uint32_t _minimumPublishInterval) {
    return SetField<uint32_t>(VT_MINIMUMPUBLISHINTERVAL, _minimumPublishInterval, 100);
  }
  uint64_t minimumSampleInterval() const {
    return GetField<uint64_t>(VT_MINIMUMSAMPLEINTERVAL, 100000ULL);
  }
  bool mutate_minimumSampleInterval(uint64_t _minimumSampleInterval) {
    return SetField<uint64_t>(VT_MINIMUMSAMPLEINTERVAL, _minimumSampleInterval, 100000ULL);
  }
  uint32_t maximumBufferSize() const {
    return GetField<uint32_t>(VT_MAXIMUMBUFFERSIZE, 50);
  }
  bool mutate_maximumBufferSize(uint32_t _maximumBufferSize) {
    return SetField<uint32_t>(VT_MAXIMUMBUFFERSIZE, _maximumBufferSize, 50);
  }
  uint32_t minimumErrorInterval() const {
    return GetField<uint32_t>(VT_MINIMUMERRORINTERVAL, 10000);
  }
  bool mutate_minimumErrorInterval(uint32_t _minimumErrorInterval) {
    return SetField<uint32_t>(VT_MINIMUMERRORINTERVAL, _minimumErrorInterval, 10000);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_MINIMUMPUBLISHINTERVAL) &&
           VerifyField<uint64_t>(verifier, VT_MINIMUMSAMPLEINTERVAL) &&
           VerifyField<uint32_t>(verifier, VT_MAXIMUMBUFFERSIZE) &&
           VerifyField<uint32_t>(verifier, VT_MINIMUMERRORINTERVAL) &&
           verifier.EndTable();
  }
  SubscriptionSettingsT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(SubscriptionSettingsT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<SubscriptionSettings> Pack(flatbuffers::FlatBufferBuilder &_fbb, const SubscriptionSettingsT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct SubscriptionSettingsBuilder {
  typedef SubscriptionSettings Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_minimumPublishInterval(uint32_t minimumPublishInterval) {
    fbb_.AddElement<uint32_t>(SubscriptionSettings::VT_MINIMUMPUBLISHINTERVAL, minimumPublishInterval, 100);
  }
  void add_minimumSampleInterval(uint64_t minimumSampleInterval) {
    fbb_.AddElement<uint64_t>(SubscriptionSettings::VT_MINIMUMSAMPLEINTERVAL, minimumSampleInterval, 100000ULL);
  }
  void add_maximumBufferSize(uint32_t maximumBufferSize) {
    fbb_.AddElement<uint32_t>(SubscriptionSettings::VT_MAXIMUMBUFFERSIZE, maximumBufferSize, 50);
  }
  void add_minimumErrorInterval(uint32_t minimumErrorInterval) {
    fbb_.AddElement<uint32_t>(SubscriptionSettings::VT_MINIMUMERRORINTERVAL, minimumErrorInterval, 10000);
  }
  explicit SubscriptionSettingsBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<SubscriptionSettings> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<SubscriptionSettings>(end);
    return o;
  }
};

inline flatbuffers::Offset<SubscriptionSettings> CreateSubscriptionSettings(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t minimumPublishInterval = 100,
    uint64_t minimumSampleInterval = 100000ULL,
    uint32_t maximumBufferSize = 50,
    uint32_t minimumErrorInterval = 10000) {
  SubscriptionSettingsBuilder builder_(_fbb);
  builder_.add_minimumSampleInterval(minimumSampleInterval);
  builder_.add_minimumErrorInterval(minimumErrorInterval);
  builder_.add_maximumBufferSize(maximumBufferSize);
  builder_.add_minimumPublishInterval(minimumPublishInterval);
  return builder_.Finish();
}

flatbuffers::Offset<SubscriptionSettings> CreateSubscriptionSettings(flatbuffers::FlatBufferBuilder &_fbb, const SubscriptionSettingsT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline SubscriptionSettingsT *SubscriptionSettings::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<SubscriptionSettingsT>(new SubscriptionSettingsT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void SubscriptionSettings::UnPackTo(SubscriptionSettingsT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = minimumPublishInterval(); _o->minimumPublishInterval = _e; }
  { auto _e = minimumSampleInterval(); _o->minimumSampleInterval = _e; }
  { auto _e = maximumBufferSize(); _o->maximumBufferSize = _e; }
  { auto _e = minimumErrorInterval(); _o->minimumErrorInterval = _e; }
}

inline flatbuffers::Offset<SubscriptionSettings> SubscriptionSettings::Pack(flatbuffers::FlatBufferBuilder &_fbb, const SubscriptionSettingsT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateSubscriptionSettings(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<SubscriptionSettings> CreateSubscriptionSettings(flatbuffers::FlatBufferBuilder &_fbb, const SubscriptionSettingsT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const SubscriptionSettingsT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _minimumPublishInterval = _o->minimumPublishInterval;
  auto _minimumSampleInterval = _o->minimumSampleInterval;
  auto _maximumBufferSize = _o->maximumBufferSize;
  auto _minimumErrorInterval = _o->minimumErrorInterval;
  return comm::datalayer::CreateSubscriptionSettings(
      _fbb,
      _minimumPublishInterval,
      _minimumSampleInterval,
      _maximumBufferSize,
      _minimumErrorInterval);
}

inline const comm::datalayer::SubscriptionSettings *GetSubscriptionSettings(const void *buf) {
  return flatbuffers::GetRoot<comm::datalayer::SubscriptionSettings>(buf);
}

inline const comm::datalayer::SubscriptionSettings *GetSizePrefixedSubscriptionSettings(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<comm::datalayer::SubscriptionSettings>(buf);
}

inline SubscriptionSettings *GetMutableSubscriptionSettings(void *buf) {
  return flatbuffers::GetMutableRoot<SubscriptionSettings>(buf);
}

inline bool VerifySubscriptionSettingsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::SubscriptionSettings>(nullptr);
}

inline bool VerifySizePrefixedSubscriptionSettingsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::SubscriptionSettings>(nullptr);
}

inline void FinishSubscriptionSettingsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<comm::datalayer::SubscriptionSettings> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedSubscriptionSettingsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<comm::datalayer::SubscriptionSettings> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::SubscriptionSettingsT> UnPackSubscriptionSettings(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::SubscriptionSettingsT>(GetSubscriptionSettings(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::SubscriptionSettingsT> UnPackSizePrefixedSubscriptionSettings(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::SubscriptionSettingsT>(GetSizePrefixedSubscriptionSettings(buf)->UnPack(res));
}

}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_SUBSETTINGS_COMM_DATALAYER_H_
