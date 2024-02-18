cmake_minimum_required(VERSION 3.0.0)
project(RoadToRedis VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Set(REDIS_LIBRARIES ${CMAKE_SOURCE_DIR}\\lib)

include_directories(${CMAKE_SOURCE_DIR})

include_directories(${CMAKE_SOURCE_DIR}\\redis-plus-plus\\src)
include_directories(${CMAKE_SOURCE_DIR}\\redis-plus-plus\\src\\sw\\redis++\\cxx17)

include_directories(${CMAKE_SOURCE_DIR}\\redis-plus-plus\\src\\sw\\redis++\\tls)

message(${CMAKE_SOURCE_DIR})
add_executable(RoadToRedis main.cpp)

target_link_libraries(RoadToRedis ${REDIS_LIBRARIES}\\hiredisd.lib  ${REDIS_LIBRARIES}\\redis++_static.lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
