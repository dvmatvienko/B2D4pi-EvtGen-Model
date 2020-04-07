//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package. If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//
// Module: EvtGenModels/EvtBcBsStarNPi.hh
//
// Description: Decay model for Bc -> Bs* + npi
//
// Modification history:
//
//    A.Berezhnoy, A.Likhoded, A.Luchinsky  April 2011   Module created
//
//------------------------------------------------------------------------

#ifndef EvtBcBsStarNpi_HH
#define EvtBcBsStarNpi_HH

#include "EvtGenModels/EvtBcToNPi.hh"
#include "EvtGenBase/EvtDecayBase.hh"

#include <string>

class EvtBcBsStarNPi : public EvtBcToNPi {
public:

  EvtBcBsStarNPi();
  void init() override;

  void initProbMax() override;

  std::string getName() override;
  EvtBcBsStarNPi* clone() override;

};

#endif
