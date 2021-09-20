#pragma once

#include <stdint.h>
#include <string.h>

#define DATALAYER_STATUS_MAKE_SUCCESS(fac,x) uint32_t(0x00000000 + (x) + (static_cast<uint32_t>(fac) << 16))
#define DATALAYER_STATUS_MAKE_ERROR(fac,x)   uint32_t(0x80000000 + (x) + (static_cast<uint32_t>(fac) << 16))


//! Namespace for datalayer
namespace comm {
namespace datalayer {


//! Result data type for all function calls
struct DlResult
{

  //! facicility 
  enum class Facility {
    COMMON  = 0,        // common   
    APPLICATION = 1,    // eg. Data invalid, node not available, ...
    COMMUNICATION = 2,  // ZMQ related communcation errors
    CLIENT = 3,         // internal client errors
    PROVIDER = 4,       // internal provider errors
    BROKER = 5,         // internal broker errors
    REALTIME = 6,       // datalayer realtime related errors
    SECURITY = 7        // datalayer security related errors
  };

  // additional error codes can be added if they are useable for all components
  enum Value : uint32_t
  { 
    //! common
    DL_OK = DATALAYER_STATUS_MAKE_SUCCESS(Facility::COMMON, 0),                           //! function call succeeded
    DL_OK_NO_CONTENT = DATALAYER_STATUS_MAKE_SUCCESS(Facility::COMMON, 1),                //! function call succeeded with no content
    DL_FAILED = DATALAYER_STATUS_MAKE_ERROR(Facility::COMMON, 1),                         //! only allowed for temporary use - define matching error code

