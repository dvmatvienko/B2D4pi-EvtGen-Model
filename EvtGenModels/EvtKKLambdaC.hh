#ifndef EVTKKLAMBDAC_HH
#define EVTKKLAMBDAC_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>

class Evtparticle;

// Description:Semileptonic decays with pole form form factors

class EvtKKLambdaC : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void initProbMax() override;
    void init() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> _ffmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> _calcamp;
};

#endif
