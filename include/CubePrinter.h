#ifndef CUBEPRINTER_H_INCLUDED
#define CUBEPRINTER_H_INCLUDED

#include "Cube.h"
#include "Colors.h"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

class CubePrinter
{
public:
    CubePrinter();
    ~CubePrinter();
    void print(Cube cube);
    void setCube(Cube cube);
    Cube getCube();

private:
    unsigned startX, startY;
    Mat* view;
    Cube cube;
    string windowName;
    unsigned short squareSize;
    unsigned short spaceBetweenSquares;
    void drawWall(unsigned x, unsigned y, unsigned w);
    void drawSquare(unsigned x, unsigned y, Color color);
    Scalar getColorScalar(Color color);
    void drawWallNames();
    double fontScale;
    short wallNamePosFix;
    Scalar textColor;
};



#endif
