#ifndef EVTSEMILEPTONICVECTORAMP_HH
#define EVTSEMILEPTONICVECTORAMP_HH

#include "EvtGenBase/EvtSemiLeptonicAmp.hh"

class EvtParticle;
class EvtAmp;
class EvtSemiLeptonicFF;

class EvtSemiLeptonicVectorAmp : public EvtSemiLeptonicAmp {
  public:
    //Daughters are initialized and have been added to the parent.
    //No need to carry around the daughters seperately!
    void CalcAmp( EvtParticle* parent, EvtAmp& amp,
                  EvtSemiLeptonicFF* FormFactors ) override;
};

#endif
