#ifndef NSAPPLINKRPCV2_ONAUDIOPASSTHRUMARSHALLER_INCLUDE
#define NSAPPLINKRPCV2_ONAUDIOPASSTHRUMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/V2/OnAudioPassThru.h"


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

  struct OnAudioPassThruMarshaller
  {
    static bool checkIntegrity(OnAudioPassThru& e);
    static bool checkIntegrityConst(const OnAudioPassThru& e);
  
    static bool fromString(const std::string& s,OnAudioPassThru& e);
    static const std::string toString(const OnAudioPassThru& e);
  
    static bool fromJSON(const Json::Value& s,OnAudioPassThru& e);
    static Json::Value toJSON(const OnAudioPassThru& e);
  };
}

#endif
