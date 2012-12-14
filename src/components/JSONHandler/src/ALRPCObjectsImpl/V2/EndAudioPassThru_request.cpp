#include "../include/JSONHandler/ALRPCObjects/V2/EndAudioPassThru_request.h"
#include "EndAudioPassThru_requestMarshaller.h"
#include "../include/JSONHandler/ALRPCObjects/V2/Marshaller.h"

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

EndAudioPassThru_request::~EndAudioPassThru_request(void)
{
}


EndAudioPassThru_request::EndAudioPassThru_request(const EndAudioPassThru_request& c) : NsAppLinkRPC::ALRPCMessage(c)
{
  *this=c;
}


bool EndAudioPassThru_request::checkIntegrity(void)
{
  return EndAudioPassThru_requestMarshaller::checkIntegrity(*this);
}


EndAudioPassThru_request::EndAudioPassThru_request(void) : NsAppLinkRPC::ALRPCMessage(PROTOCOL_VERSION)
{
}






