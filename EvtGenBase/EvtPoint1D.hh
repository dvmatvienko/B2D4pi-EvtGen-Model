#ifndef EVT_POINT_1D_HH
#define EVT_POINT_1D_HH

// Point on a finite 1-D interval. isValid shows whether for a given specification,
// the coordinate _value is inside the interval defined by _min, _max.

class EvtPoint1D final {
  public:
    EvtPoint1D();
    EvtPoint1D( double value );
    EvtPoint1D( double min, double max, double value );

    bool isValid() const { return _valid; }

    double value() const { return _value; }

    void print() const;

  private:
    double _min;    // interval minimum
    double _max;    // interval maximum
    double _value;
    bool _valid;    // valid point inside the interval?
};

#endif
