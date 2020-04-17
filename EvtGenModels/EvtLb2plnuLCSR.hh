#ifndef EVTLB2PMUNULCSR_HH
#define EVTLB2PMUNULCSR_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include "EvtGenModels/EvtSLBaryonAmp.hh"

class EvtParticle;

// Description:Implementation of the Lb2plnuLCSR model
// Class to handle semileptonic Lb -> p l nu decays using the using form factor predictions from Light Cone Sum Rules.
// Description: Routine to implement Lb->p l nu semileptonic decays using form factor
//              predictions form Light Cone Sum Rules.  The form factors are from
//              A. Khodjamirian, C. Klein, T. Mannel and Y.-M. Wang, arXiv.1108.2971 (2011)

class EvtLb2plnuLCSR : public EvtDecayAmp {
  public:
    EvtLb2plnuLCSR();
    ~EvtLb2plnuLCSR();

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
