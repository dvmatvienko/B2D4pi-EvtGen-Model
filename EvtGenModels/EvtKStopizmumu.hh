#ifndef EVTKSTOPIZMUMU_HH
#define EVTKSTOPIZMUMU_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include <string>

class EvtParticle;

class EvtKStopizmumu : public EvtDecayAmp {
  public:
    std::string getName() override { return "KS_PI0MUMU"; }

    EvtDecayBase* clone() override { return new EvtKStopizmumu; }

    void init() override;

    void initProbMax() override { setProbMax( 1.0e-10 ); }

    void decay( EvtParticle* p ) override;

    double F_z( const double& z, const double& rvsq );
    EvtComplex G_z( const double& z );
    double Wpol_z( const double& z, const double& as, const double& bs );
    EvtComplex chi_z( const double& z, const double& rpisq );
    EvtComplex Wpipi_z( const double& z, const double& alpha_s,
                        const double& beta_s, const double& rvsq,
                        const double& rpisq, const double& z0 );
};

#endif    //EVTKTOPIZMUMU_HH
