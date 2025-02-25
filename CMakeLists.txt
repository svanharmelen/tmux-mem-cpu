# vim: tabstop=2 shiftwidth=2 expandtab textwidth=80 linebreak wrap
#
# Copyright 2012 Matthew McCormick
# Copyright 2015 Pawel 'l0ner' Soltys
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.10)

### General Package stuff
project(tmux-mem-cpu)

# Check whether we have support for c++11 in compiler and fail if we don't
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(FATAL_ERROR
    "Compiler ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} has no C++11 support.")
endif()

# set build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE MinSizeRel CACHE STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
    FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# detect system type
if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
  message(STATUS "Darwin detected")
else()
  message(FATAL_ERROR "${CMAKE_SYSTEM_NAME} Cannot be compiled on this system")
  message(FATAL_ERROR "Cannot be compiled on this system")
endif()

# set common source files
set(COMMON_SOURCES "src/main.cc" "src/memory.cc" "src/cpu.cc" "src/tick.cc")

add_executable(tmux-mem-cpu ${COMMON_SOURCES})

# add binary tree so we find version.h
target_include_directories(tmux-mem-cpu PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(tmux-mem-cpu PUBLIC "${PROJECT_SOURCE_DIR}"
  "${PROJECT_SOURCE_DIR}/src")

install(TARGETS tmux-mem-cpu RUNTIME DESTINATION bin)

include(CTest)
if(BUILD_TESTING)
  add_test(NAME usage
    COMMAND tmux-mem-cpu -h
    )

  add_test(NAME no_arguments
    COMMAND tmux-mem-cpu
    )

  add_test(NAME custom_interval
    COMMAND tmux-mem-cpu -i 3
    )

  add_test(NAME invalid_status_interval
    COMMAND tmux-mem-cpu-load -i -1
    )

  set_tests_properties(usage
    invalid_status_interval
    PROPERTIES WILL_FAIL TRUE)
endif()
