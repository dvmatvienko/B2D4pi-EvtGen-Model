//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package. If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//
// Module: EvtBcVHad.hh
//
// Description: Module to implement Bc -> psi + (n pi) + (m K) decays
//
// Modification history:
//
//    A V Luchinsky     Jan 29, 2013        Module created
//    A V Luchinsky     Apr 30, 2019        psi K_S K node added
//
//------------------------------------------------------------------------

#ifndef EvtBcVHad_HH
#define EvtBcVHad_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtVector4C.hh"

#include "EvtGenModels/EvtBCVFF2.hh"
#include "EvtGenModels/EvtWHad.hh"

#include <string>
#include <memory>

class EvtParticle;

class EvtBcVHad : public EvtDecayAmp {
public:

    std::string getName() override;
    EvtDecayBase* clone() override;
    void initProbMax() override;
    void init() override;
    void decay(EvtParticle *p) override;

protected:

    // Hadronic current function
    EvtVector4C hardCurr(EvtParticle *root_particle) const;

private:
    // whichfit --- code of the Bc -> VW formfactor set:
    //   1 - SR
    //   2 - PM
    int whichfit;

    // idVector --- final vector particle code
    int idVector;

    // out_code: code of the hadronic final state
    //   1 - pi+
    //   2 - pi+ pi0
    //   3 -  pi+ pi+ pi-
    //   4 - 4pi
    //   5 - pi+ pi+ pi- pi- pi+
    //   6 - K+ K- pi+
    //   7 - K+ pi+ pi-
    //   8 - K_S0 K+
    int out_code;

    std::unique_ptr<EvtBCVFF2> ffmodel;
    std::unique_ptr<EvtWHad> wcurr;

};

#endif
