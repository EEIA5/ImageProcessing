#include "CubePrinter.h"
#include "ColorsRange.h"
#include "Constants.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

CubePrinter::CubePrinter(string wndName) {
	windowName = wndName;
	background = Scalar(30, 30, 30);
	squareSize = 40;
	spaceBetweenSquares = 5;
	namedWindow(windowName, WINDOW_AUTOSIZE);
	view = new Mat(500, 660, CV_8UC3, background);
	startX = 10;
	startY = 30;
	fontScale = 0.7;
	wallNamePosFix = 8;
	textColor = Scalar(255, 255, 255);
	d = (numberOfCellsInRow + 1) * squareSize + spaceBetweenSquares;
	drawWallNames();
}

CubePrinter::~CubePrinter() {
	delete view;
}


void CubePrinter::drawWallNames() const {
	putText(*view, "Orange", Point(startX, startY + d - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale, textColor);
	putText(*view, "White", Point(startX + d, startY - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale, textColor);
	putText(*view, "Green", Point(startX + d, startY + d - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale, textColor);
	putText(*view, "Red", Point(startX + 2 * d, startY + d - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale, textColor);
	putText(*view, "Blue", Point(startX + 3 * d, startY + d - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale, textColor);
	putText(*view, "Yellow", Point(startX + d, startY + 2 * d - wallNamePosFix), FONT_HERSHEY_SIMPLEX, fontScale, textColor);
}

void CubePrinter::print(Cube* cube) {
	this->cube = cube;
	drawWall(startX, startY + d, ORANGE);
	drawWall(startX + d, startY, WHITE);
	drawWall(startX + d, startY + 2 * d, YELLOW);
	drawWall(startX + d, startY + d, GREEN);
	drawWall(startX + 2 * d, startY + d, RED);
	drawWall(startX + 3 * d, startY + d, BLUE);
	imshow(windowName, *view);
}

void CubePrinter::drawWall(unsigned x, unsigned y, unsigned w) {
	Color color;
	unsigned tmpX = x, tmpY = y;
	for (unsigned short cell = 0; cell < numberOfCells; cell++) {
		color = cube->getWall(w).getColor(cell);
		if (cell % numberOfCellsInRow == 0 && cell != 0) {
			tmpX = x;
			tmpY += squareSize + spaceBetweenSquares;
		}
		drawSquare(tmpX, tmpY, color);
		if (cube->getWall(w).isLocked() && cell == 4) {
			Point leftUpper = Point(tmpX + squareSize / 4, tmpY + squareSize / 4);
			Point rightLower = Point(tmpX + squareSize - squareSize / 4, tmpY + squareSize - squareSize / 4);
			rectangle(*view, leftUpper, rightLower, Scalar(0, 0, 0), -1);
		}
		tmpX += squareSize + spaceBetweenSquares;
	}
}

void CubePrinter::drawSquare(unsigned x, unsigned y, Color color) {
	rectangle(*view, Point(x, y), Point(x + squareSize, y + squareSize), getColorScalar(color), -1);
}

Scalar CubePrinter::getColorScalar(Color color) {
	switch (color) {
	case WHITE:
		return WHITE_SCALAR;
	case YELLOW:
		return YELLOW_SCALAR;
	case RED:
		return RED_SCALAR;
	case BLUE:
		return BLUE_SCALAR;
	case GREEN:
		return GREEN_SCALAR;
	case ORANGE:
		return ORANGE_SCALAR;
	default:
		return UNDEF_SCALAR;
	}
}

void CubePrinter::setCube(Cube* cube) {
	this->cube = cube;
}

Cube* CubePrinter::getCube() const {
	return cube;
}

Mat* CubePrinter::getView() const {
	return view;
}
