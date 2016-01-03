#include "CubeResultViewer.h"
#include <stdexcept>

using namespace cv;

CubeResultViewer::CubeResultViewer(string windowName) : CubePrinter(windowName){
    CubeAlgorithmClass cubeAlgorithmClass;
    cubeView = cubeAlgorithmClass.getCubes();
    moveView = cubeAlgorithmClass.getMoves();
    if (cubeView.size() != moveView.size()){
        throw runtime_error("Cube and move sizes arent equal!");
    }
    numberOfMoves = cubeView.size();
    currentNumberOfMove = 0;
}

void CubeResultViewer::next(){
    currentNumberOfMove = (currentNumberOfMove + 1) % numberOfMoves;
    setMove(currentNumberOfMove);
}

void CubeResultViewer::prev(){
    currentNumberOfMove = currentNumberOfMove - 1;
    if (currentNumberOfMove < 0){
        currentNumberOfMove = numberOfMoves - 1;
    }
    setMove(currentNumberOfMove);
}

void CubeResultViewer::setMove(int numberMove){
    setCube(cubeView.at(numberMove));
    rectangle(*getView(), Rect(startX + 2 * d, 0, getView()->size().width, startY), background, -1);
    putText(*getView(),
            "Move: " + moveView.at(numberMove) +" nr: " + to_string(numberMove) + " / " + to_string(numberOfMoves - 1),
            Point(startX + 2 * d, startY - wallNamePosFix),
            FONT_HERSHEY_SIMPLEX, fontScale / 1.5, textColor);

    print(cubeView.at(numberMove));
}
