<<<<<<< HEAD
//
// Created by domin_000 on 25.10.2015.
//

#pragma once
#include "Cell.h"
=======
#include "Constants.h"
#include "Colors.h"
>>>>>>> origin/SideDetect

class Wall
{
public:
    Wall();
<<<<<<< HEAD
	Cell& getCell(int number);
    ~Wall();
private:
    Cell cells[9];
=======
    void print();
    void setColor(unsigned number, Color color);
    Color getColor(unsigned number);
private:
    Color colors[numberOfCells];
>>>>>>> origin/SideDetect
};
