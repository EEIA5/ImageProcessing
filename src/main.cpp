#include "CubeDetector.h"
#include "CubeAnalyzer.h"

int main( int argc,char*argv[] ){

    CubeDetector cubeDetector;
    CubeAnalyzer cubeAnalyzer;
    try {
        cubeDetector.init();
        while ( cubeDetector.isWorking() ){
            cubeDetector.findContures();
            cubeAnalyzer.analyze( cubeDetector.getCube() );
        }
    }catch ( runtime_error e ){
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}

