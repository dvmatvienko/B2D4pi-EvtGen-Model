#ifndef EVTBCTFF_HH
#define EVTBCTFF_HH

#include "EvtGenBase/EvtSemiLeptonicFF.hh"

class EvtId;

// Description: Form factors for EvtBCTFF model

class EvtBCTFF : public EvtSemiLeptonicFF {
  public:
    EvtBCTFF( int idV, int fit );
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
    int idTensor, whichfit;
    double MBc;
};

#endif
