#ifndef EVTLB2BARYONLNU_HH
#define EVTLB2BARYONLNU_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include "EvtGenModels/EvtSLBaryonAmp.hh"

class EvtParticle;

// Description:Implementation of the Lb2Baryonlnu model
// Class to handle semileptonic Lb -> p l nu decays using the using form factor predictions based on the quark model.  Here baryon can be Lc+, p, Lc*+, N*+.
// Description: Routine to implement Lb->N*+ l nu semileptonic decays using form factor predictions based on the quark model.  The form factors are from W. Roberts, M. Pervin, S. Chapstick, (2011). arXiv:nucl-th/0503030v1.  The model can be used for decays to all N*+ states with J^{P} = 1/2^{+}, 1/2^{-}, 3/2^{+}, 3/2^{-} and, in addition, decays to p, Lc+, Lc(2593)+, Lc(2625)+

class EvtLb2Baryonlnu : public EvtDecayAmp {
  public:
    EvtLb2Baryonlnu();
    ~EvtLb2Baryonlnu();

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
