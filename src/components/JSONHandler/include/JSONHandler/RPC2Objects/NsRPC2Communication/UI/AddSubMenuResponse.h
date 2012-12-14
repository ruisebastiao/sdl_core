#ifndef NSRPC2COMMUNICATION_UI_ADDSUBMENURESPONSE_INCLUDE
#define NSRPC2COMMUNICATION_UI_ADDSUBMENURESPONSE_INCLUDE

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

    class AddSubMenuResponse : public ::NsRPC2Communication::RPC2Response
    {
    public:
    
      AddSubMenuResponse(const AddSubMenuResponse& c);
      AddSubMenuResponse(void);
    
      AddSubMenuResponse& operator =(const AddSubMenuResponse&);
    
      virtual ~AddSubMenuResponse(void);
    
      bool checkIntegrity(void);
    

    private:

      friend class AddSubMenuResponseMarshaller;


    };
  }
}

#endif
