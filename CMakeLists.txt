cmake_minimum_required(VERSION 3.22)
project(elaborato_chat)

set(CMAKE_CXX_STANDARD 20)

add_executable(elaborato_chat main.cpp chat.h chat.cpp user.h user.cpp message.h message.cpp chat_registry.h chat_registry.cpp)
