#ifdef EVTGEN_PYTHIA

#ifndef EVTPYTHIARANDOM_HH
#define EVTPYTHIARANDOM_HH

#include "EvtGenBase/EvtRandom.hh"

#include "Pythia8/Basics.h"

// Description: Class to specify the chosen EvtGen random number (engine)
// to also be used for Pythia 8.

class EvtPythiaRandom : public Pythia8::RndmEngine {
  public:
    EvtPythiaRandom(){};

    virtual ~EvtPythiaRandom(){};

    double flat() override { return EvtRandom::Flat(); }

  private:
};

#endif

#endif
