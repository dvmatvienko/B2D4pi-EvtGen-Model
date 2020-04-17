#ifndef EVTSLBARYONAMP_HH
#define EVTSLBARYONAMP_HH

#include "EvtGenBase/EvtSemiLeptonicAmp.hh"

class EvtAmp;
class EvtComplex;
class EvtDiracSpinor;
class EvtParticle;
class EvtRaritaSchwinger;
class EvtSemiLeptonicFF;
class EvtVector4C;
class EvtVector4R;

class EvtSLBaryonAmp : public EvtSemiLeptonicAmp {
  public:
    ~EvtSLBaryonAmp();

    //Daughters are initialized and have been added to the parent.
    //No need to carry around the daughters seperately!
    void CalcAmp( EvtParticle* parent, EvtAmp& amp,
                  EvtSemiLeptonicFF* FormFactors ) override;

    void CalcAmp( EvtParticle* parent, EvtAmp& amp,
                  EvtSemiLeptonicFF* FormFactors, EvtComplex r00,
                  EvtComplex r01, EvtComplex r10, EvtComplex r11 );

    double CalcMaxProb( EvtId parent, EvtId meson, EvtId lepton, EvtId nudaug,
                        EvtSemiLeptonicFF* FormFactors, EvtComplex r00,
                        EvtComplex r01, EvtComplex r10, EvtComplex r11 );

  private:
    EvtVector4C EvtBaryonVACurrent( const EvtDiracSpinor& Bf,
                                    const EvtDiracSpinor& Bi,
                                    EvtVector4R parent, EvtVector4R daught,
                                    const double* ff, int pflag );

    EvtVector4C EvtBaryonVARaritaCurrent( const EvtRaritaSchwinger& Bf_vect,
                                          const EvtDiracSpinor& Bi,
                                          EvtVector4R parent, EvtVector4R daught,
                                          const double* ff, int pflag );
};

#endif
