#ifndef EVTVSSMIX_HH
#define EVTVSSMIX_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtVSSMix : public EvtDecayAmp {
  public:
    EvtVSSMix() {}

    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;

    std::string getParamName( int i ) override;
};

#endif
