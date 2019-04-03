cmake_minimum_required(VERSION 3.8)

project(XmlSample VERSION 1.0.0 DESCRIPTION "ezXML sample app")
set(SOURCE_EXE main.cpp)
add_executable(XmlSample ${SOURCE_EXE})
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/src)
TARGET_LINK_LIBRARIES(XmlSample ezXML)

include_directories("../")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(TARGET XmlSample PROPERTY CXX_STANDARD 17)

add_custom_command(
    TARGET XmlSample
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:ezXML>
        $<TARGET_FILE_DIR:XmlSample>/$<TARGET_FILE_NAME:ezXML>
)
