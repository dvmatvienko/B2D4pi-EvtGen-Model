#ifndef EVTPI0DALITZ_HH
#define EVTPI0DALITZ_HH

#include "EvtGenBase/EvtDecayProb.hh"

class EvtParticle;

class EvtPi0Dalitz : public EvtDecayProb {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;
};

#endif
