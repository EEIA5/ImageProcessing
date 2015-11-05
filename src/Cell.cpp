#include "Cell.h"
#include <iostream>

using namespace std;

Cell::Cell(){
	color = UNDEF;
}

Cell::~Cell(){

}

void Cell::setColor(Color& color){

	this->color = color;
}

Color Cell::getColor(){
	return color;
}