    //! application
    DL_INVALID_ADDRESS = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 1),           //! address not found, address invalid (browse of this node not possible, write -> address not valid)
    DL_UNSUPPORTED = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 2),               //! function not implemented
    DL_OUT_OF_MEMORY = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 3),             //! out of memory or resources (RAM, sockets, handles, disk space ...).
    DL_LIMIT_MIN = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 4),                 //! the minimum of a limitation is exceeded.
    DL_LIMIT_MAX = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 5),                 //! the maximum of a limitation is exceeded.
    DL_TYPE_MISMATCH = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 6),             //! wrong flatbuffer type, wrong data type
    DL_SIZE_MISMATCH = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 7),             //! size mismatch, present size doesn't match requested size.
    DL_INVALID_FLOATINGPOINT = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 9),     //! invalid floating point number.
    DL_INVALID_HANDLE = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 10),           //! invalid handle argument or NULL pointer argument.
    DL_INVALID_OPERATION_MODE = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 11),   //! not accessible due to invalid operation mode (write not possible)
    DL_INVALID_CONFIGURATION = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 12),    //! mismatch of this value with other configured values
    DL_INVALID_VALUE = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 13),            //! invalid value
    DL_SUBMODULE_FAILURE = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 14),        //! error in submodule
    DL_TIMEOUT = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 15),                  //! request timeout
    DL_ALREADY_EXISTS = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 16),           //! create: resource already exists
    DL_CREATION_FAILED = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 17),          //! error during creation
    DL_VERSION_MISMATCH = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 18),         //! version conflict
    DL_DEPRECATED = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 19),               //! deprecated - function not longer supported
    DL_PERMISSION_DENIED = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 20),        //! request declined due to missing permission rights
    DL_NOT_INITIALIZED = DATALAYER_STATUS_MAKE_ERROR(Facility::APPLICATION, 21),          //! object not initialized yet

    //! communication
    DL_COMM_PROTOCOL_ERROR = DATALAYER_STATUS_MAKE_ERROR(Facility::COMMUNICATION, 1),     //! internal protocol error
    DL_COMM_INVALID_HEADER = DATALAYER_STATUS_MAKE_ERROR(Facility::COMMUNICATION, 2),     //! internal header mismatch

    //! client
    DL_CLIENT_NOT_CONNECTED = DATALAYER_STATUS_MAKE_ERROR(Facility::CLIENT, 1),           //! client not connected

    //! provider
    //! broker

    //! realtime related error codes
    DL_RT_NOTOPEN = DATALAYER_STATUS_MAKE_ERROR(Facility::REALTIME, 1),                   //! not open
    DL_RT_INVALIDOBJECT = DATALAYER_STATUS_MAKE_ERROR(Facility::REALTIME, 2),             //! invalid object 
    DL_RT_WRONGREVISON = DATALAYER_STATUS_MAKE_ERROR(Facility::REALTIME, 3),              //! wrong memory revision
    DL_RT_NOVALIDDATA = DATALAYER_STATUS_MAKE_ERROR(Facility::REALTIME, 4),               //! no valid data 
    DL_RT_MEMORYLOCKED = DATALAYER_STATUS_MAKE_ERROR(Facility::REALTIME, 5),              //! memory already locked
    DL_RT_INVALIDMEMORYMAP = DATALAYER_STATUS_MAKE_ERROR(Facility::REALTIME, 6),          //! invalid memory map
    DL_RT_INVALID_RETAIN = DATALAYER_STATUS_MAKE_ERROR(Facility::REALTIME, 7),            //! invalid memory map
    DL_RT_INTERNAL_ERROR = DATALAYER_STATUS_MAKE_ERROR(Facility::REALTIME, 8),            //! internal RT error

    DL_SEC_NOTOKEN = DATALAYER_STATUS_MAKE_ERROR(Facility::SECURITY, 1),                  //! no token found
    DL_SEC_INVALIDSESSION = DATALAYER_STATUS_MAKE_ERROR(Facility::SECURITY, 2),           //! token not valid (session not found)
    DL_SEC_INVALIDTOKENCONTENT = DATALAYER_STATUS_MAKE_ERROR(Facility::SECURITY, 3),      //! token has wrong content
    DL_SEC_UNAUTHORIZED = DATALAYER_STATUS_MAKE_ERROR(Facility::SECURITY, 4),             //! unauthorized
  };

  Value value;

  DlResult() = default;
  constexpr DlResult(Value result) : value(result) {}
  constexpr DlResult(uint32_t result) : value(static_cast<Value>(result)) {}
  
  friend inline bool operator==(const DlResult& lhs, const DlResult& rhs) {
    return lhs.value == rhs.value;
  }

  friend inline bool operator!=(const DlResult& lhs, const DlResult& rhs) {
    return lhs.value != rhs.value;
  }

  const char* toString() 
  {
#define IDS(id)   case Value::id: return (#id);
    switch (static_cast<uint32_t>(value)) {
      //! facility: common
      IDS(DL_OK)
      IDS(DL_OK_NO_CONTENT)
      IDS(DL_FAILED)

      //! facility: application
      IDS(DL_INVALID_ADDRESS)
      IDS(DL_UNSUPPORTED)
      IDS(DL_OUT_OF_MEMORY)
      IDS(DL_LIMIT_MIN)
      IDS(DL_LIMIT_MAX)
      IDS(DL_TYPE_MISMATCH)
      IDS(DL_SIZE_MISMATCH)
      IDS(DL_INVALID_FLOATINGPOINT)
      IDS(DL_INVALID_HANDLE)
      IDS(DL_INVALID_OPERATION_MODE)
      IDS(DL_INVALID_CONFIGURATION)
      IDS(DL_INVALID_VALUE)
      IDS(DL_SUBMODULE_FAILURE)
      IDS(DL_TIMEOUT)
      IDS(DL_ALREADY_EXISTS)
      IDS(DL_CREATION_FAILED)
      IDS(DL_VERSION_MISMATCH)
      IDS(DL_DEPRECATED)
      IDS(DL_PERMISSION_DENIED)
      IDS(DL_NOT_INITIALIZED)

      //! facility: communication
      IDS(DL_COMM_PROTOCOL_ERROR)
      IDS(DL_COMM_INVALID_HEADER)

      //! facility: client
      IDS(DL_CLIENT_NOT_CONNECTED)

      //! facility: realtime
      IDS(DL_RT_NOTOPEN)
      IDS(DL_RT_INVALIDOBJECT)
      IDS(DL_RT_WRONGREVISON)
      IDS(DL_RT_NOVALIDDATA)
      IDS(DL_RT_MEMORYLOCKED)
      IDS(DL_RT_INVALIDMEMORYMAP)
      IDS(DL_RT_INVALID_RETAIN)
      IDS(DL_RT_INTERNAL_ERROR)

      IDS(DL_SEC_NOTOKEN)
      IDS(DL_SEC_INVALIDSESSION)
      IDS(DL_SEC_INVALIDTOKENCONTENT)
      IDS(DL_SEC_UNAUTHORIZED)

      default: return("unknown");
    }
  }
};

