#ifndef EVTVVSPWAVE_HH
#define EVTVVSPWAVE_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtVVSPwave : public EvtDecayAmp {
  public:
    EvtVVSPwave() {}

    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;
};

#endif
