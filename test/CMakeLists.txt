cmake_minimum_required(VERSION 3.22)

add_subdirectory(./GoogleTest/googletest)
set(gtest_SOURCE_DIR, ./GoogleTest/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(TEST_SOURCE_FILES runAllTest.cpp Chat_test.cpp Message_test.cpp Chat_registry_test.cpp User_test.cpp)
add_executable(runUnitTests ${TEST_SOURCE_FILES})
target_link_libraries(runUnitTests gtest gtest_main core)