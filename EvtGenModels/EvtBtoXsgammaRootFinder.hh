#ifndef EVTBTOXSGAMMAROOTFINDER_HH
#define EVTBTOXSGAMMAROOTFINDER_HH

//-------------
// C Headers --
//-------------
extern "C" {
}

//#include "EvtGenBase/EvtItgAbsFunction.hh"
class EvtItgAbsFunction;

// Description:
//       Root finding algorithms using the bilear method. Basic structure
//       lifted from the BaBar IntegrationUtils root finding algorithm
//       (author John Back).

class EvtBtoXsgammaRootFinder final {
  public:
    double GetRootSingleFunc( const EvtItgAbsFunction* theFunc,
                              double functionValue, double lowerValue,
                              double upperValue, double precision );

    double GetGaussIntegFcnRoot( EvtItgAbsFunction* theFunc1,
                                 EvtItgAbsFunction* theFunc2,
                                 double integ1Precision, double integ2Precision,
                                 int maxLoop1, int maxLoop2, double integLower,
                                 double integUpper, double lowerValue,
                                 double upperValue, double precision );
};

#endif
