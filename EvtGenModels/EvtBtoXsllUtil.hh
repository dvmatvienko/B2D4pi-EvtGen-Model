#ifndef EVTBTOXSLLUTIL_HH
#define EVTBTOXSLLUTIL_HH

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtDecayIncoherent.hh"
#include "EvtGenBase/EvtParticle.hh"

class EvtComplex;

// Description:
// Class to generate inclusive non-resonant B -> Xs l+ l- decays.
// Description: Routine to generate non-resonant B -> Xs l+ l- decays.
// It generates a dilepton mass spectrum according to
// F.Kruger and L.M.Sehgal, Phys. Lett. B380, 199 (1996)
// and then generates the two lepton momenta according to
// A.Ali, G.Hiller, L.T.Handoko and T.Morozumi, Phys. Rev. D55, 4105 (1997).
// Expressions for Wilson coefficients and power corrections are taken
// from A.Ali, E.Lunghi, C.Greub and G.Hiller, Phys. Rev. D66, 034002 (2002).
// Detailed formulae for shat dependence of these coefficients are taken
// from H.H.Asatryan, H.M.Asatrian, C.Greub and M.Walker, PRD65, 074004 (2002)
// and C.Bobeth, M.Misiak and J.Urban, Nucl. Phys. B574, 291 (2000).
// The resultant Xs particles may be decayed by JETSET.

class EvtBtoXsllUtil {
  public:
    EvtComplex GetC7Eff0( double sh, bool nnlo = true );
    EvtComplex GetC7Eff1( double sh, double mb, bool nnlo = true );
    EvtComplex GetC9Eff0( double sh, double mb, bool nnlo = true,
                          bool btod = false );
    EvtComplex GetC9Eff1( double sh, double mb, bool nnlo = true,
                          bool btod = false );
    EvtComplex GetC10Eff( double sh, bool nnlo = true );

    double dGdsProb( double mb, double ms, double ml, double s );

    double dGdsdupProb( double mb, double ms, double ml, double s, double u );

    double FermiMomentum( double pf );

    double FermiMomentumProb( double pb, double pf );
};

#endif
