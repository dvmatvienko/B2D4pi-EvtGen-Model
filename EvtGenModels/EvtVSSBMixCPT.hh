//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 2002    INFN-Pisa
//
// Module: EvtGen/EvtVSSBMixCPT.hh
//
// Description:
//    Routine to decay vector-> scalar scalar with coherent BB-like mixing
//                              including CPT effects
//    Based on VSSBMIX
//
// Modification history:
//
//    F. Sandrelli, Fernando M-V March 03, 2002
//
//------------------------------------------------------------------------

#ifndef EVTVSSBMIXCPT_HH
#define EVTVSSBMIXCPT_HH

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtParticle.hh"

class EvtVSSBMixCPT : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;

    int nRealDaughters() override { return 2; }

    std::string getParamName( int i ) override;
    std::string getParamDefault( int i ) override;

  private:
    double _freq;    // mixing frequency in hbar/mm
    double _dGamma;
    EvtComplex _qoverp;
    EvtComplex _poverq;
    EvtComplex _z;
    double _chib0_b0bar;
    double _chib0bar_b0;

    EvtComplex _A_f;
    EvtComplex _Abar_f;

    EvtComplex _A_fbar;
    EvtComplex _Abar_fbar;
};

#endif
