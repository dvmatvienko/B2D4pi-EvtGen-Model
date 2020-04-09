//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 1998      Caltech, UCSB
//
// Module: EvtGen/EvtBCTFF.hh
//
// Description: Form factors for EvtBCTFF model
//
// Modification history:
//
//    DJL     April 20, 1998         Module created
//
//------------------------------------------------------------------------

#ifndef EVTBCTFF_HH
#define EVTBCTFF_HH

#include "EvtGenBase/EvtSemiLeptonicFF.hh"

class EvtId;

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
