#ifndef EVTBTOXSGAMMAALIGREUB_HH
#define EVTBTOXSGAMMAALIGREUB_HH

#include "EvtGenModels/EvtBtoXsgammaAbsModel.hh"

// Class to generate non-resonant two-body b->s,gamma decays.

class EvtBtoXsgammaAliGreub : public EvtBtoXsgammaAbsModel {
  public:
    void init( int, double* ) override;

    double GetMass( int code ) override;
};

#endif
