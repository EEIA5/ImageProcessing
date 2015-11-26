//
// Created by domin_000 on 25.10.2015.
//

#include <stddef.h>
#include "Wall.h"
Wall::Wall()
{

}

Wall::Wall(Cell cells[9])
{
    for (size_t i = 0; i < 9; i++)
    {
        this->cells[i] = cells[i];
    }
}
Cell Wall :: getCell(int i)
{

	return  this->cells[i];
}
Wall::~Wall()
{
}