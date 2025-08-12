//--------------------------------------------------------------------------
// Description: Routine to decay B0-> D- pi+ pi- pi0 pi+.
//------------------------------------------------------------------------
#include "EvtGenModels/EvtBToD4pi.hh"
#include "EvtGenBase/EvtConst.hh"
#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtVector4R.hh"
#include <string>


  EvtBToD4pi::~EvtBToD4pi() {}


  double MomentaProd(const EvtVector4R& p1, const EvtVector4R& p2,
                     const EvtVector4R& p3)
  {

    return -(p1 * p2) + (p1 * p3) * (p2 * p3) / (p3 * p3);

  }

  double DeltaOmega(const EvtVector4R& l1, const EvtVector4R& l2,
                    const EvtVector4R& l3, const EvtVector4R& l4,
                    const EvtVector4R& l5)
  {

    EvtVector4R p1 = l1;  //Q
    EvtVector4R p4 = l2 - l4; //dl
    EvtVector4R p6 = l2 + l4; //L
    EvtVector4R p3 = p6 + l3; //p=L+l2
    EvtVector4R p5 = p3; //p
    EvtVector4R p2 = p3 + l5; //q=p+l4

    return -((p1 * p4) * (p2 * p5) * (p3 * p6) + (p1 * p5) * (p2 * p6) * (p3 * p4) +
             (p2 * p4) * (p3 * p5) * (p1 * p6) - (p1 * p6) * (p2 * p5) * (p3 * p4) -
             (p1 * p5) * (p2 * p4) * (p3 * p6) - (p2 * p6) * (p3 * p5) * (p1 * p4));


  }

  double DeltaA1(const EvtVector4R& l1, const EvtVector4R& l2,
                 const EvtVector4R& l3, const EvtVector4R& l4,
                 const EvtVector4R& l5, const short term)
  {

    EvtVector4R p1 = l1; //Q
    EvtVector4R p4 = l4 - l5; //dl
    EvtVector4R p5 = l4 + l5; // L
    EvtVector4R p3 = p5 + l3; //p
    EvtVector4R p2 = p3 + l2; // q

    if (term == 2) {

      double p1p4_p3 = MomentaProd(p1, p4, p3);
      double p2p4_p3 = MomentaProd(p2, p4, p3);
      double p1p5_p3 = MomentaProd(p1, p5, p3);
      double p2p5_p3 = MomentaProd(p2, p5, p3);

      return (p2 * p3) * (p3 * p5) * p1p4_p3 - (p1 * p3) * (p3 * p5) * p2p4_p3 +
             (p1 * p3) * (p3 * p4) * p2p5_p3 - (p2 * p3) * (p3 * p4) * p1p5_p3;
    } else if (term == 1) {

      double p3p4_p5 = MomentaProd(p3, p4, p5);
      double p1p4_p5 = MomentaProd(p1, p4, p5);
      double p2p4_p5 = MomentaProd(p2, p4, p5);

      return (p1 * l1) * (p2 * l2) * p3p4_p5 + (p3 * l2) * (p2 * l1) * p1p4_p5 -
             (p2 * l1) * (p1 * l2) * p3p4_p5 - (p3 * l2) * (p1 * l1) * p2p4_p5;

    } else return 0;

  }

  double DeltaRhoRho(const EvtVector4R& l1, const EvtVector4R& l2,
                     const EvtVector4R& l3, const EvtVector4R& l4,
                     const EvtVector4R& l5)
  {

    EvtVector4R p1 = l1; //Q
    EvtVector4R p3 = l2 - l3; //dl12
    EvtVector4R p5 = l2 + l3; // rho-
    EvtVector4R p4 = l4 - l5; //dl34
    EvtVector4R p6 = l4 + l5; //rho0
    EvtVector4R p2 = p5 + p6; // q

    return (p2 * p4) * (p6 * p3) * (p1 * p5) + (p2 * p5) * (p1 * p6) * (p3 * p4) +
           (p5 * p6) * (p2 * p3) * (p1 * p4) + (p5 * p4) * (p2 * p6) * (p1 * p3) -
           (p1 * p4) * (p6 * p3) * (p2 * p5) - (p1 * p5) * (p2 * p6) * (p3 * p4) -
           (p5 * p6) * (p1 * p3) * (p2 * p4) - (p5 * p4) * (p1 * p6) * (p2 * p3);

  }

  double DeltaRhoF0(const EvtVector4R& l1, const EvtVector4R& l2,
                    const EvtVector4R& l3, const EvtVector4R& l4,
                    const EvtVector4R& l5)
  {

    EvtVector4R p1 = l1; //Q
    EvtVector4R p3 = l2 - l3; //dl12
    EvtVector4R p4 = l2 + l3; // rho-
    EvtVector4R p2 = p4 + l4 + l5; // q

    double p1p3_p2 = MomentaProd(p1, p3, p2);
    double p1p4_p2 = MomentaProd(p1, p4, p2);

    return -p1p3_p2 + p1p4_p2 * (p3 * p4) / (p4 * p4);

  }

