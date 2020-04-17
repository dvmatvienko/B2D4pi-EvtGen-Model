#ifndef EVT_PDF_MAX_HH
#define EVT_PDF_MAX_HH

#include "EvtGenBase/EvtMacros.hh"

#include <cassert>

// Pdf maximum and its location

template <class Point>
class EvtPdfMax {
  public:
    EvtPdfMax() : _value( -1 ), _valueKnown( false ), _locKnown( false ) {}
    EvtPdfMax( double value ) :
        _value( value ), _valueKnown( true ), _locKnown( false )
    {
    }
    EvtPdfMax( Point p, double value ) :
        _value( value ), _valueKnown( true ), _locKnown( true ), _loc( p )
    {
    }

    bool valueKnown() const { return _valueKnown; }
    double value() const
    {
        assert( _valueKnown );
        return _value;
    }
    bool locKnown() const { return _locKnown; }
    Point loc() const
    {
        assert( _locKnown );
        return _loc;
    }

  private:
    double _value;
    bool _valueKnown;
    bool _locKnown;
    Point _loc;
};

#endif
