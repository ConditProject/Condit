cmake_minimum_required(VERSION 3.3)

set(ProjectName Condit)
project(${ProjectName} CXX)

set(CMAKE_CXX_STANDARD 14)  # allows for variable templates
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(third_party)  # Third party libraries/dependencies

# Static libraries because they are not that large
add_library(libstatus STATIC src/status.cc)  # Status
# TODO(samiurkh1n): StatusOr library

add_subdirectory(tests)

