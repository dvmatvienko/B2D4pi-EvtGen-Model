#ifndef EVTSEMILEPTONICAMP_HH
#define EVTSEMILEPTONICAMP_HH

class EvtAmp;
class EvtParticle;
class EvtSemiLeptonicFF;
class EvtId;

class EvtSemiLeptonicAmp {
  public:
    virtual ~EvtSemiLeptonicAmp(){};

    //Daughters are initialized and have been added to the parent.
    //No need to carry around the daughters seperately!

    virtual void CalcAmp( EvtParticle* parent, EvtAmp& amp,
                          EvtSemiLeptonicFF* FormFactors ) = 0;

    double CalcMaxProb( EvtId parent, EvtId meson, EvtId lepton, EvtId nudaug,
                        EvtSemiLeptonicFF* FormFactors, int nQ2Bins = 25 );
};

#endif
