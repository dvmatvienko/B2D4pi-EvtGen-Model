#ifndef EvtDecayProb_HH
#define EvtDecayProb_HH

#include "EvtGenBase/EvtDecayBase.hh"

class EvtParticle;

class EvtDecayProb : public EvtDecayBase {
  public:
    void makeDecay( EvtParticle* p, bool recursive = true ) override;

    void setProb( double prob ) { _prob = prob; }
    double getProb() { return _prob; }
    inline void setWeight( double weight ) { _weight = weight; }

    virtual ~EvtDecayProb() {}

  private:
    double _prob;
    double _weight;
};

#endif
