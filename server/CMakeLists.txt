cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SocketServer)

# Add executable
add_executable(SocketServer main.cpp server.cpp)

# Specify include directories
target_include_directories(SocketServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Set C++ standard
set_target_properties(SocketServer PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES)
