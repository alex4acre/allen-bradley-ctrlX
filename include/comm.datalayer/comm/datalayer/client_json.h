#pragma once

#include "metadata_helper.h"

//! Namespace for datalayer
namespace comm {
namespace datalayer {

class ClientJson
{
public:
  ClientJson(IClient &client, IFlatbufferJson &converter)
    : m_client(client)
    , m_converter(converter)
  {
  }

  virtual ~ClientJson()
  {
  }

  DlResult readJsonSync(const std::string &addr, std::string &json, std::string *error = nullptr, int32_t indentStep = 0, const std::string &token = "")
  {
    DlResult result;
    Variant type;
    Variant data;

    if (STATUS_FAILED(result = ParseJson(addr, json, data, type, "readType", error, token))) {
      return result;
    }
    if (STATUS_FAILED(result = m_client.readSync(addr, &data, token))) {
      return result;
    }
    if (STATUS_FAILED(result = generateJson(addr, json, data, type, "readType", error, indentStep, token))) {
      return result;
    }

    return result;
  }

  DlResult writeJsonSync(const std::string &addr, std::string &json, std::string *error = nullptr, int32_t indentStep = 0, const std::string &token = "")
  {
    DlResult result;
    Variant type;
    Variant data;

    if (STATUS_FAILED(result = ParseJson(addr, json, data, type, "writeType", error, token))) {
      return result;
    }
    if (STATUS_FAILED(result = m_client.writeSync(addr, &data))) {
      return result;
    }
    if (STATUS_FAILED(result = generateJson(addr, json, data, type, "writeType", error, indentStep, token))) {
      return result;
    }
    return result;
  }



  DlResult createJsonSync(const std::string &addr, std::string &json, std::string *error = nullptr, int32_t indentStep = 0, const std::string &token = "")
  {
    DlResult result;
    Variant type;
    Variant data;

    if (STATUS_FAILED(result = ParseJson(addr, json, data, type, "createType", error, token))) {
      return result;
    }
    if (STATUS_FAILED(result = m_client.createSync(addr, &data))) {
      return result;
    }
    if (STATUS_FAILED(result = generateJson(addr, json, data, type, "createType", error, indentStep, token))) {
      return result;
    }
    return result;
  }

  DlResult ParseJson(const std::string &addr, std::string &json, Variant &data, Variant &type, const std::string &reference, std::string *error, const std::string & token)
  {
    DlResult result = DlResult::DL_OK;
    if (json.length() == 0)
    {
      data.setType(VariantType::UNKNOWN);
      return result;
    }
    if (STATUS_FAILED(result = m_converter.parseJson(json, &data, error)))
    {
      if (STATUS_FAILED(result = MetadataHelper::readReferenceSync(&m_client, addr, reference, &type, token)))
      {
        if (error) { *error = "can't read type"; }
        return result;
      }
      if (STATUS_FAILED(m_converter.parseJson(json, type, &data, error)))
      {
        return result;
      }
    }
    if (error) { *error = ""; }
    return result;
  }

  DlResult generateJson(const std::string &addr, std::string &json, Variant &data, Variant &type, const std::string &reference, std::string *error, int32_t indentStep, const std::string & token)
  {
    DlResult result = DlResult::DL_OK;
    if (data.getType() != VariantType::UNKNOWN)
    {
      if (STATUS_FAILED(m_converter.generateJson(data, &json, indentStep)))
      {
        if (type.getType() == VariantType::UNKNOWN)
        {
          if (STATUS_FAILED(result = MetadataHelper::readReferenceSync(&m_client, addr, reference, &type, token)))
          {
            if (error) { *error = "can't read type"; }
            return result;
          }
        }
        if (STATUS_SUCCEEDED(result = m_converter.generateJson(data, type, &json, indentStep)))
        {
          if (error) { *error = "unable to generate json"; }
          return result;
        }
      }
    }
    if (error) { *error = ""; }
    return result;
  }

protected:
private:
  IClient &m_client;
  IFlatbufferJson &m_converter;
};

}
}
