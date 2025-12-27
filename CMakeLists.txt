
cmake_minimum_required(VERSION 3.13)

project(qglm
    VERSION 0.1.0
    LANGUAGES C
    DESCRIPTION "Fixed-point math library for embedded graphics"
)

add_library(qglm INTERFACE)

target_include_directories(qglm INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_compile_features(qglm INTERFACE c_std_11)

