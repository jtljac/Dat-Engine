cmake_minimum_required(VERSION 3.22)
add_subdirectory(dat-archive)
target_link_libraries(dat-engine dat-archive)

add_subdirectory(dat-vfs)
target_link_libraries(dat-engine dat-vfs)

add_subdirectory(asset-io)
target_link_libraries(dat-engine lib-dat-asset-info)
add_subdirectory(asset-processing)