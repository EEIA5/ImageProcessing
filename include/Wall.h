//
// Created by domin_000 on 25.10.2015.
//

#pragma once
#include "Cell.h"

class Wall
{
public:
    Wall( Cell cells[9] );
	Wall();
	Cell getCell( int number );
    ~Wall();
private:
    Cell cells[ 9 ];
};
