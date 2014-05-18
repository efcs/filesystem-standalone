cmake_minimum_required(VERSION 2.8)
project(std_any CXX)

if ( ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" )
    message(STATUS "Configuring for Compiler: GCC")
    set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic -fmax-errors=5 ${CMAKE_CXX_FLAGS}")
elseif( ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" )
    message(STATUS "Configuring for Compiler: Clang")
    set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic -ferror-limit=5 ${CMAKE_CXX_FLAGS}")
else()
    message( WARNING "Compiler not supported! (${CMAKE_CXX_COMPILER_ID})" )
endif()

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(elib)

add_executable(test_any any_test.cpp)
target_link_libraries(test_any ${Boost_LIBRARIES})

add_custom_command(TARGET test_any POST_BUILD COMMAND test_any)