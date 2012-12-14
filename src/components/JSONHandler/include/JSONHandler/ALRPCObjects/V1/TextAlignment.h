#ifndef NSAPPLINKRPC_TEXTALIGNMENT_INCLUDE
#define NSAPPLINKRPC_TEXTALIGNMENT_INCLUDE


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Thu Dec 13 13:37:09 2012
  source stamp	Thu Dec 13 13:33:23 2012
  author	robok0der
*/

namespace NsAppLinkRPC
{

///  The list of possible alignments, left, right, or centered

  class TextAlignment
  {
  public:
    enum TextAlignmentInternal
    {
      INVALID_ENUM=-1,
      LEFT_ALIGNED=0,
      RIGHT_ALIGNED=1,
      CENTERED=2
    };
  
    TextAlignment() : mInternal(INVALID_ENUM)				{}
    TextAlignment(TextAlignmentInternal e) : mInternal(e)		{}
  
    TextAlignmentInternal get(void) const	{ return mInternal; }
    void set(TextAlignmentInternal e)		{ mInternal=e; }
  
  private:
    TextAlignmentInternal mInternal;
    friend class TextAlignmentMarshaller;
  };
  
}

#endif
