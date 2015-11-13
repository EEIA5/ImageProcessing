#include "CubeAnalyzer.h"
<<<<<<< HEAD
#include <iostream>

using namespace std;

CubeAnalyzer::CubeAnalyzer(){
    whiteLv = 50;
    blackLv = 70;
    radius = 4;
}

CubeAnalyzer::~CubeAnalyzer(){

=======
#include "Constants.h"
#include "ColorsRange.h"
#include "Colors.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

CubeAnalyzer::CubeAnalyzer(){
    radius = 10;
    windowName = "Cube";
    namedWindow(windowName, WINDOW_AUTOSIZE);
>>>>>>> origin/SideDetect
}

void CubeAnalyzer::analyze(Mat cubeMat){
    this->cubeMat = cubeMat;
    Size imageSize = cubeMat.size();
    int w = imageSize.width;
    Color sideColor;
<<<<<<< HEAD
    if (w != 0){
        int step = w / 3;
        int start = w * 0.17;
        int x, y;
        for (unsigned short horizontal = 0; horizontal < 3; horizontal++){
            for (unsigned short vertical = 0; vertical < 3; vertical++){
                x = start + step * horizontal;
                y = start + step * vertical;
                circle(cubeMat, Point(x, y), radius, Scalar(0, 0, 0));
                sideColor = detectSide();
                if (sideColor != UNDEF){
                    cube.setCellColor(sideColor, horizontal + vertical * 3, reconizeColor(x, y));
                }
            }
        }
        imshow(windowRubicCube, cubeMat);
=======
    Mat display;
    cubeMat.copyTo(display);
    if (w != 0){
        int step = w / numberOfCellsInRow;
        int start = w * drawingPercentShift;
        int x, y, cellNumber;
        for (size_t horizontal = 0; horizontal < numberOfCellsInRow; horizontal++){
            for (size_t vertical = 0; vertical < numberOfCellsInRow; vertical++){
                x = start + step * horizontal;
                y = start + step * vertical;
                Color color = reconizeColor(x, y);
                drawCircles(display, Point(x,y), radius, color);
                sideColor = detectSide();
                if (sideColor != UNDEF){
                    cellNumber = horizontal + vertical * numberOfCellsInRow;
                    cube.setCell(sideColor, cellNumber, color);
                }
            }
        }
        imshow(windowName, display);
>>>>>>> origin/SideDetect
    }
}

Color CubeAnalyzer::detectSide(){
    Size cubeSize = cubeMat.size();
    return reconizeColor(cubeSize.width / 2, cubeSize.height / 2);
}

<<<<<<< HEAD
Color CubeAnalyzer::reconizeColor(int x ,int y){
=======
Color CubeAnalyzer::reconizeColor(unsigned x ,unsigned y){
>>>>>>> origin/SideDetect
    vector<Vec3b> colors;
    Size cubeSize = cubeMat.size();
    Color color = UNDEF;
    if (isInMatrixBounds(x, y, cubeSize.width, cubeSize.height)){
        colors.push_back(getRawColor(x, y));
        colors.push_back(getRawColor(x + radius, y));
        colors.push_back(getRawColor(x - radius, y));
        colors.push_back(getRawColor(x, y + radius));
        colors.push_back(getRawColor(x, y - radius));
        Vec3b avgColor = avgColors(colors);
        color = classifyColor(avgColor);
    }
    return color;
}

<<<<<<< HEAD
bool CubeAnalyzer::isInMatrixBounds(int x, int y, int width, int height){
    return (x >= radius && y >= radius && x + radius < width && y + radius < height) ;
}

Vec3b CubeAnalyzer::getRawColor(int x, int y){
=======
bool CubeAnalyzer::isInMatrixBounds(unsigned x, unsigned y, unsigned width, unsigned height){
    return (x >= radius && y >= radius && x + radius < width && y + radius < height) ;
}

Vec3b CubeAnalyzer::getRawColor(unsigned x, unsigned y){
>>>>>>> origin/SideDetect
    Mat HSV;
    Mat BGR = cubeMat(Rect(x, y, 1, 1));
    cvtColor(BGR, HSV, CV_BGR2HSV);
    return HSV.at<Vec3b>(0, 0);
}

Vec3b CubeAnalyzer::avgColors(vector<Vec3b> colors){
    int sumH = 0, sumS = 0, sumV = 0;
<<<<<<< HEAD
    for ( unsigned i = 0; i<colors.size(); i++ ){
        sumH += int( colors[i][0] );
        sumS += int( colors[i][1] );
        sumV += int( colors[i][2] );
=======
    for (size_t i = 0; i < colors.size(); i++){
        sumH += colors[i][0];
        sumS += colors[i][1];
        sumV += colors[i][2];
>>>>>>> origin/SideDetect
    }
    Vec3b color;
    color[0] = sumH / colors.size();
    color[1] = sumS / colors.size();
    color[2] = sumV / colors.size();
    return color;
}

Color CubeAnalyzer::classifyColor(Vec3b color){
<<<<<<< HEAD

    if (color[0] < 179 && color[0] >= 160 && color[1] > whiteLv && color[2] > blackLv){
        return RED;
    } else if (color[0] >= 0 && color[0] < 22 && color[1] > whiteLv && color[2] > blackLv){
        return ORANGE;
    } else if (color[0] >= 22 && color[0] < 38 && color[1] > whiteLv && color[2] > blackLv){
        return YELLOW;
    } else if (color[0] >= 38 && color[0] < 95 && color[1] > whiteLv && color[2] > blackLv){
        return GREEN;
    } else if (color[0] >= 95 && color[0] < 120 && color[1] > whiteLv && color[2] > blackLv){
        return BLUE;
    } else if (color[1] < whiteLv && color[2] > blackLv){
        return WHITE;
    }else {
=======
    if(color[0] >= RED_MIN && color[0] <= RED_MAX && color[1] > WHITE_LV && color[2] > BLACK_LV){
        return RED;
    }else if(color[0] >= ORANGE_MIN && color[0] <= ORANGE_MAX && color[1] > WHITE_LV && color[2] > BLACK_LV){
        return ORANGE;
    }else if(color[0] >= YELLOW_MIN && color[0] <= YELLOW_MAX && color[1] > WHITE_LV && color[2] > BLACK_LV){
        return YELLOW;
    }else if(color[0] >= GREEN_MIN && color[0] <= GREEN_MAX && color[1] > WHITE_LV && color[2] > BLACK_LV) {
        return GREEN;
    }else if(color[0] >= BLUE_MIN && color[0] <= BLUE_MAX && color[1] > WHITE_LV && color[2] > BLACK_LV){
        return BLUE;
    }else if(color[1] < WHITE_LV && color[2] > BLACK_LV){
        return WHITE;
    }else{
>>>>>>> origin/SideDetect
        return UNDEF;
    }
}

<<<<<<< HEAD
=======
void CubeAnalyzer::drawCircles(Mat& mat, Point point, int radius, Color color){
    switch (color){
    case RED:
        circle(mat, point, radius, RED_SCALAR, - 1);
        break;
    case YELLOW:
        circle(mat, point, radius, YELLOW_SCALAR, - 1);
        break;
    case GREEN:
        circle(mat, point, radius, GREEN_SCALAR, - 1);
        break;
    case BLUE:
        circle(mat, point, radius, BLUE_SCALAR, - 1);
        break;
    case ORANGE:
        circle(mat, point, radius, ORANGE_SCALAR, - 1);
        break;
    case WHITE:
        circle(mat, point, radius, WHITE_SCALAR, - 1);
        break;
    default:
        circle(mat, point, radius, UNDEF_SCALAR, - 1);
        break;
    }
}

>>>>>>> origin/SideDetect
Cube CubeAnalyzer::getCube(){
    return cube;
}
