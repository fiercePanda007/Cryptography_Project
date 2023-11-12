cmake_minimum_required(VERSION 3.10)

project(sha512_project)

# Include directories
include_directories(includes)

# Source files
set(SOURCES
    src/sha512.cpp
    src/main.cpp
)

# Create executable
add_executable(sha512_executable ${SOURCES})

