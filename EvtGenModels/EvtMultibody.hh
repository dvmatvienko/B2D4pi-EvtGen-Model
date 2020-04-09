#ifndef EVTMULTIBODY_HH
#define EVTMULTIBODY_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtMTree.hh"
#include "EvtGenBase/EvtSpinAmp.hh"

class EvtMultibody : public EvtDecayAmp {
  public:
    EvtMultibody()
    {
        _decayTree = NULL;
        _ilist = NULL;
    }
    ~EvtMultibody();

    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

  private:
    EvtMTree* _decayTree;
    int* _ilist;
};

#endif
