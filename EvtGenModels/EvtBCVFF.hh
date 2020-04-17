#ifndef EVTBCVFF_HH
#define EVTBCVFF_HH

#include "EvtGenBase/EvtSemiLeptonicFF.hh"

class EvtId;

// Description: Form factors for EvtBCVFF model

class EvtBCVFF : public EvtSemiLeptonicFF {
  public:
    EvtBCVFF( int idV, int fit );
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
    int idVector, whichfit;
    double MBc, MD0, Mpsi, Mpsi2S, kappa, Mchi;
};

#endif
