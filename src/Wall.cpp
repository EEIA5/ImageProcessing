#include <stddef.h>
#include "Wall.h"
#include <iostream>

using namespace std;

Cell* Wall::getCell(int number){
    return &cells[number];
}

Wall::Wall(){

}

Wall::~Wall(){

}
