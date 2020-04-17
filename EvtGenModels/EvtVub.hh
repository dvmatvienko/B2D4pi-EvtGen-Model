#ifndef EVTVUB_HH
#define EVTVUB_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

#include "EvtGenModels/EvtVubdGamma.hh"

#include <memory>
#include <vector>

class EvtParticle;

// Description:
// Class to generate inclusive B to X_u l nu decays according to various
// decay models. Implemtented are ACCM, parton-model and a QCD model.

class EvtVub : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void initProbMax() override;

    void init() override;

    void decay( EvtParticle* p ) override;

  private:
    double _mb;        // the b-quark pole mass in GeV (try 4.65 to 4.9)
    double _a;         // Parameter for the Fermi Motion (1.29 is good)
    double _alphas;    // Strong Coupling at m_b (around 0.24)
    double _dGMax;     // max dGamma*p2 value;
    int _nbins;
    int _storeQplus;
    std::vector<double> _masses;
    std::vector<double> _weights;

    std::unique_ptr<EvtVubdGamma> _dGamma;    // calculates the decay rate
    double findPFermi();
    std::vector<double> _pf;
};

#endif
