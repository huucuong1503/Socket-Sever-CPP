cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SocketClient)

# Add executable
add_executable(SocketClient main.cpp client.cpp)

# Specify include directories
target_include_directories(SocketClient PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Set C++ standard
set_target_properties(SocketClient PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES)
