# CMakeLists.txt (root)
cmake_minimum_required(VERSION 3.15)
project(calculator_project VERSION 1.0)

option(BUILD_PYTHON_BINDINGS "Build Python bindings" OFF)
include(GNUInstallDirs)

add_subdirectory(lib)
if(BUILD_PYTHON_BINDINGS)
    add_subdirectory(python)
endif()