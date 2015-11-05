//
// Created by domin_000 on 25.10.2015.
//

#include <stddef.h>
#include "Wall.h"
#include <iostream>

using namespace std;

Cell& Wall::getCell(int number){
    return cells[number];
}

Wall::Wall(){

}

Wall::~Wall(){

}
