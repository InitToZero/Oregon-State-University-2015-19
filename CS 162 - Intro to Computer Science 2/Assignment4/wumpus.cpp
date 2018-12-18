/******************************************************************************
 **Program:wumpus.cpp
 **Author: Jonathan Ropp
 **Date:5/22/16
 **Description:cpp file that holds the functions for the wumpus class
 **input:None
 **output:None
 ******************************************************************************/

#include "wumpus.h"

/******************************************************************************
 **Function: wumpus::other_events
 **Description: Returns a string with the hazard message
 **Parameters: None
 **Pre_Conditions: wumpus class exists
 **Post_conditions: string is returned
 ******************************************************************************/

string wumpus::other_events(){
   return "You smell a terrible stench.";
}

