#ifndef EVTABS_EXTERNALGEN_HH
#define EVTABS_EXTERNALGEN_HH

#include "EvtGenBase/EvtParticle.hh"

// Description: Pure abstract interface for external physics generators

class EvtAbsExternalGen {
  public:
    virtual ~EvtAbsExternalGen() = default;
    virtual bool doDecay( EvtParticle* theMother ) = 0;
    virtual double getDecayProb( EvtParticle* ) { return 1.0; }
    virtual void initialise() = 0;
};

#endif
