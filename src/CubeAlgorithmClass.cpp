#include "CubeAlgorithmClass.h"
#include "CubesAlgorithm.h"
#include "Cube.h"
#include "Colors.h"


CubeAlgorithmClass::CubeAlgorithmClass(Cube cube)
{
	for (int i = 0; i < 6; i++)
	{
		
		for (int j = 0;j < 9;j++)
		{
			Color color= cube.getWall(i).getColor(4);

			if (color == RED)//red 3
			{
				input(j, red_side, color);
			}
			else if (color == ORANGE)//orange 4
			{
				input(j, orange_side, color);
			}
			else if (color == YELLOW )//yellow 1
			{
				input(j, yellow_side, color);
			}
			else if (color == GREEN)//green 2
			{
				input(j, green_side, color);
			}
			else if (color == BLUE) 
			{
				input(j, blue_side, color);//blue 5

			}
			else if (color == WHITE)//white 0
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

void CubeAlgorithmClass::input(int i, char * tab,Color color)
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