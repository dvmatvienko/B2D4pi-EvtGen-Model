#ifndef EVTSLPOLEFF_HH
#define EVTSLPOLEFF_HH

#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

// Description:Form factor routines for EvtSLPole

class EvtSLPoleFF : public EvtSemiLeptonicFF {
  public:
    EvtSLPoleFF( int numarg, double* arglist );
    void getscalarff( EvtId parent, EvtId daught, double t, double mass,
                      double* fpf, double* f0f ) override;
    void getvectorff( EvtId parent, EvtId daught, double t, double mass,
                      double* a1f, double* a2f, double* vf,
                      double* a0f ) override;
    void gettensorff( EvtId parent, EvtId daught, double t, double mass,
                      double* hf, double* kf, double* bp, double* bm ) override;

    void getbaryonff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void getdiracff( EvtId, EvtId, double, double, double*, double*, double*,
                     double*, double*, double* ) override;

    void getraritaff( EvtId, EvtId, double, double, double*, double*, double*,
                      double*, double*, double*, double*, double* ) override;

  private:
    int numSLPoleargs;
    double SLPoleargs[16];
};

#endif
