#include "../include/JSONHandler/ALRPCObjects/V2/ChangeRegistration_response.h"
#include "ChangeRegistration_responseMarshaller.h"
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
ChangeRegistration_response& ChangeRegistration_response::operator =(const ChangeRegistration_response& c)
{
  success= c.success;
  resultCode= c.resultCode;
  info= c.info ? new std::string(c.info[0]) : 0;

  return *this;
}


ChangeRegistration_response::~ChangeRegistration_response(void)
{
  if(info)
    delete info;
}


ChangeRegistration_response::ChangeRegistration_response(const ChangeRegistration_response& c) : NsAppLinkRPC::ALRPCMessage(c)
{
  *this=c;
}


bool ChangeRegistration_response::checkIntegrity(void)
{
  return ChangeRegistration_responseMarshaller::checkIntegrity(*this);
}


ChangeRegistration_response::ChangeRegistration_response(void) : NsAppLinkRPC::ALRPCMessage(PROTOCOL_VERSION),
      info(0)
{
}



bool ChangeRegistration_response::set_success(bool success_)
{
  success=success_;
  return true;
}

bool ChangeRegistration_response::set_resultCode(const Result& resultCode_)
{
  if(!ResultMarshaller::checkIntegrityConst(resultCode_))   return false;
  resultCode=resultCode_;
  return true;
}

bool ChangeRegistration_response::set_info(const std::string& info_)
{
  if(info_.length()>1000)  return false;
  delete info;
  info=0;

  info=new std::string(info_);
  return true;
}

void ChangeRegistration_response::reset_info(void)
{
  if(info)
    delete info;
  info=0;
}




bool ChangeRegistration_response::get_success(void) const
{
  return success;
}

const Result& ChangeRegistration_response::get_resultCode(void) const 
{
  return resultCode;
}

const std::string* ChangeRegistration_response::get_info(void) const 
{
  return info;
}

