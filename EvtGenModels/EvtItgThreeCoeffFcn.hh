#ifndef EVTITTHREECOEFFFCN_HH
#define EVTITTHREECOEFFFCN_HH

#include <vector>

//-------------
// C Headers --
//-------------
extern "C" {
}

#include "EvtGenModels/EvtItgAbsFunction.hh"

// Description:
//      Class describing a function with three vectors of coefficients.

class EvtItgThreeCoeffFcn : public EvtItgAbsFunction {
  public:
    EvtItgThreeCoeffFcn( double ( *theFunction )( double,
                                                  const std::vector<double>&,
                                                  const std::vector<double>&,
                                                  const std::vector<double>& ),
                         double lowerRange, double upperRange,
                         const std::vector<double>& coeffs1,
                         const std::vector<double>& coeffs2,
                         const std::vector<double>& coeffs3 );

    void setCoeff( int, int, double ) override;
    double getCoeff( int, int ) override;

  protected:
    double myFunction( double x ) const override;

  private:
    // Data members
    double ( *_myFunction )( double x, const std::vector<double>& coeffs1,
                             const std::vector<double>& coeffs2,
                             const std::vector<double>& coeffs3 );

    std::vector<double> _coeffs1;
    std::vector<double> _coeffs2;
    std::vector<double> _coeffs3;
};

#endif    // EvtITGPTRFUNCTION_HH
