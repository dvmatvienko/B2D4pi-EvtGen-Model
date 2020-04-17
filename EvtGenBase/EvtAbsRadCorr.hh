#ifndef EVTABSRADCORR_HH
#define EVTABSRADCORR_HH

#include <assert.h>
#include <iostream>
class EvtParticle;

class EvtAbsRadCorr {
  public:
    EvtAbsRadCorr(){};
    virtual ~EvtAbsRadCorr(){};
    virtual void doRadCorr( EvtParticle* p ) = 0;

  private:
};

#endif
