cmake_minimum_required(VERSION 2.82)

file(GLOB_RECURSE SOURCES "src/*[.cpp|.h]")

message(STATUS "Building for Vita")

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	if(DEFINED ENV{VITASDK})
		set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
	else()
		message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
	endif()
endif()

project(Python-Test C CXX)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APPNAME  "Python C++")
set(VITA_TITLEID  "PYTH00010")
set(VITA_VERSION  "01.00")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -std=c++17")
set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

find_package(OpenSSL REQUIRED)

target_link_libraries(${CMAKE_PROJECT_NAME}
	python2.7

	SceIofilemgr_stub
	SceNet_stub
	SceNetCtl_stub
	SceSsl_stub
	SceSysmodule_stub
	SceLibKernel_stub

	${OPENSSL_LIBRARIES}
	z
	m
	intl
)

vita_create_self(${CMAKE_PROJECT_NAME}.self ${CMAKE_PROJECT_NAME})

vita_create_vpk(${CMAKE_PROJECT_NAME}.vpk ${VITA_TITLEID} ${CMAKE_PROJECT_NAME}.self
	VERSION ${VITA_VERSION}
	NAME ${VITA_APPNAME}

	FILE "$ENV{VITASDK}/arm-vita-eabi/lib/python27.zip" lib/python27.zip
	FILE python/main.py main.py
)
