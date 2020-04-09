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
// Module: EvtGen/EvtVtoSll.hh
//
// Description:
//
// Modification history:
//
//    RYD    Feb. 28, 2009         Module created
//
//------------------------------------------------------------------------

#ifndef EVTVTOSLL_HH
#define EVTVTOSLL_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtVtoSll : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;
    void decay( EvtParticle* p ) override;
};

#endif
