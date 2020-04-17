#ifndef EVTSTSCP_HH
#define EVTSTSCP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtSTSCP : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;
    void decay( EvtParticle* p ) override;

    std::string getParamName( int i ) override;
    std::string getParamDefault( int i ) override;
};

#endif
