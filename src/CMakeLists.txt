
# Use glob to find the sources for the main and external libraries
file(GLOB EVTGEN_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/EvtGenBase/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/EvtGenModels/*.cpp
    )

file(GLOB EVTGEN_EXTERNAL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/EvtGenExternal/*.cpp
    )

# Add the main EvtGen library...
add_library(objlib OBJECT ${EVTGEN_SOURCES})
set_target_properties(objlib PROPERTIES POSITION_INDEPENDENT_CODE 1)
target_include_directories(objlib PRIVATE ${CMAKE_SOURCE_DIR})

target_compile_definitions(objlib PRIVATE EVTGEN_CPP11)
if (EVTGEN_HEPMC3)
target_compile_definitions(objlib PRIVATE EVTGEN_HEPMC3)
target_include_directories(objlib PRIVATE ${HEPMC3_INCLUDE_DIR})
else()
target_include_directories(objlib PRIVATE ${HEPMC2_INCLUDE_DIR})
endif()

add_library(EvtGen SHARED $<TARGET_OBJECTS:objlib>)
set_target_properties(EvtGen PROPERTIES OUTPUT_NAME EvtGen)
set_target_properties(EvtGen PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION_MAJOR} )
set_target_properties(EvtGen PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
target_include_directories(EvtGen PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

if (EVTGEN_HEPMC3)
target_include_directories(EvtGen PUBLIC ${HEPMC3_INCLUDE_DIR})
target_link_libraries(EvtGen ${HEPMC3_LIB} ${HEPMC3_SEARCH_LIB} )
else()
target_include_directories(EvtGen PUBLIC ${HEPMC2_INCLUDE_DIR})
target_link_libraries(EvtGen ${HEPMC2_LIBRARIES})
endif()

target_compile_definitions(EvtGen PUBLIC EVTGEN_CPP11)


add_library(EvtGenStatic STATIC $<TARGET_OBJECTS:objlib>)
set_target_properties(EvtGenStatic PROPERTIES OUTPUT_NAME EvtGen)
set_target_properties(EvtGenStatic PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/archive)
target_include_directories(EvtGenStatic PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
if (EVTGEN_HEPMC3)
target_include_directories(EvtGenStatic PUBLIC ${HEPMC3_INCLUDE_DIR})
target_link_libraries(EvtGenStatic ${HEPMC3_LIB} ${HEPMC3_SEARCH_LIB} )
else()
target_include_directories(EvtGenStatic PUBLIC ${HEPMC2_INCLUDE_DIR})
target_link_libraries(EvtGenStatic ${HEPMC2_LIBRARIES})
endif()
target_compile_definitions(EvtGenStatic PUBLIC EVTGEN_CPP11)



# Add the EvtGenExternal library...
if( ${EVTGEN_PYTHIA} OR ${EVTGEN_PHOTOS} OR ${EVTGEN_TAUOLA} )
    add_library(objlib_ext OBJECT ${EVTGEN_EXTERNAL_SOURCES})
    set_target_properties(objlib_ext PROPERTIES POSITION_INDEPENDENT_CODE 1)
    target_include_directories(objlib_ext PRIVATE ${CMAKE_SOURCE_DIR})
    if (EVTGEN_HEPMC3)
    target_include_directories(objlib_ext PUBLIC ${HEPMC3_INCLUDE_DIR})
    target_compile_definitions(objlib_ext PRIVATE EVTGEN_HEPMC3)
    else()
    target_include_directories(objlib_ext PUBLIC ${HEPMC2_INCLUDE_DIR})
    endif()
    target_compile_definitions(objlib_ext PRIVATE EVTGEN_CPP11)
    if(${EVTGEN_PYTHIA})
        target_include_directories(objlib_ext PRIVATE ${PYTHIA8_INCLUDE_DIRS})
        target_compile_definitions(objlib_ext PRIVATE EVTGEN_PYTHIA)
    endif()
    if(${EVTGEN_PHOTOS})
        target_include_directories(objlib_ext PRIVATE ${Photos++_INCLUDE_DIRS})
        target_compile_definitions(objlib_ext PRIVATE EVTGEN_PHOTOS)
    endif()
    if(${EVTGEN_TAUOLA})
        target_include_directories(objlib_ext PRIVATE ${Tauola++_INCLUDE_DIRS})
        target_compile_definitions(objlib_ext PRIVATE EVTGEN_TAUOLA)
    endif()

    add_library(EvtGenExternal SHARED $<TARGET_OBJECTS:objlib_ext>)
    set_target_properties(EvtGenExternal PROPERTIES OUTPUT_NAME EvtGenExternal)
    set_target_properties(EvtGenExternal PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION_MAJOR} )
    set_target_properties(EvtGenExternal PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})

    if(${EVTGEN_PYTHIA})
        target_link_libraries(EvtGenExternal ${PYTHIA8_LIBRARIES})
    endif()


    if (EVTGEN_HEPMC3)
    target_link_libraries(EvtGenExternal ${HEPMC3_LIB} ${HEPMC3_SEARCH_LIB} )
    if(${EVTGEN_PHOTOS})
        target_link_libraries(EvtGenExternal ${Photos++_pp_LIBRARY} ${Photos++_ppHepMC3_LIBRARY} )
    endif()
    if(${EVTGEN_TAUOLA})
        target_link_libraries(EvtGenExternal ${Tauola++_CxxInterface_LIBRARY} ${Tauola++_Fortran_LIBRARY}  ${Tauola++_HepMC3_LIBRARY})
    endif()
    else()
    target_link_libraries(EvtGenExternal ${HEPMC2_LIBRARIES})
    if(${EVTGEN_PHOTOS})
#Photos should always have ppHepMC for compilation with HepMC2 
        target_link_libraries(EvtGenExternal ${Photos++_pp_LIBRARY} ${Photos++_ppHepMC_LIBRARY})
    endif()
    if(${EVTGEN_TAUOLA})
    target_link_libraries(EvtGenExternal ${Tauola++_CxxInterface_LIBRARY} ${Tauola++_Fortran_LIBRARY})
#The old versions of Tauola don't have HepMC, the HepMC2 interface is in CxxInterface
        if (Tauola++_HepMC_FOUND)
        target_link_libraries(EvtGenExternal ${Tauola++_HepMC_LIBRARY})
        endif()
    endif()    
    endif()
    
    

    add_library(EvtGenExternalStatic STATIC $<TARGET_OBJECTS:objlib_ext>)
    set_target_properties(EvtGenExternalStatic PROPERTIES OUTPUT_NAME EvtGenExternal)
    set_target_properties(EvtGenExternalStatic PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/archive)
    if(${EVTGEN_PYTHIA})
        target_link_libraries(EvtGenExternalStatic ${PYTHIA8_LIBRARIES})
    endif()
    if (EVTGEN_HEPMC3)
    target_link_libraries(EvtGenExternalStatic ${HEPMC3_LIB} ${HEPMC3_SEARCH_LIB} )
    if(${EVTGEN_PHOTOS})
        target_link_libraries(EvtGenExternalStatic ${Photos++_pp_LIBRARY} ${Photos++_ppHepMC3_LIBRARY})
    endif()
    if(${EVTGEN_TAUOLA})
        target_link_libraries(EvtGenExternalStatic ${Tauola++_CxxInterface_LIBRARY} ${Tauola++_Fortran_LIBRARY} ${Tauola++_HepMC3_LIBRARY})
    endif()    
    else()
    if(${EVTGEN_PHOTOS})
        target_link_libraries(EvtGenExternalStatic ${Photos++_pp_LIBRARY} ${Photos++_ppHepMC_LIBRARY})
    endif()
    if(${EVTGEN_TAUOLA})
        target_link_libraries(EvtGenExternalStatic ${Tauola++_CxxInterface_LIBRARY} ${Tauola++_Fortran_LIBRARY})
        if (Tauola++_HepMC_FOUND)
        target_link_libraries(EvtGenExternalStatic ${Tauola++_HepMC_LIBRARY} )
        endif()
    endif()    
    target_link_libraries(EvtGenExternalStatic ${HEPMC2_LIBRARIES})
    endif()
endif()

# Install the libraries
install(
    TARGETS EvtGen EvtGenStatic
    EXPORT "EvtGenTargets"
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/archive
    )

if( ${EVTGEN_PYTHIA} OR ${EVTGEN_PHOTOS} OR ${EVTGEN_TAUOLA} )
    install(
        TARGETS EvtGenExternal EvtGenExternalStatic
        EXPORT "EvtGenTargets"
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/archive
        )
endif()
