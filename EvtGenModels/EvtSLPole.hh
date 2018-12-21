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
// Module: EvtGen/EvtSLPole.hh
//
// Description:Semileptonic decays with pole form form factors
//
// Modification history:
//
//    DJL     April 23, 1998         Module created
//
//------------------------------------------------------------------------

#ifndef EVTSLPOLE_HH
#define EVTSLPOLE_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include <memory>

class Evtparticle;

class EvtSLPole:public  EvtDecayAmp  {

public:

  std::string getName() override;
  EvtDecayBase* clone() override;

  void decay(EvtParticle *p) override;
  void initProbMax() override;
  void init() override;

private:
  std::unique_ptr<EvtSemiLeptonicFF> SLPoleffmodel;
  std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
  //special case - reset the daughter masses
  bool _resetDaughterTree;

};

#endif

