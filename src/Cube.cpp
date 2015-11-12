#include <stddef.h>
#include "Cube.h"
#include "Colors.h"
#include <iostream>

using namespace std;

Cube::Cube(){

}

Cube::~Cube(){

}

Wall* Cube::getWall(Color wall){
    return &walls[wall];
}

void Cube::print(){
    for (unsigned i = 0; i < 6; i++){
        cout << endl << endl << "Side: " << i << endl << endl;
        for (unsigned j = 0; j < 9; j++){
            if (j % 3 == 0 && j != 0){
                cout << endl;
            }
            cout << walls[i].getCell(j)->getColor() << " ";
        }
    }
}

Cube& Cube::operator=(const Cube& c){
    if (this == &c){
        return *this;
    }
    for (size_t cube = 0; cube < 6; cube++){
        *(this->getWall(static_cast<Color>(cube))) ;
    }
    return *this;
}

Color Cube::operator()(int w, int c){
    if (w >= 0 && w < 6 && c >= 0 && c < 9){
        return this->walls[w].getCell(c)->getColor();
    }
    return UNDEF;
}


bool Cube::isComplete(){
    for (size_t wall = 0; wall < 6; wall++){
        for (size_t cell = 0; cell < 9; cell++){
            if (walls[wall].getCell(cell)->getColor() == UNDEF){
                return false;
            }
        }
    }
    return true;
}
