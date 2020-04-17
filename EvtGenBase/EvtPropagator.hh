#ifndef EVT_PROPAGATOR_HH
#define EVT_PROPAGATOR_HH

#include "EvtGenBase/EvtAmplitude.hh"
#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtPoint1D.hh"

#include <assert.h>

// Defines propagator as a function of mass and width

class EvtPropagator : public EvtAmplitude<EvtPoint1D> {
  public:
    EvtPropagator( double m0, double g0 ) : _m0( m0 ), _g0( g0 )
    {
        assert( m0 > 0 );
        assert( g0 >= 0 );
    }

    // Accessors

    inline double m0() const { return _m0; }
    inline double g0() const { return _g0; }

    // Modifiers (can be useful e.g. for fitting!)

    inline void set_m0( double m0 )
    {
        assert( m0 > 0 );
        _m0 = m0;
    }
    inline void set_g0( double g0 )
    {
        assert( g0 >= 0 );
        _g0 = g0;
    }

  protected:
    double _m0;
    double _g0;
};

#endif
