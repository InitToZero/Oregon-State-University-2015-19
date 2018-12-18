/*******************************************************************************
 * Program Filename: Assignment3.cpp
 * Author: Jonathan Ropp
 * Date:1/31/2016
 * Description: Which way am I going? 
 *
 *		Code that will "guide the rover from its current location to its destination."
 *		Takes user input, maps it on a grid and then makes a path to inputed destination.
 *		4 x 4 grid with "X" as markers
 *		No diagonal movement allowed
 *
 * Input:
 * Output:
 *******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Declare functions
int get_num();

void find_path(int xstart,int ystart, int xend, int yend);

void draw_grid(char grid03, char grid13, char grid23, char grid33, char grid02, char grid12, char grid22, char grid32, char grid01, char grid11, char grid21, char grid31, char grid00, char grid10, char grid20, char grid30);

int main(){

   char run = 'y';
   while (run=='y'){ //Runs program while run == y


      int xstart;
      int ystart;
      int xend;
      int yend;

      //Get user input for rover start and end locations	
      cout << endl <<"Please enter the starting x-coordinates: ";
      xstart = get_num();
      cout << "Please enter the starting y-corrdinates: ";
      ystart = get_num();
      cout << "Please enter the ending x-coordinates: ";
      xend = get_num();
      cout << "Please enter the ending y-coordinates: ";
      yend = get_num();

      //Find the path of the rover and print it to the screen
      find_path(xstart,ystart,xend,yend);

      //Ask user if they want to run again
      cout << "Do you want to run this again?" << endl;
      cout << "Type y for yes, anything else for no. : ";
      cin >> run;
   }
   return 0;
}

/*******************************************************************************************************************
 * Function: find_path
 * Description: Finds the path of the rover from the starting position to the ending, as well as prints path 
 * Parameters: xstart, ystart, xend, yend
 * Return: None
 * Pre-Conditions: All parameters are valid integers
 * Post conditions: No parameter changes and the path will be printed
 *******************************************************************************************************************/

void find_path(int xstart,int ystart, int xend, int yend)
{
   //Set local variables
   char grid03 = ' ';
   char grid13 = ' ';
   char grid23 = ' ';
   char grid33 = ' ';

   char grid02 = ' ';
   char grid12 = ' ';
   char grid22 = ' ';
   char grid32 = ' ';

   char grid01 = ' ';
   char grid11 = ' ';
   char grid21 = ' ';
   char grid31 = ' ';

   char grid00 = ' ';
   char grid10 = ' ';
   char grid20 = ' ';
   char grid30 = ' ';
   int run;

   //Counts how many steps will be make
   run = abs(xend-xstart) + abs(yend-ystart) + 1;

   //Will loop for as many steps need to be taken
   for(run; run>0; run--){

      //Depending on where the rover is, this will change that variable to an X
      if(xstart==0&&ystart==0){
	 grid00 = 'X';
      }
      else if(xstart==0&&ystart==1){
	 grid01 = 'X';    
      }
      else if(xstart==0&&ystart==2){
	 grid02 = 'X';
      }
      else if(xstart==0&&ystart==3){
	 grid03 = 'X';
      }
      else if(xstart==1&&ystart==0){
	 grid10 = 'X';
      }
      else if(xstart==1&&ystart==1){
	 grid11 = 'X';
      }
      else if(xstart==1&&ystart==2){
	 grid12 = 'X';
      }
      else if(xstart==1&&ystart==3){
	 grid13 = 'X';
      }
      else if(xstart==2&&ystart==0){
	 grid20 = 'X';
      }
      else if(xstart==2&&ystart==1){
	 grid21 = 'X';
      }
      else if(xstart==2&&ystart==2){
	 grid22 = 'X';
      }
      else if(xstart==2&&ystart==3){
	 grid23 = 'X';
      }
      else if(xstart==3&&ystart==0){
	 grid30 = 'X';
      }
      else if(xstart==3&&ystart==1){
	 grid31 = 'X';
      }
      else if(xstart==3&&ystart==2){
	 grid32 = 'X';
      }
      else if(xstart==3&&ystart==3){
	 grid33 = 'X';
      }

      //If the rover is not at the end position, change variables to make next step
      if (xstart>xend){
	 xstart = xstart - 1;
      }
      else if (xstart<xend){
	 xstart = xstart + 1;
      }
      else if (xstart == xend){

	 if (ystart>yend){
	    ystart = ystart - 1;
	 }
	 else if (ystart<yend){
	    ystart = ystart + 1;
	 }
	 else if (ystart == yend){
	 }
      }
      //Print the path of the rover to the screen
      draw_grid(grid03, grid13, grid23, grid33, grid02, grid12, grid22, grid32, grid01, grid11, grid21, grid31, grid00, grid10, grid20, grid30);
   }
}

/*******************************************************************************************************************
 * Function: get_num
 * Description: Gets user input for grid coordinates and makes sure that the input is a valid int
 * Parameters: None
 * Return: int
 * Pre-Conditions: None
 * Post conditions: Returns valid, user inputted, int
 *******************************************************************************************************************/

int get_num()
{
   string input;
   int num; 

   //Gets user input and makes sure it is a valid int; if not, print error and ask again
   cin >> input;
   for(int i=0; i<input.length();i++){
      if(!(input.at(i)>='0'&&input.at(i)<='3')){
	 cout << "Please enter a valid number. : ";
	 cin >> input;
	 i=-1;
      }
   }
   num = atoi(input.c_str());
   while (num > 3 || num < 0){
      cout << "Please enter a valid number. : ";
      cin >> num;
   }
   //Return the valid int to main
   return num; 
}

/**************************************************************************************************************************
 * Function: draw_grid
 * Description: Prints out the grid 
 * Parameters: grid00,01,02,03,10,11,12,13,20,21,22,23,30,31,32,33
 * Return: None
 * Pre-Conditions: All parameters are valid characters
 * Post conditions: No change to the parameters and the grid will be printed with any visited lcation marked with an "X."
 **************************************************************************************************************************/

void draw_grid(char grid03, char grid13, char grid23, char grid33, char grid02, char grid12, char grid22, char grid32, char grid01, char grid11, char grid21, char grid31, char grid00, char grid10, char grid20, char grid30)
{
   //Print the grid that the path will be displayed on.
   cout <<"---------\n";
   cout << "|" << grid03 << "|" << grid13 << "|" << grid23 << "|" << grid33 << "|\n";
   cout <<"---------\n";
   cout << "|" << grid02 << "|" << grid12 << "|" << grid22 << "|" << grid32 << "|\n";
   cout <<"---------\n";
   cout << "|" << grid01 << "|" << grid11 << "|" << grid21 << "|" << grid31 << "|\n";
   cout <<"---------\n";
   cout << "|" << grid00 << "|" << grid10 << "|" << grid20 << "|" << grid30 << "|\n";
   cout <<"---------\n";
}
