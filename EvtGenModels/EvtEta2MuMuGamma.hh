#ifndef EVTETA2MUMUGAMMA_HH
#define EVTETA2MUMUGAMMA_HH

#include "EvtGenBase/EvtDecayProb.hh"

class EvtParticle;

class EvtEta2MuMuGamma : public EvtDecayProb {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;
};

#endif
