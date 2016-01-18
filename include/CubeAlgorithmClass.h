#ifndef CUBESALGORITHMCLASS_H
#define CUBESALGORITHMCLASS_H

#include <iostream>
#include <string>
#include <vector>
#include "CubesAlgorithm.h"
#include "Cube.h"

using namespace std;

class CubeAlgorithmClass
{
public:
	void start(Cube cube);
	vector<Cube*> getCubes();
	vector<string> getMoves();
};

#endif

