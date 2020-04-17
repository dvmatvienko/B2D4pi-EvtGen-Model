#ifndef EVTBcSMuNu_HH
#define EVTBcSMuNu_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <fstream>
#include <memory>
#include <stdio.h>

class EvtParticle;

// Description:Implementation of the model for semileptonic Bc decays

class EvtBcSMuNu : public EvtDecayAmp {
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
    int idScalar;
};

#endif
