/******************************************************************************
 **Program:event.cpp
 **Author: Jonathan Ropp
 **Date:5/22/16
 **Description:cpp file that holds functions for event class
 **input:None
 **output:None
 ******************************************************************************/

#include "event.h"

/******************************************************************************
 **Function: event
 **Description: Default constructor
 **Parameters: None
 **Pre_Conditions: Is called
 **Post_conditions: None
 ******************************************************************************/

event::event(){

}

/******************************************************************************
 **Function: set_msg
 **Description: Sets event message
 **Parameters: string 
 **Pre_Conditions: parameters are good
 **Post_conditions: parameters are still good
 ******************************************************************************/

void event::set_msg(string){
   this->event_msg = event_msg;
}

