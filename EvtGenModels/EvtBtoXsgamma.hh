//--------------------------------------------------------------------------
//
//
// Copyright Information: See EvtGen/COPYRIGHT
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
//
// Module: EvtGen/EvtBtoXsgamma.hh
//
// Description:
// Class to generate non-resonant two-body b->s,gamma decays.
//
// Modification history:
//
//    Mark Ian Williams       July 20, 2000       Module created
//
//------------------------------------------------------------------------

#ifndef EVTBTOXSGAMMA_HH
#define EVTBTOXSGAMMA_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

#include "EvtGenModels/EvtBtoXsgammaAbsModel.hh"

#include <memory>

class EvtParticle;
class EvtBtoXsgamma : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void initProbMax() override;

    void init() override;

    void decay( EvtParticle* p ) override;

  private:
    std::unique_ptr<EvtBtoXsgammaAbsModel> _model;
};

#endif
