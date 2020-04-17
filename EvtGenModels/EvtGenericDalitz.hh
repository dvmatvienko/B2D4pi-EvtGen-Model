#ifndef EVTGENERICDALITZ_HH
#define EVTGENERICDALITZ_HH

#include "EvtGenBase/EvtDalitzReso.hh"
#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtFlatte.hh"

#include <string>
#include <vector>

class EvtParticle;

// Description: Model to describe a generic dalitz decay

class EvtGenericDalitz : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override{};    //prob max will be set in init

    void decay( EvtParticle* p ) override;

    std::string getParamName( int i ) override;

  private:
    int _d1, _d2, _d3;
    std::vector<std::pair<EvtComplex, EvtDalitzReso>> _resonances;
};

#endif
