/******************************************************
 * Program: Assignment6.cpp
 * Author: Jonathan Ropp
 * Date: 3/13/2016
 * Input:
 * Output:
 *******************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;

bool is_pos_int(int);
void is_input_good(int*, char**, int);
void check_input_args(int*, int, int *, int *, char **);
bool error_handling(int*, int*, int*, int*, char**);
char** make_board(int*, int*);
void assign_dashed_line(int, int*, char**);
void int_to_char_top(int, char**);
void assign_first_row(int*, char**);
void int_to_char_side(int, char**);
void assign_numbered_line(int, int*, char**);
void assign_zeros(char**, int*, int*, int*);
void assign_mines(char**, int*, int*, int*);
void assign_board(int*, int*, int*, char**);
char int_to_char_nums(int*);
int assign_nums_corner(int, int, char**);
int assign_nums_right(int, int, char**);
int assign_nums_bottom(int, int, char**);
int assign_nums_others(int, int, char**);
void assign_nums(char**, int*, int*, int*);
void copy(char**, char**, int*, int*);
void print_board(char**, int*, int*);
void choice_1(int*, int*, int*, int*, char**, char**);
void choice_2(int*, int*, int*, int*, char**, char**, bool*);
int check_input_for_int(int*, int*, int*, int*);
int get_input(int*, int*, int*, int*);
bool check_win(char**, char**, int*, int*);
bool play_again();
bool play_game(char**, char**, int*, int*);
void delete_board(char**, int*, int*);
void new_nums(int*, int*, int*);


int main(int argc, char *argv[]){

   //Set variables to -1 to check if they have been changed later
   int rows = -1, cols = -1, mines = -1;
   //Set randome seed
   srand(time(NULL));
   bool game = true;
   //If input arguments are bad, game = false and exits program
   game = error_handling(&rows, &cols, &mines, &argc, argv);
   while(game == true){

	  //Make vis_board
	  char** vis_board = make_board(&rows, &cols);
	  //Assign values to vis_board
	  assign_board(&rows, &cols, &mines, vis_board);
	  //Make hid_board
	  char** hid_board = make_board(&rows, &cols);
	  //Copy vis_board to hid_board 
	  copy(hid_board, vis_board, &rows, &cols);
	  //Assign zeros to hid_board
	  assign_zeros(hid_board, &rows, &cols, &mines);
	  //Assign mines to hid_board
	  assign_mines(hid_board, &rows, &cols, &mines);
	  //Assign numbers of surrounding mines to hid_board
	  assign_nums(hid_board, &rows, &cols, &mines);
	  //Print vis_board to scrren
	  print_board(vis_board, &rows, &cols);
	  //Game = play game
	  game = play_game(vis_board, hid_board, &rows, &cols);
	  //Delete alocated memory on the heap
	  delete_board(vis_board, &rows, &cols);
	  delete_board(hid_board, &rows, &cols);
	  //If user wants to play again, get new inputs
	  if(game == true){
		 new_nums(&rows, &cols, &mines);
	  }
   }
   return 0;
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
   //Else, error and exit program
   else{
	  cout<<"Usage Error"<<endl;
	  exit(1);
   }
}

/*************************************************************************************
 * Function : check_input_args
 * Description : Makes sure that the input arguments are good
 * Parameters : int* rows, int*cols, int*mines, int *argc, char *argv[]
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

void check_input_args(int *rows, int *cols, int *mines, int *argc, char *argv[]){ 

   //For every other number times up to number of args
   for(int i=1; i<*argc; i+=2){
	  //If argument = "-r" and has not been used already
	  if(strcmp(argv[i],"-r")==0 && *rows == -1){
		 //Make sure number is good
		 is_input_good(rows, argv, i);
		 //Print out number of rows
		 cout << atoi(argv[i+1])<<" rows"<<endl;
	  }
	  //If argument = "-c" and has not been used already
	  else if(strcmp(argv[i],"-c")==0 && *cols == -1){
		 //Make sure number is good
		 is_input_good(cols, argv, i);
		 //Print out number of cols
		 cout << atoi(argv[i+1])<<" cols"<<endl;
	  }
	  //If argument = "-m" and has not been used already
	  else if(strcmp(argv[i],"-m")==0 && *mines == -1){
		 //Make sure number is good
		 is_input_good(mines, argv, i);
		 //Print out number of mines
		 cout << atoi(argv[i+1])<<" mines"<<endl;
	  }
	  else{
		 //Print error
		 cout << "Usage error"<<endl;
	  }
   }
}

/*************************************************************************************
 * Function : error_handling
 * Description : Makes sure that all input arguments are assigned and good
 * Parameters : int *rows, int*  cols, int* mines, int* argc, char *argv[]
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, will have returned true or false
 * ***********************************************************************************/

