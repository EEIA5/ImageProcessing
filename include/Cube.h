//
// Created by domin_000 on 25.10.2015.
//

#pragma once
#include "Wall.h"
#include "Colors.h"

class Cube
{
public:
	Cube(Wall walls[6]);
	Cube();
	~Cube();
	void setCell(Color wall, int number, Color color);
	Wall getWall(int index);
private:
	Wall walls[6];
};
