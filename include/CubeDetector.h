#ifndef CUBEDETECTOR_H
#define CUBEDETECTOR_H

#include <string>
#include <vector>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

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
    private:
        vector<vector<Point > > squares;
        Mat frame;
        VideoCapture* videoCapture;
};

#endif // CUBEDETECTOR_H