bool error_handling(int *rows, int *cols, int *mines, int *argc, char *argv[]){ 

   //Only run if there are 7 arguments
   if (*argc == 7){
	  //Make sure args are good
	  check_input_args(rows, cols, mines, argc, argv);
   }
   //Else, error
   else{
	  cout<<"You did not enter 7 args"<<endl;
	  return false;
   }
   //If there are too many mines, error message and close program
   if(*mines>=((*cols)*(*rows))){
	  cout<<"There are too many mines!"<<endl;
	  return false;
   }
   //If there are more than 100 rows or collumns, error message and close program
   //Just for if number is absurd, can still double up lines if too many rows/cols
   if(*cols>99 || *rows>99){
	  cout<<"Please have less than 100 rows/cols"<<endl;
	  return false;
   }
   return true;
}

/*************************************************************************************
 * Function : make_board
 * Description : Dynamically makes a 2d array based on user inputted rows and collumns
 * Parameters : int* rows, int*cols
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, return 2d array
 * ***********************************************************************************/

char** make_board(int *rows, int *cols){
   //Dynamically make an array of pointers
   char** board = new char*[((*rows)*2)+1];
   //For each of the cells, make a new array 
   for(int i = 0; i < ((*rows)*2)+1; i++){
	  board[i] = new char[((*cols)*3)+2];
   }
   //Return dynamic, 2d array, AKA the blank board
   return board;
}

/*************************************************************************************
 * Function : assigned_dashed_line
 * Description : Assigns a row in the board array to be all '-'s
 * Parameters : int row, int* cols, char** vis_board
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, board has new assigned values
 * ***********************************************************************************/

void assign_dashed_line(int row, int* cols, char** vis_board){

   int i = 2;
   //Print beginning whitespace
   vis_board[row][i-1] = ' ';
   vis_board[row][i-2] = ' ';
   //Assign '-'s to the board
   while(i<((*cols)*3+2)){
	  vis_board[row][i] = '-';
	  vis_board[row][i+1] = '-';
	  vis_board[row][i+2] = '-';
	  //Increment i 
	  i = i+1; 
   }   
}

/*************************************************************************************
 * Function : int_to_char_top
 * Description : Makes and assigns the numbers that will go along the top of the board
 * Parameters : int num, char** vis_board
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, board has new assigned values
 * ***********************************************************************************/

void int_to_char_top(int num, char** vis_board){

   //Make temporary array
   char temp[2];
   //Place number into char array
   sprintf(temp, "%d", num);
   //If the number was one digit, make the next space over a ' '
   if(temp[1] == '\0'){
	  temp[1] = ' ';
   }
   //Assign new character to board
   vis_board[0][(num*3)] = temp[0];
   vis_board[0][(num*3)+1] = temp[1];
   vis_board[0][(num*3)+2] = ' ';
}

/*************************************************************************************
 * Function : assign_first_row
 * Description : Assign values to the first row of the board
 * Parameters : int* cols, char** vis_board
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, board has new assigned values
 * ***********************************************************************************/

