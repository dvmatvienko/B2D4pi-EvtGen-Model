#ifndef EVTBTOSLLFF_HH
#define EVTBTOSLLFF_HH

#include "EvtGenBase/EvtId.hh"

// This is the base class for form factors in b->sll transitions.

class EvtbTosllFF {
  public:
    virtual ~EvtbTosllFF() = default;

    virtual void getScalarFF( EvtId /*parent*/, EvtId /*daught*/, double /*t*/,
                              double /*mass*/, double& /*fp*/, double& /*f0*/,
                              double& /*ft*/ )
    {
        return;
    }
    virtual void getVectorFF( EvtId /*parent*/, EvtId /*daught*/, double /*t*/,
                              double /*mass*/, double& /*a1*/, double& /*a2*/,
                              double& /*a0*/, double& /*v*/, double& /*t1*/,
                              double& /*t2*/, double& /*t3*/ )
    {
        return;
    }
};

#endif
