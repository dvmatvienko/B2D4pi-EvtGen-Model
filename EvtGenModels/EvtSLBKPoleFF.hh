#ifndef EVTSLBKPOLEFF_HH    //modified
#define EVTSLBKPOLEFF_HH    //modified

#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"    //modified

// Description:Form factor routines for EvtSLBKPole,
//             according to Becirevic and Kaidalov(BK)

class EvtSLBKPoleFF : public EvtSemiLeptonicFF {    //modified

  public:
    EvtSLBKPoleFF( int numarg, double* arglist );    //modified
    void getscalarff( EvtId parent, EvtId daught, double t, double mass,
                      double* fpf, double* f0f ) override;
    void getvectorff( EvtId parent, EvtId daught, double t, double mass,
                      double* a1f, double* a2f, double* vf,
                      double* a0f ) override;
    void gettensorff( EvtId parent,
                      EvtId daught,    //need to be modified, but not yet
                      double t, double mass, double* hf, double* kf, double* bp,
                      double* bm ) override;

    void getbaryonff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void getdiracff( EvtId, EvtId, double, double, double*, double*, double*,
                     double*, double*, double* ) override;

    void getraritaff( EvtId, EvtId, double, double, double*, double*, double*,
                      double*, double*, double*, double*, double* ) override;

  private:
    int numSLBKPoleargs;        //modified
    double SLBKPoleargs[16];    //modified
};

#endif
