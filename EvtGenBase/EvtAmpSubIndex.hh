#ifndef EVTAMPSUBINDEX_HH
#define EVTAMPSUBINDEX_HH

#include <vector>
class EvtAmpIndex;

class EvtAmpSubIndex {
  public:
    EvtAmpSubIndex( EvtAmpIndex* ind, std::vector<int> sub );
    virtual ~EvtAmpSubIndex() {}

    int index();

  private:
    EvtAmpIndex* _ind;
    std::vector<int> _sub;
    int _size;
    std::vector<int> _nstate;
};

#endif
