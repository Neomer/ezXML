cmake_minimum_required(VERSION 3.8)

project(ezXML  VERSION 1.0.0 DESCRIPTION "ezXML. Free XML library under LGPL license.")
set(SOURCE_LIB export.h
    XmlNode.cpp XmlNode.h
    XmlAttribute.cpp XmlAttribute.h)

add_library(ezXML SHARED ${SOURCE_LIB})
include_directories("../")
set_target_properties(ezXML PROPERTIES VERSION ${PROJECT_VERSION})
add_compile_definitions(LIBRARY_EXPORT)
target_link_libraries(${TARGET} ezXML)

SET_TARGET_PROPERTIES(ezXML PROPERTIES LINKER_LANGUAGE CXX)

set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(TARGET ezXML PROPERTY CXX_STANDARD 17)

