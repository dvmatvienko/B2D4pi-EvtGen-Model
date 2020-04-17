#ifndef EVTRELBREITWIGNERBARRIERFACT_HH
#define EVTRELBREITWIGNERBARRIERFACT_HH

#include "EvtGenBase/EvtAbsLineShape.hh"

class EvtRelBreitWignerBarrierFact : public EvtAbsLineShape {
  public:
    EvtRelBreitWignerBarrierFact() = default;
    EvtRelBreitWignerBarrierFact( double mass, double width, double maxRange,
                                  EvtSpinType::spintype sp );
    //figure the m1 and l on the fly
    //			       double mDaug1, double mDaug2, int l);
    EvtRelBreitWignerBarrierFact& operator=( const EvtRelBreitWignerBarrierFact& x );
    EvtRelBreitWignerBarrierFact( const EvtRelBreitWignerBarrierFact& x );

    EvtAbsLineShape* clone() override;

    double getMassProb( double mass, double massPar, int nDaug,
                        double* massDau ) override;
    // othDaugId is the other daughter of the parent in the case of a two body decay (only!)
    // ie B->rho K rho->pipi, othDaugId = K
    double getRandMass( EvtId* parId, int nDaug, EvtId* dauId, EvtId* othDaugId,
                        double maxMass, double* dauMasses ) override;

    void reSetBlatt( double blatt ) override { _blattDecay = blatt; }
    void reSetBlattBirth( double blatt ) override { _blattBirth = blatt; }

  protected:
    double _blattDecay;
    double _blattBirth;
    bool _errorCond;
};

#endif
