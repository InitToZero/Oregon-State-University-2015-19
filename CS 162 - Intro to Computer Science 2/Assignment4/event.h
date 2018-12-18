/******************************************************************************
 **Program:event.h
 **Author: Jonathan Ropp
 **Date:5/22/16
 **Description:h file that holds the event class
 **input:None
 **output:None
 ******************************************************************************/

#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

class event{

   protected:
	  string event_msg;

   public:
	  event();
	  virtual string other_events()=0;
	  void set_msg(string);

};
#endif
