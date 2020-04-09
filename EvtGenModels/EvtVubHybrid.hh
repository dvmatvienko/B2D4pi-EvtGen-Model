//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 1998      Caltech, UCSB
//
// Module: EvtGen/EvtVubHybrid.hh
//
// Description:
// Class to generate inclusive B to X_u l nu decays.
// This class is based on EvtVub by Sven Menke with an update to
// generate the inclusive decays in such a way that the right
// mix of inclusive and exclusive decays is obtained:
// "Hybrid Model" by Dominique Fortin.
// NOTE:
// - A set of weights (for bins in the kinematic variables mX, q2, El)
//   is read from DECAY.DEC. This set of weights must be consistent
//   with the other parameters specified (excl. BF, non-res BF, mb, a).
// - If no binning/weights are specified in DECAY.DEC the hybrid
//   reweighting is not activated
//
// Modification history:
//
//   Jochen Dingfelder February 1, 2005  Created Module as update of
//                                       the module EvtVub including
//                                       hybrid model.
//------------------------------------------------------------------------

#ifndef EVTVUBHYBRID_HH
#define EVTVUBHYBRID_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

#include "EvtGenModels/EvtVubdGamma.hh"

#include <memory>
#include <vector>

class EvtParticle;
class RandGeneral;

class EvtVubHybrid : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void initProbMax() override;

    void init() override;

    void decay( EvtParticle* p ) override;

    void readWeights( int startArg = 0 );

    double getWeight( double mX, double q2, double El );

  private:
    double findPFermi();

    enum
    {
        nParameters = 3,
        nVariables = 3
    };

    bool _noHybrid =
        false;    // _noHybrid will be set TRUE if the DECAY.DEC file has no binning or weights
    bool _storeQplus =
        true;    // _storeQplus should alwasy be TRUE: writes out Fermi motion parameter

    double _mb = 4.62;        // the b-quark pole mass in GeV (try 4.65 to 4.9)
    double _a = 2.27;         // Parameter for the Fermi Motion (1.29 is good)
    double _alphas = 0.22;    // Strong Coupling at m_b (around 0.24)
    double _dGMax = 3.;       // max dGamma*p2 value;
    int _nbins = 0;
    double _masscut = 0.28;
    std::vector<double> _bins_mX;
    std::vector<double> _bins_q2;
    std::vector<double> _bins_El;
    std::vector<double> _weights;
    std::unique_ptr<EvtVubdGamma> _dGamma;    // calculates the decay rate
    std::vector<double> _pf;
};

#endif
