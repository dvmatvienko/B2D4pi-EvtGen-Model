#ifndef EVTBSQUARK_HH
#define EVTBSQUARK_HH

#include "EvtGenBase/EvtDecayProb.hh"

class EvtParticle;

class EvtBsquark : public EvtDecayProb {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;
    void decay( EvtParticle* p ) override;
};

#endif
