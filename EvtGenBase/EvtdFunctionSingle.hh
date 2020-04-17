#ifndef EVTDFUNCTIONSINGLE_HH
#define EVTDFUNCTIONSINGLE_HH

// Description:Evaluation of one Wigner d-Functions

class EvtdFunctionSingle {
  public:
    EvtdFunctionSingle();
    ~EvtdFunctionSingle();

    void init( int j, int m1, int m2 );

    double d( int j, int m1, int m2, double theta );

  private:
    int fact( int n );

    int _j;
    int _m1;
    int _m2;

    double* _coef;

    int _kmin;
    int _kmax;
};

#endif
