#ifndef EVTISGW_HH
#define EVTISGW_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>
class EvtParticle;

class EvtISGW : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> isgwffmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
};

#endif
