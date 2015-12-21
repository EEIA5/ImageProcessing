#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "CubesAlgorithm.h"

using namespace std;

vector<string> moves;
vector<Cube*> cubes;

bool sim_only = false;
bool cube_solved = true;

char yellow_side[9] = { 'y', 'y', 'y',
'y', 'y', 'y',
'y', 'y', 'y' };

char white_side[9] = { 'w', 'w', 'w',
'w', 'w', 'w',
'w', 'w', 'w' };

char blue_side[9] = { 'b', 'b', 'b',
'b', 'b', 'b',
'b', 'b', 'b' };

char red_side[9] = { 'r', 'r', 'r',
'r', 'r', 'r',
'r', 'r', 'r' };

char green_side[9] = { 'g', 'g', 'g',
'g', 'g', 'g',
'g', 'g', 'g' };

char orange_side[9] = { 'o', 'o', 'o',
'o', 'o', 'o',
'o', 'o', 'o' };



void left()
{
	printf("L', ");
    moves.push_back("L'");

	// Cube simulation
	char r_yellow_side[9];
	char r_blue_side[9];
	char r_white_side[9];
	char r_green_side[9];
	char r_red_side[9];

	for (int i = 0; i < 9; i++)
	{
		r_yellow_side[i] = yellow_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_blue_side[i] = blue_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_white_side[i] = white_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_green_side[i] = green_side[i];
	}

	yellow_side[0] = r_blue_side[0];
	yellow_side[3] = r_blue_side[3];
	yellow_side[6] = r_blue_side[6];

	blue_side[0] = r_white_side[0];
	blue_side[3] = r_white_side[3];
	blue_side[6] = r_white_side[6];

	white_side[0] = r_green_side[8];
	white_side[3] = r_green_side[5];
	white_side[6] = r_green_side[2];

	green_side[8] = r_yellow_side[0];
	green_side[5] = r_yellow_side[3];
	green_side[2] = r_yellow_side[6];

	for (int x = 0; x < 9; x++)
	{
		r_red_side[x] = red_side[x];
	}

	red_side[0] = r_red_side[6];
	red_side[1] = r_red_side[3];
	red_side[2] = r_red_side[0];
	red_side[3] = r_red_side[7];
	red_side[4] = r_red_side[4];
	red_side[5] = r_red_side[1];
	red_side[6] = r_red_side[8];
	red_side[7] = r_red_side[5];
	red_side[8] = r_red_side[2];
	cubes.push_back(toCube());
}
void left_inverted()
{
	printf("L, ");
    moves.push_back("L");

	// Cube simulation
	char r_yellow_side[9];
	char r_blue_side[9];
	char r_white_side[9];
	char r_green_side[9];
	char r_red_side[9];
	for (int i = 0; i < 9; i++)
	{
		r_yellow_side[i] = yellow_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_blue_side[i] = blue_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_white_side[i] = white_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_green_side[i] = green_side[i];
	}

	yellow_side[0] = r_green_side[8];
	yellow_side[3] = r_green_side[5];
	yellow_side[6] = r_green_side[2];

	blue_side[0] = r_yellow_side[0];
	blue_side[3] = r_yellow_side[3];
	blue_side[6] = r_yellow_side[6];

	white_side[0] = r_blue_side[0];
	white_side[3] = r_blue_side[3];
	white_side[6] = r_blue_side[6];

	green_side[8] = r_white_side[0];
	green_side[5] = r_white_side[3];
	green_side[2] = r_white_side[6];

	for (int x = 0; x < 9; x++)
	{
		r_red_side[x] = red_side[x];
	}

	red_side[0] = r_red_side[2];
	red_side[1] = r_red_side[5];
	red_side[2] = r_red_side[8];
	red_side[3] = r_red_side[1];
	red_side[4] = r_red_side[4];
	red_side[5] = r_red_side[7];
	red_side[6] = r_red_side[0];
	red_side[7] = r_red_side[3];
	red_side[8] = r_red_side[6];
	cubes.push_back(toCube());
}
void right() {
	printf("R', ");
    moves.push_back("R'");

	// Cube simulation
	char r_yellow_side[9];
	char r_blue_side[9];
	char r_white_side[9];
	char r_green_side[9];
	char r_orange_side[9];
	for (int i = 0; i < 9; i++)
	{
		r_yellow_side[i] = yellow_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_blue_side[i] = blue_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_white_side[i] = white_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_green_side[i] = green_side[i];
	}

	yellow_side[2] = r_green_side[6];
	yellow_side[5] = r_green_side[3];
	yellow_side[8] = r_green_side[0];

	blue_side[2] = r_yellow_side[2];
	blue_side[5] = r_yellow_side[5];
	blue_side[8] = r_yellow_side[8];

	white_side[2] = r_blue_side[2];
	white_side[5] = r_blue_side[5];
	white_side[8] = r_blue_side[8];

	green_side[6] = r_white_side[2];
	green_side[3] = r_white_side[5];
	green_side[0] = r_white_side[8];

	for (int x = 0; x < 9; x++)
	{
		r_orange_side[x] = orange_side[x];
	}

	orange_side[0] = r_orange_side[6];
	orange_side[1] = r_orange_side[3];
	orange_side[2] = r_orange_side[0];
	orange_side[3] = r_orange_side[7];
	orange_side[4] = r_orange_side[4];
	orange_side[5] = r_orange_side[1];
	orange_side[6] = r_orange_side[8];
	orange_side[7] = r_orange_side[5];
	orange_side[8] = r_orange_side[2];
    cubes.push_back(toCube());
}
void right_inverted()
{
	printf("R, ");
    moves.push_back("R");
	// Cube simulation
	char r_yellow_side[9];
	char r_blue_side[9];
	char r_white_side[9];
	char r_green_side[9];
	char r_orange_side[9];
	for (int i = 0; i < 9; i++)
	{
		r_yellow_side[i] = yellow_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_blue_side[i] = blue_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_white_side[i] = white_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_green_side[i] = green_side[i];
	}

	yellow_side[2] = r_blue_side[2];
	yellow_side[5] = r_blue_side[5];
	yellow_side[8] = r_blue_side[8];

	blue_side[2] = r_white_side[2];
	blue_side[5] = r_white_side[5];
	blue_side[8] = r_white_side[8];

	white_side[2] = r_green_side[6];
	white_side[5] = r_green_side[3];
	white_side[8] = r_green_side[0];

	green_side[6] = r_yellow_side[2];
	green_side[3] = r_yellow_side[5];
	green_side[0] = r_yellow_side[8];

	for (int x = 0; x < 9; x++)
	{
		r_orange_side[x] = orange_side[x];
	}

	orange_side[0] = r_orange_side[2];
	orange_side[1] = r_orange_side[5];
	orange_side[2] = r_orange_side[8];
	orange_side[3] = r_orange_side[1];
	orange_side[4] = r_orange_side[4];
	orange_side[5] = r_orange_side[7];
	orange_side[6] = r_orange_side[0];
	orange_side[7] = r_orange_side[3];
	orange_side[8] = r_orange_side[6];
	cubes.push_back(toCube());
}
void down()
{
	printf("D', ");
    moves.push_back("D'");

	// Cube simulation
	char r_yellow_side[9];
	char r_white_side[9];
	char r_orange_side[9];
	char r_red_side[9];
	char r_green_side[9];
	for (int i = 0; i < 9; i++)
	{
		r_yellow_side[i] = yellow_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_orange_side[i] = orange_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_white_side[i] = white_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_red_side[i] = red_side[i];
	}

	orange_side[8] = r_yellow_side[6];
	orange_side[5] = r_yellow_side[7];
	orange_side[2] = r_yellow_side[8];

	yellow_side[6] = r_red_side[0];
	yellow_side[7] = r_red_side[3];
	yellow_side[8] = r_red_side[6];

	red_side[0] = r_white_side[2];
	red_side[3] = r_white_side[1];
	red_side[6] = r_white_side[0];

	white_side[0] = r_orange_side[2];
	white_side[1] = r_orange_side[5];
	white_side[2] = r_orange_side[8];

	for (int x = 0; x < 9; x++)
	{
		r_green_side[x] = green_side[x];
	}
	// reassign colours on face
	green_side[0] = r_green_side[6];
	green_side[1] = r_green_side[3];
	green_side[2] = r_green_side[0];
	green_side[3] = r_green_side[7];
	green_side[4] = r_green_side[4];
	green_side[5] = r_green_side[1];
	green_side[6] = r_green_side[8];
	green_side[7] = r_green_side[5];
	green_side[8] = r_green_side[2];

    cubes.push_back(toCube());
}
void down_inverted()
{
	printf("D, ");
    moves.push_back("D");

	// Cube simulation
	char r_yellow_side[9];
	char r_white_side[9];
	char r_orange_side[9];
	char r_red_side[9];
	char r_green_side[9];
	for (int i = 0; i < 9; i++)
	{
		r_yellow_side[i] = yellow_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_orange_side[i] = orange_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_white_side[i] = white_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_red_side[i] = red_side[i];
	}

	yellow_side[6] = r_orange_side[8];
	yellow_side[7] = r_orange_side[5];
	yellow_side[8] = r_orange_side[2];

	red_side[0] = r_yellow_side[6];
	red_side[3] = r_yellow_side[7];
	red_side[6] = r_yellow_side[8];

	white_side[0] = r_red_side[6];
	white_side[1] = r_red_side[3];
	white_side[2] = r_red_side[0];

	orange_side[2] = r_white_side[0];
	orange_side[5] = r_white_side[1];
	orange_side[8] = r_white_side[2];

	for (int x = 0; x < 9; x++)
	{
		r_green_side[x] = green_side[x];
	}

	green_side[0] = r_green_side[2];
	green_side[1] = r_green_side[5];
	green_side[2] = r_green_side[8];
	green_side[3] = r_green_side[1];
	green_side[4] = r_green_side[4];
	green_side[5] = r_green_side[7];
	green_side[6] = r_green_side[0];
	green_side[7] = r_green_side[3];
	green_side[8] = r_green_side[6];
	cubes.push_back(toCube());
}
void up()
{
	printf("U', ");
    moves.push_back("U'");

	// Cube simulation
	char r_yellow_side[9];
	char r_white_side[9];
	char r_orange_side[9];
	char r_red_side[9];
	char r_blue_side[9];
	for (int i = 0; i < 9; i++)
	{
		r_yellow_side[i] = yellow_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_orange_side[i] = orange_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_white_side[i] = white_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_red_side[i] = red_side[i];
	}

	yellow_side[0] = r_orange_side[6];
	yellow_side[1] = r_orange_side[3];
	yellow_side[2] = r_orange_side[0];

	red_side[2] = r_yellow_side[0];
	red_side[5] = r_yellow_side[1];
	red_side[8] = r_yellow_side[2];

	white_side[6] = r_red_side[8];
	white_side[7] = r_red_side[5];
	white_side[8] = r_red_side[2];

	orange_side[0] = r_white_side[6];
	orange_side[3] = r_white_side[7];
	orange_side[6] = r_white_side[8];

	for (int x = 0; x < 9; x++)
	{
		r_blue_side[x] = blue_side[x];
	}

	blue_side[0] = r_blue_side[6];
	blue_side[1] = r_blue_side[3];
	blue_side[2] = r_blue_side[0];
	blue_side[3] = r_blue_side[7];
	blue_side[4] = r_blue_side[4];
	blue_side[5] = r_blue_side[1];
	blue_side[6] = r_blue_side[8];
	blue_side[7] = r_blue_side[5];
	blue_side[8] = r_blue_side[2];
	cubes.push_back(toCube());
}
void up_inverted()
{
	printf("U, ");
    moves.push_back("U");

	// Cube simulation
	char r_yellow_side[9];
	char r_white_side[9];
	char r_orange_side[9];
	char r_red_side[9];
	char r_blue_side[9];
	for (int i = 0; i < 9; i++)
	{
		r_yellow_side[i] = yellow_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_orange_side[i] = orange_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_white_side[i] = white_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_red_side[i] = red_side[i];
	}

	orange_side[6] = r_yellow_side[0];
	orange_side[3] = r_yellow_side[1];
	orange_side[0] = r_yellow_side[2];

	yellow_side[0] = r_red_side[2];
	yellow_side[1] = r_red_side[5];
	yellow_side[2] = r_red_side[8];

	red_side[2] = r_white_side[8];
	red_side[5] = r_white_side[7];
	red_side[8] = r_white_side[6];

	white_side[8] = r_orange_side[6];
	white_side[7] = r_orange_side[3];
	white_side[6] = r_orange_side[0];

	for (int x = 0; x < 9; x++)
	{
		r_blue_side[x] = blue_side[x];
	}

	blue_side[0] = r_blue_side[2];
	blue_side[1] = r_blue_side[5];
	blue_side[2] = r_blue_side[8];
	blue_side[3] = r_blue_side[1];
	blue_side[4] = r_blue_side[4];
	blue_side[5] = r_blue_side[7];
	blue_side[6] = r_blue_side[0];
	blue_side[7] = r_blue_side[3];
	blue_side[8] = r_blue_side[6];
	cubes.push_back(toCube());
}
void front()
{
	printf("F, ");
    moves.push_back("F");



	// Cube simulation
	char r_blue_side[9];
	char r_orange_side[9];
	char r_green_side[9];
	char r_red_side[9];
	char r_yellow_side[9];
	for (int i = 0; i < 9; i++)
	{
		r_blue_side[i] = blue_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_orange_side[i] = orange_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_green_side[i] = green_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_red_side[i] = red_side[i];
	}

	blue_side[6] = r_red_side[6];
	blue_side[7] = r_red_side[7];
	blue_side[8] = r_red_side[8];

	red_side[6] = r_green_side[6];
	red_side[7] = r_green_side[7];
	red_side[8] = r_green_side[8];

	green_side[6] = r_orange_side[6];
	green_side[7] = r_orange_side[7];
	green_side[8] = r_orange_side[8];

	orange_side[6] = r_blue_side[6];
	orange_side[7] = r_blue_side[7];
	orange_side[8] = r_blue_side[8];


	for (int x = 0; x < 9; x++)
	{
		r_yellow_side[x] = yellow_side[x];
	}

	yellow_side[0] = r_yellow_side[6];
	yellow_side[1] = r_yellow_side[3];
	yellow_side[2] = r_yellow_side[0];
	yellow_side[3] = r_yellow_side[7];
	yellow_side[4] = r_yellow_side[4];
	yellow_side[5] = r_yellow_side[1];
	yellow_side[6] = r_yellow_side[8];
	yellow_side[7] = r_yellow_side[5];
	yellow_side[8] = r_yellow_side[2];
	cubes.push_back(toCube());
}
void front_inverted()
{
	printf("F', ");
    moves.push_back("F'");



	// Cube simulation
	char r_blue_side[9];
	char r_orange_side[9];
	char r_green_side[9];
	char r_red_side[9];
	char r_yellow_side[9];
	for (int i = 0; i < 9; i++)
	{
		r_blue_side[i] = blue_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_orange_side[i] = orange_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_green_side[i] = green_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_red_side[i] = red_side[i];
	}

	blue_side[6] = r_orange_side[6];
	blue_side[7] = r_orange_side[7];
	blue_side[8] = r_orange_side[8];

	red_side[6] = r_blue_side[6];
	red_side[7] = r_blue_side[7];
	red_side[8] = r_blue_side[8];

	green_side[6] = r_red_side[6];
	green_side[7] = r_red_side[7];
	green_side[8] = r_red_side[8];

	orange_side[6] = r_green_side[6];
	orange_side[7] = r_green_side[7];
	orange_side[8] = r_green_side[8];

	for (int x = 0; x < 9; x++)
	{
		r_yellow_side[x] = yellow_side[x];
	}

	yellow_side[0] = r_yellow_side[2];
	yellow_side[1] = r_yellow_side[5];
	yellow_side[2] = r_yellow_side[8];
	yellow_side[3] = r_yellow_side[1];
	yellow_side[4] = r_yellow_side[4];
	yellow_side[5] = r_yellow_side[7];
	yellow_side[6] = r_yellow_side[0];
	yellow_side[7] = r_yellow_side[3];
	yellow_side[8] = r_yellow_side[6];
	cubes.push_back(toCube());
}
void back()
{
	printf("B, ");
    moves.push_back("B");


	// Cube simulation
	char r_blue_side[9];
	char r_orange_side[9];
	char r_green_side[9];
	char r_red_side[9];
	char r_white_side[9];
	for (int i = 0; i < 9; i++)
	{
		r_blue_side[i] = blue_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_orange_side[i] = orange_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_green_side[i] = green_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_red_side[i] = red_side[i];
	}

	blue_side[0] = r_orange_side[0];
	blue_side[1] = r_orange_side[1];
	blue_side[2] = r_orange_side[2];

	red_side[0] = r_blue_side[0];
	red_side[1] = r_blue_side[1];
	red_side[2] = r_blue_side[2];

	green_side[0] = r_red_side[0];
	green_side[1] = r_red_side[1];
	green_side[2] = r_red_side[2];

	orange_side[0] = r_green_side[0];
	orange_side[1] = r_green_side[1];
	orange_side[2] = r_green_side[2];

	for (int x = 0; x < 9; x++)
	{
		r_white_side[x] = white_side[x];
	}

	white_side[0] = r_white_side[6];
	white_side[1] = r_white_side[3];
	white_side[2] = r_white_side[0];
	white_side[3] = r_white_side[7];
	white_side[4] = r_white_side[4];
	white_side[5] = r_white_side[1];
	white_side[6] = r_white_side[8];
	white_side[7] = r_white_side[5];
	white_side[8] = r_white_side[2];
	cubes.push_back(toCube());
}
void back_inverted()
{
	printf("B', ");
    moves.push_back("B'");



	// Cube simulation
	char r_blue_side[9];
	char r_orange_side[9];
	char r_green_side[9];
	char r_red_side[9];
	char r_white_side[9];
	for (int i = 0; i < 9; i++)
	{
		r_blue_side[i] = blue_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_orange_side[i] = orange_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_green_side[i] = green_side[i];
	}
	for (int i = 0; i < 9; i++)
	{
		r_red_side[i] = red_side[i];
	}

	blue_side[0] = r_red_side[0];
	blue_side[1] = r_red_side[1];
	blue_side[2] = r_red_side[2];

	red_side[0] = r_green_side[0];
	red_side[1] = r_green_side[1];
	red_side[2] = r_green_side[2];

	green_side[0] = r_orange_side[0];
	green_side[1] = r_orange_side[1];
	green_side[2] = r_orange_side[2];

	orange_side[0] = r_blue_side[0];
	orange_side[1] = r_blue_side[1];
	orange_side[2] = r_blue_side[2];

	for (int x = 0; x < 9; x++)
	{
		r_white_side[x] = white_side[x];
	}

	white_side[0] = r_white_side[2];
	white_side[1] = r_white_side[5];
	white_side[2] = r_white_side[8];
	white_side[3] = r_white_side[1];
	white_side[4] = r_white_side[4];
	white_side[5] = r_white_side[7];
	white_side[6] = r_white_side[0];
	white_side[7] = r_white_side[3];
	white_side[8] = r_white_side[6];
	cubes.push_back(toCube());
}


