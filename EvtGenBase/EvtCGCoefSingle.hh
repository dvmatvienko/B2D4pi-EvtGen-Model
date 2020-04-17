#ifndef EVTCGCOEFSINGLE_HH
#define EVTCGCOEFSINGLE_HH

#include <vector>

class EvtCGCoefSingle final {
  public:
    EvtCGCoefSingle( int j1, int j2 ) { init( j1, j2 ); }

    double coef( int J, int M, int j1, int j2, int m1, int m2 );

  private:
    void init( int j1, int j2 );
    double& cg( int J, int M, int m1, int m2 );

    int _j1;
    int _j2;

    int _Jmax;
    int _Jmin;

    std::vector<std::vector<std::vector<double>>> _table;
};

#endif
