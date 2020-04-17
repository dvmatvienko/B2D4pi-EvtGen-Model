#ifndef EVTBS2LLGAMMAFF_HH
#define EVTBS2LLGAMMAFF_HH

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtId.hh"

// Description: This is the NEW base class for form factors in b->sll transitions.

class Evtbs2llGammaFF {
  public:
    virtual ~Evtbs2llGammaFF(){};

    virtual void getPhotonFF( int /*decay_id*/, double /*fb*/, EvtId /*parent*/,
                              double /*q2*/, double /*M1*/, double /*mb*/,
                              double /*mq*/, EvtComplex /*c7gam*/,
                              EvtComplex /*a1*/, EvtComplex /*lambda_qu */,
                              EvtComplex /*lambda_qc*/, EvtComplex& /*Fv*/,
                              EvtComplex& /*Fa*/, EvtComplex& /*Ftv*/,
                              EvtComplex& /*Fta*/ )
    {
        return;
    };

    virtual double getQuarkMass( int /*i*/ ) { return 0.0; };
};

#endif
