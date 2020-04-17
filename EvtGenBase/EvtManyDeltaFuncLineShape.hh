#ifndef EVTMANYDELTAFUNCLINESHAPE_HH
#define EVTMANYDELTAFUNCLINESHAPE_HH

#include "EvtGenBase/EvtAbsLineShape.hh"

class EvtManyDeltaFuncLineShape : public EvtAbsLineShape {
  public:
    EvtManyDeltaFuncLineShape();
    EvtManyDeltaFuncLineShape( double mass, double width, double maxRange,
                               EvtSpinType::spintype sp );
    //figure the m1 and l on the fly
    //			       double mDaug1, double mDaug2, int l);
    EvtManyDeltaFuncLineShape& operator=( const EvtManyDeltaFuncLineShape& x );
    EvtManyDeltaFuncLineShape( const EvtManyDeltaFuncLineShape& x );

    EvtAbsLineShape* clone() override;

    double getMassProb( double mass, double massPar, int nDaug,
                        double* massDau ) override;
    // othDaugId is the other daughter of the parent in the case of a two body decay (only!)
    // ie B->rho K rho->pipi, othDaugId = K
    double getRandMass( EvtId* parId, int nDaug, EvtId* dauId, EvtId* othDaugId,
                        double maxMass, double* dauMasses ) override;
};

#endif
