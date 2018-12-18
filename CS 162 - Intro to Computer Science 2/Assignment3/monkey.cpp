/******************************************************************************
 **Program:monkey.cpp
 **Author: Jonathan Ropp
 **Date:5/8/16
 **Description:Defines functions for the monkey class
 **input:None
 **output:None
 ******************************************************************************/

#include "monkey.h"

/******************************************************************************
 **Function: monkey
 **Description: Default constructor for the monkey class
 **Parameters: None
 **Pre_Conditions: Is called
 **Post_conditions: A new animal will be created with monkey attributes
 ******************************************************************************/
monkey::monkey() : animal(){ //Default constructor w/ inheritance
   set_cost(2500);
   set_food_cost(50);
   set_payoff(get_cost()*.08);
   set_babies(1);
   set_age(3);
}