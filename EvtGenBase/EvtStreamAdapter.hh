#ifndef EVT_STREAM_ADAPTER_HH
#define EVT_STREAM_ADAPTER_HH

// Stream adapters are used to convert a stream-like input (for example,
// a file containing N entries) to an STL like iterator interface. There
// must be a way to get point from the stream, and also an indicator of the
// end of the stream.

template <class Point>
class EvtStreamAdapter {
  public:
    EvtStreamAdapter() {}
    virtual ~EvtStreamAdapter() {}
    virtual EvtStreamAdapter* clone() const = 0;
    virtual Point currentValue() = 0;
    virtual void advance() = 0;
    virtual bool pastEnd() = 0;
};

// N points are read from a generated stream.

template <class Point, class Generator>
class EvtGenStreamAdapter : public EvtStreamAdapter<Point> {
  public:
    EvtGenStreamAdapter( Generator gen, int count ) :
        _gen( gen ), _count( count )
    {
    }

    virtual ~EvtGenStreamAdapter() {}

    EvtStreamAdapter<Point>* clone() const override
    {
        return new EvtGenStreamAdapter( *this );
    }
    Point currentValue() override { return _gen(); }
    bool pastEnd() override { return ( _count <= 0 ); }
    void advance() override { _count--; }

  private:
    Generator _gen;
    int _count;    // also serves as past the end indicator
};

// Only points satisfying a predicate are read from the stream.

template <class Point, class Iterator, class Predicate>
class EvtPredStreamAdapter : public EvtStreamAdapter<Point> {
  public:
    EvtPredStreamAdapter( Predicate pred, Iterator it, Iterator end ) :
        _pred( pred ), _it( it ), _end( end )
    {
    }
    virtual ~EvtPredStreamAdapter() {}

    virtual EvtStreamAdapter<Point>* clone() const
    {
        return new EvtPredStreamAdapter( *this );
    }
    virtual Point currentValue()
    {
        Point value;
        while ( !pastEnd() ) {
            value = *_it;
            if ( _pred( value ) )
                break;
            _it++;
        }
        return value;
    }

    virtual bool pastEnd() { return _it == _end; }
    virtual void advance() { _it++; }

  private:
    Predicate _pred;
    Iterator _it;
    Iterator _end;
};

#endif
