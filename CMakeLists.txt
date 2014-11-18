cmake_minimum_required(VERSION 2.6)

project(PluginUI)

find_package(Qt4 REQUIRED)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

#add_link_flags(/NODEFAULTLIB:library)

#add_subdirectory(src/Common)
add_subdirectory(src/PluginApp)
