#include "ImageProcessing/imgProc.cpp"
#include <iostream>

void app() {
    std::string file;
    std::cin >> file;
    ImgProc ip(file);
    for (;;) {
        int k = ip.display("aaaa");
        if (k == 's') {
            std::string output_file;
            std::cin >> output_file;
            ip.save(output_file);
        }

        if (k == 'c' || k == 's') {
            break;
        }

        ip = ImgProc(ip, k);
    }
}