// Generation of direct CP violation in hadronic environment
// Patrick Robbe, LHCb,  08 Nov 2006
//

#ifndef EVTSSD_DirectCP_HH
#define EVTSSD_DirectCP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtSSD_DirectCP : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;
    void decay( EvtParticle* p ) override;
    std::string getParamName( int i ) override;

  private:
    bool isB0Mixed( EvtParticle* p );
    bool isBsMixed( EvtParticle* p );

    //Arguments

    double _acp;
};

#endif
