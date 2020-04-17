#ifndef EVTBcVMuNu_HH
#define EVTBcVMuNu_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>

class EvtParticle;

// Description:Implementation of the model for semileptonic Bc decays

class EvtBcVMuNu : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;

    void initProbMax() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> ffmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
    int whichfit;
    int idVector;
};

#endif
