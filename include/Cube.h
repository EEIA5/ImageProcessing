#include "Wall.h"
#include "Colors.h"

class Cube
{
public:
    bool isComplete();
    void print();
    Wall getWall(unsigned w);

    void setCell(unsigned w, unsigned c, Color color);
    Color getCell(unsigned w, unsigned c);

    Cube& operator = (const Cube& c);
private:
    Wall walls[6];
};
