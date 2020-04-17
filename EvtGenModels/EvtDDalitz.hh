#ifndef EVTDDALITZ_HH
#define EVTDDALITZ_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtFlatte.hh"

#include <vector>

class EvtParticle;

class EvtDDalitz : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

  private:
    int _d1, _d2, _d3, _flag;

    EvtComplex amplDtoK0PiPi( EvtVector4R p4_p, EvtVector4R moms1,
                              EvtVector4R moms2, EvtVector4R moms3 );
    EvtComplex amplDtoK0KK( EvtVector4R p4_p, EvtVector4R moms1,
                            EvtVector4R moms2, EvtVector4R moms3 );

    vector<EvtFlatteParam> _kkpi_params;
};

#endif
