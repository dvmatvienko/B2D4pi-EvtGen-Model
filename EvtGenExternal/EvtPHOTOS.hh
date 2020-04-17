#ifndef EVTPHOTOS_HH
#define EVTPHOTOS_HH

#include "EvtGenBase/EvtAbsRadCorr.hh"

#include <string>

class EvtParticle;
class EvtAbsExternalGen;

// Description: EvtGen's interface to PHOTOS for generation of
//              QED final state radiation.

class EvtPHOTOS : public EvtAbsRadCorr {
  public:
    void doRadCorr( EvtParticle* p ) override;

  private:
    EvtAbsExternalGen* _photosEngine = nullptr;
};

#endif
