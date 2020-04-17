#ifndef EVTSSSCPPNG_HH
#define EVTSSSCPPNG_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

// Description: Routine to decay B -> 2 scalars taking into account penguin
//              contributions (assuming single quark dominance for penguins)

class EvtSSSCPpng : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;

    void init() override;
    void decay( EvtParticle* p ) override;
};

#endif
