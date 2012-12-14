#ifndef NSAPPLINKRPCV2_TURNMARSHALLER_INCLUDE
#define NSAPPLINKRPCV2_TURNMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/V2/Turn.h"


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

  struct TurnMarshaller
  {
    static bool checkIntegrity(Turn& e);
    static bool checkIntegrityConst(const Turn& e);
  
    static bool fromString(const std::string& s,Turn& e);
    static const std::string toString(const Turn& e);
  
    static bool fromJSON(const Json::Value& s,Turn& e);
    static Json::Value toJSON(const Turn& e);
  };
}

#endif
