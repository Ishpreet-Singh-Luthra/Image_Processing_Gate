#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"

using namespace cv;
using namespace std;
Mat imgHSV, mask, imgGray, imgBlur, imgCanny, imgDil, imgErode;
int hmin=0, smin=57, vmin=0;
int hmax=9, smax=255, vmax=101;
double left_length, right_length;

void getContours(Mat imgDil, Mat img)
{
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    int a,b;
    double l1, l2;
    
    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    int j=0;

    for (int i=0; i<contours.size(); i++)
    {
        int area= contourArea(contours[i]);
        //cout<< area<< endl;


        vector<vector<Point>> conPoly(contours.size());
        vector<Rect> boundRect(contours.size());
    
        //if (area>700)
        //{
            double peri= arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02*peri, false);
            drawContours(img,conPoly, i, Scalar (0, 255, 0), 2);
            boundRect[i] = boundingRect(conPoly[i]);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0,255,0), 5);
            //Point P= boundRect[i].x;
            //circle ( img, boundRect[i].tl(), 5.0, Scalar(0,0,255), 2, 8 );
            //cout<<peri/2<<endl;
            //cout<< boundRect[i].tl().x<<endl;
            if (j==0)
            {a=boundRect[i].tl().x;
            l1 = peri/2;}
            if (j==1)
            {b=boundRect[i].tl().x;
            l2 = peri/2;}
            j++;
    }
    if (a<b)
    {
        left_length=l1;
        right_length=l2;
    }
    else 
    {
        left_length=l1;
        right_length=l2;
    }
}

int main()
{
    string path = "/home/ishpreet/opencv_codes/Gate_Robosub/Gate.png";
    Mat img = imread (path);
    //cout<<"hello: "<<img.empty()<< endl;
    imshow("Original", img);

    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    Scalar lower (hmin, smin, vmin);
    Scalar upper (hmax, smax, vmax);
    inRange(imgHSV, lower, upper, mask);

    //imshow("Image", img);
    //imshow("Image HSV", imgHSV);
    imshow("Image Mask", mask);
    imwrite ("mask.png", mask);
    imwrite ("threshold.png", imgHSV);
    
    string path2 = "/home/ishpreet/opencv_codes/Gate_Robosub/mask.png";
    Mat img_mask = imread (path2);
    cvtColor(img_mask, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3,3), 3, 0);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel= getStructuringElement(MORPH_ELLIPSE, Size(6, 6));
    dilate(imgCanny, imgDil, kernel);
    Mat kernel2= getStructuringElement(MORPH_CROSS, Size(5, 5));
    erode(imgDil, imgErode, kernel2);


    //imshow("Image Mask", img_mask);
    //imshow("Image Gray", imgGray);
    //imshow("Image Blur", imgBlur);
    //imshow("Image Canny", imgCanny);
    //imshow("Image Dil", imgDil);
    //imshow("Image HSV", imgHSV);
    //imshow("Image Mask", mask);
    //imshow("Image Erosion", imgErode);

    getContours(imgDil, imgHSV);
    imshow("Image with Contours", imgHSV);
    imwrite("final.png", imgHSV);
    imwrite("erosion.png", imgErode);
    
    waitKey(0);
    return 0;
}