void assign_first_row(int* cols, char** vis_board){

   //Assign leading whitespace
   vis_board[0][0] = ' ';
   vis_board[0][1] = ' ';
   vis_board[0][2] = ' ';
   //Turn the number of cols into a char to go into the board
   for(int i = 1; i<(*cols)+1; i++){
	  int_to_char_top(i, vis_board);  
   }
}

/*************************************************************************************
 * Function : int_to_char_side
 * Description : Assigns the numbers the the left side of the board
 * Parameters : int num, char** vis_board
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, board has new assigned values
 * ***********************************************************************************/

void int_to_char_side(int num, char** vis_board){

   //Make temporary array
   char temp[2];
   //Make num the right row number
   num = (num/2)+1; 
   //Place number into char array
   sprintf(temp, "%d", num);
   //If the number was one digit, make the next space over a ' '
   if(temp[1] == '\0'){
	  temp[1] = ' ';
   }
   //Assign new character to board
   vis_board[num*2][1] = temp[1];
   vis_board[num*2][0] = temp[0];
   vis_board[num*2][2] = '|';
}

/*************************************************************************************
 * Function : assign_numbered_line
 * Description : Assigns values to the rows of the board with numbers on the left
 * Parameters : int num, int* cols, char** vis_board
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, board has new assigned values
 * ***********************************************************************************/

void assign_numbered_line(int num, int *cols, char** vis_board){

   //Get numbers for the left side
   int_to_char_side(num, vis_board);
   //Assign the first '|'
   vis_board[num+1][2] = '|';
   //For every 3 spaces starting at the 3rd space over:
   for(int i = 3; i<(*cols)*3+1; i+=3){

	  //Assign '  |' to the row for how ever many cols
	  vis_board[num+1][i] = ' ';
	  vis_board[num+1][i+1] = ' ';
	  vis_board[num+1][i+2] = '|';
   }
}

/*************************************************************************************
 * Function : assign_zeros
 * Description : Assigns '0' to all cells in board that will be used for the game
 * Parameters : char** hid_board, int* rows, int* cols, int *mines
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, board has new assigned values
 * ***********************************************************************************/

void assign_zeros(char** hid_board, int* rows, int* cols, int *mines){

   //For every 2 rows, starting at the 2nd, going to twice the rows + 1
   for(int i=2; i<((*rows)*2)+1; i+=2){
	  //For every 3 cols, starting at the 3rd, going to thrice the cols +2
	  for(int j=3; j<((*cols)*3)+2; j+=3){
		 //Assign this cell a '0'
		 hid_board[i][j] = '0';
	  }
   }
}

/*************************************************************************************
 * Function : assign_mines
 * Description : Randomly assigns mines the the board
 * Parameters : char** hid_board, int* rows, int* cols, int *mines
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, board has new assigned values
 * ***********************************************************************************/

void assign_mines(char** hid_board, int* rows, int* cols, int *mines){

   //Run for the number of mines user gave
   for(int i=0; i<*mines; i++){
	  //Get a random row
	  int rand_row = (rand() %((*rows)*2))+2;
	  rand_row = ((rand_row)/2)*2;
	  //Get a random collumn
	  int rand_col = (rand() %((*cols)*3))+3;
	  rand_col = ((rand_col)/3)*3;
	  //If there is already a mine there, dont count this run
	  if(hid_board[rand_row][rand_col] == '*'){
		 i--;
	  }
	  else{
		 //Assign a mine to this place on the board
		 hid_board[rand_row][rand_col] = '*';
	  }
   }
}

/*************************************************************************************
 * Function : assign_board
 * Description : Assign values to the board
 * Parameters : int* rows, int* cols, int* mines, char** vis_board
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, board has new assigned values
 * ***********************************************************************************/

