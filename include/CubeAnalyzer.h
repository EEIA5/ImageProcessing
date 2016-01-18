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
    Cube getCube() const;
private:
    char lockChar, unlockChar;
    string windowName;
    short radius;
    Mat cubeMat;
    Cube cube;
    bool isInMatrixBounds(unsigned x, unsigned y, unsigned width, unsigned height) const;
    Vec3b getRawColor(unsigned x, unsigned y) const;
	static Vec3b avgColors(vector<Vec3b> colors);
    Color detectSide() const;
    Color reconizeColor(unsigned x, unsigned y) const;
	static Color classifyColor(Vec3b color);
	static bool colorInBounds(Vec3b color, unsigned short min, unsigned short max);
	static bool isWhite(Vec3b color);
    void drawCircles(Mat& mat, Point point, Color color) const;
	static bool isPressed (char c);
};
#endif // CUBEANALYZER_H_INCLUDED
