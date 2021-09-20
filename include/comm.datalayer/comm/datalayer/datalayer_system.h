#pragma once
#include "datalayer.h"
#include "flatbuffer_json.h"
#include "persistence_helper.h"


#ifdef _WIN32
  #define DATALAYER_SYSTEM_TEMP_PATH "C:/temp"
#elif __linux__
  #define DATALAYER_SYSTEM_TEMP_PATH "/var/tmp"
#endif // windows


//! Namespace for datalayer
namespace comm {
namespace datalayer {

enum class BindNode { FRONTEND_TCP, BACKEND_TCP, FRONTEND_IPC, BACKEND_IPC, FRONTEND_INPROC, BACKEND_INPROC };
class Factory;
class Broker;
class FlatbufferJson;
class PersistenceHelper;
class RTDebug;

//! DatalayerSystem which includes a broker
class DatalayerSystem
{
public:
  DatalayerSystem(std::string ipcPath = DATALAYER_SYSTEM_TEMP_PATH);
  ~DatalayerSystem();

  //! Returns the factory to create clients and provider for the datalayer
  //! @return Factory
  IDataLayerFactory2* factory();

  //! Returns converter between JSON and Variant
  //! @return Converter between JSON and Variant
  IFlatbufferJson* jsonConverter();

  //! Returns persistence helper
//! @return persistence helper
  PersistenceHelper* persistenceHelper();

  //! Start the datalayer (broker)
  void start(bool boStartBroker = true);

  //! Stop the datalayer (broker)
  //! returns false if there is a client or provider active
  bool stop(bool boForceProviderStop = false);

  std::string getBrokerBindNode(BindNode type);

  void setBfbsPath(std::string path);

  std::string getServerPublicKey();

  DlResult persistNvram();

protected:
private:
  void* m_zmqContext = nullptr;
  Factory* m_factory = nullptr;
  Broker* m_broker = nullptr;
  FlatbufferJson* m_converter = nullptr;
  PersistenceHelper* m_persistenceHelper = nullptr;
  RTDebug* m_rtdebug = nullptr;
  std::string m_ipcPath = "";
  std::string m_bfbsPath = "";
};

}
}
