//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 2003      Caltech
//
// Module: EvtGen/EvtbsToLLLLHyperCP.hh
//
// Description:
//
// Modification history:
//
//  N.Nikitin (nnikit@mail.cern.ch)  May 30, 2012    Module created
//
//------------------------------------------------------------------------

#ifndef EVTBSTOLLLL_HYPERCP_HH
#define EVTBSTOLLLL_HYPERCP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;
class EvtbsToLLLLHyperCPAmp;    // my class with amplitudes for rare four-leptonic B-decays

class EvtbsToLLLLHyperCP : public EvtDecayAmp {
  public:
    EvtbsToLLLLHyperCP(){};
    virtual ~EvtbsToLLLLHyperCP();

    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;
    void decay( EvtParticle* p ) override;

  private:
    EvtbsToLLLLHyperCPAmp* _calcamp;
};

#endif
