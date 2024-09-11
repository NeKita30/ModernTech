find_package(OpenCV REQUIRED)

file(GLOB IMG_PROC_SRC *.cpp)

add_library(imgProc STATIC ${IMG_PROC_SRC})
target_include_directories(imgProc PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(imgProc ${OpenCV_LIBS})
