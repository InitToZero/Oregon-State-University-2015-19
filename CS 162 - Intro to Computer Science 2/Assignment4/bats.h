/******************************************************************************
 **Program:bats.h
 **Author: Jonathan Ropp
 **Date:5/22/16
 **Description:Holds the bats class
 **input:None
 **output:None
 ******************************************************************************/

#ifndef BATS_H
#define BATS_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include "event.h"

using namespace std;

class bats : public event{

   public:
	  string other_events();		
};
#endif
