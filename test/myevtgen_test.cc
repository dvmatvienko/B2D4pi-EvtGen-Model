#include "EvtGen/EvtGen.hh"

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtConst.hh"
#include "EvtGenBase/EvtDecayBase.hh"
#include "EvtGenBase/EvtDecayTable.hh"
#include "EvtGenBase/EvtKine.hh"
#include "EvtGenBase/EvtMTRandomEngine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParser.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtParticleFactory.hh"
#include "EvtGenBase/EvtRadCorr.hh"
#include "EvtGenBase/EvtRandom.hh"
#include "EvtGenBase/EvtRandomEngine.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtSecondary.hh"
#include "EvtGenBase/EvtSimpleRandomEngine.hh"
#include "EvtGenBase/EvtStdHep.hh"
#include "EvtGenBase/EvtTensor4C.hh"
#include "EvtGenBase/EvtVector4C.hh"
#include "EvtGenBase/EvtVector4R.hh"
#include "EvtGenBase/EvtVectorParticle.hh"

#ifdef EVTGEN_EXTERNAL
#include "EvtGenExternal/EvtExternalGenList.hh"
#endif

#include "TApplication.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TROOT.h"
#include "TString.h"
#include "TTree.h"

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::vector;

void B2D4pi( int nevent, EvtGen& myGenerator );

int main( int argc, char* argv[] )
{
  // Define the random number generator
  // Use the Mersenne-Twister generator
    EvtRandomEngine* myRandomEngine = new EvtMTRandomEngine();

    if ( !TROOT::Initialized() ) {
        static TROOT root( "RooTuple", "RooTuple ROOT in EvtGen" );
    }
    if ( argc == 1 ) {
        EvtVector4R p( 0.0, 1.0, 0.0, 0.0 );
        EvtVector4R k( 0.0, 0.0, 1.0, 0.0 );

        EvtTensor4C T = dual( EvtGenFunctions::directProd( p, k ) );

        EvtGenReport( EVTGEN_INFO, "EvtGen" ) << "p:" << p << std::endl;
        EvtGenReport( EVTGEN_INFO, "EvtGen" ) << "k:" << k << std::endl;
        EvtGenReport( EVTGEN_INFO, "EvtGen" )
            << "T=dual(directProd(p,k)):" << T << std::endl;
        EvtGenReport( EVTGEN_INFO, "EvtGen" )
            << "T03:" << T.get( 0, 3 ) << std::endl;
        return 1;
    }

    EvtAbsRadCorr* radCorrEngine = nullptr;
    std::list<EvtDecayBase*> extraModels;

#ifdef EVTGEN_EXTERNAL
    bool convertPythiaCodes( false );
    bool useEvtGenRandom( true );
    EvtExternalGenList genList( convertPythiaCodes, "", "gamma", useEvtGenRandom );
    radCorrEngine = genList.getPhotosModel();
    extraModels = genList.getListOfModels();
#endif

    EvtGen myGenerator( "../DECAY_NONPYTHIA.DEC", "../evt.pdl", myRandomEngine,
                        radCorrEngine, &extraModels );

  if ( !strcmp( argv[1], "B2D4pi" ) ) {
        int nevent = atoi( argv[2] );
        B2D4pi( nevent, myGenerator );
     }
}
void B2D4pi( int nevent, EvtGen& myGenerator )
{
    TFile* file = new TFile( "B2D4pi.root", "RECREATE" );
//    static EvtId UPS4 = EvtPDL::getId( std::string( "Upsilon(4S)" ) );
//    static EvtId B0 = EvtPDL::getId( std::string( "B0" ) );
    static EvtId B0B = EvtPDL::getId( std::string( "anti-B0" ) );

    TH1F* mpi0pi1 = new TH1F( "h1", "M([p]^0![p]?1!)", 50, 0, 4.0 );
    TH1F* mpi1pi2 = new TH1F( "h2", "M([p]?1![p]?2!)", 50, 0, 4.0 );
    TH1F* mpi1pi3 = new TH1F( "h3", "M([p]?1![p]?3!)", 50, 0, 4.0 );

    int count = 1;

    EvtVector4R p4_pi0, p4_pi1, p4_pi2, p4_pi3, p4_pi4, p4_b, p4_d;

    char udecay_name[100];

    strcpy( udecay_name, "exampleFiles/B2D4pi.DEC" );

    myGenerator.readUDecay( udecay_name );

    do {
        EvtVector4R p_init( EvtPDL::getMass( B0B ), 0.0, 0.0, 0.0 );

        EvtParticle* root_part = EvtParticleFactory::particleFactory( B0B, p_init );
        myGenerator.generateDecay( root_part );


	p4_b = root_part->getP4Lab();
	p4_d = root_part->getDaug( 0 )->getP4Lab();
	p4_pi0 = root_part->getDaug( 1 )->getP4Lab(); //pi0
	p4_pi1 = root_part->getDaug( 2 )->getP4Lab(); //pim
	p4_pi2 = root_part->getDaug( 3 )->getP4Lab(); //pip
	p4_pi3  = root_part->getDaug( 4 )->getP4Lab(); //pim

	double d_mpi0pi1 = (p4_pi0 + p4_pi1).mass();
        double d_mpi1pi2 = (p4_pi1 + p4_pi2).mass();
	double d_mpi1pi3 = (p4_pi1 + p4_pi3).mass();

        mpi0pi1->Fill( d_mpi0pi1 );
        mpi1pi2->Fill( d_mpi1pi2 );
	mpi1pi3->Fill( d_mpi1pi3 );

//        mpi0pi1->Fill( (p4_b-p4_d).mass() );
	root_part->deleteTree();

    } while ( count++ < nevent );

    file->Write();
    file->Close();
    EvtGenReport( EVTGEN_INFO, "EvtGen" ) << "SUCCESS\n";
}

