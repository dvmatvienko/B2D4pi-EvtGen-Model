#ifndef __EVTMPARTICLE_HH__
#define __EVTMPARTICLE_HH__

#include "EvtGenBase/EvtMNode.hh"

class EvtMParticle : public EvtMNode {
  public:
    EvtMParticle( int label, const EvtId& id );
    ~EvtMParticle() {}
    EvtSpinAmp amplitude( const vector<EvtVector4R>& product ) const override;
    int getnchild() const override { return 0; }

    EvtComplex line( const vector<EvtVector4R>& /*product*/ ) const override
    {
        return EvtComplex( 1.0, 0.0 );
    }

    EvtMNode* duplicate() const override;
};

#endif
