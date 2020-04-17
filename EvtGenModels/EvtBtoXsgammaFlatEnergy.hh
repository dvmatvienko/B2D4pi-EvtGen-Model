#ifndef EVTBTOXSGAMMAFLATENERGY_HH
#define EVTBTOXSGAMMAFLATENERGY_HH

#include "EvtGenModels/EvtBtoXsgammaAbsModel.hh"

// Description:
//       Implimentation of a fixed hadronic mass to measure spectrum

class EvtBtoXsgammaFlatEnergy : public EvtBtoXsgammaAbsModel {
  public:
    void init( int, double* ) override;

    double GetMass( int code ) override;

  private:
    //Input parameters
    double _eMin;
    double _eMax;
    //
    double _mB0;
    double _eRange;
};

#endif
