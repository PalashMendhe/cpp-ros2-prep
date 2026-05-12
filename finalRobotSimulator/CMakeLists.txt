cmake_minimum_required(VERSION 3.14)
project(RobotSimulator VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(sensorBuffer sensorBuffer.cpp)
target_include_directories(sensorBuffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(RobotSimulator main.cpp RobotSimulator.cpp MessageQueue.cpp TopicRegistry.cpp)
target_link_libraries(RobotSimulator PRIVATE sensorBuffer)
target_compile_options(RobotSimulator PRIVATE -Wall -Wextra)