cmake_minimum_required(VERSION 3.8)

project(XmlSample VERSION 1.0.0 DESCRIPTION "ezXML sample app")
set(SOURCE_EXE main.cpp)
add_executable(XmlSample ${SOURCE_EXE})
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/src)
TARGET_LINK_LIBRARIES(XmlSample ezXML)

include_directories("../")
