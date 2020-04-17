#if !defined( TOOLBOX_FUNCTIONS_HH )
#define TOOLBOX_FUNCTIONS_HH

#if !defined( FILENAME_ONLY ) /* relative path includes */

// system include files
#include <iostream>

// user include files

#else /* filename-only includes */
#include <iostream>
#include <types.h>
#endif /* filename-only includes */
// system include files

// user include files

// forward declarations

//
// constants, enums and typedefs
//
enum EvtGenSeverity
{
    EVTGEN_EMERGENCY,    // fatal
    EVTGEN_ALERT,        // requires immediate action
    EVTGEN_CRITICAL,     // serious
    EVTGEN_ERROR,
    EVTGEN_WARNING,
    EVTGEN_NOTICE,    // "normal but significant"
    EVTGEN_INFO,      // informational
    EVTGEN_DEBUG      // debug
};

// function declaration
std::ostream& EvtGenReport( EvtGenSeverity severity, const char* facility = 0 );

// inline function definitions

#endif /* TOOLBOX_FUNCTIONS_HH */