//! Return whether status code is an error status code
//! @param[in]  status     Status code
//! @return true if status code is an error status code
inline bool STATUS_FAILED(DlResult status)
{
  return (static_cast<uint32_t>(status.value) & (1 << 31));
}

//! Return whether status code is a successfull status code
//! @param[in]  status     Status code
//! @return true if status code is a successfull status code
inline bool STATUS_SUCCEEDED(DlResult status)
{
  return !STATUS_FAILED(status);
}

#if defined(_MSC_VER)
//! @brief save string cat (will not overwrite the destination)
//! @param[in]   dest pointer to the null-terminated byte string to append to
//! @param[in]   src    pointer to the character array to copy from
//! @param[in]   destSize the size of the destination buffer
//! @return returns zero on success, returns non-zero on error. Also, on error, writes zero to dest[0] (unless dest is a null pointer or destsz is zero or greater than RSIZE_MAX).
inline int32_t stringcat_s(char* dest, size_t destSize, const char* src)
{
  return strncat_s(dest, destSize, src, _TRUNCATE);
}

//! @brief save string copy (will not overwrite the destination)
//! @param[in]   dest pointer to the character array to copy to
//! @param[in]   src    pointer to the character array to copy from
//! @param[in]   copyCount  maximum number of characters to copy
//! @param[in]   destSize the size of the destination buffer 
//! @return returns zero on success, returns non-zero on error. Also, on error, writes zero to dest[0] (unless dest is a null pointer or destsz is zero or greater than RSIZE_MAX) and may clobber the rest of the destination array with unspecified values.
inline int32_t stringcpy_s(char* dest, size_t destSize, const char* src, size_t copyCount)
{
  return strncpy_s(dest, destSize, src, copyCount);
}
#else
//! @brief save string cat (will not overwrite the destination)
//! @param[in]   dest pointer to the null-terminated byte string to append to
//! @param[in]   src    pointer to the character array to copy from
//! @param[in]   destSize the size of the destination buffer
//! @return returns zero on success, returns non-zero on error. Also, on error, writes zero to dest[0] (unless dest is a null pointer or destsz is zero or greater than RSIZE_MAX).
inline int32_t stringcat_s(char* dest, size_t destSize, const char* src)
{
  strncat(dest, src, destSize - strlen(dest) - 1);
  return 0;
}

//! @brief save string copy (will not overwrite the destination)
//! @param[in]   dest pointer to the character array to copy to
//! @param[in]   destSize the size of the destination buffer 
//! @param[in]   src    pointer to the character array to copy from
//! @param[in]   copyCount  maximum number of characters to copy
//! @return returns zero on success, returns non-zero on error. Also, on error, writes zero to dest[0] (unless dest is a null pointer or destsz is zero or greater than RSIZE_MAX) and may clobber the rest of the destination array with unspecified values.
inline int32_t stringcpy_s(char* dest, size_t destSize, const char* src, size_t copyCount)
{
  if (destSize < (copyCount + 1)) {
    copyCount = destSize;
  }
  strncpy(dest, src, copyCount);
  return 0;
}
#endif // _MSC_VER

}
}