// a1 rho pi form factor from  Root diss
  double FFa1_root(const EvtVector4R& p)
  {

    EvtId pId = EvtPDL::getId("a_10");
    double bwm = EvtPDL::getMeanMass(pId);
    double Delta = 1.2;

    return (1 + bwm * bwm / Delta) / (1 + (p * p) / Delta);
  }

//rho omega pi interaction from achas
  double FFrho_achas(const std::string& nameDaughter1, const std::string& nameDaughter2, const EvtVector4R& pMother)
  {

    double r = 1.6;

    EvtId pdId1 = EvtPDL::getId(nameDaughter1);
    double md1 = EvtPDL::getMeanMass(pdId1);

    EvtId pdId2 = EvtPDL::getId(nameDaughter2);
    double md2 = EvtPDL::getMeanMass(pdId2);

    double bwmq = std::sqrt(pMother * pMother);

    if (bwmq < md1 + md2) return 1.;
    else  {
      double pd1pm = (pMother * pMother + md1 * md1 - md2 * md2) / 2.;
      double momDaughter = std::sqrt(pd1pm * pd1pm / (pMother * pMother) - md1 * md1);
      return 1. / (1 + (r * momDaughter) * (r * momDaughter));
    }
  }

// Blatt-Weisskopf P-wave
  double FF_Pwave(const std::string& nameMother, const std::string& nameDaughter1, const std::string& nameDaughter2,
                  const EvtVector4R& pMother)
  {

    double r = 1.6;

    EvtId pmId = EvtPDL::getId(nameMother);
    double bwm = EvtPDL::getMeanMass(pmId);

    EvtId pd1Id = EvtPDL::getId(nameDaughter1);
    double bwd1 = EvtPDL::getMeanMass(pd1Id);

    EvtId pd2Id = EvtPDL::getId(nameDaughter2);
    double bwd2 = EvtPDL::getMeanMass(pd2Id);

    double pd1pm = (pMother * pMother + bwd1 * bwd1 - bwd2 * bwd2) / 2.;
    double pd1pm0 = (bwm * bwm + bwd1 * bwd1 - bwd2 * bwd2) / 2.;

    double bwmq = std::sqrt(pMother * pMother);

    if (bwmq < bwd1 + bwd2) return 1.;
    else {
      double momDaughter = std::sqrt(pd1pm * pd1pm / (pMother * pMother) - bwd1 * bwd1);
      double momDaughter_0 = std::sqrt(pd1pm0 * pd1pm0 / bwm / bwm - bwd1 * bwd1);
      return std::sqrt((1 + r * r * momDaughter_0 * momDaughter_0) / (1 + r * r * momDaughter * momDaughter));
    }

  }

  double WidthDep(const std::string& name, const EvtVector4R& p, const short mode)
  {

    double q2 = p * p;
    EvtId pId = EvtPDL::getId(name);
    double bwm = EvtPDL::getMeanMass(pId);
    double mpi = EvtPDL::getMeanMass(EvtPDL::getId("pi+"));
    double mpi0 = EvtPDL::getMeanMass(EvtPDL::getId("pi0"));
    double momega = EvtPDL::getMeanMass(EvtPDL::getId("omega"));
    if (name == "f_0(600)") return bwm / sqrt(q2) * sqrt((1 - 4.*mpi * mpi / q2) / (1 - 4.*mpi * mpi / bwm / bwm));
    if (name == "rho0") return bwm * bwm / q2 * FF_Pwave("rho0", "pi+", "pi-", p) * FF_Pwave("rho0", "pi+", "pi-", p) *
                                 std::pow((q2 - 4 * mpi * mpi), 1.5) / std::pow((bwm * bwm - 4 * mpi * mpi), 1.5);
    else if (name == "rho+" || name  == "rho-") {
      if (mode == 1 && std::sqrt(q2) < momega + mpi) return 1.; //mode = 1  - 4pi amplitude
      else if (mode == 1 && std::sqrt(q2) > momega + mpi) {
        double pd1pm = (q2 + mpi * mpi - mpi0 * mpi0) / 2.;
        double pd1pm0 = (bwm * bwm + mpi * mpi - mpi0 * mpi0) / 2.;
        double pom = (q2 + momega * momega - mpi * mpi) / 2.;
        double grhompi = 16.;
        return bwm * bwm / q2 * FF_Pwave("rho+", "pi+", "pi0", p) * FF_Pwave("rho+", "pi+", "pi0", p) *
               std::pow((pd1pm * pd1pm / q2 - mpi * mpi), 1.5) / std::pow((pd1pm0 * pd1pm0 / bwm / bwm - mpi * mpi), 1.5) +
               grhompi * grhompi / 12 / EvtConst::pi * FFrho_achas("omega", "pi+", p) * FFrho_achas("omega", "pi+", p) * pom * pom * pom;
      } else { //mode = 0 - omega / a1 amplitude
        double pd1pm = (q2 + mpi * mpi - mpi0 * mpi0) / 2.;
        double pd1pm0 = (bwm * bwm + mpi * mpi - mpi0 * mpi0) / 2.;
        //       std::cout << " rho_1 = :" << pd1pm*pd1pm-mpi*mpi << " rho_2 = " << pd1pm0*pd1pm0-mpi*mpi << std::endl;
        return bwm * bwm / q2 * FF_Pwave("rho+", "pi+", "pi0", p) * FF_Pwave("rho+", "pi+", "pi0", p) *
               std::pow((pd1pm * pd1pm / q2 - mpi * mpi), 1.5) / std::pow((pd1pm0 * pd1pm0 / bwm / bwm - mpi * mpi), 1.5);
      }
    } else if (name == "rho(2S)+" || name == "rho(2S)-") {
      if (mode == 1 && std::sqrt(q2) < momega + mpi) return 1.; //mode= 1 - 4pi amplitude
      else if (mode == 1 && std::sqrt(q2) > momega + mpi) {
        double pd1pm = (q2 + mpi * mpi - mpi0 * mpi0) / 2.;
        double pd1pm0 = (bwm * bwm + mpi * mpi - mpi0 * mpi0) / 2.;
        double pom = (q2 + momega * momega - mpi * mpi) / 2.;
        double pom0 = (bwm * bwm + momega * momega - mpi * mpi) / 2.;
        return 0.5 * bwm * bwm / q2 * FF_Pwave("rho(2S)+", "pi+", "pi0", p) * FF_Pwave("rho(2S)+", "pi+", "pi0", p) *
               std::pow((pd1pm * pd1pm / q2 - mpi * mpi), 1.5) / std::pow((pd1pm0 * pd1pm0 / bwm / bwm - mpi * mpi), 1.5) +
               0.5 * FF_Pwave("rho(2S)+", "omega", "pi+", p) * FF_Pwave("rho(2S)+", "omega", "pi+", p) *
               std::pow((pom * pom / q2 - momega * momega), 1.5) / std::pow((pom0 * pom0 / bwm / bwm - momega * momega), 1.5);
      }
    } else if (name == "omega") {
      double ppi2q2 = std::pow((q2 - 3.*mpi * mpi), 2) / 4. / q2 - mpi * mpi;
      double ppi2 = std::pow((bwm * bwm - 3.*mpi * mpi), 2) / 4. / bwm / bwm - mpi * mpi;
      if (std::sqrt(q2) < bwm) return std::pow((ppi2q2 / ppi2), 4);
      else return std::pow((ppi2q2 / ppi2), 5);
    } else if (name == "a_1+" || name == "a_1-" || name == "a_10") {
      if (std::sqrt(q2) < 2 * mpi + mpi0) return 1.;
      else {
        double ereper[] = {0.5009, 0.5981, 0.7028, 0.7925, 0.8747, 0.9345,
                           1.009, 1.0915, 1.1514, 1.2224, 1.2859, 1.33457,
                           1.409345, 1.454205, 1.51775, 1.58878, 1.64859,
                           1.71214, 1.78317, 1.85794, 1.92897, 1.97009,
                           1.99252, 2.0112, 2.0373, 2.0859, 2.1233, 2.1869,
                           2.2429, 2.3214, 2.3813, 2.4186, 2.47476, 2.51962,
                           2.57943, 2.62803, 2.68785, 2.73271, 2.78130, 2.81495,
                           2.86728, 2.9046, 2.9383, 2.9719, 3.005, 3.0467, 3.0766, 3.1028, 3.1327
                          };
        double wreper[] = {0.0171, 0.02575, 0.06008, 0.1158, 0.19742, 0.2532,
                           0.31330, 0.38197, 0.41201, 0.46351, 0.5021, 0.55364,
                           0.5836, 0.63090, 0.6738, 0.7124, 0.7553, 0.79399,
                           0.85407, 0.88841, 0.92703, 1.02575, 1.06866,
                           1.085836, 1.124463, 1.16738, 1.23175, 1.30042,
                           1.3776, 1.44206, 1.5107, 1.56223, 1.6051, 1.67811,
                           1.75536, 1.82832, 1.9227, 1.98283, 2.03862, 2.10729,
                           2.18454, 2.2403, 2.300429, 2.3562, 2.43347, 2.506437, 2.56223, 2.6223, 2.6738
                          };
        double e  = std::sqrt(q2);
        if (e > ereper[48]) return (wreper[48] * (e - ereper[47]) - wreper[47] * (e - ereper[48])) / (ereper[48] - ereper[47]) * bwm / e;
        for (int j = 0; j < 48; j++) {
          if (e > ereper[j]
              && e < ereper[j + 1]) return (wreper[j + 1] * (e - ereper[j]) - wreper[j] * (e - ereper[j + 1])) /
                                             (ereper[j + 1] - ereper[j]) * bwm / e;
        }
      }
    }
  }


  EvtComplex RelBrWigner(const std::string& name, const EvtVector4R& p, const short mode, const short i)
  {

    // mode = 0 --> inside Omega / a1 amplitude, mode = 1 --> inside 4pi amplitude
    // i = 1 --> constant width, \= 1 --> q2-dependent
    EvtId pId = EvtPDL::getId(name);
    double q2 = p * p;
    double bwm = EvtPDL::getMeanMass(pId);
    double gamma = EvtPDL::getWidth(pId);
    double width;
    if (i == 1) width = 1; // constant width
    if (i == 2) width = WidthDep(name, p, mode); // q2-dependent width
    if (name == "a_1+" || name == "a_1-" || name == "a_10") gamma = 1;
//  if (name == "omega") gamma = .3; // special treatment for interf!.
    width = gamma * width;
    return  1. / (q2 - bwm * bwm + EvtComplex(0.0, std::sqrt(q2) * width));

  }


  std::string EvtBToD4pi::getName() const
  {

    return  "BTOD4PI";

  }


  EvtBToD4pi* EvtBToD4pi::clone() const
  {

    return new EvtBToD4pi;

  }

  void EvtBToD4pi::init()
  {

    // check that there are 9 arguments
    checkNArg(11);
    checkNDaug(5);

    checkSpinParent(EvtSpinType::SCALAR);

    checkSpinDaughter(0, EvtSpinType::SCALAR);
    checkSpinDaughter(1, EvtSpinType::SCALAR);
    checkSpinDaughter(2, EvtSpinType::SCALAR);
    checkSpinDaughter(3, EvtSpinType::SCALAR);
    checkSpinDaughter(4, EvtSpinType::SCALAR);
  }

  void EvtBToD4pi::initProbMax()
  {

//    setProbMax(getArg(10));
     noProbMax();

  }

  void EvtBToD4pi::decay(EvtParticle* p)
  {

    p->initializePhaseSpace(getNDaug(), getDaugs());
    EvtVector4R Q  = p->getDaug(0)->getP4();
    EvtVector4R p1 = p->getDaug(1)->getP4();
    EvtVector4R p2 = p->getDaug(2)->getP4();
    EvtVector4R p3 = p->getDaug(3)->getP4();
    EvtVector4R p4 = p->getDaug(4)->getP4();


    EvtComplex Omega_ampl = DeltaOmega(Q, p1, p2, p3, p4) * RelBrWigner("rho+", p1 + p3, 0, 2) * RelBrWigner("omega", p1 + p2 + p3, 0,
                            2) * FFrho_achas("rho+", "pi-", p1 + p2 + p3) * FF_Pwave("rho+", "pi+", "pi0", p1 + p3) +
                            DeltaOmega(Q, p1, p4, p3, p2) * RelBrWigner("rho+", p1 + p3, 0, 2) * RelBrWigner("omega", p1 + p3 + p4, 0, 2) * FFrho_achas("rho+",
                                "pi-", p1 + p3 + p4) * FF_Pwave("rho+", "pi+", "pi0", p1 + p3) -
                            DeltaOmega(Q, p1, p3, p2, p4) * RelBrWigner("rho-", p1 + p2, 0, 2) * RelBrWigner("omega", p1 + p2 + p3, 0, 2) * FFrho_achas("rho-",
                                "pi+", p1 + p2 + p3) * FF_Pwave("rho-", "pi-", "pi0", p1 + p2) -
                            DeltaOmega(Q, p1, p3, p4, p2) * RelBrWigner("rho-", p1 + p4, 0, 2) * RelBrWigner("omega", p1 + p3 + p4, 0, 2) * FFrho_achas("rho-",
                                "pi+", p1 + p3 + p4) * FF_Pwave("rho-", "pi-", "pi0", p1 + p4) -
                            DeltaOmega(Q, p2, p1, p3, p4) * RelBrWigner("rho0", p2 + p3, 0, 2) * RelBrWigner("omega", p1 + p2 + p3, 0, 2) * FFrho_achas("rho0",
                                "pi0", p1 + p2 + p3) * FF_Pwave("rho0", "pi+", "pi-", p2 + p3) -
                            DeltaOmega(Q, p4, p1, p3, p2) * RelBrWigner("rho0", p3 + p4, 0, 2) * RelBrWigner("omega", p1 + p3 + p4, 0, 2) * FFrho_achas("rho0",
                                "pi0", p1 + p3 + p4) * FF_Pwave("rho0", "pi+", "pi-", p3 + p4);

    Omega_ampl = EvtComplex(getArg(2) * cos(getArg(3)), getArg(2) * sin(getArg(3))) * Omega_ampl *
                 (RelBrWigner("rho-", p1 + p2 + p3 + p4, 1, 2) * FFrho_achas("omega", "pi-", p1 + p2 + p3 + p4) +
                  EvtComplex(getArg(0) * cos(getArg(1)), getArg(0) * sin(getArg(1))) * RelBrWigner("rho(2S)-", p1 + p2 + p3 + p4, 1,
                      2) * FF_Pwave("rho(2S)-", "omega", "pi-", p1 + p2 + p3 + p4));


    EvtComplex A1_ampl = DeltaA1(Q, p1, p2, p3, p4, 1) * RelBrWigner("rho0", p3 + p4, 0, 2) * RelBrWigner("a_1-", p2 + p3 + p4, 0,
                         2) * FF_Pwave("rho0", "pi+", "pi-", p3 + p4) +
                         DeltaA1(Q, p1, p4, p3, p2, 1) * RelBrWigner("rho0", p3 + p2, 0, 2) * RelBrWigner("a_1-", p2 + p3 + p4, 0, 2) * FF_Pwave("rho0",
                             "pi+", "pi-", p3 + p2) -
                         DeltaA1(Q, p2, p3, p4, p1, 1) * RelBrWigner("rho-", p1 + p4, 0, 2) * RelBrWigner("a_10", p1 + p3 + p4, 0, 2) * FF_Pwave("rho-",
                             "pi-", "pi0", p1 + p4) -
                         DeltaA1(Q, p4, p3, p2, p1, 1) * RelBrWigner("rho-", p1 + p2, 0, 2) * RelBrWigner("a_10", p1 + p2 + p3, 0, 2) * FF_Pwave("rho-",
                             "pi-", "pi0", p1 + p2) -
                         DeltaA1(Q, p2, p4, p3, p1, 1) * RelBrWigner("rho+", p1 + p3, 0, 2) * RelBrWigner("a_10", p1 + p3 + p4, 0, 2) * FF_Pwave("rho+",
                             "pi+", "pi0", p1 + p3) -
                         DeltaA1(Q, p4, p2, p3, p1, 1) * RelBrWigner("rho+", p1 + p3, 0, 2) * RelBrWigner("a_10", p1 + p2 + p3, 0, 2) * FF_Pwave("rho+",
                             "pi+", "pi0", p1 + p3);

    A1_ampl = EvtComplex(getArg(4) * cos(getArg(5)), getArg(4) * sin(getArg(5))) * A1_ampl *
              EvtComplex(getArg(0) * cos(getArg(1)), getArg(0) * sin(getArg(1))) * RelBrWigner("rho(2S)-", p1 + p2 + p3 + p4, 1, 2);

    EvtComplex RhoRho_ampl = DeltaRhoRho(Q, p1, p2, p3, p4) * RelBrWigner("rho-", p1 + p2, 0, 2) * RelBrWigner("rho0", p3 + p4, 0,
                             2) * FF_Pwave("rho-", "pi-", "pi0", p1 + p2) * FF_Pwave("rho0", "pi+", "pi-", p3 + p4) +
                             DeltaRhoRho(Q, p1, p4, p3, p2) * RelBrWigner("rho-", p1 + p4, 0, 2) * RelBrWigner("rho0", p3 + p2, 0, 2) * FF_Pwave("rho-", "pi-",
                                 "pi0", p1 + p4) * FF_Pwave("rho0", "pi+", "pi-", p3 + p2);

    RhoRho_ampl = EvtComplex(getArg(6) * cos(getArg(7)), getArg(6) * sin(getArg(7))) * RhoRho_ampl *
                  EvtComplex(getArg(0) * cos(getArg(1)), getArg(0) * sin(getArg(1))) * RelBrWigner("rho(2S)-", p1 + p2 + p3 + p4, 1, 2);

    EvtComplex RhoF0_ampl = DeltaRhoF0(Q, p1, p2, p3, p4) * RelBrWigner("rho-", p1 + p2, 0, 2) * RelBrWigner("f_0(600)", p3 + p4, 0,
                            2) * FF_Pwave("rho-", "pi-", "pi0", p1 + p2) +
                            DeltaRhoF0(Q, p1, p4, p3, p2) * RelBrWigner("rho-", p1 + p4, 0, 2) * RelBrWigner("f_0(600)", p3 + p2, 0, 2) * FF_Pwave("rho-",
                                "pi-", "pi0", p1 + p4);

    RhoF0_ampl = EvtComplex(getArg(8) * cos(getArg(9)), getArg(8) * sin(getArg(9))) * RhoF0_ampl *
                 EvtComplex(getArg(0) * cos(getArg(1)), getArg(0) * sin(getArg(1))) * RelBrWigner("rho(2S)-", p1 + p2 + p3 + p4, 1, 2);


//  EvtComplex OmegaA1_ampl = EvtComplex(getArg(2)*cos(getArg(3)),getArg(2)*sin(getArg(3)))*Omega_ampl + EvtComplex(getArg(4)*cos(getArg(5)),getArg(4)*sin(getArg(5)))*A1_ampl;

//  EvtComplex amp = OmegaA1_ampl*(RelBrWigner("rho-",p1+p2+p3+p4,1,2) +
//                   EvtComplex(getArg(0)*cos(getArg(1)),getArg(0)*sin(getArg(1)))*RelBrWigner("rho(2S)-",p1+p2+p3+p4,1,2));


//  EvtComplex amp = Omega_ampl + A1_ampl + RhoRho_ampl + RhoF0_ampl;
    EvtComplex amp = sqrt(abs2(Omega_ampl) + abs2(A1_ampl) + abs2(RhoRho_ampl) + abs2(RhoF0_ampl));

//  EvtComplex amp = sqrt(abs2(EvtComplex(getArg(2)*cos(getArg(3)),getArg(2)*sin(getArg(3)))*Omega_ampl) +
//                        abs2(EvtComplex(getArg(4)*cos(getArg(5)),getArg(4)*sin(getArg(5)))*A1_ampl)) *
//                   (RelBrWigner("rho-",p1+p2+p3+p4,1,2) +
//                   EvtComplex(getArg(0)*cos(getArg(1)),getArg(0)*sin(getArg(1)))*RelBrWigner("rho(2S)-",p1+p2+p3+p4,1,2));


    vertex(amp);

//  std::cout << " MaxProb = " << getProbMax(0.0) << std::endl;

    return;
  }

