#ifndef __EVTMHELAMP_HH__
#define __EVTMHELAMP_HH__

#include "EvtGenBase/EvtMRes.hh"

class EvtMHelAmp : public EvtMRes {
  public:
    EvtMHelAmp( const EvtId& id, EvtMLineShape*, const vector<EvtMNode*>&,
                const vector<EvtComplex>& );
    ~EvtMHelAmp(){};

    EvtSpinAmp amplitude( const vector<EvtVector4R>& product ) const override;

    EvtMNode* duplicate() const override;

  private:
    vector<EvtComplex> _elem;
};

#endif
