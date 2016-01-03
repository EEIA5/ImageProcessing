#include "CubeDetector.h"
#include "CubeAnalyzer.h"
#include "CubePrinter.h"
#include "CubeResultViewer.h"
#include "CubeAlgorithmClass.h"
#include <iostream>
#include <stdexcept>

using namespace std;

bool keyPressed(char character);

int main(int argc, char* argv[]){
    Cube cube;
    try {
        CubeDetector cubeDetector;
        CubeAnalyzer cubeAnalyzer;
        CubePrinter cubePrinter;
        bool work = true;
        while (work){
            cubeDetector.findContures();
            cubeAnalyzer.analyze(cubeDetector.getCube());
            cube = cubeAnalyzer.getCube();
            cubePrinter.print(&cube);
            if (cube.isComplete()){
                work = false;
			} else if (keyPressed('q')){
                return -1;
			}
        }
        CubeAlgorithmClass cubeAlgorithmClass;
        cubeAlgorithmClass.start(cube);

        CubeResultViewer cubeResultViewer("Results");
        while (!keyPressed('q')){
            if (keyPressed('d')){
                cubeResultViewer.next();
            }else if (keyPressed('a')){
                cubeResultViewer.prev();
            }
        }

    }catch (runtime_error e){
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}

bool keyPressed(char character){
	auto key = static_cast<char>(waitKey(10));
        if (key == character){
            return true;
        }
    return false;
}

