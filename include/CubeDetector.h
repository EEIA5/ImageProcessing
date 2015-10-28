#ifndef CUBEDETECTOR_H
#define CUBEDETECTOR_H

#include <string>
#include <vector>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

const int WHITE = 0;
const int YELLOW = 1;
const int GREEN = 2;
const int RED = 3;
const int ORANGE = 4;
const int BLUE = 5;
const int UNDEF = 6;

using namespace std;
using namespace cv;

class CubeDetector
{
    public:
        int tresholdCannyOne;
        int tresholdCannyTwo;
        string windowCamera;
        string windowCanny;
        string windowRubicCube;
        bool init();
        void getFrame();
        void findCube();
        void updateCubeWindow();
        bool isWorking();
        int detectSide();
        void getColors(int*side);
        CubeDetector();
        virtual ~CubeDetector();
        void print(int * colors);
    private:
        int getColor(int x, int y);
        vector<vector<Point > > squares;
        Mat frame;
        Mat cube;
        VideoCapture* videoCapture;
};

#endif
