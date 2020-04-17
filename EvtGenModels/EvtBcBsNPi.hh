#ifndef EvtBcBsNpi_HH
#define EvtBcBsNpi_HH

#include "EvtGenBase/EvtDecayBase.hh"

#include "EvtGenModels/EvtBcToNPi.hh"

#include <string>

// Description: Decay model for Bc -> Bs + npi

class EvtBcBsNPi : public EvtBcToNPi {
  public:
    EvtBcBsNPi();

    void init() override;
    void initProbMax() override;

    std::string getName() override;
    EvtBcBsNPi* clone() override;
};

#endif
