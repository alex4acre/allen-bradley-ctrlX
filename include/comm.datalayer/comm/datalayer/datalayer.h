/*! \file
 *
 * Datalayer main header
 */
#pragma once

#include "datalayer_version.h"
#include "datalayer_defs.h"
#include "variant.h"
#include "datalayer_rt.h"
#include <functional>

#define IDATALAYER_CONSUMER_RANGE "[" IDATALAYER_VERSION_MAJOR "." IDATALAYER_VERSION_MINOR ".0,2.0.0)"                                                 //! Version range for users of Datalayer
#define IDATALAYER_FACTORY_INTERFACE_NAME "com.boschrexroth.comm.datalayer.factory"               //! Interface name of factory
#define IDATALAYER_FACTORY_INTERFACE_NAME2 "com.boschrexroth.comm.datalayer.factory2"             //! Interface for the factory which implements version 2 of the datalayer factory. Version 2 of the interface introduces support for subscriptions.
#define IDATALAYER_CONVERTER_INTERFACE_NAME "com.boschrexroth.comm.datalayer.converter"           //! Interface name of converter
#define IDATALAYER_TRACE_INTERFACE_NAME "com.boschrexroth.comm.datalayer.trace"                   //! Interface name of trace (trace registers here to avoid dependency cycles)

#define DL_TCP_FRONTEND_FIRST_PORT      2069                                                      //! First port number of frontend
#define DL_TCP_BACKEND_FIRST_PORT       2070                                                      //! First port number of backend
#define DL_PORT_NUM                     50                                                        //! Number of communication ports per broker
#define DL_TCP_ANY_ADDR                 "*:"                                                      //! Any IP address
#define DL_TCP_LOCAL_ADDR               "127.0.0.1:"                                              //! localhost
#define DL_TCP                          "tcp://"                                                  //! TCP protocoll scheme
#define DL_IPC                          "ipc://"                                                  //! IPC protocoll scheme
#define DL_INPROC                       "inproc://"                                               //! inproc protocoll scheme
#define DL_IPC_AUTO                     DL_IPC                                                    //! automatic select IPC connection
#define DL_INTERN_CLIENT                "intern"                                                  //! intern datalayer client
#define DL_INTERN_PROVIDER              "intern"                                                  //! intern datalayer provider

#define DL_IPC_FRONTEND                 ".datalayer/frontend/"                                    //! Datalayer frontend path
#define DL_IPC_BACKEND                  ".datalayer/backend/"                                     //! Datalayer backend path
#define DL_INPROC_FRONTEND              "/tmp/datalayer/frontend"                                 //! Datalayer backend path inproc
#define DL_INPROC_BACKEND               "/tmp/datalayer/backend"                                  //! Datalayer backend path inproc

#define DL_INPROC_FRONTEND_SERVER       (DL_INPROC DL_INPROC_FRONTEND)                            //! Datalayer inproc fronend URI
#define DL_INPROC_BACKEND_SERVER        (DL_INPROC DL_INPROC_BACKEND)                             //! Datalayer inproc backend URI

//! Namespace for datalayer
namespace comm {
namespace datalayer {

class Variant;

//! Settings of different timeout values
enum class TimeoutSetting
{
  Idle,      // timeout to check whether to broker is still active when client is idle
  Ping,      // timeout to wait for a response for a request - it timeout exceeds request will be aborted with DL_TIMEOUT
  Reconnect, // timeout a reconnect attempt will be done if client looses connection to broker
};

//! Client interface for accessing data from the system
class IClient
{
public:
  virtual ~IClient() {}

  //! Response function when a asynchronous call is ready.
  //! @param[out] status    Response status of the call
  //! @param[out] data      Response data
  typedef std::function<void(DlResult status, const Variant* data)> ResponseCallback;

  //! Ping the next hop. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! @param[in]  callback  Callback to call when function is finished
  //! @result status of function call
  virtual DlResult pingAsync(const ResponseCallback &callback) = 0;

  //! Create an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  address   Address of the node to create object in
  //! @param[in]  data      Data of the object
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult createAsync(const std::string &address, const Variant &data, const ResponseCallback &callback, const std::string &token = {}) = 0;

