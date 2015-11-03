
#include<string>
#include "OpenCV.h"
#include "Colors.h"

using namespace cv;

class Cell
{
public:
	Cell();
	Cell( std::string name );
	~Cell();
	void setColor( Scalar color );
	Scalar getColor();
	Scalar getHSVmin();
	Scalar getHSVmax();
    Color colorEnum;
	void setHSVmin( Scalar min );
	void setHSVmax( Scalar max );
private:
	Scalar color;
	Scalar HSVmin, HSVmax;
};

