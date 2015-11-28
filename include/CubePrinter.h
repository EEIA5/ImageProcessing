#ifndef CUBEPRINTER_H_INCLUDED
#define CUBEPRINTER_H_INCLUDED

#include "Cube.h"
#include "Colors.h"
#include <windows.h>
#include <string>

class CubePrinter
{
public:
    CubePrinter(unsigned short W, unsigned short H);
    ~CubePrinter();
    void print(Cube cube);
    void setCube(Cube cube);
    Cube getCube();

private:
    Cube cube;
    unsigned short squareSide, spaceBetweenSquares, posX, posY;
    const unsigned short width, height;
    HANDLE consoleHandle;
    SMALL_RECT windowSize;
    SMALL_RECT writeArea;
    COORD characterPos;
    COORD charBufSize;
    COORD bufferSize;
    CHAR_INFO* consoleBuffer;
    void clearConsole();
    int getColorAtt(Color color);
    void drawWall(unsigned x, unsigned y, unsigned w);
    void drawSquare(unsigned x, unsigned y, Color color);
    void drawText(std::string text, unsigned x);
    std::string getColorName(unsigned color);
};



#endif // CUBEPRINTER_H_INCLUDED
