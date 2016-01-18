#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

#include "Wall.h"
#include "Colors.h"

class Cube
{
public:
    bool isComplete();
    Wall getWall(unsigned w);

    void setCell(unsigned w, unsigned c, Color color);
    Color getCell(unsigned w, unsigned c);

    void lockWall(unsigned w);
    void unlockWall(unsigned w);
    bool isWallLocked(unsigned w);

    Cube& operator = (const Cube& c);
private:
    Wall walls[6];
};

#endif
