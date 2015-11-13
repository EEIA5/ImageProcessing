#include "Constants.h"
#include "Colors.h"

class Wall
{
public:
    Wall();
    void print();
    void setColor(unsigned number, Color color);
    Color getColor(unsigned number);
private:
    Color colors[numberOfCells];
};
