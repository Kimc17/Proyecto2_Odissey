cmake_minimum_required(VERSION 3.9)
project(Proyecto2_Odissey)

set(CMAKE_CXX_STANDARD 11)

add_executable(Proyecto2_Odissey XML/XML_Editor.cpp XML/XML_Editor.h XML/pugixml.cpp XML/pugiconfig.hpp main.cpp)
