#include "CubeAnalyzer.h"

CubeAnalyzer::CubeAnalyzer() {

}

CubeAnalyzer::~CubeAnalyzer() {

}

void CubeAnalyzer::analyze(Mat cubeMat) {
	this->cubeMat = cubeMat;
	Size imageSize = cubeMat.size();
	int w = imageSize.width;
	if (w != 0) {
		int step = w / 3;
		int start = w*0.17;
		for (unsigned short horizontal = 0; horizontal < 3; horizontal++) {
			for (unsigned short vertical = 0; vertical < 3; vertical++) {
				circle(cubeMat, Point(start + step * horizontal, start + step * vertical), 4, Scalar(0, 0, 0));
				//cube.getWall(detectSide()).getCell(horizontal+vertical*3).colorEnum = getColor(start+step*horizontal,start+step*vertical);
				cube.setCell(detectSide(), horizontal + vertical * 3, getColor(start + step * horizontal, start + step * vertical));
			}
		}
		imshow(windowRubicCube, cubeMat);
	}
}

Color CubeAnalyzer::detectSide() {
	Size cubeSize = cubeMat.size();
	return static_cast<Color>(getColor(cubeSize.width / 2, cubeSize.height / 2));
}

Color CubeAnalyzer::getColor(int x, int y) {
	Mat HSV;
	Size cubeSize = cubeMat.size();
	int radius = 4;
	int sumH = 0, sumS = 0, sumV = 0;
	if (isPointInMatrixBounds(x, y, cubeSize.width, cubeSize.height, radius)) {
		vector<Vec3b> colors;
		Mat RGB = cubeMat(Rect(x, y, 1, 1));
		cvtColor(RGB, HSV, CV_BGR2HSV);
		colors.push_back(HSV.at<Vec3b>(0, 0));
		RGB = cubeMat(Rect(x - radius, y, 1, 1));
		cvtColor(RGB, HSV, CV_BGR2HSV);
		colors.push_back(HSV.at<Vec3b>(0, 0));
		RGB = cubeMat(Rect(x + radius, y, 1, 1));
		cvtColor(RGB, HSV, CV_BGR2HSV);
		colors.push_back(HSV.at<Vec3b>(0, 0));
		RGB = cubeMat(Rect(x, y - radius, 1, 1));
		cvtColor(RGB, HSV, CV_BGR2HSV);
		colors.push_back(HSV.at<Vec3b>(0, 0));
		RGB = cubeMat(Rect(x, y + radius, 1, 1));
		cvtColor(RGB, HSV, CV_BGR2HSV);
		colors.push_back(HSV.at<Vec3b>(0, 0));

		for (unsigned i = 0; i<colors.size(); i++) {
			sumH += int(colors[i][0]);
			sumS += int(colors[i][1]);
			sumV += int(colors[i][2]);
		}

		Vec3b color = HSV.at<Vec3b>(0, 0);
		color[0] = sumH / colors.size();
		color[1] = sumS / colors.size();
		color[2] = sumV / colors.size();

		short whiteLv = 50;
		short blackLv = 70;

		if (color[0] < 179 && color[0] >= 160 && color[1] > whiteLv && color[2] > blackLv) {
			return RED;
		}
		else if (color[0] >= 0 && color[0] < 22 && color[1] > whiteLv && color[2] > blackLv) {
			return ORANGE;
		}
		else if (color[0] >= 22 && color[0] < 38 && color[1] > whiteLv && color[2] > blackLv) {
			return YELLOW;
		}
		else if (color[0] >= 38 && color[0] < 95 && color[1] > whiteLv && color[2] > blackLv) {
			return GREEN;
		}
		else if (color[0] >= 95 && color[0] < 120 && color[1] > whiteLv && color[2] > blackLv) {
			return BLUE;
		}
		else if (color[1] < whiteLv && color[2] > blackLv) {
			return WHITE;
		}
		else {
			return UNDEF;
		}
	}
	return UNDEF;
}

bool CubeAnalyzer::isPointInMatrixBounds(int x, int y, int width, int height, int radius) {
	return (x >= radius && y >= radius && x + radius < width && y + radius < height);

}

