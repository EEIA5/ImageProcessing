#include "Colors.h"

class Cell
{
public:
	Cell();
	~Cell();
	void setColor(Color color);
	Color getColor();

	Cell& operator = (const Cell& c);
	bool operator == (const Cell& c) const;
private:
    Color color;
};

