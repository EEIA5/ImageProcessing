#include "CubeAlgorithmClass.h"
#include "CubesAlgorithm.h"
#include "Cube.h"
#include "Colors.h"
#include "Constants.h"


CubeAlgorithmClass::CubeAlgorithmClass(Cube cube)
{
	for (int i = 0; i < numberOfWalls; i++)
	{
		Color wallColor = cube.getWall(i).getColor(4);

		for (int j = 0;j < numberOfCells;j++)
		{
			Color color = cube.getWall(i).getColor(j);

			if (wallColor == RED)//red 3
			{
				input(j, red_side, color);
			}
			else if (wallColor == ORANGE)//orange 4
			{
				input(j, orange_side, color);
			}
			else if (wallColor == YELLOW )//yellow 1
			{
				input(j, yellow_side, color);
			}
			else if (wallColor == GREEN)//green 2
			{
				input(j, green_side, color);
			}
			else if (wallColor == BLUE)
			{
				input(j, blue_side, color);//blue 5
			}
			else if (wallColor == WHITE)//white 0
			{
				input(j, white_side, color);
			}

		}

	}

}

void CubeAlgorithmClass::start()
{
	auto_test(true);
}

void CubeAlgorithmClass::input(int i, char * tab, Color color)
	{
		if (color == WHITE)
		{
			tab[i] = 'w';
		}
		else if (color == YELLOW)
		{
			tab[i] = 'y';
		}
		else if (color == GREEN)
		{
			tab[i] = 'g';
		}
		else if (color == RED)
		{
			tab[i] = 'r';
		}
		else if (color == ORANGE)
		{
			tab[i] = 'o';
		}
		else if (color == BLUE)
		{
			tab[i] = 'b';
		}
	}
