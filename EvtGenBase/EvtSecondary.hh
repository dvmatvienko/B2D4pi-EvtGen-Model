#ifndef EVTSECONDARY_HH
#define EVTSECONDARY_HH

const int EVTSECONDARYLENGTH = 100;

class EvtParticle;
#include <iosfwd>

class EvtSecondary {
  public:
    EvtSecondary() {}
    ~EvtSecondary() {}

    void init();

    int getStdHepIndex( int i ) { return _stdhepindex[i]; }
    int getD1( int i ) { return _id1[i]; }
    int getD2( int i ) { return _id2[i]; }
    int getD3( int i ) { return _id3[i]; }

    int getNPart();
    void createSecondary( int stdhepindex, EvtParticle* prnt );

    friend std::ostream& operator<<( std::ostream& s,
                                     const EvtSecondary& secondary );

  private:
    int _npart;
    int _stdhepindex[EVTSECONDARYLENGTH];
    int _id1[EVTSECONDARYLENGTH];
    int _id2[EVTSECONDARYLENGTH];
    int _id3[EVTSECONDARYLENGTH];
};

#endif
