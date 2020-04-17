#ifndef EVTSEMILEPTONICSCALARAMP_HH
#define EVTSEMILEPTONICSCALARAMP_HH

#include "EvtGenBase/EvtSemiLeptonicAmp.hh"

class EvtAmp;
class EvtParticle;
class EvtSemiLeptonicFF;

class EvtSemiLeptonicScalarAmp : public EvtSemiLeptonicAmp {
    //Daughters are initialized and have been added to the parent.
    //No need to carry around the daughters seperately!
    void CalcAmp( EvtParticle* parent, EvtAmp& amp,
                  EvtSemiLeptonicFF* FormFactors ) override;
};

#endif
