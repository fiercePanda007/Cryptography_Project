# encryption/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(EncryptionProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add include directories
include_directories(rsa_project/include)

# Add source files
add_executable(main_new
    rsa_project/src/primes.cpp
    rsa_project/src/rsa.cpp
    main_new.cpp
)
