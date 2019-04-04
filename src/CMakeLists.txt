cmake_minimum_required(VERSION 3.8)

project(ezXml  VERSION 1.0.0 DESCRIPTION "ezXml. Free XML library under LGPL license.")
set(SOURCE_LIB
    export.h
    IStringable.h
    XmlNode.cpp XmlNode.h
    XmlAttribute.cpp XmlAttribute.h
    XmlDocument.cpp XmlDocument.h
    XPath.cpp XPath.h)

add_library(ezXml SHARED ${SOURCE_LIB})
include_directories("../")
set_target_properties(ezXml PROPERTIES VERSION ${PROJECT_VERSION})

target_link_libraries(${TARGET} ezXml)

SET_TARGET_PROPERTIES(ezXml PROPERTIES LINKER_LANGUAGE CXX)

set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(TARGET ezXml PROPERTY CXX_STANDARD 17)

add_compile_definitions(LIBRARY_EXPORT)
if(${CMAKE_BUILD_TYPE} MATCHES "^Debug$")
    add_compile_definitions(DEBUG_)
endif()
add_compile_definitions(LIBRARY_EXPORT)
