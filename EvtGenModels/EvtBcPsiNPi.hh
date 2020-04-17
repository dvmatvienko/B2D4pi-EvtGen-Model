#ifndef EvtBcPsiNpi_HH
#define EvtBcPsiNpi_HH

#include "EvtGenBase/EvtDecayBase.hh"

#include "EvtGenModels/EvtBcToNPi.hh"

#include <string>

// Description: Decay model for Bc -> J/psi + npi

class EvtBcPsiNPi : public EvtBcToNPi {
  public:
    EvtBcPsiNPi();

    void init() override;
    void initProbMax() override;

    std::string getName() override;
    EvtBcPsiNPi* clone() override;
};

#endif
