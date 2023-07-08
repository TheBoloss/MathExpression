cmake_minimum_required(VERSION 3.1)
project(MathExpression)
set(CMAKE_SYSTEM_NAME WindowsStore)
set(CMAKE_SYSTEM_VERSION 10.0)
set(CMAKE_CXX_STANDARD 20)
set(SOURCES src/main.cpp
src/Token.cpp
src/Error.cpp
src/Lexer.cpp)
set(EXECUTABLE math)
add_executable(${EXECUTABLE} ${SOURCES})
include_directories(include)

# Strict compiling
# if(MSVC)
#   target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
# else()
#   target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -Wpedantic -Werror)
# endif()