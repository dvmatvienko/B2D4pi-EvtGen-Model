#ifndef EVT_PTO3P_AMP_FACTORY_HH
#define EVT_PTO3P_AMP_FACTORY_HH

#include "EvtGenBase/EvtAmpFactory.hh"
#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtCyclic3.hh"
#include "EvtGenBase/EvtDalitzPlot.hh"
#include "EvtGenBase/EvtDalitzPoint.hh"

#include <string>
#include <vector>

class EvtPto3PAmpFactory final : public EvtAmpFactory<EvtDalitzPoint> {
  public:
    EvtPto3PAmpFactory( const EvtDalitzPlot& dp ) :
        EvtAmpFactory<EvtDalitzPoint>(), _dp( dp )
    {
    }
    EvtPto3PAmpFactory( EvtPto3PAmpFactory&& ) = default;
    EvtPto3PAmpFactory( const EvtPto3PAmpFactory& ) = default;

    EvtAmpFactory<EvtDalitzPoint>* clone() const override
    {
        return new EvtPto3PAmpFactory( *this );
    }

    void processAmp( EvtComplex c, std::vector<std::string> vv,
                     bool conj ) override;

  private:
    double matchIsobarCoef( EvtAmplitude<EvtDalitzPoint>& amp,
                            EvtPdf<EvtDalitzPoint>& pdf, EvtCyclic3::Pair i );

    EvtDalitzPlot _dp;
};

#endif
