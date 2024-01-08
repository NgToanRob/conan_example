#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now(); // Bắt đầu đo thời gian
    // Đường dẫn tới ảnh
    std::string imagePath = "../Do_yeu.jpg";

    // Đọc ảnh từ đường dẫn
    cv::Mat img = cv::imread(imagePath);

    // Chuyển đổi ảnh sang không gian màu YUV
    cv::Mat img_yuv;
    cv::cvtColor(img, img_yuv, cv::COLOR_BGR2YUV);

    // Tạo một bản sao của ảnh YUV để cân bằng histogram
    cv::Mat img_yuv_equalized = img_yuv.clone();

    // Áp dụng cân bằng histogram cho kênh Y (độ sáng)
    std::vector<cv::Mat> channels;
    cv::split(img_yuv_equalized, channels);
    

    cv::equalizeHist(channels[0], channels[0]);

    auto end = std::chrono::high_resolution_clock::now(); // Kết thúc đo thời gian
    std::chrono::duration<double> elapsed = end - start; // Thời gian đã trôi qua

    cv::merge(channels, img_yuv_equalized);

    // Chuyển đổi ảnh YUV sau khi cân bằng histogram về RGB
    cv::Mat equalized_img;
    cv::cvtColor(img_yuv_equalized, equalized_img, cv::COLOR_YUV2BGR);

    // Hiển thị ảnh gốc và ảnh sau khi cân bằng histogram
    cv::imshow("Original Image", img);
    cv::imshow("Equalized Image", equalized_img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // In ra thời gian xử lý
    std::cout << "Thời gian xử lý: " << elapsed.count() << " giây" << std::endl;

    return 0;
}
