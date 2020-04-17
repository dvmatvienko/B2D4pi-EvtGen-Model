#ifndef EVTORTHOGVECTOR_HH
#define EVTORTHOGVECTOR_HH

#include <vector>

class EvtOrthogVector final {
  public:
    EvtOrthogVector( int n, std::vector<double>* vectors );

    std::vector<double> getOrthogVector() { return _orthogVector; }

  private:
    int _dimen;
    std::vector<int> _holder;
    void findOrthog( int dim, std::vector<int> invect,
                     std::vector<double>* vectors );

    std::vector<double> _orthogVector;

    int findEvenOddSwaps();
};

#endif
