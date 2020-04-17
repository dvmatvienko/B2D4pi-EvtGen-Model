#ifndef EVTMELIKHOV_HH
#define EVTMELIKHOV_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>

class EvtParticle;

// Description:Implementation of the Melikhov semileptonic model

class EvtMelikhov : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> Melikhovffmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
};

#endif
