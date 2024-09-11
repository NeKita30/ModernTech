cmake_minimum_required(VERSION 3.20)
project(ModernTech)

add_executable(app main.cpp)

add_subdirectory(ImageProcessing)
target_link_libraries(app PRIVATE imgProc)

file(COPY test_data DESTINATION ${CMAKE_BINARY_DIR})