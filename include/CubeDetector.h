#ifndef CUBEDETECTOR_H
#define CUBEDETECTOR_H

<<<<<<< HEAD
#include <string>
#include <vector>
#include <iostream>
#include "OpenCV.h"

using namespace std;
=======
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

>>>>>>> origin/SideDetect
using namespace cv;
class CubeDetector
{
public:
<<<<<<< HEAD
    void init();
=======
>>>>>>> origin/SideDetect
    void findContures();
    bool isWorking();
    Mat getCube();
    CubeDetector();
    ~CubeDetector();
private:
    int tresholdCannyOne;
    int tresholdCannyTwo;
    int minArea;
    int squareTolerance;
    int minSquareSide;
    vector<vector<Point>> squares;
    Mat frame;
    Mat cubeMat;
<<<<<<< HEAD
=======
    string windowName;
>>>>>>> origin/SideDetect
    VideoCapture* videoCapture;
    bool isSquare(int x1, int x2, int y1, int y2, int tolerance);
    bool isSizeOk(int x1, int x2, int size);
};

#endif
