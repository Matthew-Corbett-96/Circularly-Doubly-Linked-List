# DATE_CREATED: 7/23/20
# ARTHOR: Matthew J. Corbett
# *** Do Not Edit ***

cmake_minimum_required(VERSION 2.0.0)
project(CDLL)
set(CMAKE_BUILD_TYPE Release)

include_directories(Include)
file(GLOB SOURCES "Src/*.cpp")

add_library(CDLL_LIB STATIC ${SOURCES})
install(TARGETS CDLL_LIB DESTINATION /usr/bin)
