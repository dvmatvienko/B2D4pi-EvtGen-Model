#ifndef EVTSVVHELCPMIX_HH
#define EVTSVVHELCPMIX_HH

#include "EvtGenBase/EvtDecayAmp.hh"

//Class to handle decays of the form SCALAR -> VECTOR VECTOR
//according the the helicity amplitudes specified by the
//user.  There are 6 arguements, orders as amplitude then
//phase for H+, H0, and H-, in that order.
//
// Description: Routine to decay scalar -> 2 vectors
//              by specifying the helicity amplitudes, taking appropriate
//		weak phases into account to get mixing and CP violation through
//		interference. Based on EvtSVVHelAmp. Particularly appropriate for
//		Bs->J/Psi+Phi
//
// Model takes the following as user-specified arguments:
//	deltaM, averageM - mass diference and average of light and heavy mass eigenstates (real scalars)
//	gamma, deltagamma - average width and width difference of the l and h eigenstates (real scalars)
//	delta1, delta2 - strong phases (real scalars)
//	direct weak phase (real scalar) (for Bs->JPsiPhi this will be zero)
//	weak mixing phase (real scalar) (this is equal to 2*arg(Vts Vtb) for Bs->JPsiPhi)
//	Magnitudes of helicity amplitudes as in SVV_HELAMP
// See Phys Rev D 34 p1404 - p1417 and chapters 5 and 7 of Physics Reports 370 p537-680 for more details

class EvtAmp;
class EvtParticle;
class EvtId;

class EvtSVVHelCPMix : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;

    EvtComplex hp;
    EvtComplex h0;
    EvtComplex hm;
    double averageM;
    double deltaM;
    double gamma;
    double deltagamma;
    EvtComplex strongphase1;
    EvtComplex strongphase2;
    EvtComplex weakmixingphase;
    EvtComplex weakdirectphase;

    void initProbMax() override;

    void decay( EvtParticle* p ) override;

    std::string getParamName( int i ) override;
    std::string getParamDefault( int i ) override;
};

#endif
