CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT (libNativePath)

FIND_PATH(NP_INCLUDE_DIR NAMES NativeMath.h
  PATHS
  ${PROJECT_SOURCE_DIR}/NativePath/
)

INCLUDE_DIRECTORIES(${NP_INCLUDE_DIR} ${NP_INCLUDE_DIR}/../source)
INCLUDE_DIRECTORIES(${NP_INCLUDE_DIR} ${NP_INCLUDE_DIR}/../../boost_1_62_0)

IF(${CMAKE_GENERATOR} MATCHES "Unix Makefiles")
	SET(NP_LIB_DIR ${NP_INCLUDE_DIR}/..)
	SET(NP_LIB NativePath)
ELSE()
	SET(NP_LIB_DIR ${NP_INCLUDE_DIR}/..)
	SET(NP_LIB libNativePath)
ENDIF()

ADD_LIBRARY(${NP_LIB} STATIC
    source/NativeMath.c
    source/NativeMemory.c
    source/lol_trig.cpp
	source/NativeTime.cpp
	source/NativeDynamicLinking.c
	source/stdlib.c
	source/stdio.c
	source/NEONvsSSE.c
	source/NativePool.cpp
	source/NativeThreading.cpp
	source/workarounds.c
)
