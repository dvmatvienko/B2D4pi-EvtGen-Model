#ifndef EVTBTOSLLFFNEW_HH
#define EVTBTOSLLFFNEW_HH

#include "EvtGenBase/EvtId.hh"

// Description: This is the NEW base class for form factors in b->sll transitions.

class EvtbTosllFFNew {
  public:
    virtual ~EvtbTosllFFNew(){};

    virtual void getScalarFF( EvtId /*parent*/, EvtId /*daught*/, double /*t*/,
                              double& /*fp*/, double& /*f0*/, double& /*ft*/ )
    {
        return;
    }

    virtual void getVectorFF( EvtId /*parent*/, EvtId /*daught*/, double /*t*/,
                              double& /*a1*/, double& /*a2*/, double& /*a0*/,
                              double& /*v*/, double& /*t1*/, double& /*t2*/,
                              double& /*t3*/ )
    {
        return;
    }

    virtual double getQuarkMass( int /*i*/ ) { return 0.0; }
};

#endif
