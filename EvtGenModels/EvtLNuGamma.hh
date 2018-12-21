//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 2001  Caltech
//
// Module: EvtGen/EvtLNuGamma.hh
//
// Description: B+ -> l+ nu gamma.  Form factor is tree level, from
//  Korchemsky, Pirjol, and Yan,Phy Rev D 61 (200) 114510
//
//
// Modification history:
//
//    Edward Chen     April 24, 2001         Module created
//
//------------------------------------------------------------------------

#ifndef EVTLNUGAMMA_HH
#define EVTLNUGAMMA_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtLNuGamma:public  EvtDecayAmp  {

public:

  std::string getName() override;
  EvtDecayBase* clone() override;

  void decay(EvtParticle *p) override;
  void init() override;
  void initProbMax() override;
  double getFormFactor(double photonEnergy);

  bool _fafvzero = false;

};

#endif
