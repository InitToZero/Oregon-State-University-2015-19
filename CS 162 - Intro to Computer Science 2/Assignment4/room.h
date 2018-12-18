/******************************************************************************
 **Program:room.h
 **Author: Jonathan Ropp
 **Date:5/22/16
 **Description:h file that holds the room class
 **input:None
 **output:None
 ******************************************************************************/

#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include "event.h"
#include "bats.h"
#include "event.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"

using namespace std;

class room{

   private:
	  char** cave;
	  char** temp_cave;
	  int rows, cols;
	  int player_r, player_c;
	  int escape_r, escape_c;
	  int arrows;
	  bool has_gold;
	  bool w_dead;

   public:
	  room(int*, int*, bool);
	  ~room();
	  void game();
	  void test();
	  void map();
	  void check();
	  void print_msg(int, int);
	  bool conditions(int, int);
	  void find_player();
	  void shoot_arrow(int);
	  void find_e_rope();
	  void move_w();


};
#endif
