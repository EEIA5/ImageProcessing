#include "Cell.h"

Cell::Cell(){
    color = UNDEF;
}

Cell::~Cell(){

}

void Cell::setColor(Color color){
	this->color = color;
}

Color Cell::getColor(){
	return this->color;
}

