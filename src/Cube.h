//
// Created by domin_000 on 25.10.2015.
//

#pragma once
#include "Wall.h"

class Cube
{
public:
    Cube(Wall walls[]);
	Wall getWall(int i);
	//Cube getWall(int i);
    ~Cube();
private:
    Wall walls[6];
};
