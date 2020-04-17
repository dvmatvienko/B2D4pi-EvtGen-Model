#ifndef EVTVPHOTOVISRHI_HH
#define EVTVPHOTOVISRHI_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include <string>

class EvtParticle;

class EvtVPHOtoVISRHi : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;
};

#endif
