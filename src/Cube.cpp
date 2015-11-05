//
// Created by domin_000 on 25.10.2015.
//

#include "Cube.h"
#include "Colors.h"

Cube::Cube(Wall _walls[6])
{
	for (size_t i = 0; i < 6; i++) {
		walls[i] = _walls[i];
	}
}

Cube::Cube() {
	for (size_t i = 0; i < 6; i++) {
		Cell cell[9];
		walls[i] = Wall(cell);
	}
}

void Cube::setCell(Color wall, int number, Color color) {
	auto w = walls[wall];
	w.getCell(number).setColor(color);
}
Cube::~Cube()
{

}