void assign_board(int *rows, int *cols, int *mines, char** vis_board){

   //Assigns first row to board
   assign_first_row(cols, vis_board);
   //For every pair of rows
   for(int r = 1; r<(*rows)*2+1; r+=2){
	  //Assign dashed line and the numbered line
	  assign_dashed_line(r, cols, vis_board);
	  assign_numbered_line(r, cols, vis_board);
   }
}

/*************************************************************************************
 * Function : int_to_char_nums
 * Description : Changes an int to a char for the assign_nums function
 * Parameters : int* num
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, returned a char 
 * ***********************************************************************************/

char int_to_char_nums(int* num){

   //Creat a temporary array
   char temp[1]; 
   //Assign the int to the char array
   sprintf(temp, "%d", *num);
   //Create a char and assign it the char that is the int
   char character = temp[0];
   //Return char
   return character;
}

/*************************************************************************************
 * Function : assign_nums_corner
 * Description : Assign the cell in the corner the number of mines around it
 * Parameters : int i, int j, char** hid_board
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

int assign_nums_corner(int i, int j, char** hid_board){

   //Temporary counter
   int temp = 0;
   //If there is a mine around the cell, count it
   if(hid_board[i-2][j] == '*'){//North
	  temp++;
   }
   if(hid_board[i][j-3] == '*'){//West
	  temp++;
   }
   if(hid_board[i-2][j-3] == '*'){//North-West
	  temp++;
   }
   //Return number of mines around cell
   return temp;
}

/*************************************************************************************
 * Function : assign_nums_right
 * Description : Assign the cells on the right num of mines around them
 * Parameters : int i, int j, char** hid_board
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

int assign_nums_right(int i, int j, char** hid_board){

   int temp = 0;
   //If there is a mine around the cell, count it
   if(hid_board[i-2][j] == '*'){//North
	  temp++;
   }
   if(hid_board[i][j-3] == '*'){//West
	  temp++;
   }
   if(hid_board[i-2][j-3] == '*'){//North-West
	  temp++;
   }
   if(hid_board[i+2][j] == '*'){//South
	  temp++;
   }
   if(hid_board[i+2][j-3] == '*'){//South-West
	  temp++;
   }
   //Return number of mines around the cell
   return temp;
}

/*************************************************************************************
 * Function : assing_nums_bottom
 * Description : Assign the cells on the bottom the num of mines around them
 * Parameters : int i, int j, char** hid_board
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

int assign_nums_bottom(int i, int j, char** hid_board){

   int temp = 0;
   //If there is a mine around the cell, count it
   if(hid_board[i-2][j+3] == '*'){//North-East
	  temp++;
   }
   if(hid_board[i][j+3] == '*'){//East
	  temp++;
   }
   if(hid_board[i-2][j] == '*'){//North
	  temp++;
   }
   if(hid_board[i-2][j-3] == '*'){//North-West
	  temp++;
   }
   if(hid_board[i][j-3] == '*'){//West
	  temp++;
   }
   //Return number of mines around cell
   return temp;
}

/*************************************************************************************
 * Function : assign_nums_others
 * Description : Assign the other cells the number of mines around them
 * Parameters : inti, int j, char** hid_board
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

int assign_nums_others(int i, int j, char** hid_board){
 
   int temp = 0;
   //If there is a mine around the cell, count it
   if(hid_board[i-2][j] == '*'){//North
	  temp++;
   }
   if(hid_board[i][j-3] == '*'){//West
	  temp++;
   }
   if(hid_board[i-2][j-3] == '*'){//North-West
	  temp++;
   }
   if(hid_board[i+2][j] == '*'){//South
	  temp++;
   }
   if(hid_board[i+2][j-3] == '*'){//South-West
	  temp++;
   }
   if(hid_board[i-2][j+3] == '*'){//North-East
	  temp++;
   }
   if(hid_board[i+2][j+3] == '*'){//South-East
	  temp++;
   }
   if(hid_board[i][j+3] == '*'){//East
	  temp++;
   }
   //Return number of mines around cell
   return temp;
}

/*************************************************************************************
 * Function : assign_nums
 * Description : Assigns numbers to cells based on how many mines are around it
 * Parameters : char** hid_board, int*rows, int* cols, int* mines
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, board has new assigned values
 * ***********************************************************************************/

