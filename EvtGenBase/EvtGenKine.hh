#ifndef EVTGENKINE_HH
#define EVTGENKINE_HH

class EvtVector4R;

class EvtGenKine {
  public:
    static double PhaseSpace( int ndaug, double mass[30], EvtVector4R p4[30],
                              double mp );

    static double PhaseSpacePole( double M, double m1, double m2, double m3,
                                  double a, EvtVector4R p4[10] );
};

#endif
