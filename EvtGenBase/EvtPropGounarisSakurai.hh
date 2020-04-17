#ifndef EVT_PROP_GOUNARIS_SAKURAI_HH
#define EVT_PROP_GOUNARIS_SAKURAI_HH

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtCyclic3.hh"
#include "EvtGenBase/EvtDalitzPlot.hh"
#include "EvtGenBase/EvtDalitzPoint.hh"
#include "EvtGenBase/EvtPropagator.hh"

class EvtPropGounarisSakurai : public EvtPropagator {
  public:
    EvtPropGounarisSakurai( EvtDalitzPlot* dp, EvtCyclic3::Pair pair, double m0,
                            double g0 );

    EvtAmplitude<EvtPoint1D>* clone() const override;

  protected:
    EvtComplex amplitude( const EvtPoint1D& x ) const override;

  private:
    EvtDalitzPlot* _dalitzSpace;

    EvtCyclic3::Pair _pair;
    double _gbase;
    double _m1;
    double _m2;
    double _dfun;
    double dFun( double s ) const;
    double dh_dsFun( double s ) const;
    double hFun( double s ) const;
    double kFun( double s ) const;
    double fsFun( double s ) const;
};

#endif