void assign_nums(char** hid_board, int* rows, int* cols, int* mines){

   for(int i=2; i<((*rows)*2)+1; i+=2){
	  for(int j=3; j<((*cols)*3)+2; j+=3){

		 int temp = 0;
		 //If there is not already a mine at this position
		 if(hid_board[i][j] != '*'){
			//If this cell is in the corner
			if(j>=((*cols)*3) && i>=((*rows)*2)){
			   temp = temp + assign_nums_corner(i, j, hid_board);
			}
			//If this cell is on the right
			else if(j>=((*cols)*3)){
			   temp = temp + assign_nums_right(i, j, hid_board);
			}
			//If this cell is on the bottom
			else if(i>=((*rows)*2)){
			   temp = temp + assign_nums_bottom(i, j, hid_board);
			}
			//Else...
			else{
			   temp = temp + assign_nums_others(i, j, hid_board);
			}
			//Number of counts gets turned into a char
			char character = int_to_char_nums(&temp);
			//Char gets assigned to that place on board
			hid_board[i][j] = character;
		 }
	  }
   }
}

/*************************************************************************************
 * Function : copy
 * Description : Will copy the contents of orig into dest
 * Parameters : char dest[], char orig[]
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good and dest will now have contents of orig
 * ***********************************************************************************/

void copy(char** dest, char** orig, int *rows, int *cols){

   //Copy contents of orig to dest
   for(int i=0; i<((*rows)*2)+1; i++){
	  for(int j=0; j<((*cols)*3)+2; j++){
		 dest[i][j] = orig[i][j];
	  }
   }
}

/*************************************************************************************
 * Function : print_board
 * Description : Prints every cell of the board onto the screen
 * Parameters : char** board, int*rows, int* cols
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good, board printed to screen
 * ***********************************************************************************/

void print_board(char** board, int* rows, int* cols){

   //Clears screen
   system("clear");
   //Goes to each cell in board array and prints it
   for(int i=0; i<((*rows)*2)+1; i++){
	  for(int j=0; j<((*cols)*3)+2; j++){
		 cout<<board[i][j];
	  }
	  cout<<endl;
   }
   cout<<endl;
}

