#include "../include/JSONHandler/ALRPCObjects/V2/UnsubscribeButton_response.h"
#include "UnsubscribeButton_responseMarshaller.h"
#include "../include/JSONHandler/ALRPCObjects/V2/Marshaller.h"
#include "ResultMarshaller.h"

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
UnsubscribeButton_response& UnsubscribeButton_response::operator =(const UnsubscribeButton_response& c)
{
  success= c.success;
  resultCode= c.resultCode;
  info= c.info ? new std::string(c.info[0]) : 0;

  return *this;
}


UnsubscribeButton_response::~UnsubscribeButton_response(void)
{
  if(info)
    delete info;
}


UnsubscribeButton_response::UnsubscribeButton_response(const UnsubscribeButton_response& c) : NsAppLinkRPC::ALRPCMessage(c)
{
  *this=c;
}


bool UnsubscribeButton_response::checkIntegrity(void)
{
  return UnsubscribeButton_responseMarshaller::checkIntegrity(*this);
}


UnsubscribeButton_response::UnsubscribeButton_response(void) : NsAppLinkRPC::ALRPCMessage(PROTOCOL_VERSION),
      info(0)
{
}



bool UnsubscribeButton_response::set_success(bool success_)
{
  success=success_;
  return true;
}

bool UnsubscribeButton_response::set_resultCode(const Result& resultCode_)
{
  if(!ResultMarshaller::checkIntegrityConst(resultCode_))   return false;
  resultCode=resultCode_;
  return true;
}

bool UnsubscribeButton_response::set_info(const std::string& info_)
{
  if(info_.length()>1000)  return false;
  delete info;
  info=0;

  info=new std::string(info_);
  return true;
}

void UnsubscribeButton_response::reset_info(void)
{
  if(info)
    delete info;
  info=0;
}




bool UnsubscribeButton_response::get_success(void) const
{
  return success;
}

const Result& UnsubscribeButton_response::get_resultCode(void) const 
{
  return resultCode;
}

const std::string* UnsubscribeButton_response::get_info(void) const 
{
  return info;
}

