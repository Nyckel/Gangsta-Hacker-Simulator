cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

project(jsoncpp)

include_directories(../../include/json/)
include_directories(../../include/)
include_directories(src/)
file(GLOB PG_JSON ../../include/json/*.h)
file(GLOB HD_JSON src/*.cpp src/*.h src/*.in src/*.inl)

add_library(jsoncpp ${PG_JSON} ${HD_JSON})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)