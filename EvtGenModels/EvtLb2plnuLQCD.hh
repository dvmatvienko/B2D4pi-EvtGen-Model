#ifndef EVTLB2PMUNULQCD_HH
#define EVTLB2PMUNULQCD_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include "EvtGenModels/EvtSLBaryonAmp.hh"

class EvtParticle;

// Description:Implementation of the Lb2plnuLQCD model
// Class to handle semileptonic Lb -> p l nu decays using the using form factor predictions from Lattice QCD.
// Description: Routine to implement Lb->p l nu semileptonic decays using form factor predictions from LQCD.
// The form factors are from:
//            W. Detmold, C-J. Lin, S. Meinel and M.Wingate, arXiv:1306.0446 (2013)

class EvtLb2plnuLQCD : public EvtDecayAmp {
  public:
    EvtLb2plnuLQCD();
    ~EvtLb2plnuLQCD();

    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void initProbMax() override;
    void init() override;

  private:
    EvtSemiLeptonicFF* ffmodel;
    EvtSLBaryonAmp* calcamp;
};

#endif
