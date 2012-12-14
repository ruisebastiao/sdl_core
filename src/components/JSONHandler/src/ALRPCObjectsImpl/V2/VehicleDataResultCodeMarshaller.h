#ifndef NSAPPLINKRPCV2_VEHICLEDATARESULTCODEMARSHALLER_INCLUDE
#define NSAPPLINKRPCV2_VEHICLEDATARESULTCODEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "PerfectHashTable.h"

#include "../include/JSONHandler/ALRPCObjects/V2/VehicleDataResultCode.h"


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

//! marshalling class for VehicleDataResultCode

  class VehicleDataResultCodeMarshaller
  {
  public:
  
    static std::string toName(const VehicleDataResultCode& e) 	{ return getName(e.mInternal) ?: ""; }
  
    static bool fromName(VehicleDataResultCode& e,const std::string& s)
    { 
      return (e.mInternal=getIndex(s.c_str()))!=VehicleDataResultCode::INVALID_ENUM;
    }
  
    static bool checkIntegrity(VehicleDataResultCode& e)		{ return e.mInternal!=VehicleDataResultCode::INVALID_ENUM; } 
    static bool checkIntegrityConst(const VehicleDataResultCode& e)	{ return e.mInternal!=VehicleDataResultCode::INVALID_ENUM; } 
  
    static bool fromString(const std::string& s,VehicleDataResultCode& e);
    static const std::string toString(const VehicleDataResultCode& e);
  
    static bool fromJSON(const Json::Value& s,VehicleDataResultCode& e);
    static Json::Value toJSON(const VehicleDataResultCode& e);
  
    static const char* getName(VehicleDataResultCode::VehicleDataResultCodeInternal e)
    {
       return (e>=0 && e<8) ? mHashTable[e].name : NULL;
    }
  
    static const VehicleDataResultCode::VehicleDataResultCodeInternal getIndex(const char* s);
  
    static const PerfectHashTable mHashTable[8];
  };
  
}

#endif
