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
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

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
std::map<std::string, int> ptrABtagMap;
std::vector<std::string> tagNames;
std::vector<comm::datalayer::VariantType> tagTypes;
std::vector<ABTag> abTags;
ABTag tempABTag = ABTag("nothing really", comm::datalayer::VariantType::FLOAT32);
using comm::datalayer::IProviderNode;

/*Settings that are defined in the AB.json*/
std::string ABIP;
int64_t UpdateRate;


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
    comm::datalayer::Variant *result;
    tempABTag = abTags[ptrABtagMap[address]];
    result = &(abTags[ptrABtagMap[address]].datalayerVariable);//tempABTag.datalayerVariable;//tempABTag.datalayerVariable;
    callback(comm::datalayer::DlResult::DL_OK, result);
  }

  // Write function of a node. Function will be called whenever a node should be written.
  virtual void onWrite(const std::string &address, const comm::datalayer::Variant* data, const comm::datalayer::IProviderNode::ResponseCallback &callback) override
  {
    //std::cout << "About to write the type " << data->typeAsString() << std::endl;
    //::comm::datalayer::VariantType dataType = m_data.getType();
    
    data->checkConvert(m_data.getType()); 
    if ((data->getType() == m_data.getType()) || (m_data.getType() == ::comm::datalayer::VariantType::BOOL8))
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
        //  std::cout << "About to write the type " << m_data.typeAsString() << std::endl;
          
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
              plc_tag_set_string(tag, 0, (const char*)setData);

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
    comm::datalayer::Variant variant;
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
comm::datalayer::IProvider *myProvider = datalayer.factory()->createProvider(DL_IPC_AUTO);

//write some sample test code:
//std::string filePath = "/var/snap/rexroth-solutions/common/solutions/activeConfiguration/test.txt";
std::string line;
std::string completeFile;
//std::cout << "write " << filePath << std::endl;
//std::ofstream outfile (filePath);
std::string filePath = "/var/snap/rexroth-solutions/common/solutions/activeConfiguration/AB.json";
std::ifstream infile (filePath);
if (infile.is_open())
  {
    while(std::getline(infile, line))
      {
        //std::cout << "read " << line << std::endl; 
        completeFile += line;
      }
    infile.close(); 
    if (completeFile.size() != 0)
    {
      const char* json = completeFile.c_str();
      rapidjson::Document parsedJSON;
      
      rapidjson::ParseResult jsonResultOK = parsedJSON.Parse(json);
      if (jsonResultOK)
      { 
        if (parsedJSON.HasMember("IP")) 
        {
          ABIP = parsedJSON["IP"].GetString();
        }  
        else
        {
          ABIP = "192.168.0.70";
        }
        std::cout << "this is the IP Address of the AB controller: " << ABIP <<std::endl; 
        if (parsedJSON.HasMember("Rate")) 
        {
          UpdateRate = parsedJSON["Rate"].GetInt64();
        } 
        else
        {
           UpdateRate = 2000;
        }
        std::cout << "this is the Update Period of the AB PLC: " << std::to_string(UpdateRate) <<std::endl;   


        if (parsedJSON.HasMember("tag")) 
        {
          rapidjson::Value& tags = parsedJSON["tag"];
          assert(tags.IsArray());
          comm::datalayer::Variant tempVariant;
          for (rapidjson::SizeType i = 0; i < tags.Size(); i++) 
          {
            std::cout << "this is the tag name " << tags[i]["name"].GetString() <<std::endl;
            std::cout << "this is the tag type " << tags[i]["type"].GetString() <<std::endl;
            tagNames.push_back(tags[i]["name"].GetString());
            std::string tempVariantName = tags[i]["type"].GetString(); 
            comm::datalayer::VariantType tempType = tempVariant.getTypeByName(tempVariantName);
            tagTypes.push_back(tempType);
            abTags.push_back(ABTag(tags[i]["name"].GetString(), tempType));
          }
        }
      }
      else
        std::cout << "JSON parse error " << jsonResultOK.Code() << std::endl; 
    }
    std::cout << "read string " << completeFile << std::endl; 
  }
else
  {
    std::cout << "error: " << filePath << std::endl;
  }

//std::string activeData;
for (int i = 0; i < abTags.size(); i++)
{
  //tempString = ("protocol=ab_eip&gateway=192.168.0.70&path=1,0&cpu=LGX&name=" + tagNames[i]);
  tag = plc_tag_create(("protocol=ab_eip&gateway=" + ABIP + "&path=1,0&cpu=LGX&name=" + abTags[i].path).c_str(), 5000);
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
      abTags[i].tag = tag;
      tagMap.insert(std::make_pair("AB/" + abTags[i].path, temp));
      ABtagMap.insert(std::make_pair("AB/" + abTags[i].path, abTags[i]));
      ptrABtagMap.insert(std::make_pair("AB/" + abTags[i].path, i));//&abTags[i])))
      abTags[i].datalayerVariable.setType(abTags[i].type);
      result = myProvider->registerNode("AB/" + abTags[i].path, new MyProviderNode(abTags[i].datalayerVariable));
      if(STATUS_FAILED(result))
      {
        std::cout << "Register node 'AB/" << abTags[i].path << "' failed with: " << result.toString() << std::endl;
      }
      else
      {
        std::cout << "Register node 'AB/" << abTags[i].path <<"' was successful!" << std::endl;
      }
    }
  }
  

}
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
  
  //std::map<std::string, ABTag>::iterator iterator;// = ABtagMap.begin();
  std::vector<ABTag>::iterator iterator;// = ABtagMap.begin();
  ABTag localTag = ABTag("SinCounter", comm::datalayer::VariantType::FLOAT32);

  do
  {
    /* code */
    // Time to interrupt this thread for lower cpu utilization
    std::this_thread::sleep_for(std::chrono::milliseconds(UpdateRate));
    iterator = abTags.begin();
    while (iterator != abTags.end())
    {
      //std::cout << "Attempting to read "<< localTag.path << std::endl;
      if(rc = plc_tag_status(iterator->tag) != PLCTAG_STATUS_OK)
      {
        std::cout << "Error setting up tag internal state for "<< localTag.path << "with Error: "<< plc_tag_decode_error(rc) << std::endl;
      }
      else
      {
        rc = plc_tag_read(tag, 5000);
        if(rc != PLCTAG_STATUS_OK) 
        {
          std::cout << "ERROR: Unable to read the data for variable " << iterator->path << "with error code: "<< plc_tag_decode_error(rc) << std::endl;
        }
        else
        {
        //result.setValue(plc_tag_get_float32((int32_t)tagMap[address], 0));
          //std::cout << "About to write the type " << result.typeAsString() << std::endl;
          ::comm::datalayer::VariantType dataType = iterator->type;//result.getType();
          tag = iterator->tag;
          switch (dataType)
          {
            case ::comm::datalayer::VariantType::BOOL8:
            //  std::cout << "Bool8 type" << std::endl;
              //result.setValue(plc_tag_get_bit(tag, 0));     
              iterator->datalayerVariable.setValue(plc_tag_get_bit(tag, 0));     
              break;
            case ::comm::datalayer::VariantType::INT8:
            //  std::cout << "INT8 type" << std::endl;
              //result.setValue(plc_tag_get_int8(tag, 0));    
              iterator->datalayerVariable.setValue(plc_tag_get_int8(tag, 0));     
              break;
            case ::comm::datalayer::VariantType::UINT8:
            //  std::cout << "UINT8 type" << std::endl;
              //result.setValue(plc_tag_get_uint8(tag, 0));              
              iterator->datalayerVariable.setValue(plc_tag_get_uint8(tag, 0));             
              break;
            case ::comm::datalayer::VariantType::INT16: 
            //  std::cout << "INT16 type" << std::endl;
              //result.setValue(plc_tag_get_int16(tag, 0));             
              iterator->datalayerVariable.setValue(plc_tag_get_int16(tag, 0));                 
              break;
            case ::comm::datalayer::VariantType::UINT16:  
            //  std::cout << "UINT16 type" << std::endl;
              //result.setValue(plc_tag_get_uint16(tag, 0));                
              iterator->datalayerVariable.setValue(plc_tag_get_uint16(tag, 0));                
              break;
            case ::comm::datalayer::VariantType::INT32:
            //  std::cout << "INT32 type" << std::endl;
              //result.setValue(plc_tag_get_int32(tag, 0));           
              iterator->datalayerVariable.setValue(plc_tag_get_int32(tag, 0));           
              break;
            case ::comm::datalayer::VariantType::UINT32:
            //  std::cout << "UINT32 type" << std::endl;
              //result.setValue(plc_tag_get_uint32(tag, 0));                   
              iterator->datalayerVariable.setValue(plc_tag_get_uint32(tag, 0));                   
              break;
            case ::comm::datalayer::VariantType::INT64:   
            //  std::cout << "INT64 type" << std::endl;
              //result.setValue(plc_tag_get_int64(tag, 0));           
              iterator->datalayerVariable.setValue(plc_tag_get_int64(tag, 0)); 
              //std::cout << "Read " << localTag.path << "= " << *(int64_t*)iterator->datalayerVariable.getData() << std::endl;          
              break;
            case ::comm::datalayer::VariantType::UINT64:  
            //  std::cout << "UINT64 type" << std::endl;
              //result.setValue(plc_tag_get_uint64(tag, 0));         
              iterator->datalayerVariable.setValue(plc_tag_get_uint64(tag, 0));          
              break;
            case ::comm::datalayer::VariantType::FLOAT32: 
            //  std::cout << "FLOAT32 type" << std::endl;     
              //result.setValue(plc_tag_get_float32(tag, 0));
              iterator->datalayerVariable.setValue(plc_tag_get_float32(tag, 0));
              //std::cout << "Read " << localTag.path << "= " << *(_Float32*)iterator->datalayerVariable.getData() << std::endl; 
              //std::cout << "Data in AB variable " << *(_Float32*)(iterator->datalayerVariable.getData()) << std::endl; 
              break;
            case ::comm::datalayer::VariantType::FLOAT64:  
            //  std::cout << "FLOAT64 type" << std::endl;         
              //result.setValue(plc_tag_get_float32(tag, 0));
              iterator->datalayerVariable.setValue(plc_tag_get_float32(tag, 0));
              break;
            case ::comm::datalayer::VariantType::STRING: 
            //  std::cout << "STRING type" << std::endl;
              char temp[100];
              plc_tag_get_string(tag, 0, temp, 100);
              //result.setValue(temp);
              iterator->datalayerVariable.setValue(temp);
              break;
            default:
              std::cout << "Unknown Type" << std::endl;
          }
        }
      }
      //iterator->second = localTag;
      iterator++;
    }

  } while (!endProcess);

  // Unregister type and nodes
  for (auto key = tagMap.begin(); key != tagMap.end(); ++key)
    {
    myProvider->unregisterNode(key->first);    
    }
  std::cout << std::endl << "Provider type and nodes were unregistered!" << std::endl;

  // Stop Datalayer Provider
  myProvider->stop();
  std::cout << "Provider was stopped!" << std::endl;
  // Delete it to free your memory
  delete myProvider;
  std::cout << "Provider was deleted!" << std::endl;
}