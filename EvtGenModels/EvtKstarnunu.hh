#ifndef EVTKSTARNUNU_HH
#define EVTKSTARNUNU_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtKstarnunu : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;

    void decay( EvtParticle* p ) override;
};

#endif
