cmake_minimum_required(VERSION 3.9)
project(Proyecto2_Odissey)

set(CMAKE_CXX_STANDARD 11)

add_executable(Proyecto2_Odissey Odyssey_Server.cpp Odyssey_Server.h Base64.cpp Base64.h .idea/Chunk.cpp .idea/Chunk.h .idea/MetaData.h .idea/Lista.h)