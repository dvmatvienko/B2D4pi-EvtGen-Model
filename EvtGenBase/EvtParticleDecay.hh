#ifndef EVTPARTICLEDECAY_HH
#define EVTPARTICLEDECAY_HH

#include "EvtGenBase/EvtDecayBase.hh"

class EvtParticleDecay {
  public:
    EvtParticleDecay()
    {
        _decay = 0;
        _brfrsum = 0.0;
        _massmin = 0.0;
    }

    ~EvtParticleDecay()
    {
        if ( _decay != 0 )
            delete _decay;
    }

    void chargeConj( EvtParticleDecay* decay );

    void setDecayModel( EvtDecayBase* decay ) { _decay = decay; }
    EvtDecayBase* getDecayModel() { return _decay; }
    double getBrfrSum() { return _brfrsum; }
    void setBrfrSum( double brfrsum ) { _brfrsum = brfrsum; }
    double getMassMin() { return _massmin; }
    void setMassMin( double massmin ) { _massmin = massmin; }

    void printSummary();

  private:
    EvtDecayBase* _decay;

    double _brfrsum;
    double _massmin;
};

#endif
