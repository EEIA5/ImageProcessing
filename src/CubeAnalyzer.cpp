#include "CubeAnalyzer.h"
#include <iostream>

using namespace std;

CubeAnalyzer::CubeAnalyzer(){
    whiteLv = 50;
    blackLv = 70;
    radius = 4;
}

CubeAnalyzer::~CubeAnalyzer(){

}

void CubeAnalyzer::analyze(Mat cubeMat){
    this->cubeMat = cubeMat;
    Size imageSize = cubeMat.size();
    int w = imageSize.width;
    Color sideColor;
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
    }
}

Color CubeAnalyzer::detectSide(){
    Size cubeSize = cubeMat.size();
    return reconizeColor(cubeSize.width / 2, cubeSize.height / 2);
}

Color CubeAnalyzer::reconizeColor(int x ,int y){
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

bool CubeAnalyzer::isInMatrixBounds(int x, int y, int width, int height){
    return (x >= radius && y >= radius && x + radius < width && y + radius < height) ;
}

Vec3b CubeAnalyzer::getRawColor(int x, int y){
    Mat HSV;
    Mat BGR = cubeMat(Rect(x, y, 1, 1));
    cvtColor(BGR, HSV, CV_BGR2HSV);
    return HSV.at<Vec3b>(0, 0);
}

Vec3b CubeAnalyzer::avgColors(vector<Vec3b> colors){
    int sumH = 0, sumS = 0, sumV = 0;
    for ( unsigned i = 0; i<colors.size(); i++ ){
        sumH += int( colors[i][0] );
        sumS += int( colors[i][1] );
        sumV += int( colors[i][2] );
    }
    Vec3b color;
    color[0] = sumH / colors.size();
    color[1] = sumS / colors.size();
    color[2] = sumV / colors.size();
    return color;
}

Color CubeAnalyzer::classifyColor(Vec3b color){

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
        return UNDEF;
    }
}

Cube CubeAnalyzer::getCube(){
    return cube;
}
