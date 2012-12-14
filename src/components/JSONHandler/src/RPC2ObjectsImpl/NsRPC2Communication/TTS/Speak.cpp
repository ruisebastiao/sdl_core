#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/TTS/Speak.h"
#include "../src/../include/JSONHandler/RPC2Objects/Marshaller.h"

/*
  interface	NsRPC2Communication::TTS
  version	1.2
  generated at	Fri Dec 14 06:14:25 2012
  source stamp	Fri Dec 14 06:14:23 2012
  author	robok0der
*/

using namespace NsRPC2Communication::TTS;


Speak& Speak::operator =(const Speak& c)
{
  ttsChunks=c.ttsChunks;
  appId=c.appId;
  return *this;
}


Speak::~Speak(void)
{
}


Speak::Speak(void) : 
  RPC2Request(Marshaller::METHOD_NSRPC2COMMUNICATION_TTS__SPEAK)
{
}


Speak::Speak(const Speak& c) : RPC2Request(Marshaller::METHOD_NSRPC2COMMUNICATION_TTS__SPEAK,c.getId())
{
  *this=c;
}


const std::vector< NsAppLinkRPC::TTSChunk>& Speak::get_ttsChunks(void)
{
  return ttsChunks;
}

bool Speak::set_ttsChunks(const std::vector< NsAppLinkRPC::TTSChunk>& ttsChunks_)
{
  ttsChunks=ttsChunks_;
  return true;
}

int Speak::get_appId(void)
{
  return appId;
}

bool Speak::set_appId(int appId_)
{
  appId=appId_;
  return true;
}

bool Speak::checkIntegrity(void)
{
  return SpeakMarshaller::checkIntegrity(*this);
}
