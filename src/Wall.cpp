//
// Created by domin_000 on 25.10.2015.
//

#include <stddef.h>
#include "Wall.h"


Wall::Wall(Cell cells[6])
{
    for (size_t i = 0; i < 6; i++)
    {
        this->cells[i] = cells[i];
    }
}

Wall::~Wall()
{
}