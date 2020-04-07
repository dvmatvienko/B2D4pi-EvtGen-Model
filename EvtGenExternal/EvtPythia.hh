//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 1998      Caltech, UCSB
//                    2011      University of Warwick, UK
//
// Module: EvtGen/EvtPythia.hh
//
// Description:
// Class to handle generic phase space decays not done
// in other decay models.
//
// Modification history:
//
//    DJL/RYD     August 11, 1998         Module created
//    JJB         April 2011         Modified to use new Pythia8 interface
//
//------------------------------------------------------------------------

#ifndef EVTPYTHIA_HH
#define EVTPYTHIA_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

#include <string>
#include <vector>

class EvtParticle;
class EvtAbsExternalGen;
class EvtDecayBase;

class EvtPythia: public  EvtDecayIncoherent  {

public:

  EvtPythia();
  ~EvtPythia();

  std::string getName() override;

  EvtDecayBase* clone() override;

  void initProbMax() override;

  void init() override;

  void decay(EvtParticle *p) override;

  std::string commandName() override;
  void command(std::string) override;

protected:

  EvtAbsExternalGen* _pythiaEngine;

private:

  void fixPolarisations(EvtParticle *p);
  std::vector<std::string> _commandList;

};

#endif

