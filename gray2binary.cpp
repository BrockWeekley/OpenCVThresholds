#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv )
{
    if ( argc != 5 )
    {
        printf("usage: ./rgb2gray <Image_Path> <Output_Image_Path> <Threshold_Value> <Input_Ground_Truth_Image> \n");
        return -1;
    }
    cv::Mat image = cv::imread( argv[1], cv::IMREAD_GRAYSCALE);
    int rows, cols;
    rows = image.size[0];
    cols = image.size[1];
    
    cv::Mat comparison = cv::imread( argv[4], 1 );

    int thresh = atoi(argv[3]);
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (image.at<uchar>(row, col) < thresh) {
                image.at<uchar>(row, col) = 0;
            } else {
                image.at<uchar>(row, col) = 255;
            }
        }
    }
    cv::imshow("Display Image", image);
    cv::waitKey(0);
    return 0;
}
