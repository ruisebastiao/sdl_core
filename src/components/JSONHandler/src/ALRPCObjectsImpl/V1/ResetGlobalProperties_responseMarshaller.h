#ifndef NSAPPLINKRPC_RESETGLOBALPROPERTIES_RESPONSEMARSHALLER_INCLUDE
#define NSAPPLINKRPC_RESETGLOBALPROPERTIES_RESPONSEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/V1/ResetGlobalProperties_response.h"


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Thu Dec 13 13:37:09 2012
  source stamp	Thu Dec 13 13:33:23 2012
  author	robok0der
*/

namespace NsAppLinkRPC
{

  struct ResetGlobalProperties_responseMarshaller
  {
    static bool checkIntegrity(ResetGlobalProperties_response& e);
    static bool checkIntegrityConst(const ResetGlobalProperties_response& e);
  
    static bool fromString(const std::string& s,ResetGlobalProperties_response& e);
    static const std::string toString(const ResetGlobalProperties_response& e);
  
    static bool fromJSON(const Json::Value& s,ResetGlobalProperties_response& e);
    static Json::Value toJSON(const ResetGlobalProperties_response& e);
  };
}

#endif
