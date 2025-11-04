cmake_minimum_required(VERSION 3.15)
project(KeepWindowsAwake CXX)

# ============================================
# Compiler configuration
# ============================================
# use clang++
set(CMAKE_CXX_COMPILER clang++ CACHE STRING "C++ compiler" FORCE)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Default type is Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# ============================================
# Build Options
# ============================================
# Debug/Release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

add_executable(${PROJECT_NAME} WIN32 main.cpp)

# ============================================
# Windows API Libraries
# ============================================
target_link_libraries(${PROJECT_NAME} PRIVATE user32)
