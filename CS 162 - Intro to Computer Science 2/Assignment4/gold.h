/******************************************************************************
 **Program:gold.h
 **Author: Jonathan Ropp
 **Date:5/22/16
 **Description:h file that holds the gold class
 **input:None
 **output:None
 ******************************************************************************/

#ifndef GOLD_H
#define GOLD_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include "event.h"

using namespace std;

class gold : public event{

   public:
	  string other_events();
};
#endif

