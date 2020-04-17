#ifndef EVTBTOSLLALIFF_HH
#define EVTBTOSLLALIFF_HH

#include "EvtGenModels/EvtbTosllFF.hh"

class EvtId;

// Description: Form factors for b->sll according to Ali '02 et al.
//              PRD 66 34002

class EvtbTosllAliFF : public EvtbTosllFF {
  public:
    EvtbTosllAliFF();

    void getScalarFF( EvtId parent, EvtId daught, double t, double mass,
                      double& fp, double& f0, double& ft ) override;
    void getVectorFF( EvtId parent, EvtId daught, double t, double mass,
                      double& a1, double& a2, double& a0, double& v, double& t1,
                      double& t2, double& t3 ) override;
};

#endif
