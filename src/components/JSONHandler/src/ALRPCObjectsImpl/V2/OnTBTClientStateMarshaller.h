#ifndef NSAPPLINKRPCV2_ONTBTCLIENTSTATEMARSHALLER_INCLUDE
#define NSAPPLINKRPCV2_ONTBTCLIENTSTATEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/V2/OnTBTClientState.h"


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

  struct OnTBTClientStateMarshaller
  {
    static bool checkIntegrity(OnTBTClientState& e);
    static bool checkIntegrityConst(const OnTBTClientState& e);
  
    static bool fromString(const std::string& s,OnTBTClientState& e);
    static const std::string toString(const OnTBTClientState& e);
  
    static bool fromJSON(const Json::Value& s,OnTBTClientState& e);
    static Json::Value toJSON(const OnTBTClientState& e);
  };
}

#endif
