#ifndef EVTVTOSLL_HH
#define EVTVTOSLL_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtVtoSll : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;
    void decay( EvtParticle* p ) override;
};

#endif
