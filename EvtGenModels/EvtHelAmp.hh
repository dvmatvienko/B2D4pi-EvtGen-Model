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
// Module: EvtGen/EvtHelAmp.hh
//
// Description:Decay model for implementation of generic 2 body
//             decay specified by the helicity amplitudes
//
// Modification history:
//
//    RYD      March 14, 1999         Module created
//
//------------------------------------------------------------------------

#ifndef EVTHELAMP_HH
#define EVTHELAMP_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtId.hh"
#include <memory>

class EvtParticle;
class EvtEvalHelAmp;

class EvtHelAmp:public  EvtDecayAmp{

public:

  std::string getName() override;
  EvtDecayBase* clone() override;

  void init() override;
  void initProbMax() override;

  void decay(EvtParticle *p) override;


private:

  void fillHelicity(int* lambda2,int n,int J2, EvtId id);

  std::unique_ptr<EvtEvalHelAmp> _evalHelAmp;

};

#endif
