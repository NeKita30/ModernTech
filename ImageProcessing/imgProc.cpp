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

    ImgProc(const ImgProc& oth, int r) {
        if (r == 'g') {
            cv::cvtColor(oth.img, img, cv::COLOR_BGR2GRAY);
        } else {
            img = oth.img;
        }
    }

    int display(const std::string& window_name) {
        cv::imshow(window_name, img);
        return cv::waitKey(0);
    }

    void save(std::string& path) {
        cv::imwrite(path, img);
    }

private:
    cv::Mat img;
};