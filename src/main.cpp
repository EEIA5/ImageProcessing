#include "CubeDetector.h"

int main(int argc,char*argv[]){

    int *side= new int[9];
    CubeDetector cubeDetector;
    cubeDetector.init();

    while (cubeDetector.isWorking()){
        cubeDetector.getFrame();
        cubeDetector.findCube();
        cubeDetector.updateCubeWindow();
        cubeDetector.getColors(side);
        cubeDetector.print(side);

    }
    free(side);
}




