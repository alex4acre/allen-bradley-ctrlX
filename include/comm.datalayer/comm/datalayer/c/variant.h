#pragma once
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef void *DLR_VARIANT;
  typedef enum DLR_RESULT {
    DL_OK = 0,                                 //! function call succeeded
    DL_FAILED = 0x80000001,                    //! only allowed for temporary use - define matching error code

    //! application
    DL_INVALID_ADDRESS = 0x80010001,           //! address not found, address invalid (browse of this node not possible, write -> address not valid)
    DL_UNSUPPORTED = 0x80010002,               //! function not implemented
    DL_OUT_OF_MEMORY = 0x80010003,             //! out of memory or resources (RAM, sockets, handles, disk space ...).
    DL_LIMIT_MIN = 0x80010004,                 //! the minimum of a limitation is exceeded.
    DL_LIMIT_MAX = 0x80010005,                 //! the maximum of a limitation is exceeded.
    DL_TYPE_MISMATCH = 0x80010006,             //! wrong flatbuffer type, wrong data type
    DL_SIZE_MISMATCH = 0x80010007,             //! size mismatch, present size doesn't match requested size.
    DL_INVALID_FLOATINGPOINT = 0x80010009,     //! invalid floating point number.
    DL_INVALID_HANDLE = 0x8001000A,            //! invalid handle argument or NULL pointer argument.
    DL_INVALID_OPERATION_MODE = 0x8001000B,    //! not accessible due to invalid operation mode (write not possible)
    DL_INVALID_CONFIGURATION = 0x8001000C,     //! mismatch of this value with other configured values
    DL_INVALID_VALUE = 0x8001000D,             //! invalid value
    DL_SUBMODULE_FAILURE = 0x8001000E,         //! error in submodule
    DL_TIMEOUT = 0x8001000F,                   //! request timeout
    DL_ALREADY_EXISTS = 0x80010010,            //! create: resource already exists
    DL_CREATION_FAILED = 0x80010011,           //! error during creation
    DL_VERSION_MISMATCH = 0x80010012,          //! version conflict
    DL_DEPRECATED = 0x80010013,                //! deprecated - function not longer supported
    DL_PERMISSION_DENIED = 0x80010014,         //! request declined due to missing permission rights
    DL_NOT_INITIALIZED = 0x80010015,           //! object not initialized yet

    //! communication
    DL_COMM_PROTOCOL_ERROR = 0x80020001,       //! internal protocol error
    DL_COMM_INVALID_HEADER = 0x80020002,       //! internal header mismatch

    //! client
    DL_CLIENT_NOT_CONNECTED = 0x80030001,      //! client not connected

    //! provider
    //! broker

    //! realtime related error codes
    DL_RT_NOTOPEN = 0x80060001,                //! not open
    DL_RT_INVALIDOBJECT = 0x80060002,          //! invalid object 
    DL_RT_WRONGREVISON = 0x80060003,           //! wrong memory revision
    DL_RT_NOVALIDDATA = 0x80060004,            //! no valid data 
    DL_RT_MEMORYLOCKED = 0x80060005,           //! memory already locked
    DL_RT_INVALIDMEMORYMAP = 0x80060006,       //! invalid memory map
    DL_RT_INVALID_RETAIN = 0x80060007,         //! invalid memory map
    DL_RT_INTERNAL_ERROR = 0x80060008,         //! internal RT error

    DL_SEC_NOTOKEN = 0x80070001,               //! no token found
    DL_SEC_INVALIDSESSION = 0x80070002,        //! token not valid (session not found)
    DL_SEC_INVALIDTOKENCONTENT = 0x80070003,   //! token has wrong content
    DL_SEC_UNAUTHORIZED = 0x80070004,          //! unauthorized

  }DLR_RESULT;

  typedef enum DLR_VARIANT_TYPE {
    DLR_VARIANT_TYPE_UNKNOWN,            //! unknown data type
    DLR_VARIANT_TYPE_BOOL8,              //! bool 8 bit
    DLR_VARIANT_TYPE_INT8,               //! signed int 8 bit
    DLR_VARIANT_TYPE_UINT8,              //! unsigned int 8 bit
    DLR_VARIANT_TYPE_INT16,              //! signed int 16 bit
    DLR_VARIANT_TYPE_UINT16,             //! unsigned int 16 bit
    DLR_VARIANT_TYPE_INT32,              //! signed int 32 bit
    DLR_VARIANT_TYPE_UINT32,             //! unsigned int 32 bit
    DLR_VARIANT_TYPE_INT64,              //! signed int 64 bit
    DLR_VARIANT_TYPE_UINT64,             //! unsigned int 64 bit
    DLR_VARIANT_TYPE_FLOAT32,            //! float 32 bit
    DLR_VARIANT_TYPE_FLOAT64,            //! float 64 bit
    DLR_VARIANT_TYPE_STRING,             //! string (UTF-8)

    DLR_VARIANT_TYPE_ARRAY_OF_BOOL8,     //! array of bool 8 bit
    DLR_VARIANT_TYPE_ARRAY_OF_INT8,      //! array of signed int 8 bit
    DLR_VARIANT_TYPE_ARRAY_OF_UINT8,     //! array of unsigned int 8 bit
    DLR_VARIANT_TYPE_ARRAY_OF_INT16,     //! array of signed int 16 bit
    DLR_VARIANT_TYPE_ARRAY_OF_UINT16,    //! array of unsigned int 16 bit
    DLR_VARIANT_TYPE_ARRAY_OF_INT32,     //! array of signed int 32 bit
    DLR_VARIANT_TYPE_ARRAY_OF_UINT32,    //! array of unsigned int 32 bit
    DLR_VARIANT_TYPE_ARRAY_OF_INT64,     //! array of signed int 64 bit
    DLR_VARIANT_TYPE_ARRAY_OF_UINT64,    //! array of unsigned int 64 bit
    DLR_VARIANT_TYPE_ARRAY_OF_FLOAT32,   //! array of float 32 bit
    DLR_VARIANT_TYPE_ARRAY_OF_FLOAT64,   //! array of float 64 bit
    DLR_VARIANT_TYPE_ARRAY_OF_STRING,    //! array of string (UTF-8)

    DLR_VARIANT_TYPE_RAW,                //! raw bytes
    DLR_VARIANT_TYPE_FLATBUFFERS,        //! bytes as a complex data type encoded as a flatbuffer
  }DLR_VARIANT_TYPE;


  //! Creates a variant
  DLR_VARIANT DLR_variantCreate();

  //! Deletes a variant
  //! @param[in] variant     Variant to delete
  void DLR_variantDelete(DLR_VARIANT variant);

  //! Set a bool value
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetBOOL8(DLR_VARIANT variant,   const bool value);

  //! Set a int8 value
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetINT8(DLR_VARIANT variant,    const int8_t value);

  //! Set a uint8 value
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetUINT8(DLR_VARIANT variant,   const uint8_t value);

  //! Set a int16 value
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetINT16(DLR_VARIANT variant,   const int16_t value);

  //! Set a uint16 value
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetUINT16(DLR_VARIANT variant,  const uint16_t value);

  //! Set a int32 value
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetINT32(DLR_VARIANT variant,   const int32_t value);

  //! Set a uint32 value
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetUINT32(DLR_VARIANT variant,  const uint32_t value);

  //! Set a int64 value
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetINT64(DLR_VARIANT variant,   const int64_t value);

  //! Set a uint64 value
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetUINT64(DLR_VARIANT variant,  const uint64_t value);

  //! Set a float value
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetFLOAT32(DLR_VARIANT variant, const float value);

  //! Set a double value
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetFLOAT64(DLR_VARIANT variant, const double value);

  //! Set a string
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Value to set
  //! @return Status of set value
  DLR_RESULT DLR_variantSetSTRING(DLR_VARIANT variant,  const char* value);

  //! Set an array of bool
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_BOOL8(DLR_VARIANT variant,   const bool* value, const size_t count);

  //! Set an array of int8
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_INT8(DLR_VARIANT variant,    const int8_t* value, const size_t count);

  //! Set an array of uint8
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_UINT8(DLR_VARIANT variant,   const uint8_t* value, const size_t count);

  //! Set an array of int16
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_INT16(DLR_VARIANT variant,   const int16_t* value, const size_t count);

  //! Set an array of uint16
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_UINT16(DLR_VARIANT variant,  const uint16_t* value, const size_t count);

  //! Set an array of int32
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_INT32(DLR_VARIANT variant,   const int32_t* value, const size_t count);

  //! Set an array of uint32
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_UINT32(DLR_VARIANT variant,  const uint32_t* value, const size_t count);

  //! Set an array of int64
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_INT64(DLR_VARIANT variant,   const int64_t* value, const size_t count);

  //! Set an array of uint64
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_UINT64(DLR_VARIANT variant,  const uint64_t* value, const size_t count);

  //! Set an array of float
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_FLOAT32(DLR_VARIANT variant, const float* value, const size_t count);

  //! Set an array of double
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_FLOAT64(DLR_VARIANT variant, const double* value, const size_t count);

  //! Set an array of strings
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Array of Values to set
  //! @param[in] count       Count of array values
  //! @return Status of set value
  DLR_RESULT DLR_variantSetARRAY_OF_STRING(DLR_VARIANT variant,  const char** value, const size_t count);

  //! Set an flatbuffers
  //! @param[in] variant     Reference to variant
  //! @param[in] value       Pointer to flatbuffers
  //! @param[in] count       Size of flatbuffers
  //! @return Status of set value
  DLR_RESULT DLR_variantSetFlatbuffers(DLR_VARIANT variant, const int8_t* value, const size_t size);

  //! Returns the value of the variant as a bool (auto convert if possible) otherwise 0
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  bool     DLR_variantGetBOOL8(DLR_VARIANT variant);

  //! Returns the value of the variant as a int8 (auto convert if possible) otherwise 0
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  int8_t   DLR_variantGetINT8(DLR_VARIANT variant);

  //! Returns the value of the variant as a uint8 (auto convert if possible) otherwise 0
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  uint8_t  DLR_variantGetUINT8(DLR_VARIANT variant);

  //! Returns the value of the variant as a int16 (auto convert if possible) otherwise 0
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  int16_t  DLR_variantGetINT16(DLR_VARIANT variant);

  //! Returns the value of the variant as a uint16 (auto convert if possible) otherwise 0
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  uint16_t DLR_variantGetUINT16(DLR_VARIANT variant);

  //! Returns the value of the variant as a int32 (auto convert if possible) otherwise 0
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  int32_t  DLR_variantGetINT32(DLR_VARIANT variant);

  //! Returns the value of the variant as a uint32 (auto convert if possible) otherwise 0
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  uint32_t DLR_variantGetUINT32(DLR_VARIANT variant);

  //! Returns the value of the variant as a int64 (auto convert if possible) otherwise 0
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  int64_t  DLR_variantGetINT64(DLR_VARIANT variant);

  //! Returns the value of the variant as a uint64 (auto convert if possible) otherwise 0
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  uint64_t DLR_variantGetUINT64(DLR_VARIANT variant);

  //! Returns the value of the variant as a float (auto convert if possible) otherwise 0
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  float    DLR_variantGetFLOAT32(DLR_VARIANT variant);

  //! Returns the value of the variant as a double (auto convert if possible) otherwise 0
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  double   DLR_variantGetFLOAT64(DLR_VARIANT variant);

  //! Returns the value of the variant as a string otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const char* DLR_variantGetSTRING(DLR_VARIANT variant);

  //! Returns the array of bool8 if the type is a array of bool otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const bool*      DLR_variantGetArrayOfBOOL8(DLR_VARIANT variant);

  //! Returns the array of int8 if the type is a array of int8 otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const int8_t*    DLR_variantGetArrayOfINT8(DLR_VARIANT variant);

  //! Returns the array of uint8 if the type is a array of uint8 otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const uint8_t*   DLR_variantGetArrayOfUINT8(DLR_VARIANT variant);

  //! Returns the array of int16 if the type is a array of int16 otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const int16_t*   DLR_variantGetArrayOfINT16(DLR_VARIANT variant);

  //! Returns the array of uint16 if the type is a array of uint16 otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const uint16_t*  DLR_variantGetArrayOfUINT16(DLR_VARIANT variant);

  //! Returns the array of int32 if the type is a array of int32 otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const int32_t*   DLR_variantGetArrayOfINT32(DLR_VARIANT variant);

  //! Returns the array of uint32 if the type is a array of uint32 otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const uint32_t*  DLR_variantGetArrayOfUINT32(DLR_VARIANT variant);

  //! Returns the array of int64 if the type is a array of int64 otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const int64_t*   DLR_variantGetArrayOfINT64(DLR_VARIANT variant);

  //! Returns the array of uint64 if the type is a array of uint64 otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const uint64_t*  DLR_variantGetArrayOfUINT64(DLR_VARIANT variant);

  //! Returns the array of float if the type is a array of float otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const float*     DLR_variantGetArrayOfFLOAT32(DLR_VARIANT variant);

  //! Returns the array of double if the type is a array of double otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const double*    DLR_variantGetArrayOfFLOAT64(DLR_VARIANT variant);

  //! Returns the array of string if the type is a array of string otherwise null
  //! @param[in] variant     Reference to variant
  //! @return Value of the variant
  const char**     DLR_variantGetArrayOfSTRING(DLR_VARIANT variant);

  //! Returns the type of the variant
  //! @param[in] variant     Reference to variant
  //! @return Type of the variant
  DLR_VARIANT_TYPE DLR_variantGetType(DLR_VARIANT variant);

  //! Returns the pointer to the data of the variant
  //! @param[in] variant     Reference to variant
  //! @return Pointer to the data of the variant
  uint8_t* DLR_variantGetData(DLR_VARIANT variant);

  //! Returns the size in bytes of the variant
  //! @param[in] variant     Reference to variant
  //! @return Size in bytes of the variant
  size_t DLR_variantGetSize(DLR_VARIANT variant);

  //! Returns the count of elements in the variant (scalar data types = 1, array = count of elements in array)
  //! @param[in] variant     Reference to variant
  //! @return Size in bytes of the variant
  size_t DLR_variantGetCount(DLR_VARIANT variant);

  //! Checks whether the variant can be converted to another type
  //! @param[in] variant     Reference to variant
  //! @param[in] type        Destination type
  //! @return Result whether the conversion is possible
  DLR_RESULT DLR_variantCheckConvert(DLR_VARIANT variant, DLR_VARIANT_TYPE type);

  //! Copies the content of a variant to another variant
  //! @param[in] dest        Destination variant
  //! @param[in] src         Source variant
  //! @return Result of copy
  DLR_RESULT DLR_variantCopy(DLR_VARIANT dest, DLR_VARIANT src);

#ifdef __cplusplus
}
#endif