  //! Remove an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  address   Address of the node to remove
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult removeAsync(const std::string &address, const ResponseCallback &callback, const std::string &token = {}) = 0;

  //! Browse an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  address   Address of the node to browse
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult browseAsync(const std::string &address, const ResponseCallback &callback, const std::string &token = {}) = 0;

  //! Read an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  address   Address of the node to read
  //! @param[in]  data      Data of the object
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult readAsync(const std::string &address, const Variant &data, const ResponseCallback &callback, const std::string &token = {}) = 0;

  //! Write an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  address   Address of the node to write
  //! @param[in]  data      Data of the object
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult writeAsync(const std::string &address, const Variant &data, const ResponseCallback &callback, const std::string &token = {}) = 0;

  //! Read metadata of an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  address   Address of the node to read metadata
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult metadataAsync(const std::string &address, const ResponseCallback &callback, const std::string &token = {}) = 0;

  //! Ping the next hop. This function is synchronous: It will wait for the answer.
  //! @result status of function call
  virtual DlResult pingSync() = 0;

  //! Create an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  address   Address of the node to create object in
  //! @param[in,out]  data      Data of the object, result of write
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult createSync(const std::string &address, Variant *data, const std::string &token = {}) = 0;

  //! Remove an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  address   Address of the node to remove
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult removeSync(const std::string &address, const std::string &token = {}) = 0;

  //! Browse an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  address   Address of the node to browse
  //! @param[out] data      Children of the node. Data will be provided as Variant array of strings.
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult browseSync(const std::string &address, Variant *data, const std::string &token = {}) = 0;

  //! Read an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  address   Address of the node to read
  //! @param[out] data      Data of the node
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult readSync(const std::string &address, Variant *data, const std::string &token = {}) = 0;

  //! Write an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  address   Address of the node to write
  //! @param[in,out] data      New data of the node, result of write
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult writeSync(const std::string &address, Variant *data, const std::string &token = {}) = 0;

  //! Read metadata of an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  address   Address of the node to read metadata of
  //! @param[out] data      Metadata of the node. Data will be provided as Variant flatbuffers with metadata.fbs data type.
  //! @param[in]  token     Security access &token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult metadataSync(const std::string &address, Variant *data, const std::string &token = {}) = 0;

  //! Set client timeout value
  //! @param[in]  timeout   Timeout to set (see TimeoutSetting)
  //! @param[in]  value     Value to set
  //! @result status of function call
  virtual DlResult setTimeout(TimeoutSetting timeout, uint32_t value) = 0;

  //! returns whether provider is connected
  //| @return status of connection
  virtual bool isConnected() const = 0;

  //! Set persistent security access token for authentication as JWT payload
  //! @param[in]  token  Security access &token for authentication
  virtual void setAuthToken(const std::string &token) = 0;

  //! returns persistent security access token for authentication
  //| @return security access token for authentication
  virtual std::string getAuthToken() const = 0;

};

//! The notify item will be sent when the data value has been updated (e.g. in a subscription).
typedef struct NotifyItem
{
  Variant data; // data of the notify item
  Variant info; // containing notify_info.fbs (address, timestamp, type, ...)
}NotifyItem;

//! This callback delivers a vector with the updated nodes of a subscription.
//! It is usually called in the interval given by the publishInterval which has been set by the creation of the subscription.
//! The callback may not contain all nodes of the subscription.I.e.when a node did not change.
//! The callback may contain a node multiple times.I.e.when the node did change multiple times since the last callback.
//! The sorting order of the items in the vector is undefined.
//! @param[in] status    Notify status
//! @param[in] items     Notify data
typedef std::function<void(DlResult status, const std::vector<NotifyItem>& items)> PublishCallback;

class IClient2 : public IClient
{
public:
  virtual ~IClient2() {};

  //! Setup a subscription
  //! @param[in]  ruleset   Variant that describe ruleset of subscription as subscription.fbs
  //! @param[in]  publishCallback  Callback to call when new data is available
  //! @param[in]  token     Security access &token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult createSubscriptionSync(const Variant& ruleset, const PublishCallback& publishCallback = {}, const std::string& token = {}) = 0;

