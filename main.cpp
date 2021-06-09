/**
 * MIT License
 * 
 * Copyright (c) 2020, Bosch Rexroth AG
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
 

// The example app datalayer.register.node creates a new provider 
// with node 'myData' and different type elements to the ctrlX Data Layer.

#include "comm/datalayer/datalayer.h"
#include "comm/datalayer/datalayer_system.h"
#include "comm/datalayer/metadata_generated.h"
#include <iostream>
#include <signal.h>
#include "comm/datalayer/variant.h"
#include <thread>
#include "lib/arm/libplctag.h"
#include<string>
#include<map>
#include<vector>

#include "sampleSchema_generated.h"

class ABTag 
{
  public: 
  int32_t tag;
  std::string path;
  comm::datalayer::VariantType type;
  comm::datalayer::Variant datalayerVariable;
  ABTag(std::string name, comm::datalayer::VariantType type)
  {
    this->path = name;
    this-> type = type;
  }
};


//#define TAG_PATH "protocol=ab_eip&gateway=192.168.0.70&path=1,0&cpu=LGX&elem_size=4&elem_count=10&name=myDINTArray"
//#define TAG_PATH "protocol=ab_eip&gateway=192.168.0.70&path=1,0&cpu=LGX&name=SinCounter"
//#define DATA_TIMEOUT 5000

// Add some signal Handling so we are able to abort the program with sending sigint
bool endProcess = false;
static void sigHandler (int sig, siginfo_t *siginfo, void *context)
{
  endProcess = true;
}

int32_t tag = 0;
int rc;
std::map<std::string, int> tagMap;
std::map<std::string, ABTag> ABtagMap;
using comm::datalayer::IProviderNode;

// Basic class Provider node interface for providing data to the system
class MyProviderNode : public IProviderNode {
public:
  MyProviderNode(comm::datalayer::Variant value)
  {
    m_data = value;
  };
  virtual ~MyProviderNode() override
  {};

  // Create function of an object. Function will be called whenever a object should be created.
  virtual void onCreate(const std::string &address, const comm::datalayer::Variant* data, const comm::datalayer::IProviderNode::ResponseCallback &callback) override
  {
    callback(comm::datalayer::DlResult::DL_FAILED, nullptr);
  }

  // Read function of a node. Function will be called whenever a node should be read.
  virtual void onRead(const std::string &address, const comm::datalayer::Variant* data, const comm::datalayer::IProviderNode::ResponseCallback &callback) override
  {
    comm::datalayer::Variant result;
    result = m_data;
    //int rc;
    tag = (int32_t)tagMap[address];
      if(rc = plc_tag_status(tag) != PLCTAG_STATUS_OK)
      {
        std::cout << "Error setting up tag internal state for "<< address << "with Error: "<< plc_tag_decode_error(rc) << std::endl;
      }
      else
      {
        rc = plc_tag_read(tag, 5000);
        if(rc != PLCTAG_STATUS_OK) 
        {
          std::cout << "ERROR: Unable to read the data for variable " << address << "with error code: "<< plc_tag_decode_error(rc) << std::endl;
        }
        else
        {
        //result.setValue(plc_tag_get_float32((int32_t)tagMap[address], 0));
          //std::cout << "About to write the type " << result.typeAsString() << std::endl;
          ::comm::datalayer::VariantType dataType = result.getType();
          switch (dataType)
          {
            case ::comm::datalayer::VariantType::BOOL8:
            //  std::cout << "Bool8 type" << std::endl;
              result.setValue(plc_tag_get_bit(tag, 0));     
              break;
            case ::comm::datalayer::VariantType::INT8:
            //  std::cout << "INT8 type" << std::endl;
              result.setValue(plc_tag_get_int8(tag, 0));     
              break;
            case ::comm::datalayer::VariantType::UINT8:
            //  std::cout << "UINT8 type" << std::endl;
              result.setValue(plc_tag_get_uint8(tag, 0));              
              break;
            case ::comm::datalayer::VariantType::INT16: 
            //  std::cout << "INT16 type" << std::endl;
              result.setValue(plc_tag_get_int16(tag, 0));                 
              break;
            case ::comm::datalayer::VariantType::UINT16:  
            //  std::cout << "UINT16 type" << std::endl;
              result.setValue(plc_tag_get_uint16(tag, 0));                
              break;
            case ::comm::datalayer::VariantType::INT32:
            //  std::cout << "INT32 type" << std::endl;
              result.setValue(plc_tag_get_int32(tag, 0));           
              break;
            case ::comm::datalayer::VariantType::UINT32:
            //  std::cout << "UINT32 type" << std::endl;
              result.setValue(plc_tag_get_uint32(tag, 0));                   
              break;
            case ::comm::datalayer::VariantType::INT64:   
            //  std::cout << "INT64 type" << std::endl;
              result.setValue(plc_tag_get_int64(tag, 0));           
              break;
            case ::comm::datalayer::VariantType::UINT64:  
            //  std::cout << "UINT64 type" << std::endl;
              result.setValue(plc_tag_get_uint64(tag, 0));          
              break;
            case ::comm::datalayer::VariantType::FLOAT32: 
            //  std::cout << "FLOAT32 type" << std::endl;     
              result.setValue(plc_tag_get_float32(tag, 0));
              break;
            case ::comm::datalayer::VariantType::FLOAT64:  
            //  std::cout << "FLOAT64 type" << std::endl;         
              result.setValue(plc_tag_get_float32(tag, 0));
              break;
            case ::comm::datalayer::VariantType::STRING: 
            //  std::cout << "STRING type" << std::endl;
              char temp[100];
              plc_tag_get_string(tag, 0, temp, 100);
              result.setValue(temp);
              break;
            default:
              std::cout << "Unknown Type" << std::endl;
          }
        }
      }
    callback(comm::datalayer::DlResult::DL_OK, &result);
  }

  // Write function of a node. Function will be called whenever a node should be written.
  virtual void onWrite(const std::string &address, const comm::datalayer::Variant* data, const comm::datalayer::IProviderNode::ResponseCallback &callback) override
  {
    std::cout << "About to write the type " << data->typeAsString() << std::endl;
    if (data->getType() == m_data.getType())
    {
      m_data = *data;
      int32_t tag = (int32_t)tagMap[address];
      if(rc = plc_tag_status(tag) != PLCTAG_STATUS_OK)
      {
        std::cout << "Error setting up tag internal state for "<< address << "with Error: "<< plc_tag_decode_error(rc) << std::endl;
      }
      else
      {
        //result.setValue(plc_tag_get_float32((int32_t)tagMap[address], 0));
          std::cout << "About to write the type " << m_data.typeAsString() << std::endl;
          ::comm::datalayer::VariantType dataType = m_data.getType();
          uint8_t* setData = m_data.getData();
          switch (dataType) 
          {
            case ::comm::datalayer::VariantType::BOOL8:
              std::cout << "write Bool8 type =" << *(bool*)setData << std::endl;
              plc_tag_set_bit(tag, 0, *(bool*)setData);    
              break;
            case ::comm::datalayer::VariantType::INT8:
              std::cout << "write INT8 type =" << *(int8_t*)setData << std::endl;
              plc_tag_set_int8(tag, 0, *(int8_t*)setData);   
              break;
            case ::comm::datalayer::VariantType::UINT8:
              std::cout << "write UINT8 type =" << *(uint8_t*)setData << std::endl;
              plc_tag_set_uint8(tag, 0, *(uint8_t*)setData);            
              break;
            case ::comm::datalayer::VariantType::INT16: 
              std::cout << "write INT16 type =" << *(int16_t*)setData << std::endl;
              plc_tag_set_int16(tag, 0, *(int16_t*)setData);                  
              break;
            case ::comm::datalayer::VariantType::UINT16:  
              std::cout << "write UINT16 type =" << *(uint16_t*)setData << std::endl;
              plc_tag_set_uint16(tag, 0, *(uint16_t*)setData);            
              break;
            case ::comm::datalayer::VariantType::INT32:
              std::cout << "write INT32 type =" << *(int32_t*)setData << std::endl;
              plc_tag_set_int32(tag, 0, *(int32_t*)setData); 
              break;
            case ::comm::datalayer::VariantType::UINT32:
              std::cout << "write UINT32 type =" << *(uint32_t*)setData << std::endl;
              plc_tag_set_uint32(tag, 0, *(uint32_t*)setData);                   
              break;
            case ::comm::datalayer::VariantType::INT64:   
              std::cout << "write INT64 type =" << *(int64_t*)setData << std::endl;
              plc_tag_set_int64(tag, 0, *(int64_t*)setData); 
              break;
            case ::comm::datalayer::VariantType::UINT64:  
              std::cout << "write UINT64 type =" <<  *(uint64_t*)setData << std::endl;
              plc_tag_set_uint64(tag, 0, *(uint64_t*)setData); 
              break;
            case ::comm::datalayer::VariantType::FLOAT32: 
              std::cout << "write FLOAT32 type =" << *(_Float32*)setData << std::endl;
              plc_tag_set_float32(tag, 0, *(_Float32*)setData);   
              break;
            case ::comm::datalayer::VariantType::FLOAT64:  
              std::cout << "write FLOAT64 type =" << *(_Float64*)setData << std::endl;         
              plc_tag_set_float64(tag, 0, *(_Float64*)setData);   
              break;
            case ::comm::datalayer::VariantType::STRING: 
              std::cout << "write STRING type" << *(const char*)setData << std::endl;
              //const char* temp;// = (char[])*setData;
              //temp = (const char*)setData;
              plc_tag_set_string(tag, 0, (const char*)setData);
              //plc_tag_get_string((int32_t)tagMap[address], 0, temp, 100);

              break;
            default:
              std::cout << "Unknown Type" << std::endl;
          }
          rc = plc_tag_write(tag, 5000);
          if(rc != PLCTAG_STATUS_OK) 
          {
          std::cout << "ERROR: Unable to read the data for variable " << address << "with error code: "<< plc_tag_decode_error(rc) << std::endl;
          }
      } 
      callback(comm::datalayer::DlResult::DL_OK, data);
    }
    else
    {
      callback(comm::datalayer::DlResult::DL_TYPE_MISMATCH, nullptr);
    }
  }


  // Remove function for an object. Function will be called whenever a object should be removed.
  virtual void onRemove(const std::string &address, const comm::datalayer::IProviderNode::ResponseCallback &callback) override
  {
   // plc_tag_destroy(tag);
    callback(comm::datalayer::DlResult::DL_FAILED, nullptr);
  }

  // Browse function of a node. Function will be called to determine children of a node.
  virtual void onBrowse(const std::string &address, const comm::datalayer::IProviderNode::ResponseCallback &callback) override
  {
    callback(comm::datalayer::DlResult::DL_FAILED, nullptr);
  }

  // Read function of metadata of an object. Function will be called whenever a node should be written.
  virtual void onMetadata(const std::string &address, const comm::datalayer::IProviderNode::ResponseCallback &callback) override
  {
    flatbuffers::FlatBufferBuilder builder;
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<comm::datalayer::Reference>>> references;
    auto emptyString = builder.CreateString("This is a Description");

    if (address.compare("myData/myFlatbuffer") == 0)
    {
      flatbuffers::Offset<comm::datalayer::Reference> vecReferences[] =
      {
        comm::datalayer::CreateReferenceDirect(builder, "readType", "types/sampleSchema/inertialValue"),
      };

      references = builder.CreateVectorOfSortedTables(vecReferences, 1);
    }

    // Set allowed operations
    comm::datalayer::AllowedOperationsBuilder allowedOperations(builder);
    allowedOperations.add_read(true);
    allowedOperations.add_write(false);
    allowedOperations.add_create(true);
    allowedOperations.add_delete_(false);
    auto operations = allowedOperations.Finish();

    // Create metadata
    comm::datalayer::MetadataBuilder metadata(builder);
    metadata.add_description(emptyString);
    metadata.add_descriptionUrl(emptyString);
    metadata.add_operations(operations);
    if (address.compare("myData/myFlatbuffer") == 0)
    {
      metadata.add_references(references);
    }
    auto metaFinished = metadata.Finish();
    builder.Finish(metaFinished);

    comm::datalayer::Variant variant;
    variant.shareFlatbuffers(builder);
    callback(comm::datalayer::DlResult::DL_OK, &variant);
  }
  
private:
  comm::datalayer::Variant m_data;
};


int main(int ac, char* av[])
{
#ifdef MY_DEBUG
  raise(SIGSTOP);
#endif

comm::datalayer::DatalayerSystem datalayer;
comm::datalayer::DlResult result;

// Starts the ctrlX Data Layer system without a new broker because one broker is already running on ctrlX device
datalayer.start(false);

// Creates a provider at Data Layer backend to provide data to Data Layer clients
comm::datalayer::IProvider *myProvider = datalayer.factory()->createProvider(DL_IPC_AUTO);//"tcp://boschrexroth:boschrexroth@192.168.1.16:2070"); //or "tcp://boschrexroth:boschrexroth@192.168.1.1:2070

/*Define what data to look at*/
std::vector<std::string> tagNames;
std::vector<comm::datalayer::VariantType> tagTypes;
std::vector<ABTag> abTags;
tagNames.push_back("SinCounter");
tagTypes.push_back(comm::datalayer::VariantType::FLOAT32);
tagNames.push_back("myLINT");
tagTypes.push_back(comm::datalayer::VariantType::INT64);
tagNames.push_back("Line1_OEE");
tagTypes.push_back(comm::datalayer::VariantType::FLOAT32);
tagNames.push_back("mySINReflection");
tagTypes.push_back(comm::datalayer::VariantType::FLOAT32);
tagNames.push_back("MyString");
tagTypes.push_back(comm::datalayer::VariantType::STRING);

