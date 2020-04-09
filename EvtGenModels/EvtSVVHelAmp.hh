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
// Module: EvtGen/EvtSVVHelAmp.hh
//
// Description:
//
// Modification history:
//
//    DJL/RYD     August 11, 1998         Module created
//
//------------------------------------------------------------------------

#ifndef EVTSVVHELAMP_HH
#define EVTSVVHELAMP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

//Class to handle decays of the form SCALAR -> VECTOR VECTOR
//according the the helicity amplitudes specified by the
//user.  There are 6 arguements, orders as amplitude then
//phase for H+, H0, and H-, in that order.

class EvtAmp;
class EvtParticle;
class EvtId;

class EvtSVVHelAmp : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

    static void SVVHel( EvtParticle* parent, EvtAmp& amp, EvtId n_v1,
                        EvtId n_v2, const EvtComplex& hp, const EvtComplex& h0,
                        const EvtComplex& hm );

    std::string getParamName( int i ) override;
    std::string getParamDefault( int i ) override;
};

#endif
