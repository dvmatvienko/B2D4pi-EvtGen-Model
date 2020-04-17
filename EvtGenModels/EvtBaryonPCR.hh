#ifndef EVTBARYONPCR_HH
#define EVTBARYONPCR_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicBaryonAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>

class EvtParticle;

// Description:Implementation of the BaryonPCR model
// Class to handle semileptonic decays using the BaryonVminusA
// model.

class EvtBaryonPCR : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtBaryonPCR* clone() override;

    void decay( EvtParticle* p ) override;
    void initProbMax() override;
    void init() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> baryonpcrffmodel;
    std::unique_ptr<EvtSemiLeptonicBaryonAmp> calcamp;
};

#endif
