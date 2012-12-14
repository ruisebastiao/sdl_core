#ifndef NSRPC2COMMUNICATION_TTS_PERFORMAUDIOPASSTHRU_INCLUDE
#define NSRPC2COMMUNICATION_TTS_PERFORMAUDIOPASSTHRU_INCLUDE

#include <string>
#include <vector>
#include "JSONHandler/RPC2Request.h"

#include "../include/JSONHandler/ALRPCObjects/V1/TTSChunk.h"
#include "../include/JSONHandler/ALRPCObjects/V2/SamplingRate.h"
#include "../include/JSONHandler/ALRPCObjects/V2/AudioCaptureQuality.h"
#include "../include/JSONHandler/ALRPCObjects/V2/AudioType.h"

/*
  interface	NsRPC2Communication::TTS
  version	1.2
  generated at	Fri Dec 14 06:14:25 2012
  source stamp	Fri Dec 14 06:14:23 2012
  author	robok0der
*/

namespace NsRPC2Communication
{
  namespace TTS
  {

    class PerformAudioPassThru : public ::NsRPC2Communication::RPC2Request
    {
    public:
    
      PerformAudioPassThru(const PerformAudioPassThru& c);
      PerformAudioPassThru(void);
    
      PerformAudioPassThru& operator =(const PerformAudioPassThru&);
    
      virtual ~PerformAudioPassThru(void);
    
      bool checkIntegrity(void);
    
// getters
      const std::vector< NsAppLinkRPC::TTSChunk>& get_initialPrompt(void);

      const std::string* get_audioPassThruDisplayText1(void);
      const std::string* get_audioPassThruDisplayText2(void);
      const NsAppLinkRPCV2::SamplingRate& get_samplingRate(void);

      unsigned int get_maxDuration(void);

      const NsAppLinkRPCV2::AudioCaptureQuality& get_bitsPerSample(void);

      const NsAppLinkRPCV2::AudioType& get_audioType(void);

      int get_appId(void);


// setters
/// 1 <= size <= 100
      bool set_initialPrompt(const std::vector< NsAppLinkRPC::TTSChunk>& initialPrompt);

/// audioPassThruDisplayText1 <= 500
      bool set_audioPassThruDisplayText1(const std::string& audioPassThruDisplayText1);

      void reset_audioPassThruDisplayText1(void);

/// audioPassThruDisplayText2 <= 500
      bool set_audioPassThruDisplayText2(const std::string& audioPassThruDisplayText2);

      void reset_audioPassThruDisplayText2(void);

      bool set_samplingRate(const NsAppLinkRPCV2::SamplingRate& samplingRate);

/// maxDuration <= 1000000
      bool set_maxDuration(unsigned int maxDuration);

      bool set_bitsPerSample(const NsAppLinkRPCV2::AudioCaptureQuality& bitsPerSample);

      bool set_audioType(const NsAppLinkRPCV2::AudioType& audioType);

      bool set_appId(int appId);


    private:

      friend class PerformAudioPassThruMarshaller;

      std::vector< NsAppLinkRPC::TTSChunk> initialPrompt;
      std::string* audioPassThruDisplayText1;
      std::string* audioPassThruDisplayText2;
      NsAppLinkRPCV2::SamplingRate samplingRate;
      unsigned int maxDuration;
      NsAppLinkRPCV2::AudioCaptureQuality bitsPerSample;
      NsAppLinkRPCV2::AudioType audioType;
      int appId;

    };
  }
}

#endif
