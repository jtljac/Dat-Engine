cmake_minimum_required(VERSION 3.22)

project(lib-dat-asset-processor
        VERSION 1.0.0
        DESCRIPTION "Library for handling asset processing"
        LANGUAGES CXX
)



add_library(lib-dat-asset-processor STATIC source/main.cpp)
target_link_libraries(lib-dat-asset-processor PRIVATE lib-dat-asset-io)

find_package(glslang CONFIG REQUIRED)
target_link_libraries(lib-dat-asset-processor PRIVATE glslang::glslang glslang::glslang-default-resource-limits glslang::SPIRV glslang::SPVRemapper)

find_package(assimp CONFIG REQUIRED)
target_link_libraries(lib-dat-asset-processor PRIVATE assimp::assimp)

target_include_directories(lib-dat-asset-processor PUBLIC include)

target_sources(lib-dat-asset-processor PRIVATE
        include/base-asset-processor.h
        include/copy-processor.h source/copy-processor.cpp
        include/shader-processor.h source/shader-processor.cpp
)
