#ifndef EVT_PTO3P_AMP_SMPRSL_HH
#define EVT_PTO3P_AMP_SMPRSL_HH

#include "EvtGenBase/EvtCyclic3.hh"
#include "EvtGenBase/EvtPto3PAmp.hh"

class EvtComplex;

class EvtPto3PAmpSmpResolution : public EvtPto3PAmp {
  public:
    EvtPto3PAmpSmpResolution( EvtDalitzPlot dp, EvtCyclic3::Pair pairAng,
                              EvtCyclic3::Pair pairRes,
                              EvtSpinType::spintype spin,
                              const EvtPropagator& prop, NumType typeN );

    EvtAmplitude<EvtDalitzPoint>* clone() const override
    {
        return new EvtPto3PAmpSmpResolution( *this );
    }

    EvtComplex evalPropagator( double m ) const override;

    void setResolution( double bias, double sigma )
    {
        _bias = bias;
        _sigma = sigma;
    }

  private:
    double _bias;
    double _sigma;
};

#endif
