#ifndef CUBEDETECTOR_H
#define CUBEDETECTOR_H

#include <string>
#include <vector>
#include <iostream>
#include "OpenCV.h"

using namespace std;
using namespace cv;

class CubeDetector
{
public:
	int tresholdCannyOne;
	int tresholdCannyTwo;
	void init();
	void findContures();
	bool isWorking();
	Mat getCube();
	CubeDetector();
	virtual ~CubeDetector();
private:
	vector<vector<Point>> squares;
	Mat frame;
	Mat cubeMat;
	VideoCapture* videoCapture;
	bool isSquare(int x1, int x2, int y1, int y2, int tolerance) const;
	bool isSizeOk(int x1, int x2, int size) const;
};

#endif