/*************************************************************************************
 * Function : choice_1
 * Description : Flags the cell that the user called
 * Parameters : int* row, int* col, int* rows, int* cols, char** vis_board, char** hid_board
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

void choice_1(int* row, int* col, int* rows, int* cols, char** vis_board, char** hid_board){

   //If there is already something in the cell
   if(vis_board[*row*2][*col*3] != ' ' || vis_board[*row*2][*col*2] == '!'){
	  //Print board (also clears screen)
	  print_board(vis_board, rows, cols);
	  //Print error
	  cout<<"There is already something here!"<<endl;
   }
   else{
	  //Assign that cell with a '!'
	  vis_board[*row*2][*col*3] = '!';
	  //Print new board
	  print_board(vis_board, rows, cols);
   }
}

/*************************************************************************************
 * Function : choice_2
 * Description : Determines if user selected a mine, an already opened cell, or a numbered cell
 * Parameters : int* row, int* col, int* rows, int* cols, char** vis_board, char** hid_board, bool* win_cond
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

void choice_2(int* row, int* col, int* rows, int* cols, char** vis_board, char** hid_board, bool* win_cond){

   //If the user chose a mine cell
   if (hid_board[*row*2][*col*3] == '*'){
	  //Print the hidden board
	  print_board(hid_board, rows, cols);
	  //Change win condition to true
	  *win_cond = true;
   }
   else{
	  //If the user already opened this cell
	  if(vis_board[*row*2][*col*3] != ' ' && vis_board[*row*2][*col*3] != '!'){
		 //Print board
		 print_board(vis_board, rows, cols);
		 //Print error message
		 cout<<"You already opened this cell!"<<endl;
	  }
	  else{
		 //If the user selected a numbered cell
		 vis_board[*row*2][*col*3] = hid_board[*row*2][*col*3];
		 //Recursive

		 //Print board with numbered cell reveiled
		 print_board(vis_board, rows, cols);
	  }
   }
}

/*************************************************************************************
 * Function : check_input_for_int
 * Description : Gets user input and checks to see if it is an int, if not, run again
 * Parameters : int* row, int* cols, int* rows, int* cols
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

int check_input_for_int(int* row, int* col, int* rows, int* cols){

   int num;
   //Get user input for what row
   cin>>num;
   //If input is not a number, error
   if(cin.fail()){
	  cout<<"You did not enter a number"<<endl;
	  cin.clear();
	  cin.ignore();
	  return -1;
   }
   return num;

}

/*************************************************************************************
 * Function : get_input
 * Description : Gets user input for what to do on turn with error checking
 * Parameters : int* row, int* col, int* rows, int* cols
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

int get_input(int* row, int* col, int* rows, int* cols){

   int choice;
   cout<<"Flag(1) or Open(2): \n"; 
   //Get user input for choice
   choice = check_input_for_int(row, col, rows, cols);
   //If choice is returned as -1, return this function
   if(choice == -1){
	  return get_input(row, col, rows, cols);
   }
   //If input is not 1 or 2
   if((choice != 2 && choice != 1)){
	  //Print error message
	  cout<<"\nYou did not enter 1 or 2"<<endl;
	  //Run again
	  return get_input(row, col, rows, cols);
   }
   cout<<"Type a row: ";
   //Get user input for row
   *row = check_input_for_int(row, col, rows, cols);
   //If row is returned as -1, return this function
   if(*row == -1){
	  return get_input(row, col, rows, cols);
   }
   //If input is not 1 or 2
   if(*row == 0 || *row >*rows){
	  //Print error message
	  cout<<"\nYou did not enter a valid number"<<endl;
	  //return this function
	  return get_input(row, col, rows, cols);
   }  
   cout<<"\nType a col: ";
   //Get user input for col
   *col = check_input_for_int(row, col, rows, cols);
   //If col is returned at -1, return this function
   if(*col == -1){
	  return get_input(row, col, rows, cols);
   }
   //If input is not 1 or 2
   if(*col == 0 || *col >*cols){
	  //Print error message
	  cout<<"\nYou did not enter a valid number"<<endl;
	  //return this function
	  return get_input(row, col, rows, cols);
   }
   cout<<endl;
   //If everything is good, return choice
   //This will go through all the other returns 
   return choice; 
}

/*************************************************************************************
 * Function : check_win
 * Description : Checks to see if the user has won
 * Parameters : char** vis_baord, char** hid_board, int* rows, int* cols
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

bool check_win(char** vis_board, char** hid_board, int* rows, int* cols){

   for(int i=2; i<((*rows)*2)+1; i+=2){
	  for(int j=3; j<((*cols)*3)+2; j+=3){
		 //If cell is ' '
		 if(vis_board[i][j] == ' '){
			//and hidden cell is a mine
			if(hid_board[i][j] == '*'){
			   //Might be a win
			}
			//If space but no mine, didnt win
			else{
			   return false;
			}
		 }
	  }
   }
   return true;
}

/*************************************************************************************
 * Function : play_again
 * Description : Ask user if they want to play agian 
 * Parameters : None
 * Pre-conditions : None
 * Post-conditions : None
 * ***********************************************************************************/

