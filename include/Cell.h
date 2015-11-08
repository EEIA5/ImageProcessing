#include "Colors.h"

class Cell
{
public:
	Cell();
	~Cell();
	void setColor(Color color);
	Color getColor();
private:
    Color color;
};

