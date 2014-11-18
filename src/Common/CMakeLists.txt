cmake_minimum_required(VERSION 2.6)

project(App)

set(GRP_SRCS
   main.cpp
)

include_directories(..)
include_directories(../../inc)
include_directories(../../inc-ext)
include_directories(../../inc/Common)
include_directories(../../inc/ptree_export)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../lib-ext)
add_executable(App ${GRP_SRCS})

target_link_libraries(App LINK_PRIVATE ptree_export)
