#ifndef CUBEANALYZER_H_INCLUDED
#define CUBEANALYZER_H_INCLUDED

#include "OpenCV.h"
#include "Colors.h"
#include "Cube.h"

using namespace cv;

class CubeAnalyzer
{
public:
    CubeAnalyzer();
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
};
#endif // CUBEANALYZER_H_INCLUDED
