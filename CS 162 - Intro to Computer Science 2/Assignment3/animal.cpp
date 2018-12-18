/******************************************************************************
 **Program:animal.cpp
 **Author: Jonathan Ropp
 **Date:5/8/16
 **Description:Holds the functions for the animal class
 **input:None
 **output:None
 ******************************************************************************/

#include "animal.h"

/******************************************************************************
 **Function:animal
 **Description:Default constructor for the animal class
 **Parameters:None
 **Pre_Conditions:Is called
 **Post_conditions:A new animal will be created
 ******************************************************************************/
animal::animal(){ //Default constructor
   age = 0;
   cost = 0;
   babies = 0;
   food_cost = 0;
   payoff = 0;	
}
int animal::get_age(){ //Getter
   return age;
}
void animal::set_age(int num){ //Setter
   age = num;
}
int animal::get_cost(){//Getter
   return cost;
}
void animal::set_cost(int cost){//Setter
   this->cost = cost;
}
int animal::get_food_cost(){//Getter
   return food_cost;
}
void animal::set_food_cost(int f_cost){//Setter
   food_cost = f_cost;
}
int animal::get_payoff(){//Getter
   return payoff;
}
void animal::set_payoff(int pay){//Setter
   payoff = pay;
}
int animal::get_babies(){//Getter
   return babies;
}
void animal::set_babies(int num){//Setter
   babies = num;
}
