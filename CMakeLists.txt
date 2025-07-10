cmake_minimum_required(VERSION 3.14)
project(MyProject CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GCC-specific flags
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wall -Wextra -Wpedantic)
    # Optional: -O2 for optimization, -g for debug
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
endif()

# Fetch external library
include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.1.0  # Always specify a version
)
FetchContent_MakeAvailable(fmt)

# Your executable
add_executable(myapp src/main.cpp)
target_link_libraries(myapp PRIVATE fmt::fmt)
