cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

project(GHS)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/extlibs/find/")

add_subdirectory(extlibs/build/json)

file(GLOB PG_GHS include/*.h)
file(GLOB HD_GHS src/*.cpp)

find_package(SFML 2 REQUIRED graphics window system network audio)
add_subdirectory(extlibs/build/TGUI)

include_directories(include/)
include_directories(extlibs/include/)
include_directories(${SFML_INCLUDE_DIR})

add_executable(GHS ${PG_GHS} ${HD_GHS})


target_link_libraries(GHS jsoncpp tgui)
if(SFML_FOUND)
    target_link_libraries(GHS ${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)