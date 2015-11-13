#include "CubeDetector.h"
#include "CubeAnalyzer.h"
<<<<<<< HEAD

int main(int argc, char* argv[]){

    CubeDetector cubeDetector;
    CubeAnalyzer cubeAnalyzer;
    try {
        cubeDetector.init();
        while (cubeDetector.isWorking()){
            cubeDetector.findContures();
            cubeAnalyzer.analyze(cubeDetector.getCube());
            cubeAnalyzer.getCube().print();
=======
#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char* argv[]){
    Cube cube;
    try {
        CubeDetector cubeDetector;
        CubeAnalyzer cubeAnalyzer;

        while (cubeDetector.isWorking()){
            cubeDetector.findContures();
            cubeAnalyzer.analyze(cubeDetector.getCube());
            cube = cubeAnalyzer.getCube();
            cube.print();
            if (cube.isComplete()){
                cout<<"Complete!"<<endl;
            }
>>>>>>> origin/SideDetect
        }
    }catch (runtime_error e){
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}

