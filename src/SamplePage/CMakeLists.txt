cmake_minimum_required(VERSION 2.6)

project(${PROJECT_NAME_SAMPLEPAGE})

set(SAMPLE_PAGE_MOC_SRCS
   SamplePage.h
)

set(SAMPLE_PAGE_SRCS
   ${SAMPLE_PAGE_MOC_SRCS}
   SamplePage_global.h
   SamplePage.cpp
)

set(SAMPLE_PAGE_UI
   SamplePage.ui
)

include_directories(../Common)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

link_directories(${CMAKE_CURRENT_BINARY_DIR}/../../Common/Debug)

QT4_WRAP_CPP(SAMPLE_PAGE_MOC_OUTFILES ${SAMPLE_PAGE_MOC_SRCS})
QT4_WRAP_UI(SAMPLE_PAGE_UI_OUTFILES ${SAMPLE_PAGE_UI})

source_group("Generated Files" FILES ${SAMPLE_PAGE_MOC_OUTFILES} ${SAMPLE_PAGE_UI_OUTFILES})

add_library(${PROJECT_NAME_SAMPLEPAGE} SHARED
   ${SAMPLE_PAGE_SRCS}
   ${SAMPLE_PAGE_MOC_OUTFILES}
   ${SAMPLE_PAGE_UI_OUTFILES}
)

target_link_libraries(${PROJECT_NAME_SAMPLEPAGE} LINK_PRIVATE
   ${QT_LIBRARIES}
   ${PROJECT_NAME_COMMON}
)
