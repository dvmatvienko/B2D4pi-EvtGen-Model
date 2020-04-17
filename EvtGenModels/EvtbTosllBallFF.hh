#ifndef EVTBTOSLLBALLFF_HH
#define EVTBTOSLLBALLFF_HH

#include "EvtGenModels/EvtbTosllFF.hh"

class EvtId;

// Description: Form factors for b->sll according to Ali, Ball et al.
//              hep-ph/9910221v2

class EvtbTosllBallFF : public EvtbTosllFF {
  public:
    EvtbTosllBallFF( int );

    void getScalarFF( EvtId parent, EvtId daught, double t, double mass,
                      double& fp, double& f0, double& ft ) override;
    void getVectorFF( EvtId parent, EvtId daught, double t, double mass,
                      double& a1, double& a2, double& a0, double& v, double& t1,
                      double& t2, double& t3 ) override;

  private:
    int _theFFModel;
};

#endif
