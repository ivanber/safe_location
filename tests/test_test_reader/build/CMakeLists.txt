cmake_minimum_required (VERSION 2.8)

IF (DEFINED CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ELSE ()
   SET(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ENDIF ()

set(PROJECT test_test_reader)
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
  ../../../src/test_reader.h
)

set (SOURCES
  ../../../src/test_parser.cpp
  ../../../src/test_reader.cpp
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


set (${PROJECT}_DATA_FILES
  single_test_single_point.txt
  single_test_multiple_points.txt
  multiple_tests.txt
)
foreach (DATA_FILE ${${PROJECT}_DATA_FILES})
  ADD_CUSTOM_COMMAND(
    TARGET ${PROJECT}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ARGS ${CMAKE_CURRENT_SOURCE_DIR}/../data/${DATA_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${DATA_FILE}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../data/${DATA_FILE}
  )
endforeach()

add_test(${PROJECT} ${PROJECT})

