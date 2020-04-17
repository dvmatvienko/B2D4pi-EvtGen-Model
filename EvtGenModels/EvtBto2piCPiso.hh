#ifndef EVTBTO2PICPISO_HH
#define EVTBTO2PICPISO_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtParticle.hh"

class EvtBto2piCPiso : public EvtDecayAmp {
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
