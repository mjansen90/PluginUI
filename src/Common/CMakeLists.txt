cmake_minimum_required(VERSION 2.6)

project(Common)

set(COMMON_MOC_SRCS
   BasePage.h
)

set(COMMON_SRCS
   ${COMMON_MOC_SRCS}
   BasePage.cpp
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_CPP(COMMON_MOC_OUTFILES ${COMMON_MOC_SRCS})

source_group("Generated Files" FILES ${COMMON_MOC_OUTFILES})

add_library(Common SHARED
   ${COMMON_SRCS}
   ${COMMON_MOC_OUTFILES}
)

target_link_libraries(Common ${QT_LIBRARIES})
