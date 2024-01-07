#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    std::string imagePath = "Do_yeu.jpg";

    cv::Mat originalImage = cv::imread(imagePath);
    if (originalImage.empty()) {
        std::cout << "Error: Unable to load image!" << std::endl;
        return 1;
    }

    cv::Mat grayImage;
    cv::cvtColor(originalImage, grayImage, cv::COLOR_BGR2GRAY);

    cv::Mat balancedImage;
    cv::equalizeHist(grayImage, balancedImage);

    cv::Mat comparisonImage;
    cv::hconcat(grayImage, balancedImage, comparisonImage);

    cv::imshow("Comparison", comparisonImage);
    cv::waitKey(0);

    return 0;
}
