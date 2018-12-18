/******************************************************************************
 **Program:penguin.cpp
 **Author: Jonathan Ropp
 **Date:5/8/16
 **Description:Holds the functions for the penguin class
 **input:None
 **output:None
 ******************************************************************************/

#include "penguin.h"

/******************************************************************************
 **Function:penguin
 **Description:Default constructor for the penguin class
 **Parameters:None
 **Pre_Conditions:Is called
 **Post_conditions:A new animal with penguin attributes will be made
 ******************************************************************************/
penguin::penguin():animal(){//Default constructor w/ inheritance
   set_cost(1000);
   set_food_cost(30);
   set_payoff(get_cost()*.05);
   set_babies(3);
   set_age(3);
}