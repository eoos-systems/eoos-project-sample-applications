# EOOS Sample Application.
#
# @author    Sergey Baigudin, sergey@baigudin.software
# @copyright 2022, Sergey Baigudin, Baigudin Software

cmake_minimum_required(VERSION 3.10)
project(eoos-sample-application VERSION 0.2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(WIN32)
message(STATUS "EOOS Apps is building for WIN32")
# Enable the __cplusplus macro to report the supported standard as it is off by default.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus" CACHE STRING "" FORCE)
elseif(UNIX)
message(STATUS "EOOS Apps is building for UNIX")
find_package(Threads REQUIRED)
else()
message(FATAL_ERROR "EOOS Sample Application cannot be built for your OS")
endif()

find_package(EOOS 0.11.0 REQUIRED)

add_subdirectory(codebase)
