#ifndef EVTSSDCP_HH
#define EVTSSDCP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

// Description: This module is part of the unification of simulation of CP violation in
//              B decays. This model handles decays of the type B->SD where D is either
//              a spin 0, 1, or 2 particle. See long writeup for more information.

class EvtSSDCP : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;
    void decay( EvtParticle* p ) override;

    std::string getParamName( int i ) override;
    std::string getParamDefault( int i ) override;

  private:
    //Arguments

    double _dm;

    double _dgog;

    EvtComplex _qoverp;
    EvtComplex _poverq;
    EvtComplex _z;    //FS CPTV parameter

    // FS commented next line becuse not used
    //  int _cp;

    EvtComplex _A_f;
    EvtComplex _Abar_f;

    EvtComplex _A_fbar;
    EvtComplex _Abar_fbar;

    //Derived quantities

    double _gamma;
    double _dgamma;

    bool _eigenstate;
};

#endif
