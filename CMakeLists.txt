cmake_minimum_required(VERSION 3.22)
project(elaborato_chat)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(test)
set(SOURCE_FILES User.cpp User.h Message.cpp Message.h Chat.cpp Chat.h Chat_registry.cpp Chat_registry.h)
add_executable(elaborato_chat main.cpp)
add_library(core ${SOURCE_FILES})

target_link_libraries(elaborato_chat core)
