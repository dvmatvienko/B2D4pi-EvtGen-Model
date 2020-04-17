#ifndef EVTPARTICLEDECAYLIST_HH
#define EVTPARTICLEDECAYLIST_HH

#include "EvtGenBase/EvtParticleDecay.hh"

typedef EvtParticleDecay* EvtParticleDecayPtr;

class EvtParticleDecayList {
  public:
    EvtParticleDecayList()
    {
        _decaylist = 0;
        _nmode = 0;
        _rawbrfrsum = 0;
    }

    EvtParticleDecayList( const EvtParticleDecayList& o );

    ~EvtParticleDecayList();

    EvtParticleDecayList& operator=( const EvtParticleDecayList& o );

    int getNMode() const { return _nmode; }

    void setNMode( int nmode );

    EvtDecayBase* getDecayModel( EvtParticle* p );
    EvtDecayBase* getDecayModel( int imode );

    EvtParticleDecay& getDecay( int nchannel ) const;

    double getRawBrfrSum() { return _rawbrfrsum; }
    void setRawBrfrSum( double rawbrfrsum ) { _rawbrfrsum = rawbrfrsum; }

    void makeChargeConj( EvtParticleDecayList* conjDecayList );

    void removeDecay();

    void alocateDecay( int nmode )
    {
        _decaylist = new EvtParticleDecayPtr[nmode];
    }

    void removeMode( EvtDecayBase* decay );

    void addMode( EvtDecayBase* decay, double brfr, double massmin );
    void finalize();

    void printSummary();

    bool isJetSet() const;

  private:
    EvtParticleDecayPtr* _decaylist;

    double _rawbrfrsum;
    int _nmode;
};

#endif
