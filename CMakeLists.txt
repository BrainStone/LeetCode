cmake_minimum_required(VERSION 3.27)
project(LeetCode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON" FORCE)

# Get all LeetCode project files in the current directory
file(GLOB CPP_SOURCES problems/leetcode/editor/en/*.cpp)

# Allow us to use helpers
include_directories(helpers)

# Loop through each .cpp file
foreach(CPP_SOURCE ${CPP_SOURCES})
    # Define variables (Read the problem ID and detect the entry point)
    string(REGEX REPLACE ".*\\[([0-9]+)\\].*" "\\1" ID ${CPP_SOURCE})
    set(EXECUTABLE_NAME Problem_${ID})
    file(READ ${CPP_SOURCE} CPP_SOURCE_STR)
    string(REGEX MATCH "public:[ \t\r\n]+([^ \t\r\n]+)[ \t\r\n]+([^ \t\r\n]+)\\(([^)]+)\\)" FUNCTION_DECLARATION ${CPP_SOURCE_STR})
    set(FUNCTION_RETURN_TYPE ${CMAKE_MATCH_1})
    set(FUNCTION_NAME ${CMAKE_MATCH_2})
    string(REGEX REPLACE "[ \t\r\n]+[^ \t\r\n]+[ \t\r\n]*(,|$)" "\\1" FUNCTION_ARG_TYPES ${CMAKE_MATCH_3})

    # Setup code
    add_executable(${EXECUTABLE_NAME} ${CPP_SOURCE})
    target_compile_definitions(${EXECUTABLE_NAME} PRIVATE
            LEETCODE_PROBLEM_RETURNTYPE=${FUNCTION_RETURN_TYPE}
            LEETCODE_PROBLEM_FUNCNAME=${FUNCTION_NAME}
            LEETCODE_PROBLEM_ARGTYPES=${FUNCTION_ARG_TYPES}
    )
endforeach()
