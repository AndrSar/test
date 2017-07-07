#          Copyright Andrey Lifanov 2017.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.2)

project(test CXX)

message (STATUS "C++ compiler is ${CMAKE_CXX_COMPILER}")

if (NOT MSVC)
add_compile_options(-std=c++14)
endif ()

add_library(utest
    src/include/test.hpp
    src/test.cpp
)

if (WITH_EXAMPLES)
    add_executable(example_simple_test src/examples/simple_test.cpp)
    target_link_libraries(example_simple_test PRIVATE utest)
endif()