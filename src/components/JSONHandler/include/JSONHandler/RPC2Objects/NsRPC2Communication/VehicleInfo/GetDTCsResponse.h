#ifndef NSRPC2COMMUNICATION_VEHICLEINFO_GETDTCSRESPONSE_INCLUDE
#define NSRPC2COMMUNICATION_VEHICLEINFO_GETDTCSRESPONSE_INCLUDE

#include <vector>
#include "JSONHandler/RPC2Response.h"

#include "../include/JSONHandler/ALRPCObjects/V2/DTC.h"

/*
  interface	NsRPC2Communication::VehicleInfo
  version	1.2
  generated at	Fri Dec 14 06:14:25 2012
  source stamp	Fri Dec 14 06:14:23 2012
  author	robok0der
*/

namespace NsRPC2Communication
{
  namespace VehicleInfo
  {

    class GetDTCsResponse : public ::NsRPC2Communication::RPC2Response
    {
    public:
    
      GetDTCsResponse(const GetDTCsResponse& c);
      GetDTCsResponse(void);
    
      GetDTCsResponse& operator =(const GetDTCsResponse&);
    
      virtual ~GetDTCsResponse(void);
    
      bool checkIntegrity(void);
    
// getters
      const std::vector< NsAppLinkRPCV2::DTC>* get_dtcList(void);

// setters
/// 1 <= size <= 100
      bool set_dtcList(const std::vector< NsAppLinkRPCV2::DTC>& dtcList);

      void reset_dtcList(void);


    private:

      friend class GetDTCsResponseMarshaller;

      std::vector< NsAppLinkRPCV2::DTC>* dtcList;

    };
  }
}

#endif
