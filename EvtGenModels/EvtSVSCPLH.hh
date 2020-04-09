//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 1999      Caltech, UCSB
//
// Module: EvtGen/EvtSVSCPLH.hh
//
// Description:
//
// Modification history:
//
//    Ryd       March 29, 2001         Module created
//
//------------------------------------------------------------------------

#ifndef EVTSVSCPLH_HH
#define EVTSVSCPLH_HH

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtSVSCPLH : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;

    void decay( EvtParticle* p ) override;

  private:
    EvtComplex _Af, _Abarf;
    EvtComplex _qop, _poq;

    double _dm;
    double _dgamma;
};

#endif
