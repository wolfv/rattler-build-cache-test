
# python/CMakeLists.txt
find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(py_calculator 
    bindings.cpp
)

target_link_libraries(py_calculator PRIVATE calculator)

target_include_directories(py_calculator PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/include
)

# Installation rules for Python module
install(TARGETS py_calculator 
    LIBRARY DESTINATION "${Python_SITEARCH}"
)

# Set output directory for the Python module
set_target_properties(py_calculator PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/python
)