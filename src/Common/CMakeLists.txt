cmake_minimum_required(VERSION 2.6)

project(${PROJECT_NAME_COMMON})

set(COMMON_MOC_SRCS
   BasePage.h
)

set(COMMON_SRCS
   ${COMMON_MOC_SRCS}
   BasePage.cpp
   Common.h
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_CPP(COMMON_MOC_OUTFILES ${COMMON_MOC_SRCS})

source_group("Generated Files" FILES ${COMMON_MOC_OUTFILES})

add_library(${PROJECT_NAME_COMMON} SHARED
   ${COMMON_SRCS}
   ${COMMON_MOC_OUTFILES}
)

target_link_libraries(${PROJECT_NAME_COMMON} ${QT_LIBRARIES})
