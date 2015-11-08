#include "Cell.h"

class Wall
{
public:
    Wall();
	Cell* getCell(int number);
    ~Wall();
private:
    Cell cells[9];
};
