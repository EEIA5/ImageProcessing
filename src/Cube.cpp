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

