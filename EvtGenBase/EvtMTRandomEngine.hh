#ifndef EVTMTRANDOMENGINE_HH
#define EVTMTRANDOMENGINE_HH

#include "EvtGenBase/EvtRandomEngine.hh"

#include <random>

class EvtMTRandomEngine : public EvtRandomEngine {
  public:
    EvtMTRandomEngine( unsigned int seed = 1430957218 );

    virtual double random();

  private:
    std::mt19937 engine_;

    typedef std::uniform_real_distribution<double> URDist;
    URDist distribution_;
};

#endif
