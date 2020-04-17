#ifndef EVT_FLAT_AMP_HH
#define EVT_FLAT_AMP_HH

#include "EvtGenBase/EvtAmplitude.hh"

// Flat amplitude

template <class T>
class EvtFlatAmp : public EvtAmplitude<T> {
  public:
    EvtFlatAmp() {}
    EvtFlatAmp( const EvtFlatAmp<T>& other ) : EvtAmplitude<T>( other ) {}
    virtual ~EvtFlatAmp() {}

    EvtAmplitude<T>* clone() const override
    {
        return new EvtFlatAmp<T>( *this );
    }
    EvtComplex amplitude( const T& ) const override
    {
        return EvtComplex( 1., 0. );
    }
};

#endif
