<<<<<<< HEAD
//
// Created by domin_000 on 25.10.2015.
//

#include <stddef.h>
#include "Cube.h"
#include "Colors.h"

Cube::Cube(){

}

Cube::~Cube(){

}

void Cube::setCellColor(Color wall, int number, Color color){
    walls[wall].getCell(number).setColor(color);
}

void Cube::print(){
    for (unsigned i = 0; i < 6; i++){
        cout<<endl<<endl<<"Side: "<<i<<endl<<endl;
        for (unsigned j = 0; j < 9; j++){
            if (j % 3 == 0 && j != 0){
                cout<<endl;
            }
            cout<<walls[i].getCell(j).getColor()<<" ";

        }
    }
}

=======
#include "Cube.h"
#include "Colors.h"
#include "Constants.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void Cube::print(){
    for (size_t i = 0; i < numberOfWalls; i++){
        cout << endl << endl << "Side: " << i << endl << endl;
        getWall(i).print();
    }
}

Wall Cube::getWall(unsigned w){
    if (w < numberOfWalls){
        return walls[w];
    }
    throw runtime_error("Wall index out of bounds!");
}

void Cube::setCell(unsigned w, unsigned c, Color color){
    if (w < numberOfWalls && c < numberOfCells){
        walls[w].setColor(c, color);
        return;
    }
    throw runtime_error("Wall or cell index out of bounds!");
}

Color Cube::getCell(unsigned w, unsigned c){
    if (w < numberOfWalls && c < numberOfCells){
        return walls[w].getColor(c);
    }
    throw runtime_error("Wall or cell index out of bounds!");
}

bool Cube::isComplete(){
    for (size_t wall = 0; wall < numberOfWalls; wall++){
        for (size_t cell = 0; cell < numberOfCells; cell++){
            if (walls[wall].getColor(cell) == UNDEF){
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



>>>>>>> origin/SideDetect
