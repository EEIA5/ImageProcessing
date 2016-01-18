#ifndef CUBEANALYZER_H_INCLUDED
#define CUBEANALYZER_H_INCLUDED

#include "Colors.h"
#include "Cube.h"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

class CubeAnalyzer
{
public:
    CubeAnalyzer();
    void analyze(Mat cubeMat);
    Cube getCube();
private:
    char lockChar, unlockChar;
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
    bool colorInBounds(Vec3b color, unsigned short min, unsigned short max);
    bool isWhite(Vec3b color);
    void drawCircles(Mat& mat, Point point, Color color);
    bool isPressed (char c);
};
#endif // CUBEANALYZER_H_INCLUDED
