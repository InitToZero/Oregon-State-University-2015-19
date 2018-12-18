/******************************************************************************
 **Program:wumpus.h
 **Author: Jonathan Ropp
 **Date:5/22/16
 **Description:h file that holds the wumpus class
 **input:None
 **output:None
 ******************************************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include "event.h"

using namespace std;

class wumpus : public event{

   public:
	  string other_events();	
};
#endif
