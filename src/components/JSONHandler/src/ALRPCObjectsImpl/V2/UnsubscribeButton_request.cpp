#include "../include/JSONHandler/ALRPCObjects/V2/UnsubscribeButton_request.h"
#include "UnsubscribeButton_requestMarshaller.h"
#include "../include/JSONHandler/ALRPCObjects/V2/Marshaller.h"
#include "ButtonNameMarshaller.h"

#define PROTOCOL_VERSION	2


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Dec 13 14:18:29 2012
  source stamp	Thu Dec 13 14:18:27 2012
  author	robok0der
*/

using namespace NsAppLinkRPCV2;

UnsubscribeButton_request::~UnsubscribeButton_request(void)
{
}


UnsubscribeButton_request::UnsubscribeButton_request(const UnsubscribeButton_request& c) : NsAppLinkRPC::ALRPCMessage(c)
{
  *this=c;
}


bool UnsubscribeButton_request::checkIntegrity(void)
{
  return UnsubscribeButton_requestMarshaller::checkIntegrity(*this);
}


UnsubscribeButton_request::UnsubscribeButton_request(void) : NsAppLinkRPC::ALRPCMessage(PROTOCOL_VERSION)
{
}



bool UnsubscribeButton_request::set_buttonName(const ButtonName& buttonName_)
{
  if(!ButtonNameMarshaller::checkIntegrityConst(buttonName_))   return false;
  buttonName=buttonName_;
  return true;
}




const ButtonName& UnsubscribeButton_request::get_buttonName(void) const 
{
  return buttonName;
}

