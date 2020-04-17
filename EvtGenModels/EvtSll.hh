#ifndef EVTSLL_HH
#define EVTSLL_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

//Class to handle decays of the form SCALAR -> DIRAC DIRAC.

class EvtSll : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;

    void decay( EvtParticle* p ) override;
};

#endif
