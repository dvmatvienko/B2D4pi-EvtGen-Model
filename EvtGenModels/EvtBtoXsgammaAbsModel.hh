#ifndef EVTBTOXSGAMMAABSMODEL_HH
#define EVTBTOXSGAMMAABSMODEL_HH

// Description:
//      B->Xs gamma model base class.

class EvtBtoXsgammaAbsModel {
  public:
    virtual ~EvtBtoXsgammaAbsModel() = default;

    virtual void init( int, double* );

    virtual double GetMass( int code ) = 0;
};

#endif
