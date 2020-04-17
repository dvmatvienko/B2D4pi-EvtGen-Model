#ifndef EVTVPHOTOVISR_HH
#define EVTVPHOTOVISR_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtVPHOtoVISR : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;
};

#endif
