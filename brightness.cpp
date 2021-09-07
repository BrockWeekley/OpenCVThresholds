#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv )
{
    if ( argc != 3 )
    {
        printf("usage: ./brightness <Intensity> <Image_Path> \n");
        return -1;
    }
    cv::Mat image = cv::imread( argv[2], cv::IMREAD_GRAYSCALE );
    int rows, cols;
    rows = image.size[0];
    cols = image.size[1];
    int intensity = atoi(argv[1]);
    
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (image.at<uint8_t>(row, col) + intensity > 255) {
                image.at<uint8_t>(row, col) = 255;
                continue;
            }
            if (image.at<uint8_t>(row, col) + intensity < 0) {
                image.at<uint8_t>(row, col) = 0;
                continue;
            }
            
            image.at<uint8_t>(row, col) += intensity;
        }
    }
    cv::imshow("Display Image", image);
    cv::waitKey(0);
    return 0;
}
