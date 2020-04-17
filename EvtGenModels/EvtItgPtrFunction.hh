#ifndef EVTITGPTRFUNCTION_HH
#define EVTITGPTRFUNCTION_HH

#include "EvtGenModels/EvtItgAbsFunction.hh"

#include <vector>

// Description:
//      Class describing a function with one vector of coefficients. (Stolen and
//      modified from the BaBar IntegrationUtils package - author: Phil Strother).

class EvtItgPtrFunction : public EvtItgAbsFunction {
  public:
    EvtItgPtrFunction( double ( *theFunction )( double,
                                                const std::vector<double>& ),
                       double lowerRange, double upperRange,
                       const std::vector<double>& coeffs1 );

    void setCoeff( int, int, double ) override;
    double getCoeff( int, int ) override;

  protected:
    double myFunction( double x ) const override;

  private:
    // Data members
    double ( *_myFunction )( double x, const std::vector<double>& coeffs1 );

    std::vector<double> _coeffs1;
};

#endif    // EVTITGPTRFUNCTION_HH
