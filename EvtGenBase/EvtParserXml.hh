#ifndef EVTPARSERXML_HH
#define EVTPARSERXML_HH

#include <fstream>
#include <string>
#include <vector>

class EvtParserXml final {
  public:
    bool open( std::string filename );
    bool close();

    bool readNextTag();

    std::string getTagTitle() { return _tagTitle; }
    std::string getParentTagTitle();
    int getLineNumber() { return _lineNo; }
    bool isTagInline() { return _inLineTag; }

    std::string readAttribute( std::string attribute,
                               std::string defaultValue = "" );
    bool readAttributeBool( std::string attribute, bool defaultValue = false );
    int readAttributeInt( std::string attribute, int defaultValue = -1 );
    double readAttributeDouble( std::string attribute, double defaultValue = -1. );

  private:
    std::ifstream _fin;
    std::string _line;
    int _lineNo = 0;

    std::string _tag;
    std::string _tagTitle;
    bool _inLineTag;
    std::vector<std::string> _tagTree;

    bool processTagTree();

    bool expandEnvVars( std::string& str );
    bool isAlphaNum( char c );
};

#endif