  //! Adds a node to a subscription id
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Address of a node, that should be added to the given subscription.
  //! @result status of function call
  virtual DlResult subscribeSync(const std::string& id, const std::string& address) = 0;

  //! Adds a set of nodes to a subscription id
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Set of Addresses of a node, that should be added to the given subscription.
  //! @result status of function call
  virtual DlResult subscribeSync(const std::string& id, const std::set<std::string>& address) = 0;

  //! Removes a node from a subscription id
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Address of a node, that should be removed to the given subscription.
  //! @result status of function call
  virtual DlResult unsubscribeSync(const std::string& id, const std::string& address) = 0;

  //! Removes a set of nodes from a subscription id
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Set of addresses of nodes, that should be removed to the given subscription.
  //! @result status of function call
  virtual DlResult unsubscribeSync(const std::string& id, const std::set<std::string>& address) = 0;

  //! Removes subscription id completely
  //! @param[in]  id        ID of subscription to remove
  //! @result status of function call
  virtual DlResult unsubscribeSync(const std::string& id) = 0;

  //! Setup a subscription
  //! @param[in]  ruleset   Variant that describe ruleset of subscription as subscription.fbs
  //! @param[in]  publishCallback Callback to call when new data is available
  //! @param[in]  callback  Callback to be called when subscription is created
  //! @param[in]  token     Security access &token for authentication as JWT payload
  //! @result status of function call
  virtual DlResult createSubscriptionAsync(const Variant& ruleset, const PublishCallback& publishCallback, const ResponseCallback& callback, const std::string& token = {}) = 0;

  //! Setup a subscription to a node
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Address of the node to add a subscription to
  //! @param[in]  callback  Callback to called when data is subscribed
  //! @result status of function call
  virtual DlResult subscribeAsync(const std::string& id, const std::string& address, const ResponseCallback& callback) = 0;

  //! Setup a subscription to multiple nodes
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Set of addresses of nodes, that should be removed to the given subscription.
  //! @param[in]  callback  Callback to called when data is subscribed
  //! @result status of function call
  virtual DlResult subscribeAsync(const std::string& id, const std::set<std::string>& address, const ResponseCallback& callback) = 0;

  //! Removes a node from a subscription id
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Address of a node, that should be removed to the given subscription.
  //! @param[in]  callback  Callback to called when data is subscribed
  //! @result status of function call
  virtual DlResult unsubscribeAsync(const std::string& id, const std::string& address, const ResponseCallback& callback) = 0;

  //! Removes a set of nodes from a subscription id
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Address of a node, that should be removed to the given subscription.
  //! @param[in]  callback  Callback to called when data is subscribed
  //! @result status of function call
  virtual DlResult unsubscribeAsync(const std::string& id, const std::set<std::string>& address, const ResponseCallback& callback) = 0;

  //! Removes all subscriptions from a subscription id
  //! @param[in]  id        ID of subscription to remove
  //! @param[in]  callback  Callback to called when data is subscribed
  //! @result status of function call
  virtual DlResult unsubscribeAsync(const std::string& id, const ResponseCallback& callback) = 0;
};

//! Provider node interface for providing data to the system
class IProviderNode
{
public:
  virtual ~IProviderNode() {}

  //! Response function to call when a call is finished.
  //! @param[in]  status    Response status of the call
  //! @param[in]  data      Response data
  typedef std::function<void(DlResult, const Variant* data)> ResponseCallback;

  //! Create function of an object. Function will be called whenever a object should be created.
  //! @param[in]  address   Address of the node to create object in
  //! @param[in]  data      Data of the object
  //! @param[in]  callback  Callback to call when function is finished. After calling this method content of data is not valid anymore.
  virtual void onCreate(const std::string &address, const comm::datalayer::Variant* data, const comm::datalayer::IProviderNode::ResponseCallback &callback) = 0;

  //! Remove function for an object. Function will be called whenever a object should be removed.
  //! @param[in]  address   Address of the node to remove
  //! @param[in]  callback  Callback to call when function is finished
  virtual void onRemove(const std::string &address, const ResponseCallback &callback) = 0;

