find_program(LATEX  NAMES latex HINTS  ${LATEX}  PATHS $ENV{PATH} /usr/bin/ /usr/local/bin )
find_program(BIBTEX  NAMES bibtex HINTS  ${BIBTEX}  PATHS $ENV{PATH} /usr/bin/ /usr/local/bin )
find_program(MAKEINDEX  NAMES makeindex HINTS  ${MAKEINDEX}  PATHS $ENV{PATH} /usr/bin/ /usr/local/bin )
find_program(DVIPS  NAMES dvips HINTS  ${DVIPS} PATHS $ENV{PATH} /usr/bin/ /usr/local/bin )

if ( LATEX AND BIBTEX AND MAKEINDEX AND DVIPS )
MESSAGE(STATUS "EvtGen doc: Using LATEX=${LATEX} BIBTEX=${BIBTEX} MAKEINDEX=${MAKEINDEX} DVIPS=${DVIPS}.")

file(GLOB EVTGEN_DOC_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.tex
    ${CMAKE_CURRENT_SOURCE_DIR}/*.eps
    ${CMAKE_CURRENT_SOURCE_DIR}/*.fig
    ${CMAKE_CURRENT_SOURCE_DIR}/*.pdf
    ${CMAKE_CURRENT_SOURCE_DIR}/*.bib
    )

foreach ( s ${EVTGEN_DOC_SOURCES} )
configure_file(${s} ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
endforeach ( s ${EVTGEN_DOC_SOURCES}  )
ADD_CUSTOM_COMMAND(OUTPUT guide.ps  
COMMAND ${LATEX} guide
COMMAND ${BIBTEX} guide
COMMAND ${LATEX} guide
COMMAND ${MAKEINDEX} guide
COMMAND ${LATEX} guide
COMMAND ${DVIPS} guide.dvi -o guide.ps
DEPENDS ${EVTGEN_DOC_SOURCES}
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
ADD_CUSTOM_TARGET(GUIDE ALL DEPENDS guide.ps)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/guide.ps DESTINATION ${CMAKE_INSTALL_DOCDIR} COMPONENT doc)
else()
MESSAGE(STATUS "EvtGen doc: some of the required programs were not found: LATEX=${LATEX} BIBTEX=${BIBTEX} MAKEINDEX=${MAKEINDEX} DVIPS=${DVIPS}. The documentation will not be generated.")
endif()


