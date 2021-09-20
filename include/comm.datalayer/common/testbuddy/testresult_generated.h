// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TESTRESULT_COMMON_TESTBUDDY_H_
#define FLATBUFFERS_GENERATED_TESTRESULT_COMMON_TESTBUDDY_H_

#include "flatbuffers/flatbuffers.h"

namespace common {
namespace testbuddy {

struct Log;
struct LogBuilder;
struct LogT;

struct Data;
struct DataBuilder;
struct DataT;

struct TestResult;
struct TestResultBuilder;
struct TestResultT;

enum LogType : int8_t {
  LogType_Log = 0,
  LogType_Warning = 1,
  LogType_Error = 2,
  LogType_MIN = LogType_Log,
  LogType_MAX = LogType_Error
};

inline const LogType (&EnumValuesLogType())[3] {
  static const LogType values[] = {
    LogType_Log,
    LogType_Warning,
    LogType_Error
  };
  return values;
}

inline const char * const *EnumNamesLogType() {
  static const char * const names[4] = {
    "Log",
    "Warning",
    "Error",
    nullptr
  };
  return names;
}

inline const char *EnumNameLogType(LogType e) {
  if (flatbuffers::IsOutRange(e, LogType_Log, LogType_Error)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesLogType()[index];
}

struct LogT : public flatbuffers::NativeTable {
  typedef Log TableType;
  uint32_t index = 0;
  common::testbuddy::LogType type = common::testbuddy::LogType_Log;
  std::string log{};
};

struct Log FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef LogT NativeTableType;
  typedef LogBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_INDEX = 4,
    VT_TYPE = 6,
    VT_LOG = 8
  };
  uint32_t index() const {
    return GetField<uint32_t>(VT_INDEX, 0);
  }
  bool mutate_index(uint32_t _index) {
    return SetField<uint32_t>(VT_INDEX, _index, 0);
  }
  common::testbuddy::LogType type() const {
    return static_cast<common::testbuddy::LogType>(GetField<int8_t>(VT_TYPE, 0));
  }
  bool mutate_type(common::testbuddy::LogType _type) {
    return SetField<int8_t>(VT_TYPE, static_cast<int8_t>(_type), 0);
  }
  const flatbuffers::String *log() const {
    return GetPointer<const flatbuffers::String *>(VT_LOG);
  }
  flatbuffers::String *mutable_log() {
    return GetPointer<flatbuffers::String *>(VT_LOG);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_INDEX) &&
           VerifyField<int8_t>(verifier, VT_TYPE) &&
           VerifyOffset(verifier, VT_LOG) &&
           verifier.VerifyString(log()) &&
           verifier.EndTable();
  }
  LogT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(LogT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Log> Pack(flatbuffers::FlatBufferBuilder &_fbb, const LogT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct LogBuilder {
  typedef Log Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_index(uint32_t index) {
    fbb_.AddElement<uint32_t>(Log::VT_INDEX, index, 0);
  }
  void add_type(common::testbuddy::LogType type) {
    fbb_.AddElement<int8_t>(Log::VT_TYPE, static_cast<int8_t>(type), 0);
  }
  void add_log(flatbuffers::Offset<flatbuffers::String> log) {
    fbb_.AddOffset(Log::VT_LOG, log);
  }
  explicit LogBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Log> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Log>(end);
    return o;
  }
};

inline flatbuffers::Offset<Log> CreateLog(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t index = 0,
    common::testbuddy::LogType type = common::testbuddy::LogType_Log,
    flatbuffers::Offset<flatbuffers::String> log = 0) {
  LogBuilder builder_(_fbb);
  builder_.add_log(log);
  builder_.add_index(index);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<Log> CreateLogDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t index = 0,
    common::testbuddy::LogType type = common::testbuddy::LogType_Log,
    const char *log = nullptr) {
  auto log__ = log ? _fbb.CreateString(log) : 0;
  return common::testbuddy::CreateLog(
      _fbb,
      index,
      type,
      log__);
}

flatbuffers::Offset<Log> CreateLog(flatbuffers::FlatBufferBuilder &_fbb, const LogT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct DataT : public flatbuffers::NativeTable {
  typedef Data TableType;
  std::string name{};
  double value = 0.0;
};

struct Data FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef DataT NativeTableType;
  typedef DataBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_VALUE = 6
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  flatbuffers::String *mutable_name() {
    return GetPointer<flatbuffers::String *>(VT_NAME);
  }
  bool KeyCompareLessThan(const Data *o) const {
    return *name() < *o->name();
  }
  int KeyCompareWithValue(const char *val) const {
    return strcmp(name()->c_str(), val);
  }
  double value() const {
    return GetField<double>(VT_VALUE, 0.0);
  }
  bool mutate_value(double _value) {
    return SetField<double>(VT_VALUE, _value, 0.0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<double>(verifier, VT_VALUE) &&
           verifier.EndTable();
  }
  DataT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(DataT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Data> Pack(flatbuffers::FlatBufferBuilder &_fbb, const DataT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct DataBuilder {
  typedef Data Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Data::VT_NAME, name);
  }
  void add_value(double value) {
    fbb_.AddElement<double>(Data::VT_VALUE, value, 0.0);
  }
  explicit DataBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Data> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Data>(end);
    fbb_.Required(o, Data::VT_NAME);
    return o;
  }
};

inline flatbuffers::Offset<Data> CreateData(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    double value = 0.0) {
  DataBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<Data> CreateDataDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    double value = 0.0) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return common::testbuddy::CreateData(
      _fbb,
      name__,
      value);
}

flatbuffers::Offset<Data> CreateData(flatbuffers::FlatBufferBuilder &_fbb, const DataT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct TestResultT : public flatbuffers::NativeTable {
  typedef TestResult TableType;
  int32_t numWarnings = 0;
  int32_t numErrors = 0;
  std::vector<std::unique_ptr<common::testbuddy::LogT>> log{};
  std::vector<std::unique_ptr<common::testbuddy::DataT>> data{};
};

struct TestResult FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef TestResultT NativeTableType;
  typedef TestResultBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NUMWARNINGS = 4,
    VT_NUMERRORS = 6,
    VT_LOG = 8,
    VT_DATA = 10
  };
  int32_t numWarnings() const {
    return GetField<int32_t>(VT_NUMWARNINGS, 0);
  }
  bool mutate_numWarnings(int32_t _numWarnings) {
    return SetField<int32_t>(VT_NUMWARNINGS, _numWarnings, 0);
  }
  int32_t numErrors() const {
    return GetField<int32_t>(VT_NUMERRORS, 0);
  }
  bool mutate_numErrors(int32_t _numErrors) {
    return SetField<int32_t>(VT_NUMERRORS, _numErrors, 0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Log>> *log() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Log>> *>(VT_LOG);
  }
  flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Log>> *mutable_log() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Log>> *>(VT_LOG);
  }
  const flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Data>> *data() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Data>> *>(VT_DATA);
  }
  flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Data>> *mutable_data() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Data>> *>(VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_NUMWARNINGS) &&
           VerifyField<int32_t>(verifier, VT_NUMERRORS) &&
           VerifyOffset(verifier, VT_LOG) &&
           verifier.VerifyVector(log()) &&
           verifier.VerifyVectorOfTables(log()) &&
           VerifyOffset(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) &&
           verifier.VerifyVectorOfTables(data()) &&
           verifier.EndTable();
  }
  TestResultT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(TestResultT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<TestResult> Pack(flatbuffers::FlatBufferBuilder &_fbb, const TestResultT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct TestResultBuilder {
  typedef TestResult Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_numWarnings(int32_t numWarnings) {
    fbb_.AddElement<int32_t>(TestResult::VT_NUMWARNINGS, numWarnings, 0);
  }
  void add_numErrors(int32_t numErrors) {
    fbb_.AddElement<int32_t>(TestResult::VT_NUMERRORS, numErrors, 0);
  }
  void add_log(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Log>>> log) {
    fbb_.AddOffset(TestResult::VT_LOG, log);
  }
  void add_data(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Data>>> data) {
    fbb_.AddOffset(TestResult::VT_DATA, data);
  }
  explicit TestResultBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<TestResult> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<TestResult>(end);
    return o;
  }
};

inline flatbuffers::Offset<TestResult> CreateTestResult(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t numWarnings = 0,
    int32_t numErrors = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Log>>> log = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<common::testbuddy::Data>>> data = 0) {
  TestResultBuilder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_log(log);
  builder_.add_numErrors(numErrors);
  builder_.add_numWarnings(numWarnings);
  return builder_.Finish();
}

inline flatbuffers::Offset<TestResult> CreateTestResultDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t numWarnings = 0,
    int32_t numErrors = 0,
    const std::vector<flatbuffers::Offset<common::testbuddy::Log>> *log = nullptr,
    std::vector<flatbuffers::Offset<common::testbuddy::Data>> *data = nullptr) {
  auto log__ = log ? _fbb.CreateVector<flatbuffers::Offset<common::testbuddy::Log>>(*log) : 0;
  auto data__ = data ? _fbb.CreateVectorOfSortedTables<common::testbuddy::Data>(data) : 0;
  return common::testbuddy::CreateTestResult(
      _fbb,
      numWarnings,
      numErrors,
      log__,
      data__);
}

