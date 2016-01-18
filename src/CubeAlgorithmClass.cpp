#include "CubeAlgorithmClass.h"


void CubeAlgorithmClass::start(Cube cube){
	auto_test(cube);
}

vector<Cube*> CubeAlgorithmClass::getCubes(){
    return getCubeVec();
}

vector<string> CubeAlgorithmClass::getMoves(){
    return getMoveVec();
}

