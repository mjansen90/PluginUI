cmake_minimum_required(VERSION 2.6)

project(${PROJECT_NAME_SAMPLEPAGE2})

set(SAMPLE_PAGE_TWO_MOC_SRCS
   SamplePage2.h
)

set(SAMPLE_PAGE_TWO_SRCS
   ${SAMPLE_PAGE_TWO_MOC_SRCS}
   SamplePage2_global.h
   SamplePage2.cpp
)

set(SAMPLE_PAGE_TWO_UI
   SamplePage2.ui
)

include_directories(../Common)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

link_directories(${CMAKE_CURRENT_BINARY_DIR}/../../Common/Debug)

QT4_WRAP_CPP(SAMPLE_PAGE_TWO_MOC_OUTFILES ${SAMPLE_PAGE_TWO_MOC_SRCS})
QT4_WRAP_UI(SAMPLE_PAGE_TWO_UI_OUTFILES ${SAMPLE_PAGE_TWO_UI})

source_group("Generated Files" FILES ${SAMPLE_PAGE_TWO_MOC_OUTFILES} ${SAMPLE_PAGE_TWO_UI_OUTFILES})

add_library(${PROJECT_NAME_SAMPLEPAGE2} SHARED
   ${SAMPLE_PAGE_TWO_SRCS}
   ${SAMPLE_PAGE_TWO_MOC_OUTFILES}
   ${SAMPLE_PAGE_TWO_UI_OUTFILES}
)

target_link_libraries(${PROJECT_NAME_SAMPLEPAGE2} LINK_PRIVATE
   ${QT_LIBRARIES}
   ${PROJECT_NAME_COMMON}
)
