#include "CubeAnalyzer.h"
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
    lockChar = '1';
    unlockChar = '2';
}

void CubeAnalyzer::analyze(Mat cubeMat){
    Mat display;
    Size imageSize = cubeMat.size();
    int w = imageSize.width;
    this->cubeMat = cubeMat;

    medianBlur(cubeMat, cubeMat, 5);
    cubeMat.copyTo(display);

    Color sideColor = detectSide();
    if (isPressed(lockChar)){
        cube.lockWall(sideColor);
    }else if (isPressed(unlockChar)){
        cube.unlockWall(sideColor);
    }

    if (w != 0 && sideColor != UNDEF){
        int step = w / numberOfCellsInRow;
        int start = w * drawingPercentShift;
        int x, y, cellNumber;
        for (size_t horizontal = 0; horizontal < numberOfCellsInRow; horizontal++){
            for (size_t vertical = 0; vertical < numberOfCellsInRow; vertical++){
                x = start + step * horizontal;
                y = start + step * vertical;
                Color color = reconizeColor(x, y);
                drawCircles(display, Point(x,y), color);
                if (!cube.isWallLocked(sideColor)){
                    cellNumber = horizontal + vertical * numberOfCellsInRow;
                    cube.setCell(sideColor, cellNumber, color);
                }
            }
        }
        imshow(windowName, display);
    }
}

Color CubeAnalyzer::detectSide() const {
    Size cubeSize = cubeMat.size();
    return reconizeColor(cubeSize.width / 2, cubeSize.height / 2);
}

Color CubeAnalyzer::reconizeColor(unsigned x ,unsigned y) const {
    vector<Vec3b> colors;
    Size cubeSize = cubeMat.size();
    Color color = UNDEF;
    if (isInMatrixBounds(x, y, cubeSize.width, cubeSize.height)){
        colors.push_back(getRawColor(x, y));
        colors.push_back(getRawColor(x + radius, y));
        colors.push_back(getRawColor(x - radius, y));
        colors.push_back(getRawColor(x, y + radius));
        colors.push_back(getRawColor(x, y - radius));
        colors.push_back(getRawColor(x + radius / 2, y));
        colors.push_back(getRawColor(x - radius / 2, y));
        colors.push_back(getRawColor(x, y + radius / 2));
        colors.push_back(getRawColor(x, y - radius / 2));
        colors.push_back(getRawColor(x + radius / 2, y + radius / 2));
        colors.push_back(getRawColor(x - radius / 2, y - radius / 2));
        colors.push_back(getRawColor(x - radius / 2, y + radius / 2));
        colors.push_back(getRawColor(x + radius / 2, y - radius / 2));
        Vec3b avgColor = avgColors(colors);
        color = classifyColor(avgColor);
    }
    return color;
}

bool CubeAnalyzer::isInMatrixBounds(unsigned x, unsigned y, unsigned width, unsigned height) const {
    return (x >= radius && y >= radius && x + radius < width && y + radius < height) ;
}

Vec3b CubeAnalyzer::getRawColor(unsigned x, unsigned y) const {
    Mat HSV;
    Mat BGR = cubeMat(Rect(x, y, 1, 1));
    cvtColor(BGR, HSV, CV_BGR2HSV);
    return HSV.at<Vec3b>(0, 0);
}

Vec3b CubeAnalyzer::avgColors(vector<Vec3b> colors){
    int sumH = 0, sumS = 0, sumV = 0;
    for (size_t i = 0; i < colors.size(); i++){
        sumH += colors[i][0];
        sumS += colors[i][1];
        sumV += colors[i][2];
    }
    Vec3b color;
    color[0] = sumH / colors.size();
    color[1] = sumS / colors.size();
    color[2] = sumV / colors.size();
    return color;
}

Color CubeAnalyzer::classifyColor(Vec3b color) {

	if(colorInBounds(color, RED_MIN, RED_MAX) || colorInBounds(color, RED_2_MIN, RED_2_MAX)){
        return RED;
    }
	if(colorInBounds(color, ORANGE_MIN, ORANGE_MAX)){
		return ORANGE;
	}
	if(colorInBounds(color, YELLOW_MIN, YELLOW_MAX)){
		return YELLOW;
	}
	if(colorInBounds(color, GREEN_MIN, GREEN_MAX)) {
		return GREEN;
	}
	if(colorInBounds(color, BLUE_MIN, BLUE_MAX)){
		return BLUE;
	}
	if(isWhite(color)){
		return WHITE;
	}
	return UNDEF;
}

bool CubeAnalyzer::colorInBounds(Vec3b color, unsigned short min, unsigned short max){
    unsigned short H,S,V;
    H = color[0];
    S = color[1];
    V = color[2];
    return (H >= min && H <= max && S > WHITE_LV && V > BLACK_LV);
}

bool CubeAnalyzer::isWhite(Vec3b color){
    unsigned short S,V;
    S = color[1];
    V = color[2];
    return S < WHITE_LV && V > BLACK_LV;
}


void CubeAnalyzer::drawCircles(Mat& mat, Point point, Color color) const {
    switch (color){
    case RED:
        circle(mat, point, radius, RED_SCALAR, -1);
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
    circle(mat, point, radius, BORDER_SCALAR);
}

bool CubeAnalyzer::isPressed(char c){
    auto key = static_cast<char>(waitKey(5));
    if (key == c){
        return true;
    }
    return false;
}

Cube CubeAnalyzer::getCube() const {
    return cube;
}
