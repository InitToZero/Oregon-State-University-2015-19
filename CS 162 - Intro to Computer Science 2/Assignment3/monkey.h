/******************************************************************************
 **Program:monkey.h
 **Author: Jonathan Ropp
 **Date:5/8/16
 **Description:header file for the monkey class
 **input:None
 **output:None
 ******************************************************************************/
#ifndef MONKEY_H
#define MONKEY_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "animal.h"

using namespace std;

class monkey : public animal{

   public:
	  monkey(); //Default constructor
};
#endif