#include <gtest/gtest.h>
#include "ImageProcessing/imgProc.cpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

TEST(ColorTest, GrayTest) {
    ImgProc ip("../test_data/cmake.png");
    ip = ip.BGR2Gray();
    ip.Save("test_result.png");

    cv::Mat result = cv::imread("test_result.png", cv::IMREAD_COLOR);
    cv::Mat right = cv::imread("../test_data/cmake_gray.png");
    cv::Mat diff;

    cv::compare(result, right, diff, cv::CMP_NE);
    ASSERT_EQ(cv::countNonZero(diff.reshape(1)), 0);
}

class RotateParamTest: public testing::TestWithParam<int> {};

TEST_P(RotateParamTest, RightTest) {
    ImgProc ip("../test_data/cmake.png");
    for (int i = 0; i < GetParam(); ++i) {
        ip = ip.RotateRight();
    }
    ip.Save("test_result.png");

    cv::Mat result = cv::imread("test_result.png", cv::IMREAD_COLOR);
    cv::Mat right = cv::imread("../test_data/cmake_" +
                               std::to_string(GetParam()) + ".png");
    cv::Mat diff;

    cv::compare(result, right, diff, cv::CMP_NE);
    ASSERT_EQ(cv::countNonZero(diff.reshape(1)), 0);
}

INSTANTIATE_TEST_SUITE_P(RotateTests, RotateParamTest, testing::Values(1, 2, 3)) ;

int main (int argc, char ** argv ) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}