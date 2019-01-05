cmake_minimum_required(VERSION 3.3)

set(ProjectName Condit)
project(${ProjectName} CXX)

set(CMAKE_CXX_STANDARD 14)  # allows for variable templates
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
)

if (MSVC)
  foreach(CompilerFlag ${CompilerFlags})
    set(${CompilerFlag} "/MTd")
  endforeach()
endif()

add_subdirectory(third_party)  # Third party libraries/dependencies

add_library(libstatus STATIC src/status.cc)

add_subdirectory(tests)

