//
// Created by domin_000 on 25.10.2015.
//

#pragma once
#include "Cell.h"

class Wall
{
public:
	
	Wall();

	Wall(Cell cells[9]);
	Cell getCell(int i);
    ~Wall();
private:
    Cell cells[9];
	
};
