#include "Cell.h"
#include "OpenCV.h"

Cell::Cell()
{
	setColor(Scalar(0, 0, 0));
}

Cell::Cell(string name)
{
	if (name == "blue") {
		setHSVmin(Scalar(92, 0, 0));
		setHSVmax(Scalar(124, 256, 256));
		setColor(Scalar(255, 0, 0));
	}
	else if (name == "green") {
		setHSVmin(Scalar(34, 50, 50));
		setHSVmax(Scalar(80, 220, 200));
		setColor(Scalar(0, 255, 0));
	}
	else if (name == "yellow") {
		setHSVmin(Scalar(20, 124, 123));
		setHSVmax(Scalar(30, 256, 256));
		setColor(Scalar(0, 255, 255));
	}
	else if (name == "red") {
		setHSVmin(Scalar(0, 200, 0));
		setHSVmax(Scalar(19, 255, 255));
		setColor(Scalar(0, 0, 255));
	}
}

Cell::Cell(Color color)
{
	switch (color)
	{
	case WHITE:
		break;
	case YELLOW:
		setHSVmin(Scalar(20, 124, 123));
		setHSVmax(Scalar(30, 256, 256));
		setColor(Scalar(0, 255, 255));
		break;
	case GREEN:
		setHSVmin(Scalar(34, 50, 50));
		setHSVmax(Scalar(80, 220, 200));
		setColor(Scalar(0, 255, 0));
		break;
	case RED:
		setHSVmin(Scalar(0, 200, 0));
		setHSVmax(Scalar(19, 255, 255));
		setColor(Scalar(0, 0, 255));
		break;
	case ORANGE:
		break;
	case BLUE:
		setHSVmin(Scalar(92, 0, 0));
		setHSVmax(Scalar(124, 256, 256));
		setColor(Scalar(255, 0, 0));
		break;
	case UNDEF:
		break;
	default:
		break;
	}
}

Cell::~Cell()
{
}

void Cell::setColor(Scalar color)
{
	this->color = color;
}

cv::Scalar Cell::getColor() const
{
	return this->color;
}

cv::Scalar Cell::getHSVmin() const
{
	return this->HSVmin;
}

cv::Scalar Cell::getHSVmax() const
{
	return this->HSVmax;
}

void Cell::setHSVmin(Scalar min)
{
	this->HSVmin = min;
}

void Cell::setHSVmax(Scalar max)
{
	this->HSVmax = max;
}
