#ifndef EVT_AMPLITUDE_HH
#define EVT_AMPLITUDE_HH

#include "EvtGenBase/EvtComplex.hh"

// Complex-valued amplitude

template <class T>
class EvtAmplitude {
  public:
    EvtAmplitude() = default;
    EvtAmplitude( const EvtAmplitude& ) = default;
    EvtAmplitude( EvtAmplitude&& ) = default;
    EvtAmplitude& operator=( const EvtAmplitude& ) = default;
    EvtAmplitude& operator=( EvtAmplitude&& ) = default;
    virtual ~EvtAmplitude() = default;

    virtual EvtAmplitude<T>* clone() const = 0;

    EvtComplex evaluate( const T& p ) const
    {
        EvtComplex ret( 0., 0. );
        if ( p.isValid() )
            ret = amplitude( p );
        return ret;
    }

  protected:
    // Derive in subclasses to define amplitude computation
    // for a fully constructed amplitude object.

    virtual EvtComplex amplitude( const T& ) const = 0;
};

#endif
