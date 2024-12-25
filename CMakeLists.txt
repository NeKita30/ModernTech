cmake_minimum_required(VERSION 3.16)
project(ModernTech)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_subdirectory(ImageProcessing)

add_executable(app main.cpp)
target_link_libraries(app PRIVATE imgProc)

add_subdirectory(test)

file(COPY test_data DESTINATION ${CMAKE_BINARY_DIR})