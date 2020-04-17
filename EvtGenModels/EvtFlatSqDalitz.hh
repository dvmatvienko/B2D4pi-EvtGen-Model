#ifndef EVTFLATSQDALITZ_HH
#define EVTFLATSQDALITZ_HH

#include "EvtGenBase/EvtDecayProb.hh"

class EvtParticle;

// Description: B->3 body flat in square dalitz vairiables
// the square dalitz is the plane m12 theta12

class EvtFlatSqDalitz : public EvtDecayProb {
  public:
    EvtFlatSqDalitz() {}
    ~EvtFlatSqDalitz();

    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;
};

#endif
