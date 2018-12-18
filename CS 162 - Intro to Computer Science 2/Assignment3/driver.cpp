/******************************************************************************
 **Program:driver.cpp
 **Author: Jonathan Ropp
 **Date:5/8/16
 **Description:Holds the main function for zoo tycoon
 **input:None
 **output:None
 ******************************************************************************/
#include "zoo.h"
#include "animal.h"
#include "penguin.h"
#include "p_bear.h"
#include "tiger.h"

int main(){

   cout<<"Welcome to Zoo Tycoon!"<<endl;
   zoo z; //Make a zoo
   z.turn(); //Run game


   return 0;
}
