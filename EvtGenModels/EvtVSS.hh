#ifndef EVTVSS_HH
#define EVTVSS_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtVSS : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;
};

#endif
