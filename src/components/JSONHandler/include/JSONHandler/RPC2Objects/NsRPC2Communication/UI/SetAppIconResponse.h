#ifndef NSRPC2COMMUNICATION_UI_SETAPPICONRESPONSE_INCLUDE
#define NSRPC2COMMUNICATION_UI_SETAPPICONRESPONSE_INCLUDE

#include "JSONHandler/RPC2Response.h"


/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Fri Dec 14 06:14:25 2012
  source stamp	Fri Dec 14 06:14:23 2012
  author	robok0der
*/

namespace NsRPC2Communication
{
  namespace UI
  {

    class SetAppIconResponse : public ::NsRPC2Communication::RPC2Response
    {
    public:
    
      SetAppIconResponse(const SetAppIconResponse& c);
      SetAppIconResponse(void);
    
      SetAppIconResponse& operator =(const SetAppIconResponse&);
    
      virtual ~SetAppIconResponse(void);
    
      bool checkIntegrity(void);
    

    private:

      friend class SetAppIconResponseMarshaller;


    };
  }
}

#endif
