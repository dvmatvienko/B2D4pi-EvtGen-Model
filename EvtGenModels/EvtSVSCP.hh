#ifndef EVTSVSCP_HH
#define EVTSVSCP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtSVSCP : public EvtDecayAmp {
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
