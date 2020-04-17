#ifndef EVTDECAYAMP_HH
#define EVTDECAYAMP_HH

#include "EvtGenBase/EvtAmp.hh"
#include "EvtGenBase/EvtDecayBase.hh"

// Description: Baseclass for models that calculates amplitudes

class EvtDecayAmp : public EvtDecayBase {
  public:
    void makeDecay( EvtParticle* p, bool recursive = true ) override;
    inline void setWeight( double weight ) { _weight = weight; }

    /**
  * sets the amplitudes calculated in the decay objects
  */
    void vertex( const EvtComplex& amp ) { _amp2.vertex( amp ); }

    /**
  * sets the amplitudes calculated in the decay objects
  */
    void vertex( int i1, const EvtComplex& amp ) { _amp2.vertex( i1, amp ); }

    /**
  * sets the amplitudes calculated in the decay objects
  */
    void vertex( int i1, int i2, const EvtComplex& amp )
    {
        _amp2.vertex( i1, i2, amp );
    }

    /**
  * sets the amplitudes calculated in the decay objects
  */
    void vertex( int i1, int i2, int i3, const EvtComplex& amp )
    {
        _amp2.vertex( i1, i2, i3, amp );
    }

    /**
  * sets the amplitudes calculated in the decay objects
  */
    void vertex( int* i1, const EvtComplex& amp ) { _amp2.vertex( i1, amp ); }

    /**
   *  Provide access to the amplitude
   */
    const EvtAmp& amplitude() const { return _amp2; }

    virtual ~EvtDecayAmp() {}

  protected:
    EvtAmp _amp2;

  private:
    double _weight;
};

#endif
