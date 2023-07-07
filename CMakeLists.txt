cmake_minimum_required(VERSION 3.1)
project(MathExpression)
set(CMAKE_CXX_STANDARD 20)
set(SOURCES src/main.cpp)
set(EXECUTABLE math)
add_executable(${EXECUTABLE} ${SOURCES})

# Strict compiling
# if(MSVC)
#   target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
# else()
#   target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -Wpedantic -Werror)
# endif()