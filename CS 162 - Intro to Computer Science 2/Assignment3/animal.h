/******************************************************************************
 **Program:animal.h
 **Author: Jonathan Ropp
 **Date:5/8/16
 **Description:Header file for the animal class
 **input:None
 **output:None
 ******************************************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

class animal{

   protected:
	  int age;
	  int cost;
	  int babies;
	  int food_cost;
	  int payoff;

   public:
	  animal();
	  int get_age();
	  void set_age(int);		
	  int get_cost();
	  void set_cost(int);
	  int get_food_cost();
	  void set_food_cost(int);
	  int get_payoff();
	  void set_payoff(int);
	  int get_babies();
	  void set_babies(int);

};
#endif
