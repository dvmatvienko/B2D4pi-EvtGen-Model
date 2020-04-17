#ifndef EVTPARSER_HH
#define EVTPARSER_HH

#include <string>

class EvtParser {
  public:
    EvtParser();
    ~EvtParser();

    int read( const std::string filename );
    int getNToken();
    const std::string& getToken( int i );
    int getLineofToken( int i );

  private:
    int _ntoken;
    std::string* _tokenlist;
    int* _linelist;
    int _lengthoftokenlist;

    void addToken( int line, const std::string& string );
};

#endif
