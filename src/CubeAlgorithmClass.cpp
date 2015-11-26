#include "CubeAlgorithmClass.h"
#include "CubesAlgorithm.h"
#include "Cube.h"
#include "Wall.h"


CubeAlgorithmClass::CubeAlgorithmClass(Cube cube)
{
	for (int i = 0; i < 6; i++)
	{
		Wall walls = cube.getWall(i);
		for (int j = 0;j < 9;j++)
		{
			Cell cell = walls.getCell(j);

			if (walls.getCell(4).getColor().val[0,0] ==3)//red
			{
				input(j, red_side, walls);
			}
			else if (walls.getCell(4).getColor().val[0, 0] == 4)//orange
			{
				input(j, orange_side, walls);
			}
			else if (walls.getCell(4).getColor().val[0, 0] == 1)//yellow
			{
				input(j, yellow_side, walls);
			}
			else if (walls.getCell(4).getColor().val[0, 0] == 2)//green
			{
				input(j, green_side, walls);
			}
			else if (walls.getCell(4).getColor().val[0, 0] == 5)
			{
				input(j, blue_side, walls);//blue

			}
			else if (walls.getCell(4).getColor().val[0, 0] == 0)//white
			{
				input(j, white_side, walls);
			}

		}

	}
	
}



void CubeAlgorithmClass::input(int i, char * tab, Wall wall)
	{
		if (wall.getCell(i).getColor().val[0, 0] == 0)
		{
			tab[i] = 'w';
		}
		else if (wall.getCell(i).getColor().val[0, 0] == 1)
		{
			tab[i] = 'y';
		}
		else if (wall.getCell(i).getColor().val[0, 0] == 2)
		{
			tab[i] = 'g';
		}
		else if (wall.getCell(i).getColor().val[0, 0] == 3)
		{
			tab[i] = 'r';
		}
		else if (wall.getCell(i).getColor().val[0, 0] == 4)
		{
			tab[i] = 'o';
		}
		else if (wall.getCell(i).getColor().val[0, 0] == 5)
		{
			tab[i] = 'b';
		}
	}
