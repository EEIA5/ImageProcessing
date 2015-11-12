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

Cell& Cell::operator = (const Cell& c){
    if (this == &c){
        return *this;
    }
    this->color = c.color;
}

bool Cell::operator == (const Cell& c) const{
    if (this->color == c.color){
        return true;
    }
    return false;
}