void scramble() // random 25 moves
{
	//printf("\n Scramble: ");
	int move;
	for (int j = 0; j < 25; j++)
	{
		/*move = rand() % 12 + 1;
		//Serial.println(move);
		switch (move)
		{
		case 1:
		right();
		break;
		case 2:
		right_inverted();
		break;
		case 3:
		left();
		break;
		case 4:
		left_inverted();
		break;
		case 5:
		up();
		break;
		case 6:
		up_inverted();
		break;
		case 7:
		down();
		break;
		case 8:
		down_inverted();
		break;
		case 9:
		front();
		break;
		case 10:
		front_inverted();
		break;
		case 11:
		back();
		break;
		case 12:
		back_inverted();
		break;
		}*/
	}

}

void print_cube(char cube_side[])
{
	// make a for loop for this
	for (int i = 0; i < 1; i++){
		printf("\r");
	}
	printf("Face: ");
	printf("%c\n", cube_side[4]);
	for (int i = 0; i < 9; i = i + 3)
	{
		printf("|");
		printf("%c", cube_side[i]);
		printf("|");
		printf("%c", cube_side[i + 1]);
		printf("|");
		printf("%c", cube_side[i + 2]);
		printf("|\n");
	}
	printf("\n\n");
}


void print_whole_cube()
{
	printf("\n");
	print_cube(yellow_side);
	printf("\n");
	print_cube(white_side);
	printf("\n");
	print_cube(blue_side);
	printf("\n");
	print_cube(red_side);
	printf("\n");
	print_cube(green_side);
	printf("\n");
	print_cube(orange_side);
}

