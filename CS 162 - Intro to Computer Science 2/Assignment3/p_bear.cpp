/******************************************************************************
 **Program:p_bear.cpp
 **Author: Jonathan Ropp
 **Date:5/8/16
 **Description:Holds the functions for the p_bear class
 **input:None
 **output:None
 ******************************************************************************/

#include "p_bear.h"

/******************************************************************************
 **Function:p_bear
 **Description:Default constructor for the p_bear class
 **Parameters:None
 **Pre_Conditions:Is called
 **Post_conditions:A new animal with p_bear attributes will be made
 ******************************************************************************/
p_bear::p_bear():animal(){ //Default constructor w/ inheritance
   set_cost(5000);
   set_food_cost(90);
   set_payoff(get_cost()*.05);
   set_babies(2);
   set_age(3);
}
