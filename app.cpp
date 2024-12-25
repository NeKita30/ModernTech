#include "ImageProcessing/imgProc.cpp"
#include <iostream>

void UpdateWindowName(std::string& name) {
    if (name[0] != '*') {
        name = "*" + name;
    }
}

void App() {
    std::string file;
    std::cin >> file;
    ImgProc ip(file);

    std::string window_name = file;
    ip.Display(window_name);
    std::string output_file;

    char command;
    for (;;) {
        std::cin >> command;

        switch (command) {
            case 'd':
                ip.Display(window_name);
                continue;
            case 's':
                std::cin >> output_file;
                ip.Save(output_file);
                window_name = output_file;
                continue;
            case 'g':
                ip = ip.BGR2Gray();
                break;
            case 'b':
                ip = ip.Gray2BGR();
                break;
            case 'h':
                ip = ip.BGR2HSV();
            case 'r':
                ip = ip.RotateRight();
            default:
                break;
        }

        if (command == 'c') {
            break;
        }

        UpdateWindowName(window_name);
    }
}