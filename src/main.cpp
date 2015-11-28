#include "CubeDetector.h"
#include "CubeAnalyzer.h"
#include "CubePrinter.h"
#include "CubeAlgorithmClass.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char* argv[]){
    Cube cube;
    try {
        CubeDetector cubeDetector;
        CubeAnalyzer cubeAnalyzer;
        CubePrinter cubePrinter(80,100);

        while (cubeDetector.isWorking()){
            cubeDetector.findContures();
            cubeAnalyzer.analyze(cubeDetector.getCube());
            cube = cubeAnalyzer.getCube();
            cubePrinter.print(cube);
            if (cube.isComplete()){
                cout<<"Complete!"<<endl;
				CubeAlgorithmClass cubeAlgorithmClass(cube);
				cubeAlgorithmClass.start();
            }
        }
    }catch (runtime_error e){
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}

