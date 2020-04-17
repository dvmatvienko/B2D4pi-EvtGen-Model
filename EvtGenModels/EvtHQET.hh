#ifndef EVTHQET_HH
#define EVTHQET_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>

class EvtParticle;

// Description:Implementation of the HQET model

class EvtHQET : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void initProbMax() override;
    void init() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> hqetffmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
};
#endif
