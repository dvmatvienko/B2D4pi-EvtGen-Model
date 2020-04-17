#ifndef EVTHQETFF_HH
#define EVTHQETFF_HH

#include "EvtGenBase/EvtSemiLeptonicFF.hh"

class EvtId;

class EvtHQETFF : public EvtSemiLeptonicFF {
  public:
    EvtHQETFF( double hqetrho2, double hqetr1, double hqetr2, double hqetc = 0. );
    EvtHQETFF( double hqetrho2, double hqetc = 0. );
    void getvectorff( EvtId parent, EvtId daught, double t, double mass,
                      double* a1f, double* a2f, double* vf,
                      double* a0f ) override;

    void getscalarff( EvtId parent, EvtId daught, double t, double mass,
                      double* f0p, double* f0m ) override;

    void gettensorff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void getbaryonff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void getdiracff( EvtId, EvtId, double, double, double*, double*, double*,
                     double*, double*, double* ) override;

    void getraritaff( EvtId, EvtId, double, double, double*, double*, double*,
                      double*, double*, double*, double*, double* ) override;

  private:
    double r1;
    double rho2;
    double r2;
    double c;
};

#endif
