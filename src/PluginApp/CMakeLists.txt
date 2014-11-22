cmake_minimum_required(VERSION 2.6)

project(${PROJECT_NAME_PLUGINAPP})

set(PLUGINAPP_MOC_SRCS
   PluginApp.h
)

set(PLUGINAPP_SRCS
   ${PLUGINAPP_MOC_SRCS}
   main.cpp
   PluginApp.cpp
)

set(PLUGINAPP_UI
   PluginApp.ui
)

include_directories(..)
include_directories(../Common)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_CPP(PLUGINAPP_MOC_OUTFILES ${PLUGINAPP_MOC_SRCS})
QT4_WRAP_UI(PLUGINAPP_UI_OUTFILES ${PLUGINAPP_UI})

source_group("Generated Files" FILES ${PLUGINAPP_MOC_OUTFILES} ${PLUGINAPP_UI_OUTFILES})

add_executable(${PROJECT_NAME_PLUGINAPP}
   ${PLUGINAPP_SRCS}
   ${PLUGINAPP_MOC_OUTFILES}
   ${PLUGINAPP_UI_OUTFILES}
)

target_link_libraries(${PROJECT_NAME_PLUGINAPP}
   ${QT_LIBRARIES}
)
