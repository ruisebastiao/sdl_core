#ifndef NSAPPLINKRPCV2_LISTFILES_RESPONSEMARSHALLER_INCLUDE
#define NSAPPLINKRPCV2_LISTFILES_RESPONSEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/V2/ListFiles_response.h"


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

  struct ListFiles_responseMarshaller
  {
    static bool checkIntegrity(ListFiles_response& e);
    static bool checkIntegrityConst(const ListFiles_response& e);
  
    static bool fromString(const std::string& s,ListFiles_response& e);
    static const std::string toString(const ListFiles_response& e);
  
    static bool fromJSON(const Json::Value& s,ListFiles_response& e);
    static Json::Value toJSON(const ListFiles_response& e);
  };
}

#endif
