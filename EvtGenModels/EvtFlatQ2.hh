#ifndef EVTFLATQ2_HH
#define EVTFLATQ2_HH

#include "EvtGenBase/EvtDecayProb.hh"

class EvtParticle;

// Description:   B->Xu l nu with flat q2 distribution

class EvtFlatQ2 : public EvtDecayProb {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

  private:
    bool _usePhsp;
};

#endif
