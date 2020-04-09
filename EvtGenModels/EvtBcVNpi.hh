#ifndef EvtBcVNpi_HH
#define EvtBcVNpi_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtScalarParticle.hh"

#include "EvtGenModels/EvtBCVFF.hh"
#include "EvtGenModels/EvtWnPi.hh"

#include <iostream>
#include <memory>

using std::endl;
using std::string;

class EvtBcVNpi : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;
    void initProbMax() override;
    void init() override;
    void decay( EvtParticle* p ) override;

  protected:
    int nCall;
    int whichfit, idVector;
    std::unique_ptr<EvtBCVFF> ffmodel;
    std::unique_ptr<EvtWnPi> wcurr;

    EvtComplex Fpi( EvtVector4R q1, EvtVector4R q2 );
    EvtComplex BWa( EvtVector4R q );
    EvtComplex BWf( EvtVector4R q );
    EvtComplex BWr( EvtVector4R q );
    EvtVector4C JB( EvtVector4R q1, EvtVector4R q2, EvtVector4R q3,
                    EvtVector4R q4, EvtVector4R q5 );
};
#endif
