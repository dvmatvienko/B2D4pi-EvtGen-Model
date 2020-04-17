#ifndef EVTBTODIBARYONLNUPQCDFF_HH
#define EVTBTODIBARYONLNUPQCDFF_HH

class EvtParticle;
#include <vector>

// Description: Module for computation of B->ppbar form factors according
// to pQCD counting rules, see arXiv:1107.0801.

class EvtBToDiBaryonlnupQCDFF {
  public:
    class FormFactors final {
      public:
        double F1, F2, F3, F4, F5;
        double G1, G2, G3, G4, G5;
    };

    EvtBToDiBaryonlnupQCDFF();

    EvtBToDiBaryonlnupQCDFF( std::vector<double>& DParameters );

    void getDiracFF( EvtParticle* parent, double dibaryonMass,
                     EvtBToDiBaryonlnupQCDFF::FormFactors& FF ) const;

    void getRaritaFF( EvtParticle* parent, double dibaryonMass,
                      EvtBToDiBaryonlnupQCDFF::FormFactors& FF ) const;

    void getFF( EvtParticle* parent, double dibaryonMass,
                EvtBToDiBaryonlnupQCDFF::FormFactors& FF ) const;

  private:
    std::vector<double> DPars;
    int nDPars;
};

#endif
