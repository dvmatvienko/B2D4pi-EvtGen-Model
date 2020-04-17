#ifndef EVTITTWOCOEFFFCN_HH
#define EVTITTWOCOEFFFCN_HH

#include <vector>

//-------------
// C Headers --
//-------------
extern "C" {
}

#include "EvtGenModels/EvtItgAbsFunction.hh"

// Description:
//      Class describing a function with two vectors of coefficients.

class EvtItgTwoCoeffFcn : public EvtItgAbsFunction {
  public:
    EvtItgTwoCoeffFcn( double ( *theFunction )( double, const std::vector<double>&,
                                                const std::vector<double>& ),
                       double lowerRange, double upperRange,
                       const std::vector<double>& coeffs1,
                       const std::vector<double>& coeffs2 );

    void setCoeff( int, int, double ) override;
    double getCoeff( int, int ) override;

  protected:
    double myFunction( double x ) const override;

  private:
    // Data members
    double ( *_myFunction )( double x, const std::vector<double>& coeffs1,
                             const std::vector<double>& coeffs2 );

    std::vector<double> _coeffs1;
    std::vector<double> _coeffs2;
};

#endif    // EvtITGTWOCOEFFFUNCTION_HH
