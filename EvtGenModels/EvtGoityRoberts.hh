#ifndef EVTGOITYROBERTS_HH
#define EVTGOITYROBERTS_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;
class EvtId;

class EvtGoityRoberts : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void decay( EvtParticle* p ) override;
    void initProbMax() override;

  private:
    void DecayBDstarpilnuGR( EvtParticle* pb, EvtId ndstar, EvtId nlep,
                             EvtId nnu );

    void DecayBDpilnuGR( EvtParticle* pb, EvtId nd, EvtId nlep, EvtId nnu );
};

#endif
