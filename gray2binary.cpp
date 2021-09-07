#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv )
{
    if ( argc != 5 )
    {
        printf("usage: ./rgb2gray <Image_Path> <Output_Image_Path> <Threshold_Value> <Input_Ground_Truth_Image> \n");
        return -1;
    }
    cv::Mat image = cv::imread( argv[1], 1 );
    cv::Mat comparison = cv::imread( argv[4], 1 );
    cv::Mat binaryImage;
    int thresh = atoi(argv[3]);
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    cv::threshold( image, binaryImage, thresh, 255, cv::THRESH_BINARY );
    cv::imshow("Display Image", binaryImage);
    cv::waitKey(0);
    return 0;
}
