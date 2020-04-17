#ifndef EVTTAUVECTORNU_HH
#define EVTTAUVECTORNU_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtTauVectornu : public EvtDecayAmp {
  public:
    EvtTauVectornu() {}

    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;
};

#endif
