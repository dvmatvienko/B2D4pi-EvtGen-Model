#ifndef EVTISGW2_HH
#define EVTISGW2_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>
class EvtParticle;

// Description:Implementation of the ISGW2 model
// Class to handle semileptonic decays using the ISGW2
// model, as described in PRD 52 5 (1995) by
// Isgur and Scora.  Electron, muon, and tau models
// are available.  Form factors, q2 and lepton energy
// spectra checked against code from Scora.

class EvtISGW2 : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void initProbMax() override;
    void init() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> isgw2ffmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
};

#endif
