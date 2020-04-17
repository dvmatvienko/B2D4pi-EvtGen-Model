#ifndef EVT_PTO3P_HH
#define EVT_PTO3P_HH

#include "EvtGenBase/EvtDalitzPoint.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include "EvtGenModels/EvtIntervalDecayAmp.hh"

#include <vector>

class EvtPto3P : public EvtIntervalDecayAmp<EvtDalitzPoint> {
  public:
    EvtPto3P() {}
    ~EvtPto3P() {}
    std::string getName() override { return "PTO3P"; }
    EvtDecayBase* clone() override { return new EvtPto3P(); }

    EvtAmpFactory<EvtDalitzPoint>* createFactory(
        const EvtMultiChannelParser& parser ) override;
    std::vector<EvtVector4R> initDaughters( const EvtDalitzPoint& p ) const override;

    EvtDalitzPlot dp();
};

#endif
