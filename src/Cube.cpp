//
// Created by domin_000 on 25.10.2015.
//

#include <stddef.h>
#include "Cube.h"
#include "Wall.h"
#include "Cell.h"

Cube::Cube(Wall  _walls[])
{
    for (size_t i = 0; i < 6; i++)
    {
        walls[i] = _walls[i];
    }

}
Wall Cube::getWall(int i)
{
	return this->walls[i];
}


Cube::~Cube()
{
}