abTags.push_back(ABTag("SinCounter", comm::datalayer::VariantType::FLOAT32));
abTags.push_back(ABTag("myLINT", comm::datalayer::VariantType::INT64));
abTags.push_back(ABTag("Line1_OEE", comm::datalayer::VariantType::FLOAT32));
abTags.push_back(ABTag("mySINReflection", comm::datalayer::VariantType::FLOAT32));
abTags.push_back(ABTag("MyString", comm::datalayer::VariantType::STRING));

//std::string activeData;
for (int i = 0; i < abTags.size(); i++)
{
  //tempString = ("protocol=ab_eip&gateway=192.168.0.70&path=1,0&cpu=LGX&name=" + tagNames[i]);
  tag = plc_tag_create(("protocol=ab_eip&gateway=192.168.0.70&path=1,0&cpu=LGX&name=" + abTags[i].path).c_str(), 5000);
  if (tag < 0)
  {
    std::cout << "ERROR: Could not create tag "<< abTags[i].path << std::endl;
  }
  else
  {
    if((rc = plc_tag_status(tag)) != PLCTAG_STATUS_OK) 
    {
        std::cout << "Error setting up tag internal state for " << abTags[i].path << ". Error: " << plc_tag_decode_error(rc) << std::endl;
        plc_tag_destroy(tag);
    }
    else
    {
      int temp = (int)tag;
      tagMap.insert(std::make_pair("myData/" + abTags[i].path, temp));
      ABtagMap.insert(std::make_pair("myData/" + abTags[i].path, abTags[i]));

      abTags[i].datalayerVariable.setType(abTags[i].type);
      result = myProvider->registerNode("myData/" + abTags[i].path, new MyProviderNode(abTags[i].datalayerVariable));
      if(STATUS_FAILED(result))
      {
        std::cout << "Register node 'myData/" << abTags[i].path << "' failed with: " << result.toString() << std::endl;
      }
      else
      {
        std::cout << "Register node 'myData/" << abTags[i].path <<"' was successful!" << std::endl;
      }
    }
  }
  

}
/*
 // tag = plc_tag_create("protocol=ab_eip&gateway=192.168.0.70&path=1,0&cpu=LGX&name=SinCounter", 5000);
  if (tag < 0){
    std::cout << "FOURAKER - ERROR: Could not create tag!"<< std::endl;
  }

  if((rc = plc_tag_status(tag)) != PLCTAG_STATUS_OK) {
       std::cout << "FOURAKER - Error setting up tag internal state. Error"<< std::endl;
        plc_tag_destroy(tag);
    }
  else
  {
    int temp = (int)tag;
    tagMap.insert(std::make_pair("myData/SinCounter", temp));
  }

  tag = plc_tag_create("protocol=ab_eip&gateway=192.168.0.70&path=1,0&cpu=LGX&name=MyString", 5000);
  if (tag < 0){
    std::cout << "FOURAKER - ERROR: Could not create tag!"<< std::endl;
  }

  if((rc = plc_tag_status(tag)) != PLCTAG_STATUS_OK) {
       std::cout << "FOURAKER - Error setting up tag internal state. Error"<< std::endl;
    }
  else
  {
    int temp2 = (int)tag;
    tagMap.insert(std::make_pair("myData/MyString", temp2));
  }

  tag = plc_tag_create("protocol=ab_eip&gateway=192.168.0.70&path=1,0&cpu=LGX&name=myLINT", 5000);
  if (tag < 0){
    std::cout << "FOURAKER - ERROR: Could not create tag!"<< std::endl;
  }

  if((rc = plc_tag_status(tag)) != PLCTAG_STATUS_OK) {
       std::cout << "FOURAKER - Error setting up tag internal state. Error"<< std::endl;
    }
  else
  {
    int temp2 = (int)tag;
    tagMap.insert(std::make_pair("myData/myLINT", temp2));
  }
  plc_tag_set_int64(tag, 0, 987654321);
  plc_tag_write(tag, 5000);
*/
  /* get the data */
 /*   rc = plc_tag_read(tag, 5000);
    if(rc != PLCTAG_STATUS_OK) {
        std::cout << "FOURAKER - ERROR: Unable to read the data! Got error code"<< std::endl;
        //fprintf(stderr,"ERROR: Unable to read the data! Got error code %d: %s\n",rc, plc_tag_decode_error(rc));
        plc_tag_destroy(tag);*
        return 0;
    }
  float readValue = plc_tag_get_float32(tag, 0);
  std::cout << "FOURAKER - SUCCESS: Data "<< readValue << std::endl;
*/

  // Starts the ctrlX Data Layer system without a new broker because one broker is already running on ctrlX device
 // datalayer.start(false);
  //std::cout << "Register 'myData' as root element with 4 nodes 'myFlatbuffer', 'myFloat', 'myString' and 'myInt64'" << std::endl;
  
  // Creates a provider at Data Layer backend to provide data to Data Layer clients
  //comm::datalayer::IProvider *myProvider = datalayer.factory()->createProvider(DL_IPC_AUTO);//"tcp://boschrexroth:boschrexroth@192.168.1.16:2070"); //or "tcp://boschrexroth:boschrexroth@192.168.1.1:2070

  // Create some simple dummy data
  /*comm::datalayer::Variant SinCounter;
  SinCounter.setValue((_Float32)0.0);
  SinCounter.setType(::comm::datalayer::VariantType::FLOAT32, 4);
  comm::datalayer::Variant MyString;
  MyString.setValue("Hello ctrlX AUTOMATION sample string");
  comm::datalayer::Variant myLINT;
  myLINT.setValue((int64_t)0);

  // Register a node as string value
  result = myProvider->registerNode("myData/MyString", new MyProviderNode(MyString));
  if(STATUS_FAILED(result))
  {
    std::cout << "Register node 'myData/MyString' failed with: " << result.toString() << std::endl;
  }
  else
  {
    std::cout << "Register node 'myData/MyString' was successful!" << std::endl;
  }

  result = myProvider->registerNode("myData/myLINT", new MyProviderNode(myLINT));
  if(STATUS_FAILED(result))
  {
    std::cout << "Register node 'myData/myLINT' failed with: " << result.toString() << std::endl;
  }
  else
  {
    std::cout << "Register node 'myData/myLINT' was successful!" << std::endl;
  }

  // Register a node as float value
  result = myProvider->registerNode("myData/SinCounter", new MyProviderNode(SinCounter));
  if(STATUS_FAILED(result))
  {
    std::cout << "Register node 'myData/SinCounter' failed with: " << result.toString() << std::endl;
  }
  else
  {
    std::cout << "Register node 'myData/SinCounter' was successful!" << std::endl;
  }
*/
  // Start to add Code here to register more nodes
  // Start your ctrlX Data Layer provider
  result = myProvider->start();
  if (STATUS_FAILED(result))
  {
    std::cout << "Starting the Data Layer provider failed with: " << result.toString() << std::endl;
    // If the provider could not be started exit the program
    return -1;
  }
  else
  {
    std::cout << "Provider was started!" << std::endl;
  } 

  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  if (!myProvider->isConnected())
  {
    std::cout << "Failed to connect to Data Layer broker!" << std::endl;
    return -1;
  }

  // Prepare signal structure to interrupt the endless loop with ctrl + c 
  struct sigaction act;
  memset (&act, '\0', sizeof(act));
  act.sa_sigaction = &sigHandler;
  act.sa_flags = SA_SIGINFO;
  sigaction(SIGINT, &act, NULL);
  
  do
  {
    /* code */
    // Time to interrupt this thread for lower cpu utilization
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  } while (!endProcess);

  // Unregister type and nodes
  //myProvider->unregisterType("types/sampleSchema/inertialValue");
  //myProvider->unregisterNode("myData/myFlatbuffer");
  for (auto key = tagMap.begin(); key != tagMap.end(); ++key)
    {
    myProvider->unregisterNode(key->first);    
    }
  //myProvider->unregisterNode("myData/MyString");
  //myProvider->unregisterNode("myData/SinCounter");
  //myProvider->unregisterNode("myData/myLINT");
  //myProvider->unregisterNode("myData/myInt64");
  std::cout << std::endl << "Provider type and nodes were unregistered!" << std::endl;

  // Stop Datalayer Provider
  myProvider->stop();
  std::cout << "Provider was stopped!" << std::endl;
  // Delete it to free your memory
  delete myProvider;
  std::cout << "Provider was deleted!" << std::endl;
}