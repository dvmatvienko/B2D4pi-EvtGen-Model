#ifndef EVTEVALHELAMP_HH
#define EVTEVALHELAMP_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtSpinType.hh"

class EvtParticle;
class EvtAmp;

class EvtEvalHelAmp {
  public:
    EvtEvalHelAmp( EvtId idA, EvtId idB, EvtId idC, EvtComplexPtrPtr HBC );

    virtual ~EvtEvalHelAmp();

    double probMax();

    void evalAmp( EvtParticle* p, EvtAmp& amp );

  private:
    void fillHelicity( int* lambda2, int n, int J2, EvtId id );
    void setUpRotationMatrices( EvtParticle* p, double theta, double phi );
    void applyRotationMatrices();

    //spins states available for particle A, B, and C.
    int _nA, _nB, _nC;

    //helicity amplitudes
    EvtComplexPtrPtr _HBC;

    //2 times spin for each of the particles
    int _JA2, _JB2, _JC2;

    //2 times the helicity for the states
    int *_lambdaA2, *_lambdaB2, *_lambdaC2;

    //Rotation matrices
    EvtComplexPtrPtr _RA, _RB, _RC;

    //temporary array for amplitudes
    EvtComplexPtrPtrPtr _amp, _amp1, _amp3;
};

#endif
