#ifndef EVTSVVCPLH_HH
#define EVTSVVCPLH_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtSVVCPLH : public EvtDecayAmp {
  public:
    EvtSVVCPLH() {}

    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;

    void decay( EvtParticle* p ) override;
};

#endif
