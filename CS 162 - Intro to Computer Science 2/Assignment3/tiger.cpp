/******************************************************************************
 **Program:tiger.cpp
 **Author: Jonathan Ropp
 **Date:5/8/16
 **Description:Defines the functions for the tiger class
 **input:None
 **output:None
 ******************************************************************************/

#include "tiger.h"

/******************************************************************************
 **Function:tiger
 **Description:Default constructor for the tiger class
 **Parameters:None
 **Pre_Conditions:Is called
 **Post_conditions:A new animal with tiger attributes will be created
 ******************************************************************************/
tiger::tiger():animal(){ //Default constructor w/ inheritance
   set_cost(10000);
   set_food_cost(150);
   set_payoff(get_cost()*.1);
   set_babies(1);
   set_age(3);
}/*
	tiger::tiger(const tiger &other):animal(){ //Copy constructor
	age = other.age;
	cost = other.cost;
	babies = other.babies;
	food_cost = other.food_cost;
	payoff = other.payoff;

	}
	void tiger::operator=(const tiger &other){ //Operator overload
	age = other.age;
	cost = other.cost;
	babies = other.babies;
	food_cost = other.food_cost;
	payoff = other.payoff;

	}*/