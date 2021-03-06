#include "Cube.h"
#include "Colors.h"
#include "Constants.h"
#include <iostream>
#include <stdexcept>


void Cube::lockWall(unsigned w){
    walls[w].lock();
}

void Cube::unlockWall(unsigned w){
    walls[w].unlock();
}

bool Cube::isWallLocked(unsigned w){
    return walls[w].isLocked();
}

Wall Cube::getWall(unsigned w){
    if (w < numberOfWalls){
        return walls[w];
    }
    throw std::runtime_error("Wall index out of bounds!");
}

void Cube::setCell(unsigned w, unsigned c, Color color){
    if (w < numberOfWalls && c < numberOfCells){
        walls[w].setColor(c, color);
        return;
    }
    throw std::runtime_error("Wall or cell index out of bounds!");
}

Color Cube::getCell(unsigned w, unsigned c){
    if (w < numberOfWalls && c < numberOfCells){
        return walls[w].getColor(c);
    }
    throw std::runtime_error("Wall or cell index out of bounds!");
}

bool Cube::isComplete(){
    for (size_t wall = 0; wall < numberOfWalls; wall++){
        for (size_t cell = 0; cell < numberOfCells; cell++){
            if (walls[wall].getColor(cell) == UNDEF || !walls[wall].isLocked()){
                return false;
            }
        }
    }
    return true;
}

Cube& Cube::operator = (const Cube& c){
    if (this == &c){
        return *this;
    }
    for (size_t i = 0; i < numberOfWalls; i++){
        this->walls[i] = c.walls[i];
    }
    return *this;
}



