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

