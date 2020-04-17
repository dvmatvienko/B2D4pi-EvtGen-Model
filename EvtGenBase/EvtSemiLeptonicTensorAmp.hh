#ifndef EVTSEMILEPTONICTENSORAMP_HH
#define EVTSEMILEPTONICTENSORAMP_HH

#include "EvtGenBase/EvtSemiLeptonicAmp.hh"

class EvtParticle;
class EvtSemiLeptonicFF;
class EvtAmp;

class EvtSemiLeptonicTensorAmp : public EvtSemiLeptonicAmp {
  public:
    //Daughters are initialized and have been added to the parent.
    //No need to carry around the daughters seperately!
    void CalcAmp( EvtParticle* parent, EvtAmp& amp,
                  EvtSemiLeptonicFF* FormFactors ) override;
};

#endif
