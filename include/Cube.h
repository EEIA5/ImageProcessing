//
// Created by domin_000 on 25.10.2015.
//

#include "Wall.h"
#include "Colors.h"
#include <iostream>

using namespace std;

class Cube
{
public:
    Cube();
    ~Cube();
    void setCellColor(Color wall, int number, Color color);
    void print();
private:
    Wall walls[6];
};
