cmake_minimum_required(VERSION 2.6)

project(PluginUI)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

#add_link_flags(/NODEFAULTLIB:library)

set(PROJECT_NAME_COMMON       Common)
set(PROJECT_NAME_PLUGINAPP    PluginApp)
set(PROJECT_NAME_SAMPLEPAGE   SamplePage)

add_subdirectory(src/Common)
add_subdirectory(src/PluginApp)
add_subdirectory(src/SamplePage)
