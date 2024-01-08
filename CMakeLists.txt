cmake_minimum_required(VERSION 3.27)
project(LeetCode)

set(CMAKE_CXX_STANDARD 20)

# Get all LeetCode project files in the current directory
file(GLOB CPP_SOURCES problems/leetcode/editor/en/*.cpp)

# Loop through each .cpp file
foreach(CPP_SOURCE ${CPP_SOURCES})
    # Define variables
    string(REGEX REPLACE ".*\\[([0-9]+)\\].*" "\\1" ID ${CPP_SOURCE})
    set(EXECUTABLE_NAME Problem_${ID})

    # Setup code
    add_executable(${EXECUTABLE_NAME} ${CPP_SOURCE})
    target_include_directories(${EXECUTABLE_NAME} PRIVATE helpers)
endforeach()
