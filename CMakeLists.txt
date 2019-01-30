cmake_minimum_required(VERSION 3.0)

project(luacv)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(THIRD_PARTY_PATH "${CMAKE_CURRENT_BINARY_DIR}/third_party" CACHE STRING
  "A path setting third party libraries download & build directories.")

set(CMAKE_INSTALL_PREFIX ${THIRD_PARTY_PATH}/luacv)
set(DCMAKE_INSTALL_LIBDIR ${THIRD_PARTY_PATH}/luacv/lib)

#for testing
#set(DEP_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/deps")
#set(OPENCV_INSTALL_DIR "${DEP_LIB_PATH}/opencv")
#set(LUA_INSTALL_DIR "${DEP_LIB_PATH}/lua")
#set(KAGUYA_INSTALL_DIR "${DEP_LIB_PATH}/kaguya/include")

#include kaguya headers
set(KAGUYA_BINDING_SRC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src")

#include opencv
if(NOT EXISTS ${OPENCV_INSTALL_DIR})
    message(SEND_ERROR "not found installed opencv in ${OPENCV_INSTALL_DIR}")
endif()
include_directories(${OPENCV_INSTALL_DIR}/include)
link_directories(${OPENCV_INSTALL_DIR}/lib)

#include lua libs
if(NOT EXISTS ${LUA_INSTALL_DIR})
    include(external/lua)
else()
    add_library(lua STATIC IMPORTED GLOBAL)
    set_property(TARGET lua 
                PROPERTY IMPORTED_LOCATION 
                ${LUA_INSTALL_DIR}/lib/liblua.a)
endif()
set(LUA_INCLUDE_PATH "${LUA_INSTALL_DIR}/include")
set(LUA_LIBRARY_PATH "${LUA_INSTALL_DIR}/lib")
message("lua path ${LUA_INSTALL_DIR}")

include_directories(${LUA_INCLUDE_PATH})
link_directories(${LUA_LIBRARY_PATH})

#include kaguya
if(NOT EXISTS ${KAGUYA_INSTALL_DIR})
    include(external/kaguya)
endif()
message("use kaguya in: ${KAGUYA_INSTALL_DIR}")
include_directories("${KAGUYA_INSTALL_DIR}")

include_directories("${KAGUYA_BINDING_SRC_PATH}")
add_definitions("-Wall -std=c++11 -fPIC")

file(GLOB SRC_FILES
        "${KAGUYA_BINDING_SRC_PATH}/*.cc")
add_library(luacv ${SRC_FILES})
add_dependencies(luacv kaguya)

INSTALL(
    DIRECTORY "${KAGUYA_INSTALL_DIR}/kaguya"
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")

INSTALL(
    TARGETS luacv
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)
