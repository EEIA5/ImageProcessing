//
// Created by domin_000 on 25.10.2015.
//

#include <stddef.h>
#include "Cube.h"

Cube::Cube(Wall _walls[6])
{
    for (size_t i = 0; i < 6; i++)
    {
        walls[i] = _walls[i];
    }
}

Cube::~Cube()
{
}