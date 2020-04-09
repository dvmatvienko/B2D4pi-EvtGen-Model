//--------------------------------------------------------------------------
//
// Module: EvtGen/EvtHQET2.hh
//
// Description:Implementation of the HQET model with dispersive FF due to
//             Caprini et al.
//
// Modification history:
//
//    Marco Bomben   March 11, 2003         Module created
//
//------------------------------------------------------------------------

#ifndef EVTHQET2_HH
#define EVTHQET2_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>

class EvtParticle;

class EvtHQET2 : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void initProbMax() override;
    void init() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> hqetffmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
};
#endif
