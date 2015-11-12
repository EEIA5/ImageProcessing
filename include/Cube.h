#include "Wall.h"
#include "Colors.h"

class Cube
{
public:
    Cube();
    ~Cube();
    Wall* getWall(Color wall);
    bool isComplete();
    void print();

    Cube& operator=(const Cube& c);
    bool operator==(const Cube& c);
    Color operator()(int w, int c);

private:
    Wall walls[6];
};
