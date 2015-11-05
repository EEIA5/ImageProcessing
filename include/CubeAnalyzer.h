#ifndef CUBEANALYZER_H_INCLUDED
#define CUBEANALYZER_H_INCLUDED

#include "OpenCV.h"
#include "Colors.h"
#include "Cube.h"

class CubeAnalyzer
{
public:
	CubeAnalyzer();
	virtual ~CubeAnalyzer();
	void analyze(Mat cubeMat);

private:
	Mat cubeMat;
	Cube cube;
	static bool isPointInMatrixBounds(int x, int y, int width, int height, int radius);
	Color detectSide() const;
	Color getColor(int x, int y) const;
};


#endif // CUBEANALYZER_H_INCLUDED
