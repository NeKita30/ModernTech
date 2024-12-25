add_executable(testIP imgProcTest.cpp)
target_link_libraries(testIP imgProc gtest gtest_main ${OpenCV_LIBS})
#gtest_add_tests(TARGET testIP)
target_include_directories(testIP PUBLIC ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR} ${PROJECT_SOURCE_DIR} ${OpenCV_INCLUDE_DIRS})