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

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)


include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(libs/elib)

add_definitions(-DELIB_FILESYSTEM_V2_UNIT_TEST_PATH="${CMAKE_CURRENT_LIST_DIR}/unit_tests")

add_library(ObjLib OBJECT 
                    src/filesystem/v2/directory_iterator.cpp
                    src/filesystem/v2/operations.cpp
                    src/filesystem/v2/path.cpp)

add_executable(test_filesystem 
                    $<TARGET_OBJECTS:ObjLib> 
                    unit_tests/test_main.cpp
                    unit_tests/directory_entry_test.cpp 
                    unit_tests/file_status_test.cpp)

target_link_libraries(test_filesystem ${Boost_LIBRARIES})

add_custom_command(TARGET test_filesystem POST_BUILD COMMAND test_filesystem)