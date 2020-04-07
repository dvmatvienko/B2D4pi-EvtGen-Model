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
// Module: EvtGen/EvtSLBKPole.hh
//
// Description:Semileptonic decays with pole form form factors,
//             according to Becirevic and Kaidalov(BK)
//
// Modification history:
//
//    liheng     October 20, 2005         Module created
//
//------------------------------------------------------------------------

#ifndef EVTSLBKPOLE_HH//modified
#define EVTSLBKPOLE_HH//modified

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"//modified
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include <memory>
class Evtparticle;

class EvtSLBKPole:public  EvtDecayAmp  {

public:

  std::string getName() override;
  EvtDecayBase* clone() override;

  void decay(EvtParticle *p) override;
  void initProbMax() override;
  void init() override;

private:
  std::unique_ptr<EvtSemiLeptonicFF> SLBKPoleffmodel;//modified
  std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
};

#endif

