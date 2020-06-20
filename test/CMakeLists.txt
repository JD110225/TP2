cmake_minimum_required(VERSION 2.8.8)

set(This app)
set(Sources Test1.cpp)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC ListManager gtest_main)