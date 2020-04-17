#ifndef EVT_POINT_PRED_HH
#define EVT_POINT_PRED_HH

// Predicate testing validity of a point. The point class must provide
// bool isValid() method

template <class Point>
class EvtPointPred {
  public:
    typedef Point argument_type;
    typedef bool result_type;

    EvtPointPred() {}
    EvtPointPred( const EvtPointPred& ) {}
    ~EvtPointPred() {}

    result_type operator()( argument_type x ) { return x.isValid(); }
};
