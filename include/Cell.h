#pragma once
#include<string>
#include<cv.h>
using namespace cv;
class Cell
{
public:
	Cell();
	Cell(std::string name);
	~Cell();
	void setColor(cv::Scalar color);
	cv::Scalar getColor();
	cv::Scalar getHSVmin();
	cv::Scalar getHSVmax();

	void setHSVmin(cv::Scalar min);
	void setHSVmax(cv::Scalar max);
private:
	cv::Scalar color;
	cv::Scalar HSVmin, HSVmax;
};

