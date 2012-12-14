#include "../include/JSONHandler/ALRPCObjects/V2/ParameterPermissions.h"


#include "ParameterPermissionsMarshaller.h"


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Dec 13 14:18:29 2012
  source stamp	Thu Dec 13 14:18:27 2012
  author	robok0der
*/

using namespace NsAppLinkRPCV2;


bool ParameterPermissionsMarshaller::checkIntegrity(ParameterPermissions& s)
{
  return checkIntegrityConst(s);
}


bool ParameterPermissionsMarshaller::fromString(const std::string& s,ParameterPermissions& e)
{
  try
  {
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(s,json,false))  return false;
    if(!fromJSON(json,e))  return false;
  }
  catch(...)
  {
    return false;
  }
  return true;
}


const std::string ParameterPermissionsMarshaller::toString(const ParameterPermissions& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool ParameterPermissionsMarshaller::checkIntegrityConst(const ParameterPermissions& s)
{
  {
    unsigned int i=s.allowed.size();
    if(i>100 || i<0)  return false;
    while(i--)
    {
      if(s.allowed[i].length()>100)  return false;
    }
  }
  {
    unsigned int i=s.userDisallowed.size();
    if(i>100 || i<0)  return false;
    while(i--)
    {
    }
  }
  return true;
}

Json::Value ParameterPermissionsMarshaller::toJSON(const ParameterPermissions& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["allowed"]=Json::Value(Json::arrayValue);
  json["allowed"].resize(e.allowed.size());
  for(unsigned int i=0;i<e.allowed.size();i++)
    json["allowed"][i]=Json::Value(e.allowed[i]);

  json["userDisallowed"]=Json::Value(Json::arrayValue);
  json["userDisallowed"].resize(e.userDisallowed.size());
  for(unsigned int i=0;i<e.userDisallowed.size();i++)
    json["userDisallowed"][i]=Json::Value(e.userDisallowed[i]);


  return json;
}


bool ParameterPermissionsMarshaller::fromJSON(const Json::Value& json,ParameterPermissions& c)
{
  try
  {
    if(!json.isObject())  return false;

    if(!json.isMember("allowed"))  return false;
    {
      const Json::Value& j=json["allowed"];
      if(!j.isArray())  return false;
      c.allowed.resize(j.size());
      for(unsigned int i=0;i<j.size();i++)
        if(!j[i].isString())
          return false;
        else
          c.allowed[i]=j[i].asString();
    }
    if(!json.isMember("userDisallowed"))  return false;
    {
      const Json::Value& j=json["userDisallowed"];
      if(!j.isArray())  return false;
      c.userDisallowed.resize(j.size());
      for(unsigned int i=0;i<j.size();i++)
        if(!j[i].isString())
          return false;
        else
          c.userDisallowed[i]=j[i].asString();
    }

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}

