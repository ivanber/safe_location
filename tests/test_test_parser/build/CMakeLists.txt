cmake_minimum_required (VERSION 2.8)

IF (DEFINED CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ELSE ()
   SET(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ENDIF ()

set(PROJECT test_test_parser)
project (${PROJECT})

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake)
include(compiler_flags)

set (${PROJECT}_INCLUDE_DIRS
  ..
  ../src
  ../../../src
  ../../../3rdparty/Catch/single_include
)

set (HEADERS
  ../../../src/test_parser.h
)

set (SOURCES
  ../../../src/test_parser.cpp
  ../src/main.cpp
)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_executable(${PROJECT} ${HEADERS} ${SOURCES})

set(${PROJECT}_ABS_INCLUDE_DIRS)
foreach (INCLUDE_DIR ${${PROJECT}_INCLUDE_DIRS})
  get_filename_component(ABS_INCLUDE_DIR ${INCLUDE_DIR} ABSOLUTE)
  set(${PROJECT}_ABS_INCLUDE_DIRS ${${PROJECT}_ABS_INCLUDE_DIRS} ${ABS_INCLUDE_DIR})
endforeach()
set_target_properties (${PROJECT} PROPERTIES INCLUDE_DIRECTORIES "${${PROJECT}_ABS_INCLUDE_DIRS}")

add_test(${PROJECT} ${PROJECT})

