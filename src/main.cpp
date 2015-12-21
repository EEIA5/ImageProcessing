#include "CubeDetector.h"
#include "CubeAnalyzer.h"
#include "CubePrinter.h"
#include "CubeAlgorithmClass.h"
#include <iostream>
#include <stdexcept>
#include <windows.h>

using namespace std;

vector<Cube*> cubeView;
vector<string> moveView;
bool solved = false;
CubePrinter results ("Wyniki");
int numberOfMove = 0;

void setMove(int number){
   results.setCube(cubeView.at(number));
   results.print(cubeView.at(number));
}

void solveAndPrintResults(Cube* cube){
    if (solved == false){
        solved = true;
        cout<<"Scanning complete!"<<endl;
        cout<<"Solving..."<<endl;
        CubeAlgorithmClass cubeAlgorithmClass;
        cubeAlgorithmClass.start(*cube);
        cubeView = cubeAlgorithmClass.getCubes();
        moveView = cubeAlgorithmClass.getMoves();
    }
    auto key = static_cast<char>(waitKey(5));

    if (key == 'd'){
        numberOfMove = (numberOfMove + 1) % cubeView.size();
        cout<<numberOfMove <<": "<<moveView.at(numberOfMove)<<endl;
    }
    setMove(numberOfMove);
}



int main(int argc, char* argv[]){
    Cube cube;
    try {
        CubeDetector cubeDetector;
        CubeAnalyzer cubeAnalyzer;
        CubePrinter cubePrinter;
        while (cubeDetector.isWorking()){
            if (cube.isComplete()){
                solveAndPrintResults(&cube);
                continue;
			}
            cubeDetector.findContures();
            cubeAnalyzer.analyze(cubeDetector.getCube());
            cube = cubeAnalyzer.getCube();
            cubePrinter.print(&cube);
        }

    }catch (runtime_error e){
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}

