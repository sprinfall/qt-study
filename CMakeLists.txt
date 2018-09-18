cmake_minimum_required(VERSION 3.1.0)

if(POLICY CMP0074)
    # find_package() uses <PackageName>_ROOT variables.
    # This policy was introduced in CMake version 3.12.
    cmake_policy(SET CMP0074 NEW)
endif()

project(qt_study LANGUAGES CXX)

# Find includes in corresponding build directories.
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

add_definitions(-DUNICODE -D_UNICODE)

if(WIN32)
    # Disable warning on boost string algorithms.
    add_definitions(-D_SCL_SECURE_NO_WARNINGS)

    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# C++ standard requirements.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt5Widgets)
# find_package(Qt5Core)
# find_package(Qt5Gui)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