bool play_again(){
   bool choice;
   cout<<"Would you like to play again? Yes(1) or no(0): ";
   //Get user input for choice
   cin>>choice;
   //Error check input. If bad, run again
   if(cin.fail()){
	  cout<<"\nYou did not enter a valid number"<<endl;
	  cin.clear();
	  cin.ignore();
	  play_again();
   }
   if(choice < 0 || choice>=2){
	  cout<<"\nYou did not enter a valid number"<<endl;
	  play_again();
   }
   return choice;
}
/*************************************************************************************
 * Function : play_game
 * Description : Decide what to do with user input and if they won or not
 * Parameters : char** vis_board, char** hid_board, int* rows, int* cols
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

bool play_game(char** vis_board, char** hid_board, int* rows, int* cols){

   //Declar variables
   int row;
   int col;
   int choice;
   bool win_cond = false;
   //While the user has not won
   while(win_cond == false){
	  //Get choice for what user wants to do on turn
	  choice = get_input(&row, &col, rows, cols);
	  if (choice == 1){
		 choice_1(&row, &col, rows, cols, vis_board, hid_board);
	  }
	  else if (choice == 2){
		 choice_2(&row, &col, rows, cols, vis_board, hid_board, &win_cond);
	  }
	  //If the win condition is false here, check again
	  if(win_cond == false){
		 win_cond = check_win(vis_board, hid_board, rows, cols);
		 //If win condition is true now, the user wins
		 if (win_cond == true){
			cout<<"Congrats! You won!"<<endl;
		 }
	  }
	  //If the win condition was already true, user loses
	  else if (win_cond == true){
		 cout<<"You lost"<<endl;
	  }
   }
   //Ask user if they want to play again
   return(play_again());
}

/*************************************************************************************
 * Function : delete_board
 * Description : Deletes memory on heap of the boards
 * Parameters : char** board, int* rows, int* cols
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

void delete_board(char** board, int* rows, int* cols){

   //Delete each array in each cell of board
   for(int i=0; i<((*rows)*2)+1; i++){
	  delete[]board[i];
   }
   //Delete board
   delete[]board;
}

/*************************************************************************************
 * Function : check_input_for_num
 * Description : Make sure user inpu is good
 * Parameters : int* rows, int* cols, int* mines
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

int check_input_for_num(int* rows, int* cols, int* mines){

   int num;
   //Get user input for num
   cin >> num;
   //If num is not an int
   if(cin.fail()){
	  //Print error
	  cout<<"\nYou did not enter a valid number"<<endl;
	  //Clear stream
	  cin.clear();
	  cin.ignore();
	  //Run again
	  new_nums(rows, cols, mines);
   }
   else{
	  return num;
   }
}

/*************************************************************************************
 * Function : new_nums
 * Description : Ask user for new number of rows, cols, mines
 * Parameters : int*rows, int* cols, int* mines
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good
 * ***********************************************************************************/

void new_nums(int* rows, int* cols, int* mines){

   cout<<"Please enter new numbers:"<<endl;
   cout<<"Rows: ";
   //Get # rows from user
   *rows = check_input_for_num(rows, cols, mines);
   //If negative, run again
   if(*rows <= 0){
	  cout<<"\nYou did not enter a valid number"<<endl;
	  new_nums(rows, cols, mines);
   }
   cout<<"\nCols: ";
   //Get # cols from user
   *cols = check_input_for_num(rows, cols, mines);
   //If negative, run again
   if(*cols <= 0){
	  cout<<"\nYou did not enter a valid number"<<endl;
	  new_nums(rows, cols, mines);
   }
   cout<<"\nMines: ";
   //Get # mines from user
   *mines = check_input_for_num(rows, cols, mines);
   //If there are too many mines, run again
   if(*mines>=((*cols)*(*rows))){
	  //Print error
	  cout<<"\nThere are too many mines!"<<endl;
	  new_nums(rows, cols, mines);
   }
   //If negative, run again
   if(*mines <= 0){
	  cout<<"\nYou did not enter a valid number"<<endl;
	  new_nums(rows, cols, mines);
   }
}

