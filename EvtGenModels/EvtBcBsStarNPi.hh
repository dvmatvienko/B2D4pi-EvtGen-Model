#ifndef EvtBcBsStarNpi_HH
#define EvtBcBsStarNpi_HH

#include "EvtGenBase/EvtDecayBase.hh"

#include "EvtGenModels/EvtBcToNPi.hh"

#include <string>

// Description: Decay model for Bc -> Bs* + npi

class EvtBcBsStarNPi : public EvtBcToNPi {
  public:
    EvtBcBsStarNPi();
    void init() override;

    void initProbMax() override;

    std::string getName() override;
    EvtBcBsStarNPi* clone() override;
};

#endif