int solve_stage = 1;


void flip_cube(char cube_rotation)	// flips the cube on the F or U axis
{
	switch (cube_rotation)
	{
		char r_blue_side[9];
		char r_orange_side[9];
		char r_green_side[9];
		char r_red_side[9];
		char r_white_side[9];
		char r_yellow_side[9];
	case 'F': // CW on F
		printf("[Cube Flip: CW on F], ");
        moves.push_back("[Cube Flip: CW on F]");


		// cube simulation
		for (int i = 0; i < 9; i++)
		{
			r_blue_side[i] = blue_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			r_orange_side[i] = orange_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			r_green_side[i] = green_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			r_red_side[i] = red_side[i];
		}

		for (int x = 0; x < 9; x++)
		{
			r_white_side[x] = white_side[x];
		}
		for (int x = 0; x < 9; x++)
		{
			r_yellow_side[x] = yellow_side[x];
		}

		// assign copies to real faces
		for (int i = 0; i < 9; i++)
		{
			orange_side[i] = r_blue_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			green_side[i] = r_orange_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			red_side[i] = r_green_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			blue_side[i] = r_red_side[i];
		}

		white_side[0] = r_white_side[2];
		white_side[1] = r_white_side[5];
		white_side[2] = r_white_side[8];
		white_side[3] = r_white_side[1];
		white_side[4] = r_white_side[4];
		white_side[5] = r_white_side[7];
		white_side[6] = r_white_side[0];
		white_side[7] = r_white_side[3];
		white_side[8] = r_white_side[6];

		yellow_side[0] = r_yellow_side[6];
		yellow_side[1] = r_yellow_side[3];
		yellow_side[2] = r_yellow_side[0];
		yellow_side[3] = r_yellow_side[7];
		yellow_side[4] = r_yellow_side[4];
		yellow_side[5] = r_yellow_side[1];
		yellow_side[6] = r_yellow_side[8];
		yellow_side[7] = r_yellow_side[5];
		yellow_side[8] = r_yellow_side[2];
		cubes.push_back(toCube());
		break;
	case 'f': // CCW on F
		printf("[Cube Flip: CCW on F], ");
        moves.push_back("[Cube Flip: CCW on F]");

		// assign colors to a copy of the face
		for (int i = 0; i < 9; i++)
		{
			r_blue_side[i] = blue_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			r_orange_side[i] = orange_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			r_green_side[i] = green_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			r_red_side[i] = red_side[i];
		}

		for (int x = 0; x < 9; x++)
		{
			r_white_side[x] = white_side[x];
		}
		for (int x = 0; x < 9; x++)
		{
			r_yellow_side[x] = yellow_side[x];
		}

		// assign copies to real faces
		for (int i = 0; i < 9; i++)
		{
			red_side[i] = r_blue_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			blue_side[i] = r_orange_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			orange_side[i] = r_green_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			green_side[i] = r_red_side[i];
		}

		yellow_side[0] = r_yellow_side[2];
		yellow_side[1] = r_yellow_side[5];
		yellow_side[2] = r_yellow_side[8];
		yellow_side[3] = r_yellow_side[1];
		yellow_side[4] = r_yellow_side[4];
		yellow_side[5] = r_yellow_side[7];
		yellow_side[6] = r_yellow_side[0];
		yellow_side[7] = r_yellow_side[3];
		yellow_side[8] = r_yellow_side[6];

		white_side[0] = r_white_side[6];
		white_side[1] = r_white_side[3];
		white_side[2] = r_white_side[0];
		white_side[3] = r_white_side[7];
		white_side[4] = r_white_side[4];
		white_side[5] = r_white_side[1];
		white_side[6] = r_white_side[8];
		white_side[7] = r_white_side[5];
		white_side[8] = r_white_side[2];
        cubes.push_back(toCube());
		break;
	case 'U': // CW on U

		printf("[Cube Flip: CW on U], ");
        moves.push_back("[Cube Flip: CW on U]");


		for (int i = 0; i < 9; i++)
		{
			r_white_side[i] = white_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			r_orange_side[i] = orange_side[i];

		}
		for (int i = 0; i < 9; i++)
		{
			r_yellow_side[i] = yellow_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			r_red_side[i] = red_side[i];
		}

		for (int x = 0; x < 9; x++)
		{
			r_blue_side[x] = blue_side[x];
		}
		for (int x = 0; x < 9; x++)
		{
			r_green_side[x] = green_side[x];
		}

		orange_side[0] = r_white_side[8];
		orange_side[1] = r_white_side[7];
		orange_side[2] = r_white_side[6];
		orange_side[3] = r_white_side[5];
		orange_side[4] = r_white_side[4];
		orange_side[5] = r_white_side[3];
		orange_side[6] = r_white_side[2];
		orange_side[7] = r_white_side[1];
		orange_side[8] = r_white_side[0];


		yellow_side[0] = r_orange_side[6];
		yellow_side[1] = r_orange_side[3];
		yellow_side[2] = r_orange_side[0];
		yellow_side[3] = r_orange_side[7];
		yellow_side[4] = r_orange_side[4];
		yellow_side[5] = r_orange_side[1];
		yellow_side[6] = r_orange_side[8];
		yellow_side[7] = r_orange_side[5];
		yellow_side[8] = r_orange_side[2];

		white_side[8] = r_red_side[6];
		white_side[7] = r_red_side[3];
		white_side[6] = r_red_side[0];
		white_side[5] = r_red_side[7];
		white_side[4] = r_red_side[4];
		white_side[3] = r_red_side[1];
		white_side[2] = r_red_side[8];
		white_side[1] = r_red_side[5];
		white_side[0] = r_red_side[2];

		red_side[6] = r_yellow_side[0];
		red_side[3] = r_yellow_side[1];
		red_side[0] = r_yellow_side[2];
		red_side[7] = r_yellow_side[3];
		red_side[4] = r_yellow_side[4];
		red_side[1] = r_yellow_side[5];
		red_side[8] = r_yellow_side[6];
		red_side[5] = r_yellow_side[7];
		red_side[2] = r_yellow_side[8];

		green_side[0] = r_green_side[2];
		green_side[1] = r_green_side[5];
		green_side[2] = r_green_side[8];
		green_side[3] = r_green_side[1];
		green_side[4] = r_green_side[4];
		green_side[5] = r_green_side[7];
		green_side[6] = r_green_side[0];
		green_side[7] = r_green_side[3];
		green_side[8] = r_green_side[6];

		blue_side[0] = r_blue_side[6];
		blue_side[1] = r_blue_side[3];
		blue_side[2] = r_blue_side[0];
		blue_side[3] = r_blue_side[7];
		blue_side[4] = r_blue_side[4];
		blue_side[5] = r_blue_side[1];
		blue_side[6] = r_blue_side[8];
		blue_side[7] = r_blue_side[5];
		blue_side[8] = r_blue_side[2];
		cubes.push_back(toCube());
	case 'u':
		printf("[Cube Flip: CCW on U], ");
        moves.push_back("[Cube Flip: CCW on U]");

		for (int i = 0; i < 9; i++)
		{
			r_white_side[i] = white_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			r_orange_side[i] = orange_side[i];

		}
		for (int i = 0; i < 9; i++)
		{
			r_yellow_side[i] = yellow_side[i];
		}
		for (int i = 0; i < 9; i++)
		{
			r_red_side[i] = red_side[i];
		}

		for (int x = 0; x < 9; x++)
		{
			r_blue_side[x] = blue_side[x];
		}
		for (int x = 0; x < 9; x++)
		{
			r_green_side[x] = green_side[x];
		}

		red_side[6] = r_white_side[0];
		red_side[3] = r_white_side[1];
		red_side[0] = r_white_side[2];
		red_side[7] = r_white_side[3];
		red_side[4] = r_white_side[4];
		red_side[1] = r_white_side[5];
		red_side[8] = r_white_side[6];
		red_side[5] = r_white_side[7];
		red_side[2] = r_white_side[8];


		white_side[0] = r_orange_side[6];
		white_side[1] = r_orange_side[3];
		white_side[2] = r_orange_side[0];
		white_side[3] = r_orange_side[7];
		white_side[4] = r_orange_side[4];
		white_side[5] = r_orange_side[1];
		white_side[6] = r_orange_side[8];
		white_side[7] = r_orange_side[5];
		white_side[8] = r_orange_side[2];

		yellow_side[0] = r_red_side[6];
		yellow_side[1] = r_red_side[3];
		yellow_side[2] = r_red_side[0];
		yellow_side[3] = r_red_side[7];
		yellow_side[4] = r_red_side[4];
		yellow_side[5] = r_red_side[1];
		yellow_side[6] = r_red_side[8];
		yellow_side[7] = r_red_side[5];
		yellow_side[8] = r_red_side[2];

		orange_side[6] = r_yellow_side[0];
		orange_side[3] = r_yellow_side[1];
		orange_side[0] = r_yellow_side[2];
		orange_side[7] = r_yellow_side[3];
		orange_side[4] = r_yellow_side[4];
		orange_side[1] = r_yellow_side[5];
		orange_side[8] = r_yellow_side[6];
		orange_side[5] = r_yellow_side[7];
		orange_side[2] = r_yellow_side[8];

		blue_side[0] = r_blue_side[2];
		blue_side[1] = r_blue_side[5];
		blue_side[2] = r_blue_side[8];
		blue_side[3] = r_blue_side[1];
		blue_side[4] = r_blue_side[4];
		blue_side[5] = r_blue_side[7];
		blue_side[6] = r_blue_side[0];
		blue_side[7] = r_blue_side[3];
		blue_side[8] = r_blue_side[6];

		green_side[0] = green_side[6];
		green_side[1] = green_side[3];
		green_side[2] = green_side[0];
		green_side[3] = green_side[7];
		green_side[4] = green_side[4];
		green_side[5] = green_side[1];
		green_side[6] = green_side[8];
		green_side[7] = green_side[5];
		green_side[8] = green_side[2];
        cubes.push_back(toCube());
	default:
		printf("INVALID CUBE ROTATION: SEE < void flip_cube() >");
	}
}


