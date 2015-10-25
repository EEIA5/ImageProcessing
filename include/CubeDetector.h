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
        CubeDetector();
        virtual ~CubeDetector();
        bool init();
        void getFrame();
        void findCube();
        void drawCube();
        bool isWorking();

        void updateColors(int site);
        int detectSide();
    private:
        int getColor(int x, int y);
        vector<vector<Point > > squares;
        Mat frame;
        Mat cube;
        VideoCapture* videoCapture;
};

#endif
