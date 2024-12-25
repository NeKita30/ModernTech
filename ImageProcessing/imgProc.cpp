#include "opencv2/imgproc.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <stdexcept>

class ImgProc {
public:
    explicit ImgProc(const std::string& path) : img(cv::imread(path, cv::IMREAD_COLOR)) {
        if (img.empty()) {
            throw std::runtime_error("Couldn't open given file: " + path);
        }
    }

    ImgProc BGR2Gray() {
        if (img.channels() != 3) {
            return *this;
        }
        return ImgProc(ApplyConversion(cv::COLOR_BGR2GRAY));
    }

    ImgProc Gray2BGR() {
        if (img.channels() != 1) {
            return *this;
        }
        return ImgProc(ApplyConversion(cv::COLOR_GRAY2BGR));
    }

    ImgProc BGR2HSV() {
        if (img.channels() != 3) {
            return *this;
        }
        return ImgProc(ApplyConversion(cv::COLOR_BGR2HLS));
    }

    ImgProc RotateRight() {
        return ImgProc(RotateByCode(cv::ROTATE_90_CLOCKWISE));
    }

    void Display(const std::string& window_name) {
        cv::imshow(window_name, img);
        cv::waitKey();
        cv::destroyWindow(window_name);
    }

    void Save(std::string& path) {
        cv::imwrite(path, img);
    }

    void Save(std::string&& path) {
        cv::imwrite(path, img);
    }

private:
    cv::Mat img;

    explicit ImgProc(cv::Mat&& img): img(img) {}

    cv::Mat ApplyConversion(cv::ColorConversionCodes code) {
        cv::Mat other;
        cv::cvtColor(img, other, code);
        return other;
    }

    cv::Mat RotateByCode(cv::RotateFlags code) {
        cv::Mat other;
        cv::rotate(img, other, code);
        return other;
    }
};