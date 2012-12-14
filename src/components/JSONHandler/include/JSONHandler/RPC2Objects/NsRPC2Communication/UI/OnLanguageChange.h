#ifndef NSRPC2COMMUNICATION_UI_ONLANGUAGECHANGE_INCLUDE
#define NSRPC2COMMUNICATION_UI_ONLANGUAGECHANGE_INCLUDE

#include "JSONHandler/RPC2Notification.h"

#include "../include/JSONHandler/ALRPCObjects/V1/Language.h"

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

    class OnLanguageChange : public ::NsRPC2Communication::RPC2Notification
    {
    public:
    
      OnLanguageChange(const OnLanguageChange& c);
      OnLanguageChange(void);
    
      OnLanguageChange& operator =(const OnLanguageChange&);
    
      virtual ~OnLanguageChange(void);
    
      bool checkIntegrity(void);
    
// getters
      const NsAppLinkRPC::Language& get_hmiDisplayLanguage(void);

      int get_appId(void);


// setters
      bool set_hmiDisplayLanguage(const NsAppLinkRPC::Language& hmiDisplayLanguage);

      bool set_appId(int appId);


    private:

      friend class OnLanguageChangeMarshaller;

      NsAppLinkRPC::Language hmiDisplayLanguage;
      int appId;

    };
  }
}

#endif
