#ifndef EVTBTOPLNUBKFF_HH
#define EVTBTOPLNUBKFF_HH

#include "EvtGenBase/EvtSemiLeptonicFF.hh"

class EvtId;

// Description:   B->Xu l nu with BK (Becirevic-Kaidalov) parametrization
//                Xu is a pseudoscalar (pi_plus,pi0,eta or eta_prime)

class EvtBToPlnuBKFF : public EvtSemiLeptonicFF {
  public:
    EvtBToPlnuBKFF( double alpha, double beta );

    void getscalarff( EvtId parent, EvtId daught, double t, double mass,
                      double* fp, double* f0 ) override;

    void getvectorff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void gettensorff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void getbaryonff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void getdiracff( EvtId, EvtId, double, double, double*, double*, double*,
                     double*, double*, double* ) override;

    void getraritaff( EvtId, EvtId, double, double, double*, double*, double*,
                      double*, double*, double*, double*, double* ) override;

  private:
    double _alpha;
    double _beta;
};

#endif
