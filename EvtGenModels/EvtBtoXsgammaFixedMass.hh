#ifndef EVTBTOXSGAMMAFIXEDMASS_HH
#define EVTBTOXSGAMMAFIXEDMASS_HH

#include "EvtGenModels/EvtBtoXsgammaAbsModel.hh"

// Description:
//       Implimentation of a fixed hadronic mass to measure spectrum

class EvtBtoXsgammaFixedMass : public EvtBtoXsgammaAbsModel {
  public:
    void init( int, double* ) override;

    double GetMass( int code ) override;

  private:
    //Input parameters
    double _mH;
};

#endif
