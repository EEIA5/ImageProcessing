#include "Wall.h"
#include "Colors.h"

class Cube
{
public:
    Cube();
    ~Cube();
    Wall* getWall(Color wall);
    void print();
private:
    Wall walls[6];
};
