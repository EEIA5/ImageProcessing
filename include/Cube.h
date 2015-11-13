<<<<<<< HEAD
//
// Created by domin_000 on 25.10.2015.
//

#include "Wall.h"
#include "Colors.h"
#include <iostream>

using namespace std;
=======
#include "Wall.h"
#include "Colors.h"
>>>>>>> origin/SideDetect

class Cube
{
public:
<<<<<<< HEAD
    Cube();
    ~Cube();
    void setCellColor(Color wall, int number, Color color);
    void print();
=======
    bool isComplete();
    void print();
    Wall getWall(unsigned w);

    void setCell(unsigned w, unsigned c, Color color);
    Color getCell(unsigned w, unsigned c);

    Cube& operator = (const Cube& c);
>>>>>>> origin/SideDetect
private:
    Wall walls[6];
};
