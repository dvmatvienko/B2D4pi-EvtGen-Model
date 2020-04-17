#ifndef EVTBTOXSLL_HH
#define EVTBTOXSLL_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"
#include "EvtGenBase/EvtParticle.hh"

#include "EvtGenModels/EvtBtoXsllUtil.hh"

#include <memory>

class EvtBtoXsllUtil;

// Description:
// Class to generate inclusive non-resonant B -> Xs l+ l- decays.
// Description: Routine to generate non-resonant B -> Xs l+ l- decays.
// It generates a dilepton mass spectrum according to Kruger and Sehgal
// and then generates the two lepton momenta accoring to Ali et al.
// The resultant X_s particles may be decayed by JETSET.

class EvtBtoXsll : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void initProbMax() override;

    void init() override;

    void decay( EvtParticle* p ) override;

  private:
    std::unique_ptr<EvtBtoXsllUtil> _calcprob;
    double _dGdsProbMax;
    double _dGdsdupProbMax;
    double _mb;
    double _ms;
    double _mq;
    double _pf;
    double _mxmin;
};

#endif
