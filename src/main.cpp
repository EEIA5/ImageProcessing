#include "CubeDetector.h"

int main(int argc,char*argv[]){

    CubeDetector cubeDetector;
    int **sides=cubeDetector.init();
    if (sides==NULL)
        return -1;
    while (cubeDetector.isWorking()){
        cubeDetector.getFrame();
        cubeDetector.findCube();
        cubeDetector.updateCubeWindow();
        cubeDetector.getColors(sides);
        cubeDetector.print(sides);
    }
	
    for (int i = 0 ; i< NumberOfSides ; i++){
        delete [] sides[i];
    }
    delete [] sides;
    return 0;
}