  //! Browse function of a node. Function will be called to determine children of a node.
  //! @param[in]  address   Address of the node to browse
  //! @param[in]  callback  Callback to call when function is finished
  virtual void onBrowse(const std::string &address, const ResponseCallback &callback) = 0;

  //! Read function of a node. Function will be called whenever a node should be read.
  //! @param[in]  address   Address of the node to read
  //! @param[in]  data      Data of the object
  //! @param[in]  callback  Callback to call when function is finished. After calling this method content of data is not valid anymore.
  virtual void onRead(const std::string &address, const comm::datalayer::Variant* data, const ResponseCallback &callback) = 0;

  //! Write function of a node. Function will be called whenever a node should be written.
  //! @param[in]  address   Address of the node to write
  //! @param[in]  data      Data of the object
  //! @param[in]  callback  Callback to call when function is finished. After calling this method content of data is not valid anymore.
  virtual void onWrite(const std::string &address, const Variant* data, const ResponseCallback &callback) = 0;

  //! Read function of metadata of an object. Function will be called whenever a node should be written.
  //! @param[in]  address   Address of the node to read metadata of
  //! @param[out] callback  Callback to call when function is finished
  virtual void onMetadata(const std::string &address, const ResponseCallback &callback) = 0;
};

class ISubscription
{
public:
  virtual ~ISubscription() {};

  //! Publishes new data for this subscription
  //! @param[in] status  Status of notification. On failure subscription is canceled for all items.
  //! @param[in] items   Notification items
  //! @return result
  virtual DlResult publish(DlResult status, const std::vector<NotifyItem>& items) = 0;

  //! Returns properties of subscription
  //! return Properties of Subscription in a Variant (see sub_properties.fbs)
  virtual const Variant* getProps() const = 0;

  //! Returns nodes subscribed for this subscription
  //! return Subscribed nodes for this subscription
  virtual const Variant getNodes() const = 0;

  //! Returns current timestamp
  virtual uint64_t getTimestamp() const = 0;
};

class ISubscriptionNode : public IProviderNode
{
public:
  virtual ~ISubscriptionNode() {};

  //! Starts a subscription of a node
  //! @param[in] subscription     Object holding detailed information about subscription. This object can be stored till onUnsubscription() will be called for this address.
  //! @Param[in] address          Address to subscribe
  virtual DlResult onSubscription(ISubscription* subscription, const std::string& address) = 0;

  //! Starts a subscription of a node
  //! @param[in] subscription     Object holding detailed information about subscription. This object can be stored till onUnsubscription() will be called for this address.
  //! @Param[in] address          Address to unsubscribe
  virtual DlResult onUnsubscription(ISubscription* subscription, const std::string& address) = 0;
};

//! Provider interface to manage provider nodes
class IProvider
{
public:
  virtual ~IProvider() {}

  //! Register a type to the datalayer
  //! @param[in]  address   Address of the node to register (no wildcards allowed)
  //! @param[in]  pathname  Path to flatbuffer bfbs
  //! @result status of function call
  virtual DlResult registerType(const std::string& address, const std::string& pathname) = 0;

  //! Unregister a type from the datalayer
  //! @param[in]  address   Address of the node to register (wildcards allowed)
  //! @result status of function call
  virtual DlResult unregisterType(const std::string& address) = 0;

  //! Register a node to the datalayer
  //! @param[in]  address   Address of the node to register (wildcards allowed)
  //! @param[in]  node      Node to register
  //! @result status of function call
  virtual DlResult registerNode(const std::string& address, IProviderNode* node) = 0;

  //! Register a node to the datalayer
  //! @param[in]  address   Address of the node to register (wildcards allowed)
  //! @param[in]  node      Node to register
  //! @result status of function call
  virtual DlResult registerNode(const char* address, IProviderNode* node) = 0;

  //! Unregister a node from the datalayer
  //! @param[in]  address   Address of the node to register (wildcards allowed)
  //! @result status of function call
  virtual DlResult unregisterNode(const std::string& address) = 0;

