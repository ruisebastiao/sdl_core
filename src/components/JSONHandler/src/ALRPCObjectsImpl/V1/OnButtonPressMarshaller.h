#ifndef NSAPPLINKRPC_ONBUTTONPRESSMARSHALLER_INCLUDE
#define NSAPPLINKRPC_ONBUTTONPRESSMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/V1/OnButtonPress.h"


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

  struct OnButtonPressMarshaller
  {
    static bool checkIntegrity(OnButtonPress& e);
    static bool checkIntegrityConst(const OnButtonPress& e);
  
    static bool fromString(const std::string& s,OnButtonPress& e);
    static const std::string toString(const OnButtonPress& e);
  
    static bool fromJSON(const Json::Value& s,OnButtonPress& e);
    static Json::Value toJSON(const OnButtonPress& e);
  };
}

#endif
