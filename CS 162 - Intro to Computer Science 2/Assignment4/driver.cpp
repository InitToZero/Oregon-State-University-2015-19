/******************************************************************************
 **Program:driver.cpp
 **Author: Jonathan Ropp
 **Date:5/22/16
 **Description:Holds the main function for hunt the wumpus
 **input:None
 **output:None
 ******************************************************************************/

#include "room.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

bool is_pos_int(int);
void check_input_args(int*, int*, int*, char **);
void is_input_good(int*, char**, int);
bool error_handling(int*, int*, int*, char**);
void new_vals(int*, int*);
int play_again(int*, int*, bool*);

/******************************************************************************
 **Function: main
 **Description: Main function for Hunt the Wumpus
 **Parameters: Command line arguments
 **Pre_Conditions: commandline arguments are good 
 **Post_conditions: Game will have been played
 ******************************************************************************/

int main(int argc, char *argv[]){

   srand(time(NULL));

   //Set variables to -1 to check if they have been changed later
   int rows = -1, cols = -1, game = 1;
   bool gg = false, rand_m = true;

   //Only start if inputs are good
   gg = error_handling(&rows, &cols, &argc, argv);

   if(gg==true){

	  //Loop game while user wants to play
	  while(game==1){

		 room r(&rows, &cols, rand_m);
		 game = play_again(&rows, &cols, &rand_m);
	  }
   }

   else{
	  return 0;
   }
}

/******************************************************************************
 **Function: play_again
 **Description: Asks user if they want to play again
 **Parameters: rows, cols, rand_m
 **Pre_Conditions: parameters are good 
 **Post_conditions: Parameters are still good
 ******************************************************************************/

int play_again(int *rows, int* cols, bool* rand_m){

   int choice;
   cout<<"Would you like to play again? Yes(1) or no(0)"<<endl;
   cin >> choice;

   if(choice==1){

	  int board;
	  cout<<"Do you want the same board or a new one? New(1) or same(0)"<<endl;
	  cin >> board;

	  if(board == 1){
		 new_vals(rows, cols);
		 return 1;
	  }

	  else if(board == 0){
		 *rand_m = false;
		 return 1;
	  }

	  else{
		 cout<<"Please enter a good number"<<endl;
		 play_again(rows, cols, rand_m);
	  }
   }

   else if(choice == 0){
	  cout<<"Thanks for playing!"<<endl;
	  return 0;
   }

   else{
	  cout<<"Please enter a good number"<<endl;
	  play_again(rows, cols, rand_m);
   }
}

/******************************************************************************
 **Function: new_vals
 **Description: Gets new ints for the cols and rows for the board
 **Parameters: rows, cols
 **Pre_Conditions: Parameters are good
 **Post_conditions: parameters are still good
 ******************************************************************************/

void new_vals(int* rows, int* cols){

   cout<<"How many rows?"<<endl;
   cin>>*rows;
   cout<<"How many cols?"<<endl;
   cin>>*cols;

   if(*cols>50 || *rows>50){
	  cout<<"Please have at most 50 rows/cols"<<endl;
	  new_vals(rows, cols);
   }

   if(*cols<4 || *rows<4){
	  cout<<"Please have more than 3 rows/cols"<<endl;
	  new_vals(rows, cols);
   }
}

/*************************************************************************************
 * Function : check_input_args
 * Description : Makes sure that the input arguments are good
 * Parameters : int* rows, int*cols, int*mines, int *argc, char *argv[]
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

void check_input_args(int *rows, int *cols, int *argc, char *argv[]){ 

   //For every other number times up to number of args
   for(int i=1; i<*argc; i+=2){

	  //If argument = "-r" and has not been used already
	  if(strcmp(argv[i],"-r")==0 && *rows == -1){
		 //Make sure number is good
		 is_input_good(rows, argv, i);
	  }

	  //If argument = "-c" and has not been used already
	  else if(strcmp(argv[i],"-c")==0 && *cols == -1){
		 //Make sure number is good
		 is_input_good(cols, argv, i);
	  }

	  else{
		 cout << "Usage error"<<endl;
	  }
   }
}

/*************************************************************************************
 * Function : is_input_good
 * Description : Makes sure that input arguments are good
 * Parameters : int *car, char *argv[], int i
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

void is_input_good(int *var, char *argv[], int i){

   //If the number is positive, *var gets that number
   if(is_pos_int(atoi(argv[i+1]))==true){
	  *var = atoi(argv[i+1]);
   }

   else{
	  cout<<"Usage Error"<<endl;
	  exit(1);
   }
}

/*************************************************************************************
 * Function : error_handling
 * Description : Makes sure that all input arguments are assigned and good
 * Parameters : int *rows, int*  cols, int* mines, int* argc, char *argv[]
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, will have returned true or false
 * ***********************************************************************************/

bool error_handling(int *rows, int *cols, int *argc, char *argv[]){ 

   //Only run if there are 5 arguments
   if (*argc == 5){
	  //Make sure args are good
	  check_input_args(rows, cols, argc, argv);
   }

   else{
	  cout<<"You did not enter 5 args"<<endl;
	  return false;
   }

   if(*cols>50 || *rows>50){
	  cout<<"Please have at most 50 rows/cols"<<endl;
	  return false;
   }
   if(*cols<4 || *rows<4){
	  cout<<"Please have more than 4 rows/cols"<<endl;
	  return false;
   }
   return true;
}

/*************************************************************************************
 * Function : is_pos_int
 * Description : Checks to see if number is positive
 * Parameters : int num
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good and will have returned true or false
 * ***********************************************************************************/

bool is_pos_int(int num){

   //If number is positive, return true
   if (num>0){
	  return true;
   }
   //Else, return false
   else{
	  return false;
   }
}
