cmake_minimum_required(VERSION 3.14)
project(robot_math VERSION 1.0)

# C++17 required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable from source files
add_executable(robot_math
    main.cpp
    mathutils.cpp
)

# Good practice — enable warnings
target_compile_options(robot_math PRIVATE -Wall -Wextra)

# Create a library from mathutils
add_library(mathutils_lib
    mathutils.cpp
)

# Create executable and link against library
add_executable(robot_math_v2
    main.cpp
)

target_link_libraries(robot_math_v2 PRIVATE mathutils_lib)

# Library needs to find its header
target_include_directories(mathutils_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})