  //! Unregister a node from the datalayer
  //! @param[in]  address   Address of the node to register (wildcards allowed)
  //! @result status of function call
  virtual DlResult unregisterNode(const char* address) = 0;

  //! Set timeout for a node for asynchron requests (default value is 10000ms)
  //! @param[in]  node      Node to set timeout for
  //! @param[in]  timeoutMS Timeout in milliseconds for this node
  //! @result status of function call
  virtual DlResult setTimeoutNode(IProviderNode* node, uint32_t timeoutMS) = 0;

  //! Start the provider
  //! @result status of function call
  virtual DlResult start() = 0;

  //! Stop the provider
  //! @result status of function call
  virtual DlResult stop() = 0;

  //! returns whether provider is connected
  //! @return status of connection
  virtual bool isConnected() = 0;

  //! return the current token of the current request
  //! you can call this function during your onRead, onWrite, ... methods of
  //! your ProviderNodes.
  //! if there is no current request the method return an empty token
  //! @return current token
  virtual const Variant& getToken() = 0;

};

class IProvider2 : public IProvider
{
public:
  virtual ~IProvider2() {};

  //! Register a node to the datalayer
  //! @param[in]  address   Address of the node to register (wildcards allowed)
  //! @param[in]  node      Node to register
  //! @result status of function call
  virtual DlResult registerSubscriptionNode(const std::string& address, ISubscriptionNode* node) = 0;

  //! Unregister a node from the datalayer
  //! @param[in]  address   Address of the node to register (wildcards allowed)
  //! @result status of function call
  virtual DlResult unregisterSubscriptionNode(const std::string& address) = 0;

};


//! Factory class
class IDataLayerFactory
{
public:
  virtual ~IDataLayerFactory() {}

  //! Response function when a asynchronous call is ready.
  //! @param[out] status    Response status of the call
  //! @param[out] data      Response data
  typedef std::function<void(DlResult result, std::shared_ptr<IMemoryOwner>& owner)> ResponseCallbackOwner;
  typedef std::function<void(DlResult result)> ResponseCallback;

  //! Creates a client for accessing data of the system
  //! @param[in] remote     Remote address of the data layer
  //! @return Client
  virtual IClient* createClient(const std::string &remote = DL_INPROC_FRONTEND_SERVER) = 0;

  //! Creates a provider to provide data to the datalayer
  //! @param[in] remote     Remote address of the data layer
  //! @return Provider
  virtual IProvider* createProvider(const std::string &remote = DL_INPROC_BACKEND_SERVER) = 0;

  //! Creates memory in datalayer rt
  virtual DlResult createMemoryAsync(const std::string &addr, IProvider* provider, size_t sizeBytes, MemoryType type, ResponseCallbackOwner &callback) = 0;
  virtual DlResult createMemorySync(std::shared_ptr<IMemoryOwner>& owner, const std::string &addr, IProvider* provider, size_t sizeBytes, MemoryType type) = 0;

  //! Delete memory in datalayer rt
  virtual DlResult deleteMemoryAsync(std::shared_ptr<IMemoryOwner>& owner, ResponseCallback &callback) = 0;
  virtual DlResult deleteMemorySync(std::shared_ptr<IMemoryOwner>& owner) = 0;

  //! Opens memory in datalayer rt
  virtual DlResult openMemory(std::shared_ptr<IMemoryUser>& user, const std::string &addr) = 0;
  virtual DlResult closeMemory(std::shared_ptr<IMemoryUser>& user) = 0;

};

//! Creates a client which implements version 2 of the datalayer client interface. Version 2 of the interfaces introduces support for subscriptions.
class IDataLayerFactory2 : public IDataLayerFactory
{
public:
  virtual ~IDataLayerFactory2() {};

  //! Creates a client for accessing data of the system
  //! @param[in] remote     Remote address of the data layer
  //! @return Client
  virtual IClient2* createClient2(const std::string& remote = DL_INPROC_FRONTEND_SERVER) = 0;

  //! Creates a provider to provide data to the datalayer
  //! @param[in] remote     Remote address of the data layer
  //! @return Provider
  virtual IProvider2* createProvider2(const std::string& remote = DL_INPROC_BACKEND_SERVER) = 0;
};

}
}
