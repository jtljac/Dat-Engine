cmake_minimum_required(VERSION 3.22)

project(dat-asset-processor
        VERSION 1.0.0
        DESCRIPTION "A program to translate assets into formats usable by the engine"
        LANGUAGES CXX
)

add_executable(dat-asset-processor main.cpp)

add_subdirectory(third-party)