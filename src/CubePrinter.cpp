#include "CubePrinter.h"
#include "Constants.h"

CubePrinter::CubePrinter(unsigned short W, unsigned short H) : width(W), height(H){
    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    bufferSize = {width , height};
    windowSize = {0, 0, width -1, height - 1};
    SetConsoleScreenBufferSize(consoleHandle, bufferSize);
    consoleBuffer = new CHAR_INFO[width * height];
    squareSide = 3;
    spaceBetweenSquares = 2;
    characterPos = {0, 0};
    writeArea = {0, 0,width, height};
    charBufSize = {width, height};
    posX = 18;
    posY = 18;
}

CubePrinter::~CubePrinter(){
    delete[] consoleBuffer;
}

void CubePrinter::print(Cube cube){
    this->cube = cube;
    clearConsole();
    drawWall(posX, 1, WHITE);
    drawWall(1, posY, ORANGE);
    drawWall(posX, posY, GREEN);
    drawWall(posX * 2, posY, RED);
    drawWall(posX * 3, posY, BLUE);
    drawWall(posX, posY * 2, YELLOW);

    WriteConsoleOutputA(consoleHandle, consoleBuffer, charBufSize, characterPos, &writeArea);
}

void CubePrinter::clearConsole(){
    for (unsigned i = 0; i < width * height; i++){
        consoleBuffer[i].Char.AsciiChar = ' ';
        consoleBuffer[i].Attributes = 0;
    }
}

int CubePrinter::getColorAtt(Color color){
    switch (color){
    case RED:
        return BACKGROUND_RED | BACKGROUND_INTENSITY;
        break;
    case GREEN:
        return BACKGROUND_GREEN | BACKGROUND_INTENSITY;
        break;
    case BLUE:
        return BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        break;
    case YELLOW:
        return BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
        break;
    case WHITE:
        return BACKGROUND_RED | BACKGROUND_GREEN |BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        break;
    case ORANGE:
        return BACKGROUND_GREEN | BACKGROUND_RED ;
        break;
    default:
        return BACKGROUND_INTENSITY;
    break;
    }
}

void CubePrinter::drawWall(unsigned x, unsigned y, unsigned w){
    Color color;
    unsigned tmpX = x, tmpY = y;
    drawText(getColorName(w), tmpX + (tmpY - 1) * width );
    for (unsigned short cell = 0; cell < numberOfCells; cell++){
        color = cube.getWall(w).getColor(cell);
        if (cell % numberOfCellsInRow == 0 && cell != 0){
            tmpX = x;
            tmpY += squareSide + spaceBetweenSquares;
        }
        drawSquare(tmpX, tmpY , color);
        if (cube.getWall(w).isLocked() && cell == 4){
            unsigned middleSquareSign = tmpX + squareSide / 2 + (tmpY + 1) * width;
            drawText("x", middleSquareSign);
        }
        tmpX +=  squareSide + spaceBetweenSquares ;
    }
}

void CubePrinter::drawText(std::string text, unsigned x){
    for (unsigned pos = x; pos < x + text.length(); pos++){
        consoleBuffer[pos].Char.AsciiChar = text[pos - x];
        consoleBuffer[pos].Attributes = FOREGROUND_RED | FOREGROUND_GREEN |
                                        FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    }
}

void CubePrinter::drawSquare(unsigned x, unsigned y, Color color){
    for (unsigned short h = 0; h < squareSide; h++){
        for (unsigned short w = 0; w < squareSide; w++){
            consoleBuffer[(x + w + h * width) + y * width].Attributes = getColorAtt(color);
        }
    }
}

void CubePrinter::setCube(Cube cube){
    this->cube = cube;
}

Cube CubePrinter::getCube(){
    return cube;
}

std::string CubePrinter::getColorName(unsigned color){
    switch (color){
    case RED:
        return "RED";
        break;
    case ORANGE:
        return "ORANGE";
        break;
    case WHITE:
        return "WHITE";
        break;
    case YELLOW:
        return "YELLOW";
        break;
    case GREEN:
        return "GREEN";
        break;
    case BLUE:
        return "BLUE";
        break;
    default:
        return "UNDEF";
        break;
    }
}
