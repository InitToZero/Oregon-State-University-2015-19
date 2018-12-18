/******************************************************************************
 **Program:tiger.h
 **Author: Jonathan Ropp
 **Date:5/8/16
 **Description:Header file for the tiger class
 **input:None
 **output:None
 ******************************************************************************/
#ifndef TIGER_H
#define TIGER_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "animal.h"

using namespace std;

class tiger : public animal{

   public:
	  tiger(); //Default constructor
	  //tiger(const tiger&); //Copy constructor
	  //void operator = (const tiger&); //Operator overload
};
#endif