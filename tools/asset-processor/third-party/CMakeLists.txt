cmake_minimum_required(VERSION 3.22)

find_package(Cargs CONFIG REQUIRED)
target_link_libraries(dat-asset-processor PRIVATE cargs)