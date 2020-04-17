#ifndef EVTSVSCPISO_HH
#define EVTSVSCPISO_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

// Description: Routine to decay scalar -> vectors scalar
//              with CP violation and isospin amplitudes.
//              More specifically, it is indended to handle
//              decays like B->rho pi and B->a1 pi.

class EvtSVSCPiso : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;
};

#endif
