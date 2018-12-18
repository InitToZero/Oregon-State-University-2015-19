/******************************************************************************
 **Program:zoo.h
 **Author: Jonathan Ropp
 **Date:5/8/16
 **Description:Header file for the zoo class
 **input:None
 **output:None
 ******************************************************************************/
#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <time.h>
#include "animal.h"
#include "penguin.h"
#include "p_bear.h"
#include "tiger.h"
#include "monkey.h"
using namespace std;

class zoo{

   private:
	  int total_money;
	  int daily_cost;
	  int day;
	  tiger * t_exhibit;
	  penguin * p_exhibit;
	  p_bear * pb_exhibit;
	  monkey * m_exhibit;
	  int t, p, pb, m;

   public:
	  zoo(); //Default constructor
	  ~zoo(); //Destructor
	  //zoo(const zoo&); //Copy constructor
	  //void operator = (const zoo&); //Operator overload
	  int get_t_money();
	  int get_d_cost();
	  int get_day();
	  void increment_day();
	  void increment_age();
	  int choose_animal();
	  int turn();
	  void refresh_money(int);
	  void restruct();
	  int end_of_day();
	  void change_t_array(int);
	  void change_p_array(int);
	  void change_pb_array(int);
	  void change_m_array(int);
	  int day_income();
	  int day_cost();
	  void rand_event();
	  void sickness();
	  void boom();
	  void baby();

};
#endif