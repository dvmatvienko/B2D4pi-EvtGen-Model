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
// Module: EvtGen/EvtBToDiBaryonlnupQCD.hh
//
// Description: Class to handle semileptonic B -> Baryon Anti-baryon l nu decays
// using the using form factor predictions from pQCD counting rules. Taken
// from arXiv:1107.0801
//
//
// Modification history:
//
//    Mark Smith     July 17, 2017     Module created
//    John B         Oct 2018          Code simplification
//
//------------------------------------------------------------------------

#ifndef EVTBTODIBARYONLNUPQCD_HH
#define EVTBTODIBARYONLNUPQCD_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include "EvtGenModels/EvtBToDiBaryonlnupQCDFF.hh"
#include "EvtGenModels/EvtSLDiBaryonAmp.hh"

#include <memory>
#include <string>

class EvtParticle;

class EvtBToDiBaryonlnupQCD : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void initProbMax() override;
    void init() override;

  private:
    std::unique_ptr<EvtBToDiBaryonlnupQCDFF> ffModel_;
    std::unique_ptr<EvtSLDiBaryonAmp> calcAmp_;
};

#endif
