//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 2004      Cornell
//
// Module: EvtGen/EvtVPHOtoVISR.hh
//
// Description:
//
// Modification history:
//
//    Ryd      March 20, 2004      Module created
//
//------------------------------------------------------------------------

#ifndef EVTVPHOTOVISR_HH
#define EVTVPHOTOVISR_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtVPHOtoVISR : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;
};

#endif
