cmake_minimum_required(VERSION 3.0.0)
project(RoadToRedis VERSION 0.1.0 LANGUAGES C CXX)

add_executable(RoadToRedis main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
