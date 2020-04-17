#ifndef EVTBTODIBARYONLNUPQCD_HH
#define EVTBTODIBARYONLNUPQCD_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include "EvtGenModels/EvtBToDiBaryonlnupQCDFF.hh"
#include "EvtGenModels/EvtSLDiBaryonAmp.hh"

#include <memory>
#include <string>

class EvtParticle;

// Description: Class to handle semileptonic B -> Baryon Anti-baryon l nu decays
// using the using form factor predictions from pQCD counting rules. Taken
// from arXiv:1107.0801

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
