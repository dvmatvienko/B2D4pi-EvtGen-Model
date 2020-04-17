#ifndef EVTRANDOM_HH
#define EVTRANDOM_HH

class EvtRandomEngine;

class EvtRandom {
  public:
    static double Flat();
    static double Flat( double max );
    static double Flat( double min, double max );

    //generate unit Gaussian
    static double Gaussian();

    static double random();

    //This class does not take ownership of the random engine;
    //the caller needs to make sure that the engine is not
    //destroyed.
    static void setRandomEngine( EvtRandomEngine* randomEngine );

  private:
    static EvtRandomEngine* _randomEngine;
};

#endif
