<<<<<<< HEAD
//
// Created by domin_000 on 25.10.2015.
//

#include <stddef.h>
#include "Wall.h"
=======
#include "Wall.h"
#include <stdexcept>
>>>>>>> origin/SideDetect
#include <iostream>

using namespace std;

<<<<<<< HEAD
Cell& Wall::getCell(int number){
    return cells[number];
}

Wall::Wall(){

}

Wall::~Wall(){

}
=======
Wall::Wall(){
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

void Wall::print(){
    for (size_t j = 0; j < numberOfCells; j++){
        if (j % numberOfCellsInRow == 0 && j != 0){
            cout << endl;
        }
        cout << colors[j] <<" ";
    }
}



>>>>>>> origin/SideDetect
