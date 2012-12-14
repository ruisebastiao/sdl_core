#ifndef NSAPPLINKRPCV2_PARAMETERPERMISSIONS_INCLUDE
#define NSAPPLINKRPCV2_PARAMETERPERMISSIONS_INCLUDE

#include <string>
#include <vector>



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

  class ParameterPermissions
  {
  public:
  
    ParameterPermissions(const ParameterPermissions& c);
    ParameterPermissions(void);
  
    bool checkIntegrity(void);
  // getters

    const std::vector<std::string>& get_allowed(void) const;
    const std::vector<std::string>& get_userDisallowed(void) const;

// setters

    bool set_allowed(const std::vector<std::string>& allowed_);
    bool set_userDisallowed(const std::vector<std::string>& userDisallowed_);

  private:

    friend class ParameterPermissionsMarshaller;


///  A set of all parameters that are permitted for this given RPC.
      std::vector<std::string> allowed;	//!<   [%s..%s] (100)

///  A set of all parameters that are prohibited for this given RPC.
      std::vector<std::string> userDisallowed;	//!<   [%s..%s] 
  };

}

#endif
