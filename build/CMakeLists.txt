cmake_minimum_required(VERSION 2.8)

IF (DEFINED CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ELSE ()
   SET(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ENDIF ()

set(PROJECT safe_place)
project(${PROJECT})

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)
include(compiler_flags)


set (${PROJECT}_INCLUDE_DIRS
  ..
  ../src
)

set(HEADERS
  ../src/point.h
  ../src/ranker.h
  ../src/test.h
  ../src/test_reader.h
  ../src/test_parser.h
  ../src/vec.h
  ../src/worker.h
)

set(SOURCES
  ../src/main.cpp
  ../src/ranker.cpp
  ../src/test_reader.cpp
  ../src/test_parser.cpp
  ../src/vec.cpp
  ../src/worker.cpp
)

add_executable(${PROJECT} ${HEADERS} ${SOURCES})

set(${PROJECT}_ABS_INCLUDE_DIRS)
foreach (INCLUDE_DIR ${${PROJECT}_INCLUDE_DIRS})
  get_filename_component(ABS_INCLUDE_DIR ${INCLUDE_DIR} ABSOLUTE)
  set(${PROJECT}_ABS_INCLUDE_DIRS ${${PROJECT}_ABS_INCLUDE_DIRS} ${ABS_INCLUDE_DIR})
endforeach()
set_target_properties (${PROJECT} PROPERTIES INCLUDE_DIRECTORIES "${${PROJECT}_ABS_INCLUDE_DIRS}")

enable_testing ()

file (GLOB TESTS ../tests/*)
foreach (TEST ${TESTS})
  if (IS_DIRECTORY ${TEST})
    get_filename_component(TEST_NAME ${TEST} NAME)
    add_subdirectory(${TEST}/build tests/${TEST_NAME})
  endif ()
endforeach()

