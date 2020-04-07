//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 2001        Royal Holloway, University of London
//
// Module: EvtGen/EvtSVVNONCPEIGEN.hh
//
// Description:  See EvtSVVNONCPEIGEN.cc
//
// Modification history:
//
//    Ajit Kurup   9 March 2001      Module created (from EvtSVSNONCPEIGEN.hh)
//
//------------------------------------------------------------------------

#ifndef EVTSVVNONCPEIGEN_HH
#define EVTSVVNONCPEIGEN_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtSVVNONCPEIGEN:public  EvtDecayAmp  {

public:

  std::string getName() override;
  EvtDecayBase* clone() override;

  void initProbMax() override;
  void init() override;

  void decay(EvtParticle *p) override;

  std::string getParamName(int i) override;
  std::string getParamDefault(int i) override;

private:

  EvtComplex _A_f[12];
};

#endif
