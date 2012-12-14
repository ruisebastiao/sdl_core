#ifndef NSAPPLINKRPCV2_SETAPPICON_REQUEST_INCLUDE
#define NSAPPLINKRPCV2_SETAPPICON_REQUEST_INCLUDE

#include <string>

#include "JSONHandler/ALRPCMessage.h"


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

/**
     Used to set existing local file on SYNC as the app's icon
     Not supported on first generation SYNC vehicles. 
*/

  class SetAppIcon_request : public NsAppLinkRPC::ALRPCMessage
  {
  public:
  
    SetAppIcon_request(const SetAppIcon_request& c);
    SetAppIcon_request(void);
    
    virtual ~SetAppIcon_request(void);
  
    bool checkIntegrity(void);

    const std::string& get_syncFileName(void) const;

    bool set_syncFileName(const std::string& syncFileName_);

  private:
  
    friend class SetAppIcon_requestMarshaller;


///  File reference name.
      std::string syncFileName;	//!< (500)
  };

}

#endif
