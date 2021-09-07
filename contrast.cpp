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
    int rows, cols;
    rows = image.rows;
    cols = image.cols;
    
    cv::Mat grayImage;
    grayImage.create(image.size(), CV_8UC1);
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    
    for (int row = 0; row < rows; row++) {
        const uchar* source = image.ptr<uchar>(row);
        uchar* destination = grayImage.ptr<uchar>(row);
        
        for (int col = 0; col < cols; col++) {
            // Blue Green Red
            // 0.2989 * Red[x][y] + 0.5871 * Green[x][y] + 0.1140 * Blue[x][y]
            
            destination[col] = (uchar)(source[2] * 0.2989 + source[1] * 0.5871 + source[0] * 0.1140);
            source += 3;
        }
    }
    cv::imwrite(argv[2], grayImage);
    cv::imshow("Display Image", grayImage);
    cv::waitKey(0);
    return 0;
}
