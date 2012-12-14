#ifndef NSAPPLINKRPCV2_DELETECOMMAND_REQUEST_INCLUDE
#define NSAPPLINKRPCV2_DELETECOMMAND_REQUEST_INCLUDE


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

///  Deletes all commands from the in-application menu with the specified command id.

  class DeleteCommand_request : public NsAppLinkRPC::ALRPCMessage
  {
  public:
  
    DeleteCommand_request(const DeleteCommand_request& c);
    DeleteCommand_request(void);
    
    virtual ~DeleteCommand_request(void);
  
    bool checkIntegrity(void);

    unsigned int get_cmdID(void) const;

    bool set_cmdID(unsigned int cmdID_);

  private:
  
    friend class DeleteCommand_requestMarshaller;


///  ID of the command(s) to delete.
      unsigned int cmdID;	//!<  (0,2000000000)
  };

}

#endif