flatbuffers::Offset<TestResult> CreateTestResult(flatbuffers::FlatBufferBuilder &_fbb, const TestResultT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline LogT *Log::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<LogT>(new LogT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void Log::UnPackTo(LogT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = index(); _o->index = _e; }
  { auto _e = type(); _o->type = _e; }
  { auto _e = log(); if (_e) _o->log = _e->str(); }
}

inline flatbuffers::Offset<Log> Log::Pack(flatbuffers::FlatBufferBuilder &_fbb, const LogT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateLog(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Log> CreateLog(flatbuffers::FlatBufferBuilder &_fbb, const LogT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const LogT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _index = _o->index;
  auto _type = _o->type;
  auto _log = _o->log.empty() ? 0 : _fbb.CreateString(_o->log);
  return common::testbuddy::CreateLog(
      _fbb,
      _index,
      _type,
      _log);
}

inline DataT *Data::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<DataT>(new DataT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void Data::UnPackTo(DataT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = name(); if (_e) _o->name = _e->str(); }
  { auto _e = value(); _o->value = _e; }
}

inline flatbuffers::Offset<Data> Data::Pack(flatbuffers::FlatBufferBuilder &_fbb, const DataT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateData(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Data> CreateData(flatbuffers::FlatBufferBuilder &_fbb, const DataT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const DataT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _name = _fbb.CreateString(_o->name);
  auto _value = _o->value;
  return common::testbuddy::CreateData(
      _fbb,
      _name,
      _value);
}

inline TestResultT *TestResult::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<TestResultT>(new TestResultT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void TestResult::UnPackTo(TestResultT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = numWarnings(); _o->numWarnings = _e; }
  { auto _e = numErrors(); _o->numErrors = _e; }
  { auto _e = log(); if (_e) { _o->log.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->log[_i] = std::unique_ptr<common::testbuddy::LogT>(_e->Get(_i)->UnPack(_resolver)); } } }
  { auto _e = data(); if (_e) { _o->data.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->data[_i] = std::unique_ptr<common::testbuddy::DataT>(_e->Get(_i)->UnPack(_resolver)); } } }
}

inline flatbuffers::Offset<TestResult> TestResult::Pack(flatbuffers::FlatBufferBuilder &_fbb, const TestResultT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateTestResult(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<TestResult> CreateTestResult(flatbuffers::FlatBufferBuilder &_fbb, const TestResultT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const TestResultT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _numWarnings = _o->numWarnings;
  auto _numErrors = _o->numErrors;
  auto _log = _o->log.size() ? _fbb.CreateVector<flatbuffers::Offset<common::testbuddy::Log>> (_o->log.size(), [](size_t i, _VectorArgs *__va) { return CreateLog(*__va->__fbb, __va->__o->log[i].get(), __va->__rehasher); }, &_va ) : 0;
  auto _data = _o->data.size() ? _fbb.CreateVector<flatbuffers::Offset<common::testbuddy::Data>> (_o->data.size(), [](size_t i, _VectorArgs *__va) { return CreateData(*__va->__fbb, __va->__o->data[i].get(), __va->__rehasher); }, &_va ) : 0;
  return common::testbuddy::CreateTestResult(
      _fbb,
      _numWarnings,
      _numErrors,
      _log,
      _data);
}

inline const common::testbuddy::TestResult *GetTestResult(const void *buf) {
  return flatbuffers::GetRoot<common::testbuddy::TestResult>(buf);
}

inline const common::testbuddy::TestResult *GetSizePrefixedTestResult(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<common::testbuddy::TestResult>(buf);
}

inline TestResult *GetMutableTestResult(void *buf) {
  return flatbuffers::GetMutableRoot<TestResult>(buf);
}

inline bool VerifyTestResultBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<common::testbuddy::TestResult>(nullptr);
}

inline bool VerifySizePrefixedTestResultBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<common::testbuddy::TestResult>(nullptr);
}

inline void FinishTestResultBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<common::testbuddy::TestResult> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedTestResultBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<common::testbuddy::TestResult> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<common::testbuddy::TestResultT> UnPackTestResult(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<common::testbuddy::TestResultT>(GetTestResult(buf)->UnPack(res));
}

inline std::unique_ptr<common::testbuddy::TestResultT> UnPackSizePrefixedTestResult(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<common::testbuddy::TestResultT>(GetSizePrefixedTestResult(buf)->UnPack(res));
}

}  // namespace testbuddy
}  // namespace common

#endif  // FLATBUFFERS_GENERATED_TESTRESULT_COMMON_TESTBUDDY_H_
