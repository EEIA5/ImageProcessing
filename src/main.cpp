#include "CubeDetector.h"

int main(int argc,char*argv[]){

    CubeDetector cubeDetector;
    cubeDetector.init();

    while (cubeDetector.isWorking()){
        cubeDetector.getFrame();
        cubeDetector.findCube();
        cubeDetector.drawCube();
    }
}




