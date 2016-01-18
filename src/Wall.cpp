#include "Wall.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Wall::Wall(){
    locked = false;
    for (size_t cell = 0; cell < numberOfCells; cell++){
        colors[cell] = UNDEF;
    }
}

Color Wall::getColor(unsigned number){
    if (number < numberOfCells){
        return colors[number];
    }
    throw runtime_error("Cell index out of bounds!");
}

void Wall::setColor(unsigned number, Color color){
    if (number < numberOfCells){
        colors[number] = color;
        return;
    }
    throw runtime_error("Cell index out of bounds!");
}

void Wall::lock(){
    locked = true;
}

void Wall::unlock(){
    locked = false;
}

bool Wall::isLocked(){
    return locked;
}



