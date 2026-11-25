cmake_minimum_required(VERSION 3.20)
project(SortingLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Полезный ключик для тех, кто использует Visual Studio.
set(CMAKE_SUPPRESS_REGENERATION true)

enable_testing()

set(BUILD_GMOCK OFF)
add_subdirectory(../lib/googletest lib/googletest)

add_subdirectory(sort)
add_subdirectory(timer)
add_subdirectory(test)