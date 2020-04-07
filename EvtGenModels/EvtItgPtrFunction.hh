//--------------------------------------------------------------------------
//
//
// Copyright Information: See EvtGen/COPYRIGHT
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Module: EvtItgPtrFunction.hh
//
// Description:
//      Class describing a function with one vector of coefficients. (Stolen and
//      modified from the BaBar IntegrationUtils package - author: Phil Strother).
//
// Modification history:
//
//    Jane Tinslay                March 21, 2001       Module adapted for use in
//                                                     EvtGen
//
//------------------------------------------------------------------------

#ifndef EVTITGPTRFUNCTION_HH
#define EVTITGPTRFUNCTION_HH

#include <vector>
#include "EvtGenModels/EvtItgAbsFunction.hh"

class EvtItgPtrFunction: public EvtItgAbsFunction {

public:

  EvtItgPtrFunction( double (*theFunction)(double, const std::vector<double> &),
		     double lowerRange, double upperRange, const std::vector<double> &coeffs1);

  void setCoeff(int, int, double) override;
  double getCoeff(int, int) override;

protected:

  double myFunction(double x) const override;

private:

  // Data members
  double (*_myFunction)(double x, const std::vector<double> & coeffs1);

  std::vector<double> _coeffs1;

};

#endif // EVTITGPTRFUNCTION_HH
