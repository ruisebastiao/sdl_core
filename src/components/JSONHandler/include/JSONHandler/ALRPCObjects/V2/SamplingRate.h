#ifndef NSAPPLINKRPCV2_SAMPLINGRATE_INCLUDE
#define NSAPPLINKRPCV2_SAMPLINGRATE_INCLUDE


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

///  Describes different sampling options for PerformAudioPassThru.

  class SamplingRate
  {
  public:
    enum SamplingRateInternal
    {
      INVALID_ENUM=-1,
      FIX_8KHZ=0,
      FIX_16KHZ=1,
      FIX_22KHZ=2,
      FIX_44KHZ=3
    };
  
    SamplingRate() : mInternal(INVALID_ENUM)				{}
    SamplingRate(SamplingRateInternal e) : mInternal(e)		{}
  
    SamplingRateInternal get(void) const	{ return mInternal; }
    void set(SamplingRateInternal e)		{ mInternal=e; }
  
  private:
    SamplingRateInternal mInternal;
    friend class SamplingRateMarshaller;
  };
  
}

#endif
