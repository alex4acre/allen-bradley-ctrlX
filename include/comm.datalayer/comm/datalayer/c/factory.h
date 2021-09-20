#pragma once

#include "client.h"
#include "provider.h"

#ifdef __cplusplus
extern "C" {
#endif

  typedef void *DLR_FACTORY;

  //! Creates a client for accessing data of the system
  //! @param[in] factory    Reference to the factory
  //! @param[in] remote     Remote address of the data layer
  //! @return Client
  DLR_CLIENT DLR_factoryCreateClient(DLR_FACTORY factory, const char* remote);

  //! Creates a provider to provide data to the datalayer
  //! @param[in] factory    Reference to the factory
  //! @param[in] remote     Remote address of the data layer
  //! @return Provider
  DLR_PROVIDER DLR_factoryCreateProvider(DLR_FACTORY factory, const char* remote);

#ifdef __cplusplus
}
#endif
