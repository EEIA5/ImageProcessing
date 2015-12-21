#include "CubePrinter.h"
#include "ColorsRange.h"
#include "Constants.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

CubePrinter::CubePrinter(string wndName){
    windowName = wndName;
    squareSize = 40;
    spaceBetweenSquares = 5;
    namedWindow(windowName, WINDOW_AUTOSIZE);
    view = new Mat(500,660, CV_8UC3, Scalar(30,30,30));
    startX = 10;
    startY = 30;
    fontScale = 0.7;
    wallNamePosFix = 8;
    textColor = Scalar(255, 255, 255);
    drawWallNames();
}

CubePrinter::~CubePrinter(){
    delete view;
}

void CubePrinter::drawWallNames(){
    unsigned d = (numberOfCellsInRow + 1) * squareSize + spaceBetweenSquares;
    putText(*view, "Orange", Point(startX ,startY + d - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale,textColor);
    putText(*view, "White", Point(startX + d, startY - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale, textColor);
    putText(*view, "Green", Point(startX + d, startY + d - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale, textColor);
    putText(*view, "Red", Point(startX + 2 * d, startY + d - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale, textColor);
    putText(*view, "Blue", Point(startX + 3 * d, startY + d - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale, textColor);
    putText(*view, "Yellow", Point(startX + d, startY + 2 * d - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale, textColor);
}

void CubePrinter::print(Cube* cube){
    this->cube = cube;
    unsigned d = (numberOfCellsInRow + 1) * squareSize + spaceBetweenSquares;
    drawWall(startX, startY + d, ORANGE);
    drawWall(startX + d , startY, WHITE);
    drawWall(startX + d , startY + 2* d, YELLOW);
    drawWall(startX + d, startY + d, GREEN);
    drawWall(startX + 2 * d, startY + d, RED);
    drawWall(startX + 3 * d, startY + d, BLUE);
    imshow(windowName, *view);
}

void CubePrinter::drawWall(unsigned x, unsigned y, unsigned w){
    Color color;
    unsigned tmpX = x, tmpY = y;
    for (unsigned short cell = 0; cell < numberOfCells; cell++){
        color = cube->getWall(w).getColor(cell);
        if (cell % numberOfCellsInRow == 0 && cell != 0){
            tmpX = x;
            tmpY += squareSize + spaceBetweenSquares;
        }
        drawSquare(tmpX, tmpY , color);
        if (cube->getWall(w).isLocked() && cell == 4){
            Point leftUpper = Point(tmpX + squareSize / 4, tmpY + squareSize / 4);
            Point rightLower = Point(tmpX + squareSize -  squareSize / 4, tmpY + squareSize  -  squareSize / 4);
            rectangle(*view, leftUpper, rightLower, Scalar(0, 0, 0), -1);
        }
        tmpX +=  squareSize + spaceBetweenSquares ;
    }
}

void CubePrinter::drawSquare(unsigned x, unsigned y, Color color){
    rectangle(*view, Point(x, y),Point(x + squareSize, y + squareSize), getColorScalar(color), -1);
}

Scalar CubePrinter::getColorScalar(Color color){
    switch (color){
    case WHITE:
        return WHITE_SCALAR;
        break;
    case YELLOW:
        return YELLOW_SCALAR;
        break;
    case RED:
        return RED_SCALAR;
        break;
    case BLUE:
        return BLUE_SCALAR;
        break;
    case GREEN:
        return GREEN_SCALAR;
        break;
    case ORANGE:
        return ORANGE_SCALAR;
        break;
    default:
        return UNDEF_SCALAR;
        break;
    }
}

void CubePrinter::setCube(Cube* cube){
    this->cube = cube;
}

Cube* CubePrinter::getCube(){
    return cube;
}