///////////////////// Cube Algorithms ///////////////////////////
void fix_cross_instance_1() // bad pieces up and right
{

	printf("\n	Fix Cross Instance 1: ");

	// cube simulation
	sim_only = true;
	right();
	right();
	back();
	up();
	up();
	back_inverted();
	right();
	right();
	sim_only = false;
}
void fix_cross_instance_2() // bad pieces up and down
{
	printf("\n	Fix Cross Instance 2: ");
	// cube simulation
	sim_only = true;
	up();
	up();
	back();
	back();
	down();
	down();
	back();
	back();
	up();
	up();
	sim_only = false;
}
void fix_corners_instance_1() // top left
{
	printf("\n	Fix Corners Instance 1: ");

	// cube simulation
	sim_only = true;
	up();
	back();
	up_inverted();
	sim_only = false;
}
void fix_corners_instance_2() // top right
{
	printf("\n	Fix Corners Instance 2: ");

	// cube simulation
	sim_only = true;
	up_inverted();
	back_inverted();
	up();
	sim_only = false;
}
void fix_corners_instance_3()
{
	printf("\n	Fix Corners Instance 3 (bring yellow piece up): ");

	// cube simulation
	sim_only = true;
	left_inverted();
	back();
	left();
	sim_only = false;
}
void add_edges_instance_1() // 2 left
{
	printf("\n	Add Edges Instance 1: ");

	// cube simulation
	sim_only = true;
	back_inverted();
	left_inverted();
	back();
	left();
	back();
	up();
	back_inverted();
	up_inverted();
	sim_only = false;
}
void add_edges_instance_2() // 2 right
{
	printf("\n	Add edges Instance 2: ");
	// cube simulation
	sim_only = true;
	back();
	right();
	back_inverted();
	right_inverted();
	back_inverted();
	up_inverted();
	back();
	up();
	sim_only = false;
}
void add_edges_instance_3()
{
	printf("\n	Add edges Instance 3: ");

	// cube simulation
	sim_only = true;
	back_inverted();
	up_inverted();
	back();
	up();
	back();
	right();
	back_inverted();
	right_inverted();
	sim_only = false;
}
void white_cross_on_top()
{
	printf("\n	White Cross On Top: ");

	// cube simulation
	sim_only = true;
	right_inverted();
	back_inverted();
	up_inverted();
	back();
	up();
	right();
	sim_only = false;
}
void finish_white_face_instance_1()
{
	printf("\n	Finish White Face Instance 1: ");

	// cube simulation
	sim_only = true;
	right();
	back();
	right_inverted();
	back();
	right();
	back();
	back();
	right_inverted();
	sim_only = false;
}
void finish_white_face_instance_2()
{
	printf("\n	Finish White Face Instance 2: ");

	// cube simulation
	sim_only = true;
	left_inverted();
	back_inverted();
	left();
	back_inverted();
	left_inverted();
	back_inverted();
	back_inverted();
	left();
	sim_only = false;
}
// insert top layer corners
void green_on_right()
{
	printf("\n	Green On Right: ");
	// cube simulation
	sim_only = true;
	right_inverted();
	up();
	right_inverted();
	down();
	down();
	right();
	up_inverted();
	right_inverted();
	down();
	down();
	right();
	right();
	sim_only = false;
}
void green_on_left()
{
	printf("\n	Green On Left: ");
	// cube simulation
	sim_only = true;
	left();
	up_inverted();
	left();
	down_inverted();
	down_inverted();
	left_inverted();
	up();
	left();
	down_inverted();
	down_inverted();
	left_inverted();
	left_inverted();
	sim_only = false;
}
// insert top layer edges
void cw_rotation() // can also be used for 4 bad edges
{
	printf("\n	CW Rotation: ");
	finish_white_face_instance_1();
	flip_cube('f');// rotate cube: right side = front side
	finish_white_face_instance_2();
	flip_cube('F');// rotate cube back to original state: left side = front side
}
void ccw_rotation()
{
	printf("\n	CCW Rotation: ");
	finish_white_face_instance_2();
	flip_cube('F');// rotate cube: left side = front side
	finish_white_face_instance_1();
	flip_cube('f');
}



