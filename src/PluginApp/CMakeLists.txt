cmake_minimum_required(VERSION 2.6)

project(PluginApp)

set(PLUGINAPP_MOC_SRCS
   PluginUI.h
)

set(PLUGINAPP_SRCS
   ${PLUGINAPP_MOC_SRCS}
   main.cpp
   PluginUI.cpp
)

set(PLUGINAPP_UI
   PluginUI.ui
)

include_directories(../Common)
include_directories(${CMAKE_CURENT_BINARY_DIR})

QT4_WRAP_CPP(PLUGINAPP_MOC_OUTFILES ${PLUGINAPP_MOC_SRCS})
QT4_WRAP_UI(PLUGINAPP_UI_OUTFILES ${PLUGINAPP_UI})

source_group("Generated Files" FILES ${PLUGINAPP_MOC_OUTFILES} ${PLUGINAPP_UI_OUTFILES})

add_executable(PluginUI
   ${PLUGINAPP_SRCS}
   ${PLUGINAPP_MOC_OUTFILES}
   ${PLUGINAPP_UI_OUTFILES}
)

target_link_libraries(PluginUI ${QT_LIBRARIES})
