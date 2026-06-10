cmake_minimum_required(VERSION 3.20)

project(mathlib)

add_library(mathlib INTERFACE)

target_include_directories(
    mathlib
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)