void cube_decide_cross()
{
	printf("\n ");
	printf(" ");
	printf("Cross: ");
	if (yellow_side[1] == 'y' &&
		yellow_side[3] == 'y' &&
		yellow_side[5] == 'y' &&
		yellow_side[7] == 'y')
	{
		solve_stage = 2;
		printf("Solved.");
		//test_ongoing = false;
	}
	///////////// move the pieces from the sides up /////////////// /// should turn this into a function later(blue_side, moves)
	else if (solve_stage == 1)
	{
		// move from blue_side[3]
		if (blue_side[3] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[3] != 'y')
				{
					left();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// move from blue_side[5]
		else if (blue_side[5] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[5] != 'y')
				{
					right_inverted();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// move from red_side[5]
		else if (red_side[5] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[1] != 'y')
				{
					up_inverted();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// move from red_side[3]
		else if (red_side[3] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[7] != 'y')
				{
					down();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// move from green_side[5]
		else if (green_side[5] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[3] != 'y')
				{
					left_inverted();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}

		// move from green_side[3]
		else if (green_side[3] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[5] != 'y')
				{
					right();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// move from orange_side[5]
		else if (orange_side[5] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[7] != 'y')
				{
					down_inverted();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// move from orange_side[3]
		else if (orange_side[3] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[1] != 'y')
				{
					up();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// move from white_side[1]
		else if (white_side[1] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[7] != 'y')
				{
					down();
					down();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// move from white_side[7]
		else if (white_side[7] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[1] != 'y')
				{
					up();
					up();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// move from white_side[3]
		else if (white_side[3] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[3] != 'y')
				{
					left();
					left();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// move from white_side[5]
		else if (white_side[5] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[5] != 'y')
				{
					right();
					right();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		/////////////////
		//////////////
		///////////////////////// get the piece from 2- move spots, like blue_side[7]
		// blue_side[1]
		else if (blue_side[1] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[1] != 'y')
				{
					up();
					front();
					right_inverted();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// blue_side[7]
		else if (blue_side[7] == 'y')
		{
			if (yellow_side[1] != 'y')
			{
				up_inverted();
				front();
				right_inverted();
			}
			else
			{
				up_inverted();
			}
		}
		// red_side[1]
		else if (red_side[1] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[3] != 'y')
				{
					left();
					front();
					up_inverted();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// red_side[7]
		else if (red_side[7] == 'y')
		{
			if (yellow_side[3] != 'y')
			{
				left_inverted();
				front();
				up_inverted();
			}
			else
			{
				left_inverted();
			}
		}
		// green_side[1]
		else if (green_side[1] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[7] != 'y')
				{
					down();
					front();
					left_inverted();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// green_side[7]
		else if (green_side[7] == 'y')
		{
			if (yellow_side[7] != 'y')
			{
				down();
				front_inverted();
				right();
			}
			else
			{
				down();
			}
		}
		// orange_side[1]
		else if (orange_side[1] == 'y')
		{
			for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
			{
				if (yellow_side[5] != 'y')
				{
					right();
					front();
					down_inverted();
					x = 3; // end loop since yellow piece has reached the top
				}
				else
				{
					front();
				}
			}
		}
		// green_side[7]
		else if (orange_side[7] == 'y')
		{
			if (yellow_side[5] != 'y')
			{
				right_inverted();
				front();
				down_inverted();
			}
			else
			{
				right_inverted();
			}
		}
	}
}
void cube_decide_whole_cross()
{
	printf("\n ");
	printf(" ");
	printf("Whole Cross: ");
	if (solve_stage == 2 &&
		blue_side[7] == 'b' &&
		red_side[7] == 'r' &&
		green_side[7] == 'g' &&
		orange_side[7] == 'o')
	{
		printf("Solved.");
		solve_stage = 3;
	}
	// green and orange are good
	else if (solve_stage == 2 && blue_side[7] != 'b' && red_side[7] != 'r' && green_side[7] == 'g' && orange_side[7] == 'o')
	{
		flip_cube('F');
		fix_cross_instance_1();
		flip_cube('f');
	}
	// red and orange are good
	else if (solve_stage == 2 && blue_side[7] != 'b' && red_side[7] == 'r' && green_side[7] != 'g' && orange_side[7] == 'o')
	{
		fix_cross_instance_2();
	}
	// red and green are good
	else if (solve_stage == 2 == true && blue_side[7] != 'b' && red_side[7] == 'r' && green_side[7] == 'g' && orange_side[7] != 'o')
	{
		fix_cross_instance_1();
	}
	// blue and orange are good
	else if (solve_stage == 2 && blue_side[7] == 'b' && red_side[7] != 'r' && green_side[7] != 'g' && orange_side[7] == 'o')
	{
		flip_cube('F');
		flip_cube('F');
		fix_cross_instance_1();
		flip_cube('f');
		flip_cube('f');
	}
	// blue and green are good
	else if (solve_stage == 2 && blue_side[7] == 'b' && red_side[7] != 'r' && green_side[7] == 'g' && orange_side[7] != 'o')
	{
		flip_cube('F');
		fix_cross_instance_2();
		flip_cube('f');
	}
	// red and blue are good
	else if (solve_stage == 2 && blue_side[7] == 'b' && red_side[7] == 'r' && green_side[7] != 'g' && orange_side[7] != 'o')
	{
		flip_cube('f');
		fix_cross_instance_1();
		flip_cube('F');
	}
	// none match, cross in done but whole cross isn't
	else if (solve_stage == 2)
	{
		front();
	}
	else
	{
		printf("Error in whole_cross");
	}
}
void cube_decide_corners() // needs fixing, maybe yellows at bottom portion
{
	printf("\n ");
	printf(" ");
	printf("Corners (First Layer): ");
	// First layer is done correctly
	if (solve_stage == 3 && yellow_side[0] == 'y' && blue_side[6] == 'b' && yellow_side[2] == 'y' && orange_side[6] == 'o' &&
		green_side[6] == 'g' && yellow_side[6] == 'y' && orange_side[6] == 'o' && yellow_side[8] == 'y' && red_side[6] == 'r')
	{
		printf("Solved.");
		solve_stage = 4;
	}
	else if (solve_stage == 3)
	{
		////////// if THERE ARE yellow on top
		if (blue_side[0] == 'y' || blue_side[2] == 'y' || red_side[0] == 'y' || red_side[2] == 'y' ||
			green_side[0] == 'y' || green_side[2] == 'y' || orange_side[0] == 'y' || orange_side[2] == 'y' ||
			white_side[0] == 'y' || white_side[2] == 'y' || white_side[6] == 'y' || white_side[8] == 'y')
		{
			////////// Do all possible cases for corner (4×3):
			//////// 3 cases for the blue/orange sides
			if (blue_side[2] == 'y' && white_side[8] == 'b' && orange_side[0] == 'o')
			{
				fix_corners_instance_2();
			}
			else if (blue_side[2] == 'o' && white_side[8] == 'y' && orange_side[0] == 'b')
			{
				fix_corners_instance_2();
				fix_corners_instance_2();
				back();
				fix_corners_instance_2();
			}
			else if (blue_side[2] == 'b' && white_side[8] == 'o' && orange_side[0] == 'y')
			{
				flip_cube('f');
				fix_corners_instance_1();
				flip_cube('F');
			}
			//////// 3 cases for the orange/green sides
			else if (orange_side[2] == 'y' && white_side[2] == 'o' && green_side[0] == 'g')
			{
				flip_cube('f');
				fix_corners_instance_2();
				flip_cube('F');
			}
			else if (orange_side[2] == 'g' && white_side[2] == 'y' && green_side[0] == 'o')
			{
				flip_cube('f');
				fix_corners_instance_2();
				fix_corners_instance_2();
				back();
				fix_corners_instance_2();
				flip_cube('F');
			}
			else if (orange_side[2] == 'o' && white_side[2] == 'g' && green_side[0] == 'y')
			{
				flip_cube('F');
				flip_cube('F');
				fix_corners_instance_1();
				flip_cube('f');
				flip_cube('f');
			}
			//////// 3 cases for the green/red sides
			else if (green_side[2] == 'y' && white_side[0] == 'g' && red_side[0] == 'r')
			{
				flip_cube('F');
				flip_cube('F');
				fix_corners_instance_2();
				flip_cube('f');
				flip_cube('f');
			}
			else if (green_side[2] == 'r' && white_side[0] == 'y' && red_side[0] == 'g')
			{
				flip_cube('F');
				flip_cube('F');
				fix_corners_instance_2();
				fix_corners_instance_2();
				back();
				fix_corners_instance_2();
				flip_cube('f');
				flip_cube('f');
			}
			else if (green_side[2] == 'g' && white_side[0] == 'r' && red_side[0] == 'y')
			{
				flip_cube('F');
				fix_corners_instance_1();
				flip_cube('f');
			}
			//////// 3 cases for the red/blue sides
			else if (red_side[2] == 'y' && white_side[6] == 'r' && blue_side[0] == 'b')
			{
				flip_cube('F');
				fix_corners_instance_2();
				flip_cube('f');
			}
			else if (red_side[2] == 'b' && white_side[6] == 'y' && blue_side[0] == 'r')
			{
				fix_corners_instance_1();
				fix_corners_instance_1();
				back_inverted();
				fix_corners_instance_1();
			}
			else if (red_side[2] == 'r' && white_side[6] == 'b' && blue_side[0] == 'y')
			{
				fix_corners_instance_1();
			}
			else
			{
				back();  // move yellow on top of correct position
			}
		}
		////////// if there are NO yellows on top and first layer isn't solved already
		else if (yellow_side[0] != 'y' || red_side[8] != 'r' || blue_side[6] != 'b' ||
			yellow_side[2] != 'y' || orange_side[6] != 'o' || blue_side[8] != 'b' ||
			yellow_side[8] != 'y' || orange_side[8] != 'o' || green_side[6] != 'g' ||
			yellow_side[6] != 'y' || red_side[6] != 'r' || blue_side[8] != 'g')
		{
			//////////// Bring all yellow corners up:
			// Blue and red corner
			if (yellow_side[0] != 'y' || red_side[8] != 'r' || blue_side[6] != 'b')
			{
				fix_corners_instance_3();
			}
			// blue and orange corner
			else if (yellow_side[2] != 'y' || orange_side[6] != 'o' || blue_side[8] != 'b')
			{
				flip_cube('f');
				fix_corners_instance_3();
				flip_cube('F');
			}
			// Orange and green corner
			else if (yellow_side[8] != 'y' || orange_side[8] != 'o' || green_side[6] != 'g')
			{
				flip_cube('f');
				flip_cube('f');
				fix_corners_instance_3();
				flip_cube('F');
				flip_cube('F');
			}
			// Green and red corner
			else if (yellow_side[6] != 'y' || red_side[6] != 'r' || blue_side[8] != 'g')
			{
				flip_cube('F');
				fix_corners_instance_3();
				flip_cube('f');
			}
		}

		else
		{
			printf("First Layer not Solved.");
		}
	}
}
void cube_decide_add_edges()
{
	printf("\n ");
	printf(" ");
	printf("Edges (Second Layer): ");
	///// Second layer done
	if (solve_stage == 4 &&
		green_side[3] == 'g' && green_side[5] == 'g' &&
		red_side[3] == 'r' && red_side[5] == 'r' &&
		blue_side[3] == 'b' && blue_side[5] == 'b' &&
		orange_side[3] == 'o' && orange_side[5] == 'o')
	{
		printf("Solved.");
		solve_stage = 5;
	}
	else if (solve_stage == 4)
	{
		///// red3 --> 2blue
		if (red_side[1] == 'r' && white_side[3] == 'b')
		{
			flip_cube('F');
			add_edges_instance_2();	// two right
			flip_cube('f');
		}
		///// red2 --> 3blue
		else if (blue_side[1] == 'b' && white_side[7] == 'r')
		{

			add_edges_instance_1();	// two left
		}

		//// blue3 --> orange
		else if (blue_side[1] == 'b' && white_side[7] == 'o')
		{
			add_edges_instance_2();	// two right
		}
		//// blue --> 3orange
		else if (orange_side[1] == 'o' && white_side[5] == 'b')
		{
			flip_cube('f');
			add_edges_instance_1();	// two left
			flip_cube('F');
		}
		//// orange3 --> green
		else if (orange_side[1] == 'o' && white_side[5] == 'g')
		{
			flip_cube('f');
			add_edges_instance_2();	// two right
			flip_cube('F');
		}
		//// orange --> 3green
		else if (green_side[1] == 'g' && white_side[1] == 'o')
		{
			flip_cube('F');
			flip_cube('F');
			add_edges_instance_1();	// two left
			flip_cube('f');
			flip_cube('f');
		}

		//// green3 --> red
		else if (green_side[1] == 'g' && white_side[1] == 'r')
		{
			flip_cube('F');
			flip_cube('F');
			add_edges_instance_2();	// two right
			flip_cube('f');
			flip_cube('f');
		}
		//// green --> 3red
		else if (red_side[1] == 'r' && white_side[3] == 'g')
		{
			flip_cube('F');
			add_edges_instance_1();	// two left
			flip_cube('f');
		}
		//// // rotate top layer to match any missing colors
		else if (blue_side[3] == 'w' || blue_side[5] == 'w' || red_side[3] == 'w' || red_side[5] == 'w' ||
			green_side[3] == 'w' || green_side[5] == 'w' || orange_side[3] == 'w' || orange_side[5] == 'w')
		{
			back();
		}

		///// bring incorrectly placed edges to the top again
		else if (blue_side[3] != 'b' || red_side[5] != 'r' ||
			red_side[3] != 'r' || green_side[5] != 'g' ||
			green_side[3] != 'g' || orange_side[5] != 'o' ||
			orange_side[3] != 'o' || blue_side[5] != 'b')
		{
			if (blue_side[3] != 'b' || red_side[5] != 'r')
			{
				flip_cube('F');
				add_edges_instance_3();
				flip_cube('f');
			}
			else if (red_side[3] != 'r' || green_side[5] != 'g')
			{
				flip_cube('F');
				flip_cube('F');
				add_edges_instance_3();
				flip_cube('f');
				flip_cube('f');
			}
			else if (green_side[3] != 'g' || orange_side[5] != 'o')
			{
				flip_cube('f');
				add_edges_instance_3();
				flip_cube('F');
			}
			else if (orange_side[3] != 'o' || blue_side[5] != 'b')
			{
				add_edges_instance_3();
			}
		}
		else
		{
			printf("second layer not solved.");
		}
	}
}
void cube_decide_white_cross() // looking for two whites, may be more efficient, but current revision get the job done
{
	printf("\n ");
	printf(" ");
	printf("White Cross: ");
	if (solve_stage == 5 &&
		white_side[1] == 'w' &&
		white_side[3] == 'w' &&
		white_side[5] == 'w' &&
		white_side[7] == 'w')
	{
		printf("Solved.");
		solve_stage = 6;
	}
	else if (blue_side[1] == 'w' || red_side[1] == 'w' || green_side[1] == 'w' || orange_side[1] == 'w')
	{
		/// whties in connecting faces
		if (blue_side[1] == 'w' && orange_side[1] == 'w')
		{
			white_cross_on_top();
		}
		else if (orange_side[1] == 'w' && green_side[1] == 'w')
		{
			back();
			white_cross_on_top();
		}
		else if (green_side[1] == 'w' && red_side[1] == 'w')
		{
			back();
			back();
			white_cross_on_top();
		}
		else if (red_side[1] == 'w' && blue_side[1] == 'w')
		{
			back_inverted();
			white_cross_on_top();
		}
		/// whites not on connecting face
		else if (blue_side[1] == 'w')
		{
			white_cross_on_top();
		}
		else if (green_side[1] == 'w')
		{
			back();
			back();
			white_cross_on_top();
		}
		else if (red_side[1] == 'w')
		{
			back_inverted();
			white_cross_on_top();
		}
		else if (orange_side[1] == 'w')
		{
			back();
			white_cross_on_top();
		}
		else
		{
			printf("No white cross");
		}
	}
}
void cube_decide_white_top()
{
	printf("\n ");
	printf(" ");
	printf("White Face: ");
	if (white_side[0] == 'w' &&
		white_side[2] == 'w' &&
		white_side[6] == 'w' &&
		white_side[8] == 'w')
	{
		printf("Solved.");
		solve_stage = 7;
	}
	else if (solve_stage == 6)
	{
		/////////////////////////////////// sune cases
		if (white_side[0] != 'w' && white_side[2] != 'w' && white_side[6] != 'w' && white_side[8] == 'w' ||
			white_side[0] != 'w' && white_side[2] != 'w' && white_side[6] == 'w' && white_side[8] != 'w' ||
			white_side[0] == 'w' && white_side[2] != 'w' && white_side[6] != 'w' && white_side[8] != 'w' ||
			white_side[0] != 'w' && white_side[2] == 'w' && white_side[6] != 'w' && white_side[8] != 'w')
		{
			// Any sune orientation is true
			/////////////////// left sune cases:
			if (white_side[0] != 'w' && white_side[2] != 'w' && white_side[6] != 'w' && white_side[8] == 'w' && red_side[0] == 'w' && blue_side[0] == 'w')
			{
				finish_white_face_instance_2();	// left sune
			}
			else if (white_side[0] != 'w' && white_side[2] == 'w' && white_side[6] != 'w' && white_side[8] != 'w' && blue_side[0] == 'w' && orange_side[0] == 'w')
			{
				back();
				finish_white_face_instance_2(); // left sune
			}
			else if (white_side[0] == 'w' && white_side[2] != 'w' && white_side[6] != 'w' && white_side[8] != 'w' && orange_side[0] == 'w' && green_side[0] == 'w')
			{
				back();
				back();
				finish_white_face_instance_2(); // left sune
			}
			else if (white_side[0] != 'w' && white_side[2] != 'w' && white_side[6] == 'w' && white_side[8] != 'w' && green_side[0] == 'w' && red_side[0] == 'w')
			{
				back_inverted();
				finish_white_face_instance_2(); // left sune
			}
			////////////////// right sune cases:
			else if (white_side[0] != 'w' && white_side[2] != 'w' && white_side[6] == 'w' && white_side[8] != 'w' && orange_side[2] == 'w' && blue_side[2] == 'w')
			{
				finish_white_face_instance_1(); // right sune
			}
			else if (white_side[0] == 'w' && white_side[2] != 'w' && white_side[6] != 'w' && white_side[8] != 'w' && blue_side[2] == 'w' && red_side[2] == 'w')
			{
				back_inverted();
				finish_white_face_instance_1(); // right sune
			}
			else if (white_side[0] != 'w' && white_side[2] == 'w' && white_side[6] != 'w' && white_side[8] != 'w' && red_side[2] == 'w' && green_side[2] == 'w')
			{
				back();
				back();
				finish_white_face_instance_1(); // right sune
			}
			else if (white_side[0] != 'w' && white_side[2] != 'w' && white_side[6] != 'w' && white_side[8] == 'w' && orange_side[2] == 'w' && green_side[2] == 'w')
			{
				back();
				finish_white_face_instance_1(); // right sune
			}
			else
			{
				printf("We are sune-less!");
			}
		}
		/// blinker or car
		else if (white_side[0] != 'w' && white_side[2] != 'w' && white_side[6] != 'w' && white_side[8] != 'w')
		{
			// car
			if (red_side[0] == 'w' && red_side[2] == 'w' && orange_side[0] == 'w' && orange_side[2] == 'w')
			{
				finish_white_face_instance_1();
			}
			else if (blue_side[0] == 'w' && blue_side[2] == 'w' && green_side[0] == 'w' && green_side[2] == 'w')
			{
				back();
				finish_white_face_instance_1();
			}
			// blinker
			if (red_side[0] == 'w' && red_side[2] == 'w' && blue_side[2] == 'w' && green_side[0] == 'w')
			{
				finish_white_face_instance_1();
			}
			else if (blue_side[0] == 'w' && blue_side[2] == 'w' && red_side[0] == 'w' && orange_side[2] == 'w')
			{
				back();
				finish_white_face_instance_1();
			}
			else if (orange_side[0] == 'w' && orange_side[2] == 'w' && blue_side[0] == 'w' && green_side[2] == 'w')
			{
				finish_white_face_instance_2();
			}
			else if (green_side[0] == 'w' && green_side[2] == 'w' && orange_side[0] == 'w' && red_side[2] == 'w')
			{
				back_inverted();
				finish_white_face_instance_1();
			}
		}
		//////// bowtie
		if (white_side[0] == 'w' && white_side[2] != 'w' && white_side[6] != 'w' && white_side[8] == 'w' ||
			white_side[0] != 'w' && white_side[2] == 'w' && white_side[6] == 'w' && white_side[8] != 'w')
		{
			if (blue_side[0] == 'w' && orange_side[2] == 'w')
			{
				finish_white_face_instance_1();
			}
			else if (red_side[0] == 'w' && blue_side[2] == 'w')
			{
				back_inverted();
				finish_white_face_instance_1();
			}
			if (green_side[0] == 'w' && red_side[2] == 'w')
			{
				back_inverted();
				back_inverted();
				finish_white_face_instance_1();
			}
			if (orange_side[0] == 'w' && green_side[2] == 'w')
			{
				back();
				finish_white_face_instance_1();
			}
		}
		/////// chameleon
		if (white_side[0] != 'w' && white_side[2] == 'w' && white_side[6] != 'w' && white_side[8] == 'w' ||
			white_side[0] != 'w' && white_side[2] != 'w' && white_side[6] == 'w' && white_side[8] == 'w' ||
			white_side[0] == 'w' && white_side[2] != 'w' && white_side[6] == 'w' && white_side[8] != 'w' ||
			white_side[0] == 'w' && white_side[2] == 'w' && white_side[6] != 'w' && white_side[8] != 'w')
		{
			if (white_side[0] == 'w' && white_side[2] == 'w' && white_side[6] != 'w' && white_side[8] != 'w')
			{
				finish_white_face_instance_1();
			}
			else if (white_side[0] != 'w' && white_side[2] != 'w' && white_side[6] == 'w' && white_side[8] == 'w')
			{
				back();
				back();
				finish_white_face_instance_1();
			}
			else if (white_side[0] != 'w' && white_side[2] == 'w' && white_side[6] != 'w' && white_side[8] == 'w')
			{
				back_inverted();
				finish_white_face_instance_1();
			}
			else if (white_side[0] == 'w' && white_side[2] != 'w' && white_side[6] == 'w' && white_side[8] != 'w')
			{
				back();
				finish_white_face_instance_1();
			}
		}
	}
}
void cube_decide_oll()
{
	printf("\n ");
	printf(" ");
	printf("OLL: ");
	//
	if (green_side[0] == 'o' && green_side[2] == 'o' && red_side[0] == 'g' && red_side[2] == 'g' &&
		blue_side[0] == 'r' && blue_side[2] == 'r' && orange_side[0] == 'b' && orange_side[2] == 'b')
	{
		back();
	}
	else if (green_side[0] == 'b' && green_side[2] == 'b' && red_side[0] == 'o' && red_side[2] == 'o' &&
		blue_side[0] == 'g' && blue_side[2] == 'g' && orange_side[0] == 'r' && orange_side[2] == 'r')
	{
		back();
		back();
	}
	else if (green_side[0] == 'r' && green_side[2] == 'r' && red_side[0] == 'b' && red_side[2] == 'b' &&
		blue_side[0] == 'o' && blue_side[2] == 'o' && orange_side[0] == 'g' && orange_side[2] == 'g')
	{
		back_inverted();
	}

	if (green_side[0] == 'g' && green_side[2] == 'g' && red_side[0] == 'r' && red_side[2] == 'r' &&
		blue_side[0] == 'b' && blue_side[2] == 'b' && orange_side[0] == 'o' && orange_side[2] == 'o')
	{
		printf("Solved.");
		solve_stage = 8;
	}

	else if (solve_stage == 7)
	{
		// green on right cases
		if (blue_side[0] == 'b' && blue_side[2] == 'g' && orange_side[2] == 'b')
		{
			green_on_right();
		}
		else if (red_side[0] == 'b' && red_side[2] == 'g' && blue_side[2] == 'b')
		{
			back_inverted();
			green_on_right();
		}
		else if (green_side[0] == 'b' && green_side[2] == 'g' && red_side[2] == 'b')
		{
			back();
			back();
			green_on_right();
		}
		else if (orange_side[0] == 'b' && orange_side[2] == 'g' && green_side[2] == 'b')
		{
			back();
			green_on_right();
		}

		// green on left cases
		else if (blue_side[0] == 'g' && blue_side[2] == 'b' && red_side[0] == 'b')
		{
			green_on_left();
		}
		else if (red_side[0] == 'g' && red_side[2] == 'b' && green_side[0] == 'b')
		{
			back_inverted();
			green_on_left();
		}
		else if (green_side[0] == 'g' && green_side[2] == 'b' && orange_side[0] == 'b')
		{
			back();
			back();
			green_on_left();
		}
		else if (orange_side[0] == 'g' && orange_side[2] == 'b' && blue_side[0] == 'b')
		{
			back();
			green_on_left();
		}
		// last resort, 2 steps to reach PLL are needed
		// green on right
		else
		{
			printf("last resort");
			if (blue_side[2] == 'g')
			{
				green_on_right();
			}
			else if (orange_side[2] == 'g')
			{
				back();
				green_on_right();
			}
			else if (green_side[2] == 'g')
			{
				back();
				back();
				green_on_right();
			}
			else if (red_side[2] == 'g')
			{
				back_inverted();
				green_on_right();
			}
			// green on left
			else if (blue_side[0] == 'g')
			{
				green_on_left();
			}
			else if (orange_side[0] == 'g')
			{
				back();
				green_on_left();
			}
			else if (green_side[0] == 'g')
			{
				back();
				back();
				green_on_left();
			}
			else if (red_side[0] == 'g')
			{
				back_inverted();
				green_on_left();
			}
		}
	}

}
void cube_decide_pll()
{
	printf("\n ");
	printf(" ");
	printf("PLL: ");
	///////////////////////////////////
	if (blue_side[1] == 'b' && red_side[1] == 'r' && green_side[1] == 'g' && orange_side[1] == 'o')
	{
		printf("Solved.");
		solve_stage = 9;
	}
	else if (solve_stage == 8)
	{
		printf("inside");
		// counter clockwise rotation cases
		if (red_side[1] == 'b' && blue_side[1] == 'o' && orange_side[1] == 'r')
		{
			ccw_rotation();
		}
		else if (green_side[1] == 'r' && red_side[1] == 'b' && blue_side[1] == 'g')
		{
			flip_cube('F');
			ccw_rotation();
			flip_cube('f');
		}
		else if (orange_side[1] == 'g' && green_side[1] == 'r' && red_side[1] == 'o')
		{
			flip_cube('F');
			flip_cube('F');
			ccw_rotation();
			flip_cube('F');
			flip_cube('F');
		}
		else if (blue_side[1] == 'o' && orange_side[1] == 'g' && green_side[1] == 'b')
		{
			flip_cube('f');
			ccw_rotation();
			flip_cube('F');
		}

		// clockwise rotation cases
		else if (red_side[1] == 'o' && blue_side[1] == 'r' && orange_side[1] == 'b')
		{
			cw_rotation();
		}
		else if (green_side[1] == 'b' && red_side[1] == 'g' && blue_side[1] == 'r')
		{
			flip_cube('F');
			cw_rotation();
			flip_cube('f');
		}
		else if (orange_side[1] == 'r' && green_side[1] == 'o' && red_side[1] == 'g')
		{
			flip_cube('F');
			flip_cube('F');
			cw_rotation();
			flip_cube('F');
			flip_cube('F');
		}
		else if (blue_side[1] == 'g' && orange_side[1] == 'b' && green_side[1] == 'o')
		{
			flip_cube('f');
			cw_rotation();
			flip_cube('F');
		}
		// all four edges are bad
		else if (blue_side[1] != 'b' && red_side[1] != 'r' && green_side[1] != 'g' && orange_side[1] != 'o')
		{
			cw_rotation();
		}
		else	// there is a problem here
		{
			printf("Problem in Pll (else statement reached)");
		}
	}
	else
	{
		printf("Error in pll_case_check()");
	}
}
void cube_decide_solved()
{
	printf(" ");
	printf("\n ");

	// check if all sides have the correct color
	for (int i = 0; i < 9; i++)
	{
		if (yellow_side[i] != 'y')
		{
			cube_solved = false;
		}
		if (white_side[i] != 'w')
		{
			cube_solved = false;
		}
		if (blue_side[i] != 'b')
		{
			cube_solved = false;
		}
		if (red_side[i] != 'r')
		{
			cube_solved = false;
		}
		if (green_side[i] != 'g')
		{
			cube_solved = false;
		}
		if (orange_side[i] != 'o')
		{
			cube_solved = false;
		}
	}
	if (cube_solved == true)
	{
		printf("The Whole Cube is solved!!!");
	//	getchar();
	}
	else
	{
		printf("There is a problem: the cube isn't solved!");
		cube_solved = false;
	}
	//print_whole_cube();
	solve_stage = 10;
}




void cube_decide()
{
	switch (solve_stage)
	{
	case 1:
		// Cross
		cube_decide_cross();
		break;
	case 2:
		// Whole Cross
		cube_decide_whole_cross();
		break;
	case 3:
		// First layer (corners)
		cube_decide_corners();

		break;
	case 4:
		// Second Layer
		cube_decide_add_edges();
		break;
	case 5:
		// White Cross
		cube_decide_white_cross();
		break;
	case 6:
		// White Top
		cube_decide_white_top();
		break;
	case 7:
		// Orientation of the Last Layer
		cube_decide_oll();
		break;
	case 8:
		// Permute the Last Layer
		cube_decide_pll();
		break;
	case 9:
		cube_decide_solved();
		break;
	}

}

void auto_test(Cube cube){
   	for (int i = 0; i < numberOfWalls; i++){
                switch (i){
                case WHITE:
                     for (int j = 0;j < numberOfCells;j++){
                        Color wallColor = cube.getWall(i).getColor(j);
                        input(j, white_side, wallColor);
                     }
                break;
                case YELLOW:
                     for (int j = 0;j < numberOfCells;j++){
                        Color wallColor = cube.getWall(i).getColor(j);
                        input(j, yellow_side, wallColor);
                     }
                break;
                case ORANGE:
                     for (int j = 0;j < numberOfCells;j++){
                        Color wallColor = cube.getWall(i).getColor(j);
                        input(j, orange_side, wallColor);
                     }
                break;
                case GREEN:
                     for (int j = 0;j < numberOfCells;j++){
                        Color wallColor = cube.getWall(i).getColor(j);
                        input(j, green_side, wallColor);
                     }
                break;
                case RED:
                     for (int j = 0;j < numberOfCells;j++){
                        Color wallColor = cube.getWall(i).getColor(j);
                        input(j, red_side, wallColor);
                     }
                break;
                case BLUE:
                     for (int j = 0;j < numberOfCells;j++){
                        Color wallColor = cube.getWall(i).getColor(j);
                        input(j, blue_side, wallColor);
                     }
                break;
                }
		}
    moves.push_back("Stan poczatkowy kostki");
    cubes.push_back(toCube());
    bool test_ongoing = true;
	while (test_ongoing == true){
	    solve_stage = 1;
		print_whole_cube();
		printf("Stage number: %d\n", solve_stage);
		solve_stage = 1;
		while (solve_stage != 10){
			cube_decide();
		}
		printf("\n\n");
		break;
	}
}

void input(int i, char * tab, Color color)
{
		if (color == WHITE){
			tab[i] = 'w';
		}
		else if (color == YELLOW){
			tab[i] = 'y';
		}
		else if (color == GREEN){
			tab[i] = 'g';
		}
		else if (color == RED){
			tab[i] = 'r';
		}
		else if (color == ORANGE){
			tab[i] = 'o';
		}
		else if (color == BLUE){
			tab[i] = 'b';
		}
}

Cube* toCube(){
    Cube* cube = new Cube();
    for (unsigned cell = 0; cell < numberOfCells; cell++){
        cube->setCell(WHITE, cell, convertCharToColor(white_side[cell]));
        cube->setCell(YELLOW, cell, convertCharToColor(yellow_side[cell]));
        cube->setCell(RED, cell, convertCharToColor(red_side[cell]));
        cube->setCell(BLUE, cell, convertCharToColor(blue_side[cell]));
        cube->setCell(ORANGE, cell, convertCharToColor(orange_side[cell]));
        cube->setCell(GREEN, cell, convertCharToColor(green_side[cell]));
    }
    return cube;
}

Color convertCharToColor(char charColor){
    switch (charColor){
    case 'w':
        return WHITE;
        break;
    case 'y':
        return YELLOW;
        break;
    case 'r':
        return RED;
        break;
    case 'g':
        return GREEN;
        break;
    case 'b':
        return BLUE;
        break;
    case 'o':
        return ORANGE;
        break;
    }
}

vector<Cube*> getCubeVec(){
    return cubes;
}

vector<string> getMoveVec(){
    return moves;
}
