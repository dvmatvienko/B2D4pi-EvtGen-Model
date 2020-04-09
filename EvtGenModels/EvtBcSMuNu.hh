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
// Module: EvtGen/EvtBcSMuNu.hh
//
// Description:Implementation of the model for semileptonic Bc decays
//
// Modification history:
//
//    AVL     Jul 6, 2012             Module created
//    AVL     Feb 5, 2018            D0, D*0 modes added
//
//------------------------------------------------------------------------

#ifndef EVTBcSMuNu_HH
#define EVTBcSMuNu_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <fstream>
#include <memory>
#include <stdio.h>

class EvtParticle;

class EvtBcSMuNu : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;

    void initProbMax() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> ffmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
    int whichfit;
    int idScalar;
};

#endif
