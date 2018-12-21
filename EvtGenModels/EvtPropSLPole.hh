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
// Module: EvtGen/EvtPropSLPole.hh
//
// Description:Semileptonic decays with pole form form factors
//
// Modification history:
//
//    DJL     April 23, 1998         Module created
//
//------------------------------------------------------------------------

#ifndef EVTPROPSLPOLE_HH
#define EVTPROPSLPOLE_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtPoint1D.hh"
#include <memory>

class Evtparticle;

class EvtPropSLPole:public  EvtDecayAmp  {

public:

  std::string getName() override;
  EvtDecayBase* clone() override;

  void decay(EvtParticle *p) override;
  void initProbMax() override;
  void init() override;

  double calBreitWigner(EvtParticle *pmeson, EvtPoint1D point);
  double calBreitWignerBasic(double maxMass);

  double calcMaxProb( EvtId parent, EvtId meson, EvtId lepton, EvtId nudaug, EvtSemiLeptonicFF *FormFactors );

private:

  bool _includeDecayFact;
  bool _includeBirthFact;
  double _mass;
  double _massMin;
  double _massMax;
  double _width;
  double _maxRange;
  EvtSpinType::spintype _spin;

  double _blatt;
  bool _isProbMaxSet;

  std::unique_ptr<EvtSemiLeptonicFF> SLPoleffmodel;
  std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
};

#endif

