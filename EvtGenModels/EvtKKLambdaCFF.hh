#ifndef EVTKKLAMBDACFF_HH
#define EVTKKLAMBDACFF_HH

#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

class EvtKKLambdaCFF : public EvtSemiLeptonicFF {
  public:
    EvtKKLambdaCFF( int numarg, double* arglist );

    void getscalarff( EvtId parent, EvtId daught, double t, double mass,
                      double* f0p, double* f0m ) override;

    void getvectorff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void gettensorff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void getbaryonff( EvtId parent, EvtId daught, double t, double mass,
                      double* f1v, double* f1a, double* f2v,
                      double* f2a ) override;

    void getdiracff( EvtId, EvtId, double, double, double*, double*, double*,
                     double*, double*, double* ) override;

    void getraritaff( EvtId, EvtId, double, double, double*, double*, double*,
                      double*, double*, double*, double*, double* ) override;

  private:
    int _nargs;
    double _args[2];
};

#endif
