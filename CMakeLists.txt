CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT (libNativePath)

FIND_PATH(NP_INCLUDE_DIR NAMES NativeMath.h
  PATHS
  ${PROJECT_SOURCE_DIR}/NativePath/
)

INCLUDE_DIRECTORIES(${NP_INCLUDE_DIR})


IF(${CMAKE_GENERATOR} MATCHES "Unix Makefiles")
	SET(NP_LIB_DIR ${NP_INCLUDE_DIR}/..)
	SET(NP_LIB NativePath)
ELSE()
	SET(NP_LIB_DIR ${NP_INCLUDE_DIR}/..)
	SET(NP_LIB libNativePath)
ENDIF()

ADD_LIBRARY(${NP_LIB} STATIC
    NativePath/NativeMath.c
    NativePath/NativeMemory.c
    NativePath/lol_trig.cpp
)
