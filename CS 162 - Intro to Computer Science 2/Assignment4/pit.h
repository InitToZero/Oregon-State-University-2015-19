/******************************************************************************
 **Program:pit.h
 **Author: Jonathan Ropp
 **Date:.h file that holds the pit class
 **Description:
 **input:None
 **output:None
 ******************************************************************************/

#ifndef PIT_H
#define PIT_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include "event.h"

using namespace std;

class pit : public event{

   public:
	  string other_events();
};
#endif
