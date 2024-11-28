# lib/CMakeLists.txt
add_library(calculator SHARED
    src/calculator.cpp
)

target_include_directories(calculator
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_definitions(calculator PRIVATE CALCULATOR_EXPORTS)

set_target_properties(calculator PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Installation rules
install(TARGETS calculator
    EXPORT calculatorTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(FILES include/calculator.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT calculatorTargets
    FILE calculatorTargets.cmake
    NAMESPACE calculator::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/calculator
)