#ifndef EVTBTOVLNUBALLFF_HH
#define EVTBTOVLNUBALLFF_HH

#include "EvtGenBase/EvtSemiLeptonicFF.hh"

class EvtId;

// Description:   B->Xu l nu with the Ball/Zwicky decay model
//                Xu is a vector (rho, rho0, omega)

class EvtBToVlnuBallFF : public EvtSemiLeptonicFF {
  public:
    EvtBToVlnuBallFF( double r2_A1, double mfit2_A1, double r1_A2, double r2_A2,
                      double mfit2_A2, double r1_V, double r2_V, double mfit2_V );

    void getvectorff( EvtId parent, EvtId daught, double t, double mass,
                      double* a1f, double* a2f, double* vf,
                      double* a0f ) override;

    void getscalarff( EvtId, EvtId, double, double, double*, double* ) override;

    void gettensorff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void getbaryonff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void getdiracff( EvtId, EvtId, double, double, double*, double*, double*,
                     double*, double*, double* ) override;

    void getraritaff( EvtId, EvtId, double, double, double*, double*, double*,
                      double*, double*, double*, double*, double* ) override;

  private:
    double _r2_A1;
    double _mfit2_A1;
    double _r1_A2;
    double _r2_A2;
    double _mfit2_A2;
    double _r1_V;
    double _r2_V;
    double _mfit2_V;
};

#endif
