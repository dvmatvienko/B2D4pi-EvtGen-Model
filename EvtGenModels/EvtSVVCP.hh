#ifndef EVTSVVCP_HH
#define EVTSVVCP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtSVVCP : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;

    void decay( EvtParticle* p ) override;

    std::string getParamName( int i ) override;
    std::string getParamDefault( int i ) override;
};

#endif
