#ifndef EVTBTOXSETAP_HH
#define EVTBTOXSETAP_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

class EvtParticle;

class EvtBtoXsEtap : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void initProbMax() override;

    void init() override;

    void decay( EvtParticle* p ) override;
};

#endif
