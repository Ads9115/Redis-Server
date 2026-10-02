cmake_minimum_required(VERSION 3.20)

project(RedisServer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(RedisServer
    src/main.cpp
    src/RedisServer.cpp
    src/RedisCommandHandler.cpp
    src/RedisDatabase.cpp
    )

target_include_directories(RedisServer PRIVATE include)

find_package(Threads REQUIRED)
target_link_libraries(RedisServer PRIVATE Threads::Threads)
