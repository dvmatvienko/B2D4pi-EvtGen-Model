#ifndef EVTITGFUNCTION_HH
#define EVTITGFUNCTION_HH

#include "EvtGenModels/EvtItgAbsFunction.hh"

/**
 *  Generic function where the pointer to the function is available.
 *
 *  The function is taken as type pointer to function returning double and
 *  taking a double (the abscissa) and a const RWTValVector<double> reference
 *  (the parameter values of the function) as arguments.
 */

class EvtItgFunction : public EvtItgAbsFunction {
  public:
    // Constructors
    EvtItgFunction( double ( *theFunction )( double ), double lowerRange,
                    double upperRange );

    void setCoeff( int, int, double ) override{};
    double getCoeff( int, int ) override { return 0.0; };

  protected:
    // Helper functions

    double myFunction( double x ) const override;

  private:
    // Data members
    double ( *_myFunction )( double x );
};

#endif    // EvtITGFUNCTION_HH
