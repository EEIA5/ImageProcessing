#include "Cell.h"



Cell::Cell()
{
	setColor(Scalar(0, 0, 0));
}

Cell::Cell(std::string name)
{
	if (name == "blue") {

		setHSVmin(Scalar(92, 0, 0));
		setHSVmax(Scalar(124, 256, 256));

		setColor(Scalar(255, 0, 0));

	}
	if (name == "green") {

		setHSVmin(Scalar(34, 50, 50));
		setHSVmax(Scalar(80, 220, 200));

		setColor(Scalar(0, 255, 0));

	}
	if (name == "yellow") {

		setHSVmin(Scalar(20, 124, 123));
		setHSVmax(Scalar(30, 256, 256));

		//BGR value for Red:
		setColor(Scalar(0, 255, 255));

	}
	if (name == "red") {

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

void Cell::setColor(cv::Scalar color)
{
	this->color = color;
}

cv::Scalar Cell::getColor()
{
	return this->color;
}

cv::Scalar Cell::getHSVmin()
{
	return this->HSVmin;
}

cv::Scalar Cell::getHSVmax()
{
	return this->HSVmax;
}

void Cell::setHSVmin(cv::Scalar min)
{
	this->HSVmin = min;
}

void Cell::setHSVmax(cv::Scalar max)
{
	this->HSVmax = max;
}