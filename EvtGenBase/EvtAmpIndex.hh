#ifndef EVTAMPINDEX_HH
#define EVTAMPINDEX_HH

#include <vector>

class EvtAmpIndex {
    friend class EvtAmpSubIndex;

  public:
    EvtAmpIndex( std::vector<int> ind );
    virtual ~EvtAmpIndex() {}

    void reset();
    bool next();

    int index();

  private:
    std::vector<int> _ind;
    int _size;
    std::vector<int> _state;
    std::vector<int> _nstate;
};

#endif
