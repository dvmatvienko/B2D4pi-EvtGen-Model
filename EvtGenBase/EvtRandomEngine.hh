#ifndef EVTRANDOMENGINE_HH
#define EVTRANDOMENGINE_HH

// Description:Class to generate random numbers. Single member
//             function random is expected to return a random
//             number in the range ]0..1[.

class EvtRandomEngine {
  public:
    virtual ~EvtRandomEngine(){};

    virtual double random() = 0;

  private:
};

#endif
