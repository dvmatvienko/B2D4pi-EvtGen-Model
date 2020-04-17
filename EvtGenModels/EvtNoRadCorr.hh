#ifndef EVTNORADCORR_HH
#define EVTNORADCORR_HH

#include "EvtGenBase/EvtAbsRadCorr.hh"

#include <string>

class EvtParticle;

// Description: Create an empty radiative correction engine which does nothing.
// This is required since the EvtGen constructor still needs at least one
// concrete implementation of EvtAbsRadCorr for the case when Photos is not used.

class EvtNoRadCorr : public EvtAbsRadCorr {
  public:
    EvtNoRadCorr() { ; }
    virtual ~EvtNoRadCorr() { ; }

    virtual void doRadCorr( EvtParticle* ) { ; }

  private:
};

#endif
