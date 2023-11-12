cmake_minimum_required(VERSION 3.10)

project(aes_project)

set(KEYFILE_PATH ${PROJECT_SOURCE_DIR}/src/keyfile)
set(MESSAGE_PATH ${PROJECT_SOURCE_DIR}/src/message.aes)
# Add the include directory

include_directories(include)

# Add the source files
set(SOURCES
    src/encryption.cpp
    src/decryption.cpp
    src/main.cpp
    src/structures.cpp
)

# Generate the executable
add_executable(aes_project ${SOURCES})

# If you have additional libraries, add them here using target_link_libraries.
# For example:
# target_link_libraries(aes_project some_library)

# If you have additional compile options, add them here.
# For example:
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
