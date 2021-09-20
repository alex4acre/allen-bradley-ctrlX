#pragma once

#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

  //! The notify item will be sent when the data value has been updated (e.g. in a subscription).
  typedef struct NotifyItem
  {
    DLR_VARIANT data; // data of the notify item
    DLR_VARIANT info; // containing notify_info.fbs
  }NotifyItem;

  typedef void* DLR_CLIENT;

  //! Response function when a asynchronous call is ready.
  //! @param[in] status     Response status of the call
  //! @param[in] data       Response data
  //! @param[in] userdata   Same userdata as in async request given
  typedef void(*DLR_CLIENT_RESPONSE)(DLR_RESULT status, DLR_VARIANT data, void* userdata);

  //! This callback delivers a vector with the updated nodes of a subscription.
  //! It is usually called in the interval given by the publishInterval which has been set by the creation of the subscription.
  //! The callback may not contain all nodes of the subscription.I.e.when a node did not change.
  //! The callback may contain a node multiple times.I.e.when the node did change multiple times since the last callback.
  //! The sorting order of the items in the vector is undefined.
  //! @param[in] status    Notify status
  //! @param[in] items     Notify data
  //! @param[in] count     count of items
  //! @param[in] userdata   Same userdata as in create subscription given
  typedef void(*DLR_CLIENT_NOTIFY_RESPONSE)(DLR_RESULT status, NotifyItem* items, uint32_t count, void* userdata);

  //! Settings of different timeout values
  typedef enum DLR_TIMEOUT_SETTING {
    DLR_TIMEOUT_SETTING_IDLE,       // timeout to check whether to broker is still active when client is idle
    DLR_TIMEOUT_SETTING_PING,       // timeout to wait for a response for a request - it timeout exceeds request will be aborted with DL_TIMEOUT
    DLR_TIMEOUT_SETTING_RECONNECT,  // timeout a reconnect attempt will be done if client looses connection to broker
  } DLR_TIMEOUT_SETTING;

  // deletes a client
  //! @param[in]  client    Reference to the client
  void DLR_clientDelete(DLR_CLIENT client);

  //! Ping the next hop. This function is synchronous: It will wait for the answer.
  //! @param[in]  client    Reference to the client
  //! @result status of function call
  DLR_RESULT DLR_clientPingSync(DLR_CLIENT client);

  //! Create an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to create object in
  //! @param[in,out]  variant      Data of the object, result of write
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  DLR_RESULT DLR_clientCreateSync(DLR_CLIENT client, const char* address, DLR_VARIANT variant, const char* token);

  //! Remove an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to remove
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  DLR_RESULT DLR_clientRemoveSync(DLR_CLIENT client, const char* address, const char* token);

  //! Browse an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to browse
  //! @param[out] variant   Children of the node. Data will be provided as Variant array of strings.
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  DLR_RESULT DLR_clientBrowseSync(DLR_CLIENT client, const char* address, DLR_VARIANT variant, const char* token);

  //! Read an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to read
  //! @param[in,out] variant   Read filter data of the node
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  DLR_RESULT DLR_clientReadSync(DLR_CLIENT client, const char* address, DLR_VARIANT variant, const char* token);

  //! Write an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to write
  //! @param[in,out] variant New data of the node, result of write
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @result status of function call
  DLR_RESULT DLR_clientWriteSync(DLR_CLIENT client, const char* address, DLR_VARIANT variant, const char* token);

  //! Read metadata of an object. This function is synchronous: It will wait for the answer.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to read metadata of
  //! @param[out] variant   Metadata of the node. Data will be provided as Variant flatbuffers with metadata.fbs data type.
  //! @param[in]  token     Security access &token for authentication as JWT payload
  //! @result status of function call
  DLR_RESULT DLR_clientMetadataSync(DLR_CLIENT client, const char* address, DLR_VARIANT variant, const char* token);

  //! Ping the next hop. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! @param[in]  client    Reference to the client
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  //! @result status of function call
  DLR_RESULT DLR_clientPingASync(DLR_CLIENT client, DLR_CLIENT_RESPONSE callback, void *userdata);

  //! Create an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to create object in
  //! @param[in]  data      Data of the object
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  //! @result status of function call
  DLR_RESULT DLR_clientCreateASync(DLR_CLIENT client, const char* address, DLR_VARIANT variant, const char* token, DLR_CLIENT_RESPONSE callback, void *userdata);

  //! Remove an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to remove
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  //! @result status of function call
  DLR_RESULT DLR_clientRemoveASync(DLR_CLIENT client, const char* address, const char* token, DLR_CLIENT_RESPONSE callback, void *userdata);

  //! Browse an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to browse
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  //! @result status of function call
  DLR_RESULT DLR_clientBrowseASync(DLR_CLIENT client, const char* address, const char* token, DLR_CLIENT_RESPONSE callback, void *userdata);

  //! Read an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to read
  //! @param[in]  data      Read filter data of the node
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  //! @result status of function call
  DLR_RESULT DLR_clientReadASync(DLR_CLIENT client, const char* address, DLR_VARIANT variant, const char* token, DLR_CLIENT_RESPONSE callback, void *userdata);

  //! Write an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to write
  //! @param[in]  data      Data of the object
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  //! @result status of function call
  DLR_RESULT DLR_clientWriteASync(DLR_CLIENT client, const char* address, DLR_VARIANT variant, const char* token, DLR_CLIENT_RESPONSE callback, void *userdata);

  //! Read metadata of an object. This function is asynchronous. It will return immediately. Callback will be called if function call is finished.
  //! Result data may be provided in callback function.
  //! @param[in]  client    Reference to the client
  //! @param[in]  address   Address of the node to read metadata
  //! @param[in]  token     Security access token for authentication as JWT payload
  //! @param[in]  callback  Callback to call when function is finished
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  //! @result status of function call
  DLR_RESULT DLR_clientMetadataASync(DLR_CLIENT client, const char* address, const char* token, DLR_CLIENT_RESPONSE callback, void *userdata);

  //! Setup a subscription
  //! @param[in]  client    Reference to the client
  //! @param[in]  ruleset   Variant that describe ruleset of subscription as subscription.fbs
  //! @param[in]  publishCallback  Callback to call when new data is available
  //! @param[in]  userdata  User data - will be returned in publishCallback as userdata. You can use this userdata to identify your subscription
  //! @param[in]  token     Security access &token for authentication as JWT payload
  //! @result status of function call
  DLR_RESULT DLR_clientCreateSubscriptionSync(DLR_CLIENT client, DLR_VARIANT ruleset, DLR_CLIENT_NOTIFY_RESPONSE publishCallback, void* userdata, const char* token);

  //! Adds a node to a subscription id
  //! @param[in]  client    Reference to the client
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Address of a node, that should be added to the given subscription.
  //! @result status of function call
  DLR_RESULT DLR_clientSubscribeSync(DLR_CLIENT client, const char* id, const char* address);

  //! Adds a list of nodes to a subscription id
  //! @param[in]  client    Reference to the client
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   List of Addresses of a node, that should be added to the given subscription.
  //! @param[in]  count     Count of addresses.
  //! @result status of function call
  DLR_RESULT DLR_clientSubscribeMultiSync(DLR_CLIENT client, const char* id, const char** address, uint32_t count);

  //! Removes a node from a subscription id
  //! @param[in]  client    Reference to the client
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Address of a node, that should be removed to the given subscription.
  //! @result status of function call
  DLR_RESULT DLR_clientUnsubscribeSync(DLR_CLIENT client, const char* id, const char* address);

  //! Removes a set of nodes from a subscription id
  //! @param[in]  client    Reference to the client
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Set of addresses of nodes, that should be removed to the given subscription.
  //! @result status of function call
  DLR_RESULT DLR_clientUnsubscribeMultiSync(DLR_CLIENT client, const char* id, const char** address, uint32_t count);

  //! Removes subscription id completely
  //! @param[in]  client    Reference to the client
  //! @param[in]  id        ID of subscription to remove
  //! @result status of function call
  DLR_RESULT DLR_clientUnsubscribeAllSync(DLR_CLIENT client, const char* id);

  //! Setup a subscription
  //! @param[in]  client    Reference to the client
  //! @param[in]  ruleset   Variant that describe ruleset of subscription as subscription.fbs
  //! @param[in]  publishCallback Callback to call when new data is available
  //! @param[in]  callback  Callback to be called when subscription is created
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request and subscription
  //! @param[in]  token     Security access &token for authentication as JWT payload
  //! @result status of function call
  DLR_RESULT DLR_clientCreateSubscriptionAsync(DLR_CLIENT client, DLR_VARIANT ruleset, DLR_CLIENT_NOTIFY_RESPONSE publishCallback, DLR_CLIENT_RESPONSE callback, void* userdata, const char* token);

  //! Setup a subscription to a node
  //! @param[in]  client    Reference to the client
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Address of the node to add a subscription to
  //! @param[in]  callback  Callback to called when data is subscribed
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  //! @result status of function call
  DLR_RESULT DLR_clientSubscribeAsync(DLR_CLIENT client, const char* id, const char* address, DLR_CLIENT_RESPONSE callback, void* userdata);

  //! Setup a subscription to multiple nodes
  //! @param[in]  client    Reference to the client
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Set of addresses of nodes, that should be removed to the given subscription.
  //! @param[in]  count     Count of addresses.
  //! @param[in]  callback  Callback to called when data is subscribed
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  //! @result status of function call
  DLR_RESULT DLR_clientSubscribeMultiAsync(DLR_CLIENT client, const char* id, const char** address, uint32_t count, DLR_CLIENT_RESPONSE callback, void* userdata);

  //! Removes a node from a subscription id
  //! @param[in]  client    Reference to the client
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Address of a node, that should be removed to the given subscription.
  //! @param[in]  callback  Callback to called when data is subscribed
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  //! @result status of function call
  DLR_RESULT DLR_clientUnsubscribeAsync(DLR_CLIENT client, const char* id, const char* address, DLR_CLIENT_RESPONSE callback, void* userdata);

  //! Removes a set of nodes from a subscription id
  //! @param[in]  client    Reference to the client
  //! @param[in]  id        Subscription ID, given in creation of the subscription. See createSbscription(A)Sync.
  //! @param[in]  address   Address of a node, that should be removed to the given subscription.
  //! @param[in]  callback  Callback to called when data is subscribed
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  //! @result status of function call
  DLR_RESULT DLR_clientUnsubscribeMultiAsync(DLR_CLIENT client, const char* id, const char** address, uint32_t count, DLR_CLIENT_RESPONSE callback, void* userdata);

  //! Removes all subscriptions from a subscription id
  //! @param[in]  client    Reference to the client
  //! @param[in]  id        ID of subscription to remove
  //! @param[in]  callback  Callback to called when data is subscribed
  //! @result status of function call
  //! @param[in]  userdata  User data - will be returned in callback as userdata. You can use this userdata to identify your request
  DLR_RESULT DLR_clientUnsubscribeAllAsync(DLR_CLIENT client, const char* id, DLR_CLIENT_RESPONSE callback, void* userdata);

  //! Set client timeout value
  //! @param[in]  client    Reference to the client
  //! @param[in]  timeout   Timeout to set (see DLR_TIMEOUT_SETTING)
  //! @param[in]  value     Value to set
  //! @result status of function call
  DLR_RESULT DLR_clientSetTimeout(DLR_CLIENT client, DLR_TIMEOUT_SETTING timeout, uint32_t value);

  //! returns whether provider is connected
  //! @param[in]  client    Reference to the client
  //| @return status of connection
  bool DLR_clientIsConnected(DLR_CLIENT client);

  //! Set persistent security access token for authentication as JWT payload
  //! @param[in]  client    Reference to the client
  //! @param[in]  token  Security access &token for authentication
  void DLR_clientSetAuthToken(DLR_CLIENT client, const char* token);

  //! returns persistent security access token for authentication
  //! @param[in]  client    Reference to the client
  //| @return security access token for authentication
  const char* DLR_clientGetAuthToken(DLR_CLIENT client);

#ifdef __cplusplus
}
#endif
