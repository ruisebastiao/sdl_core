#ifndef NSAPPLINKRPCV2_DELETEINTERACTIONCHOICESET_RESPONSEMARSHALLER_INCLUDE
#define NSAPPLINKRPCV2_DELETEINTERACTIONCHOICESET_RESPONSEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/ALRPCObjects/V2/DeleteInteractionChoiceSet_response.h"


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

  struct DeleteInteractionChoiceSet_responseMarshaller
  {
    static bool checkIntegrity(DeleteInteractionChoiceSet_response& e);
    static bool checkIntegrityConst(const DeleteInteractionChoiceSet_response& e);
  
    static bool fromString(const std::string& s,DeleteInteractionChoiceSet_response& e);
    static const std::string toString(const DeleteInteractionChoiceSet_response& e);
  
    static bool fromJSON(const Json::Value& s,DeleteInteractionChoiceSet_response& e);
    static Json::Value toJSON(const DeleteInteractionChoiceSet_response& e);
  };
}

#endif
