#ifndef EVTITGSIMPSONINTEGRATOR_HH
#define EVTITGSIMPSONINTEGRATOR_HH

//-------------
// C Headers --
//-------------
extern "C" {
}

#include "EvtGenModels/EvtItgAbsIntegrator.hh"

// Description:
//      Simpson integrator (Stolen and modified from
//      the BaBar IntegrationUtils package - author: Phil Strother).

class EvtItgSimpsonIntegrator : public EvtItgAbsIntegrator {
  public:
    EvtItgSimpsonIntegrator( const EvtItgAbsFunction&,
                             double precision = 1.0e-5, int maxLoop = 20 );

  protected:
    double evaluateIt( double, double ) const override;

  private:
    double _precision;
    double _maxLoop;

    //EvtItgSimpsonIntegrator( const EvtItgSimpsonIntegrator& );                //// Copy Constructor
    //EvtItgSimpsonIntegrator& operator= ( const EvtItgSimpsonIntegrator& );    // Assignment op
};

#endif    // ITGSIMPSONINTEGRATOR_HH
