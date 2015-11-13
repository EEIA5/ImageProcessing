#ifndef CUBEANALYZER_H_INCLUDED
#define CUBEANALYZER_H_INCLUDED

<<<<<<< HEAD
#include "OpenCV.h"
#include "Colors.h"
#include "Cube.h"
=======
#include "Colors.h"
#include "Cube.h"
#include "opencv2/core/core.hpp"
>>>>>>> origin/SideDetect

using namespace cv;

class CubeAnalyzer
{
public:
    CubeAnalyzer();
<<<<<<< HEAD
    ~CubeAnalyzer();
    void analyze(Mat cubeMat);
    Cube getCube();
private:
    short whiteLv;
    short blackLv;
    short radius;
    Mat cubeMat;
    Cube cube;
    bool isInMatrixBounds(int x, int y, int width, int height);
    Vec3b getRawColor(int x, int y);
    Vec3b avgColors(vector<Vec3b> colors);
    Color detectSide();
    Color reconizeColor(int x, int y);
    Color classifyColor(Vec3b color);
=======
    void analyze(Mat cubeMat);
    Cube getCube();
private:
    string windowName;
    short radius;
    Mat cubeMat;
    Cube cube;
    bool isInMatrixBounds(unsigned x, unsigned y, unsigned width, unsigned height);
    Vec3b getRawColor(unsigned x, unsigned y);
    Vec3b avgColors(vector<Vec3b> colors);
    Color detectSide();
    Color reconizeColor(unsigned x, unsigned y);
    Color classifyColor(Vec3b color);
    void drawCircles(Mat& mat, Point point, int radius, Color color);
>>>>>>> origin/SideDetect
};
#endif // CUBEANALYZER_H_INCLUDED
