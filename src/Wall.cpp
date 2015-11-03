//
// Created by domin_000 on 25.10.2015.
//

#include <stddef.h>
#include "Wall.h"


Wall::Wall(Cell cells[6])
{
    for ( size_t i = 0; i < 6; i++ )
    {
        this->cells[i] = cells[i];
    }
}

Cell Wall::getCell( int number ){
    return cells[number];
}

Wall::Wall()
{
}

Wall::~Wall()
{
}
