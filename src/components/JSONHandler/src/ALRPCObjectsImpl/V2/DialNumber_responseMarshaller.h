#ifndef NSAPPLINKRPCV2_DIALNUMBER_RESPONSEMARSHALLER_INCLUDE
#define NSAPPLINKRPCV2_DIALNUMBER_RESPONSEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/V2/DialNumber_response.h"


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Dec 13 14:18:29 2012
  source stamp	Thu Dec 13 14:18:27 2012
  author	robok0der
*/

namespace NsAppLinkRPCV2
{

  struct DialNumber_responseMarshaller
  {
    static bool checkIntegrity(DialNumber_response& e);
    static bool checkIntegrityConst(const DialNumber_response& e);
  
    static bool fromString(const std::string& s,DialNumber_response& e);
    static const std::string toString(const DialNumber_response& e);
  
    static bool fromJSON(const Json::Value& s,DialNumber_response& e);
    static Json::Value toJSON(const DialNumber_response& e);
  };
}

#endif
