#ifndef EVTHQET2FF_HH
#define EVTHQET2FF_HH

#include "EvtGenBase/EvtSemiLeptonicFF.hh"

class EvtId;

class EvtHQET2FF : public EvtSemiLeptonicFF {
  public:
    EvtHQET2FF( double hqetrho2, double hqetha1_1, double hqetr1_1,
                double hqetr2_1 );
    EvtHQET2FF( double hqetrho2, double hqetv1_1 );
    EvtHQET2FF( double hqetrho2, double hqetha1_1, double hqetr1_1,
                double hqetr2_1, double hqetr0_1 );
    EvtHQET2FF( double hqetrho2, double hqetv1_1, double indelta );
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
    double r1_1;
    double rho2;
    double r2_1;
    double ha1_1;
    double v1_1;
    double r0_1;
    double delta;
    bool extended;
};

#endif
