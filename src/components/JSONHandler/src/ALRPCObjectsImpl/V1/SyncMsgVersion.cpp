#include "../include/JSONHandler/ALRPCObjects/V1/SyncMsgVersion.h"
#include "SyncMsgVersionMarshaller.h"

/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Thu Dec 13 13:37:09 2012
  source stamp	Thu Dec 13 13:33:23 2012
  author	robok0der
*/



using namespace NsAppLinkRPC;

SyncMsgVersion::SyncMsgVersion(const SyncMsgVersion& c)
{
  *this=c;
}


bool SyncMsgVersion::checkIntegrity(void)
{
  return SyncMsgVersionMarshaller::checkIntegrity(*this);
}


SyncMsgVersion::SyncMsgVersion(void)
{
}



bool SyncMsgVersion::set_majorVersion(unsigned int majorVersion_)
{
  if(majorVersion_>1)  return false;
  if(majorVersion_<1)  return false;
  majorVersion=majorVersion_;
  return true;
}

bool SyncMsgVersion::set_minorVersion(unsigned int minorVersion_)
{
  if(minorVersion_>1000)  return false;
  minorVersion=minorVersion_;
  return true;
}




unsigned int SyncMsgVersion::get_majorVersion(void) const
{
  return majorVersion;
}


unsigned int SyncMsgVersion::get_minorVersion(void) const
{
  return minorVersion;
}


