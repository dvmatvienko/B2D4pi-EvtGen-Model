//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 1998      Caltech, UCSB
//
// Module: EvtGenModels/EvtBToVlnuBall.hh
//
// Description:   B->Xu l nu with the Ball/Zwicky decay model
//                Xu is a vector (rho, rho0, omega)
//
// Modification history:
//
//    Wells Wulsin      2008 Aug 14         Module created
//
//------------------------------------------------------------------------

#ifndef EVTBTOVLNUBALL_HH
#define EVTBTOVLNUBALL_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>

class EvtParticle;

class EvtBToVlnuBall : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtBToVlnuBall* clone() override;

    void decay( EvtParticle* p ) override;
    void initProbMax() override;
    void init() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> _Ballmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> _calcamp;
};
#endif
