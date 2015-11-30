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
        CubePrinter cubePrinter;

        while (cubeDetector.isWorking()){
            cubeDetector.findContures();
            cubeAnalyzer.analyze(cubeDetector.getCube());
            cube = cubeAnalyzer.getCube();
            cubePrinter.print(cube);
            if (cube.isComplete()){
                cout<<"Scanning complete!"<<endl;
                break;
			}
        }
        if (cube.isComplete()){
            cout<<"Solving..."<<endl;
            CubeAlgorithmClass cubeAlgorithmClass;
            cubeAlgorithmClass.start(cube);
        }


    }catch (runtime_error e){
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}

