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
// Module: EvtISGW.cc
//
// Description: Routine to implement semileptonic decays according
//              to the model ISGW
//
// Modification history:
//
//    DJL/RYD     September 25, 1996         Module created
//
//------------------------------------------------------------------------
//
#include "EvtGenBase/EvtPatches.hh"
#include <stdlib.h>
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenModels/EvtISGW.hh"
#include <string>
#include "EvtGenModels/EvtISGWFF.hh"
#include "EvtGenBase/EvtSemiLeptonicScalarAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicVectorAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicTensorAmp.hh"

std::string EvtISGW::getName(){

  return "ISGW";

}


EvtDecayBase* EvtISGW::clone(){

  return new EvtISGW;

}

void EvtISGW::decay( EvtParticle *p ){


  p->initializePhaseSpace(getNDaug(),getDaugs());

  calcamp->CalcAmp(p,_amp2,isgwffmodel.get());

}


void EvtISGW::init(){

  checkNArg(0);
  checkNDaug(3);


  //We expect the parent to be a scalar
  //and the daughters to be X lepton neutrino

  EvtSpinType::spintype mesontype=EvtPDL::getSpinType(getDaug(0));

  checkSpinParent(EvtSpinType::SCALAR);
  checkSpinDaughter(1,EvtSpinType::DIRAC);
  checkSpinDaughter(2,EvtSpinType::NEUTRINO);


  isgwffmodel = std::make_unique< EvtISGWFF >();

  switch(mesontype) {
  case EvtSpinType::SCALAR:
    calcamp = std::make_unique< EvtSemiLeptonicScalarAmp >();
    break;
  case EvtSpinType::VECTOR:
    calcamp = std::make_unique< EvtSemiLeptonicVectorAmp >();
    break;
  case EvtSpinType::TENSOR:
    calcamp = std::make_unique< EvtSemiLeptonicTensorAmp >();
    break;
  default:
    ;
  }

}

