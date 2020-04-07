//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information:
//      Copyright (C) 1998      Caltech, UCSB
//
// Module: EvtGen/EvtBaryonPCR.hh
//
// Description:Implementation of the BaryonPCR model
// Class to handle semileptonic decays using the BaryonVminusA
// model.
//
// Modification history:
//
//    R.J. Tesarek     May 28, 2004     Module created
//    Karen Gibson     1/20/2006        Module updated for 1/2+->1/2+,
//                                      1/2+->1/2-, 1/2+->3/2- Lambda decays
//
//------------------------------------------------------------------------

#ifndef EVTBARYONPCR_HH
#define EVTBARYONPCR_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"
#include "EvtGenBase/EvtSemiLeptonicBaryonAmp.hh"
#include <memory>

class EvtParticle;

class EvtBaryonPCR:public  EvtDecayAmp  {

public:

  std::string getName() override;
  EvtBaryonPCR* clone() override;

  void decay(EvtParticle *p) override;
  void initProbMax() override;
  void init() override;

private:
  std::unique_ptr<EvtSemiLeptonicFF> baryonpcrffmodel;
  std::unique_ptr<EvtSemiLeptonicBaryonAmp> calcamp;
};

#endif

