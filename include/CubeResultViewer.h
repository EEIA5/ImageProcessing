#ifndef CUBERESULTVIEWER_H
#define CUBERESULTVIEWER_H
#include "CubePrinter.h"
#include "Cube.h"
#include "CubeAlgorithmClass.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <string>

using namespace std;

class CubeResultViewer : public CubePrinter {
    public:
        CubeResultViewer(string windowName);
        void next();
        void prev();

    private:
        vector<Cube*> cubeView;
        vector<string> moveView;
        int numberOfMoves;
        int currentNumberOfMove;
        void setMove(int moveNumber);
};

#endif
