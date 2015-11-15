#include "CubeDetector.h"
#include "Constants.h"
#include <stdexcept>

#include "opencv2/imgproc/imgproc.hpp"

using namespace std;

CubeDetector::CubeDetector(){
    tresholdCannyOne = 30;
    tresholdCannyTwo = 30;
    minArea = 2000;
    minSquareSide = 170;
    squareTolerance = 15;
    windowName = "Camera";
    namedWindow(windowName, WINDOW_AUTOSIZE);
    videoCapture = new VideoCapture(0);
    if (!videoCapture->isOpened()){
        throw runtime_error("Failed to open a video device!\nInitialization failed!");
}
}

CubeDetector::~CubeDetector() {
    delete videoCapture;
}

bool CubeDetector::isWorking(){
	auto key = static_cast<char>(waitKey(5));
        if (key == 'q'){
            return false;
        }
    return true;
}

void CubeDetector::findContures() {
    squares.clear();
    vector<vector<Point>> contours;
    vector<Point> approxs;
    Mat imageGray;

    (*videoCapture) >> frame;
    if (frame.empty()){
        throw runtime_error("Empty frame!");
    }
    imshow(windowName, frame);

    Canny(frame, imageGray, tresholdCannyOne, tresholdCannyTwo);
    findContours(imageGray, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

    int area;
    for(unsigned contoure = 0; contoure < contours.size(); contoure++){
        approxPolyDP(Mat(contours[contoure]), approxs, arcLength(Mat(contours[contoure]), true) * 0.02, true);
        area = contourArea(Mat(approxs));

        if(approxs.size() == 4 && area > minArea){
            squares.push_back(approxs);
        }
    }
}

Mat CubeDetector::getCube() {
	auto imageSize = frame.size();
    unsigned minY = imageSize.height, minX = imageSize.width;
    unsigned maxY = 0, maxX = 0;
    unsigned n, x, y;
    for(unsigned i = 0; i < squares.size(); i++){
        n = squares[i].size();
        for(unsigned square = 0; square < n; square++){
            x = squares[i][square].x;
            y = squares[i][square].y;
            if (x > maxX)
                maxX = x;
            else if (x < minX)
                minX = x;
            if (y > maxY)
                maxY = y;
            else if (y < minY)
                minY = y;
        }
    }
    if (isSquare(maxX, minX, maxY, minY, squareTolerance) && isSizeOk(maxX, minX, minSquareSide)){
        cubeMat.release();
        cubeMat = frame(Rect(minX, minY, abs(maxX - minX), abs(maxY - minY))).clone();
    }
    return cubeMat;
}

bool CubeDetector::isSquare(int x1, int x2, int y1, int y2, int tolerance){
    return (abs(abs(x1 - x2) - abs(y1 - y2)) < tolerance);
}

bool CubeDetector::isSizeOk(int x1, int x2, int size){
    return (abs(x1 - x2) > size);
}

