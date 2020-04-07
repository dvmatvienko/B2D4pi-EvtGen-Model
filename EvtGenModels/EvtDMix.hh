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
// Module: EvtGen/EvtPhsp.hh
//
// Description:
//Class to handle generic phase space decays not done
//in other decay models.
//
// Modification history:
//
//    DJL/RYD     August 11, 1998         Module created
//
//------------------------------------------------------------------------

#ifndef EVTDMIX_HH
#define EVTDMIX_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

class EvtParticle;

class EvtDMix:public  EvtDecayIncoherent  {

public:

  std::string getName() override;

  EvtDecayBase* clone() override;

  void initProbMax() override;

  void init() override;

  void decay(EvtParticle *p) override;

private:
  double _rd;
  double _xpr;
  double _ypr;

};

#endif

