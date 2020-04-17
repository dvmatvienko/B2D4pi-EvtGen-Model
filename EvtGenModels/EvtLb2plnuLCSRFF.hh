#ifndef EVTLB2PMUNULCSRFF_HH
#define EVTLB2PMUNULCSRFF_HH

#include "EvtGenBase/EvtSemiLeptonicFF.hh"

class EvtId;

// Description: Module for computation of Lb->p form factors via LCSR

class EvtLb2plnuLCSRFF : public EvtSemiLeptonicFF {
  public:
    void getscalarff( EvtId parent, EvtId daught, double t, double mass,
                      double* fpf, double* f0f ) override;
    void getvectorff( EvtId parent, EvtId daught, double t, double mass,
                      double* a1f, double* a2f, double* vf,
                      double* a0f ) override;
    void gettensorff( EvtId parent, EvtId daught, double t, double mass,
                      double* hf, double* kf, double* bpf, double* bmf ) override;

    void getbaryonff( EvtId, EvtId, double, double, double*, double*, double*,
                      double* ) override;

    void getdiracff( EvtId parent, EvtId daught, double q2, double mass,
                     double* f1, double* f2, double* f3, double* g1, double* g2,
                     double* g3 ) override;

    void getraritaff( EvtId parent, EvtId daught, double q2, double mass,
                      double* f1, double* f2, double* f3, double* f4,
                      double* g1, double* g2, double* g3, double* g4 ) override;
};

#endif
