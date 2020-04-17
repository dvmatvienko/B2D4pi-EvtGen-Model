#ifndef EVT_TWO_BODY_VERTEX_HH
#define EVT_TWO_BODY_VERTEX_HH

#include "EvtGenBase/EvtBlattWeisskopf.hh"
#include "EvtGenBase/EvtTwoBodyKine.hh"

#include <iostream>
#include <memory>

// Two-body propagator vertex AB->A,B with an attached Blatt-Weisskopf form factor.

class EvtTwoBodyVertex {
  public:
    EvtTwoBodyVertex();
    EvtTwoBodyVertex( double mA, double mB, double mAB, int L );
    EvtTwoBodyVertex( const EvtTwoBodyVertex& other );
    EvtTwoBodyVertex& operator=( const EvtTwoBodyVertex& other );

    double widthFactor( EvtTwoBodyKine x ) const;
    double formFactor( EvtTwoBodyKine x ) const;
    double phaseSpaceFactor( EvtTwoBodyKine x, EvtTwoBodyKine::Index ) const;

    inline int L() const { return _LL; }
    inline double mA() const { return _kine.mA(); }
    inline double mB() const { return _kine.mB(); }
    inline double mAB() const { return _kine.mAB(); }
    inline double pD() const { return _p0; }
    void print( std::ostream& os ) const;

    void set_f( double R );

  private:
    EvtTwoBodyKine _kine;
    int _LL;
    double _p0;
    std::unique_ptr<EvtBlattWeisskopf> _f;    // optional Blatt-Weisskopf form factor
};

std::ostream& operator<<( std::ostream& os, const EvtTwoBodyVertex& v );

#endif
