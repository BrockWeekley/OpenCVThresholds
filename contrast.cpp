#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv )
{
    if ( argc != 4 )
    {
        printf("usage: ./contrast <Min_Value> <Max_Value> <Image_Path> \n");
        return -1;
    }
    cv::Mat image = cv::imread( argv[3], cv::IMREAD_GRAYSCALE );
    int rows, cols;
    rows = image.size[0];
    cols = image.size[1];
    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    float slope = max - min;
    
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int newPixel = (image.at<uint8_t>(row, col) - min) * 255 / slope;
            if (newPixel > max) {
                image.at<uint8_t>(row, col) = max;
                continue;
            }
            if (newPixel < min) {
                image.at<uint8_t>(row, col) = min;
                continue;
            }
            image.at<uint8_t>(row, col) = newPixel;
        }
    }
    cv::imshow("Display Image", image);
    cv::waitKey(0);
    return 0;
}
