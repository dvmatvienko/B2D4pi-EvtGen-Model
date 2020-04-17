#ifndef EVTOMEGADALITZ_HH
#define EVTOMEGADALITZ_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

// Description:Class to handle the omega -> pi pi pi dalitz decay.

class EvtOmegaDalitz : public EvtDecayAmp {
  public:
    EvtOmegaDalitz() {}

    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void decay( EvtParticle* p ) override;
    void initProbMax() override;
};

#endif
