#ifndef CUBESALGORITHM_H_INCLUDED
#define CUBESALGORITHM_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include "Cube.h"

using namespace std;

extern char yellow_side[9];
extern char white_side[9];
extern char blue_side[9];
extern char red_side[9];
extern char orange_side[9];
extern char green_side[9];
extern void left();
extern void left_inverted();
extern void right();
extern void right_inverted();
extern void down();
extern void down_inverted();
extern void up();
extern void up_inverted();
extern void front();
extern void front_inverted();
extern void back();
extern void back_inverted();
extern void print_cube(char cube_side[]);
extern void print_whole_cube();
extern void flip_cube(char cube_rotation);
extern void fix_cross_instance_1();
extern void fix_cross_instance_2();
extern void fix_corners_instance_1();
extern void fix_corners_instance_2();
extern void fix_corners_instance_3();
extern void add_edges_instance_1();
extern void add_edges_instance_2();
extern void add_edges_instance_3();
extern void white_cross_on_top();
extern void finish_white_face_instance_1();
extern void finish_white_face_instance_2();
extern void green_on_right();
extern void green_on_left();
extern void cw_rotation();
extern void ccw_rotation();
extern void cube_decide_cross();
extern void cube_decide_whole_cross();
extern void cube_decide_corners();
extern void cube_decide_add_edges();
extern void cube_decide_white_cross();
extern void cube_decide_white_top();
extern void cube_decide_oll();
extern void cube_decide_pll();
extern void cube_decide_solved();
extern void cube_decide();
extern void auto_test(Cube cube);
extern void input(int i, char * tab, Color color);

#endif // CUBESALGORITHM_H_INCLUDED
