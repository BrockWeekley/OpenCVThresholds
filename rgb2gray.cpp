#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv )
{
    if ( argc != 3 )
    {
        printf("usage: ./rgb2gray <Image_Path> <Output_Image_Path> \n");
        return -1;
    }
    cv::Mat image = cv::imread( argv[1], 1 );
    cv::Mat grayImage;
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    cv::imwrite(argv[2], grayImage);
    cv::imshow("Display Image", grayImage);
    cv::waitKey(0);
    return 0;
}
