/******************************************************************************
 **Program:room.cpp
 **Author: Jonathan Ropp
 **Date:5/22/16
 **Description:cpp file that holds functions for room class
 **input:None
 **output:None
 ******************************************************************************/

#include "room.h"

/******************************************************************************
 **Function: room
 **Description: Non-default constructor for the room class
 **Parameters: r, c, rand_m
 **Pre_Conditions: parameters are good
 **Post_conditions: class is constructed
 ******************************************************************************/

room::room(int* r, int* c, bool rand_m){

   arrows = 3;
   has_gold = false;
   w_dead = false;

   if(rand_m == true){
	  rows = *r;
	  cols = *c;

	  //Sets up 2d arrays for the game board
	  cave = new char*[rows];
	  temp_cave = new char*[rows];

	  for(int i = 0; i < rows; i++){
		 cave[i] = new char[cols];
		 temp_cave[i] = new char[cols];
	  }

	  for(int i=0; i<rows; i++){
		 for(int j=0; j<cols; j++){
			cave[i][j] = '0';
			temp_cave[i][j] = '0';
		 }
	  }
	  //Sets board 
	  map();
   }
   else{
	  for(int i=0; i<rows; i++){
		 for(int j=0; j<cols; j++){
			cave[i][j] = temp_cave[i][j];
		 }
	  }
   }
   //Plays game
   game();
}

/******************************************************************************
 **Function: ~room
 **Description: Destructor for the room class
 **Parameters: none
 **Pre_Conditions: Is called
 **Post_conditions: All dynamic memory will be freed
 ******************************************************************************/

room::~room(){

   for(int j=0; j<rows; j++){
	  delete[] cave[j];
	  delete[] temp_cave[j];
   }

   delete[] cave;
   delete[] temp_cave;
}

/******************************************************************************
 **Function: test
 **Description: Prints out the board for testing purposes
 **Parameters: None
 **Pre_Conditions: Is called (Is cheating in the game!)
 **Post_conditions: board is printed to screen
 ******************************************************************************/

void room::test(){	

   for(int i=0; i<rows; i++){
	  for(int j=0; j<cols; j++){
		 cout<<"|"<<cave[i][j];
	  }
	  cout<<"|"<<endl;
   }	
}

/******************************************************************************
 **Function: map
 **Description: Sets cells of the game board
 **Parameters: None
 **Pre_Conditions: 2d array of cave/temp_cave has been constructed
 **Post_conditions: Cells of array will be filled with events or 0's
 ******************************************************************************/

void room::map(){

   int r_num,c_num;
   for(int i=1; i<8; i++){

	  r_num = rand()%(rows);
	  c_num = rand()%(cols);

	  if(cave[r_num][c_num] == '0'){		  
		 if(i==1){
			cave[r_num][c_num] = 'W';
			temp_cave[r_num][c_num] = 'W';
		 }
		 if(i==2){
			cave[r_num][c_num] = 'G';	
			temp_cave[r_num][c_num] = 'G';
		 }
		 if(i==3||i==4){
			cave[r_num][c_num] = 'B';
			temp_cave[r_num][c_num] = 'B';
		 }
		 if(i==5||i==6){
			cave[r_num][c_num] = 'P';
			temp_cave[r_num][c_num] = 'P';
		 }
		 if(i==7){
			cave[r_num][c_num] = '*';
			temp_cave[r_num][c_num] = '*';
		 }
	  }	
	  else{
		 i--;
	  }
   }
}

/******************************************************************************
 **Function: find_player
 **Description: searches through the board to find where the player is
 **Parameters: None
 **Pre_Conditions: Player is on board
 **Post_conditions: Members of the room class will be updated
 ******************************************************************************/

void room::find_player(){

   for(int i=0; i<rows; i++){
	  for(int j=0; j<cols; j++){
		 if(cave[i][j] == '*'){

			player_r=i;
			player_c=j;
		 }
	  }
   }
}

/******************************************************************************
 **Function: find_e_rope
 **Description: Searches through the board to find player, and therefore, exit
 **Parameters: None
 **Pre_Conditions: Board has been made
 **Post_conditions: Members of the room class will be updated
 ******************************************************************************/

void room::find_e_rope(){

   for(int i=0; i<rows; i++){
	  for(int j=0; j<cols; j++){
		 if(cave[i][j] == '*'){

			escape_r=i;
			escape_c=j;
		 }
	  }
   }
}

/******************************************************************************
 **Function: check
 **Description: Checks the cells around the player for hazards
 **Parameters: None
 **Pre_Conditions: Board has been filled 
 **Post_conditions: User will know what is around their player
 ******************************************************************************/

void room::check(){

   find_player();
   //North
   if(player_r!=0){
	  if(cave[player_r-1][player_c]!=0){
		 print_msg(player_r-1, player_c);
	  }
   }

   //NorthWest
   if(player_r!=0){
	  if(player_c!=0){
		 if(cave[player_r-1][player_c-1]!=0){
			print_msg(player_r-1, player_c-1);
		 }
	  }
   }

   //NorthEast
   if(player_r!=0){
	  if(player_c<cols-1){
		 if(cave[player_r-1][player_c+1]!=0){
			print_msg(player_r-1, player_c+1);
		 }
	  }
   }

   //South
   if(player_r<rows-1){
	  if(cave[player_r+1][player_c]!=0){
		 print_msg(player_r+1, player_c);
	  }
   }

   //SouthWest
   if(player_r<rows-1){
	  if(player_c!=0){
		 if(cave[player_r+1][player_c-1]!=0){
			print_msg(player_r+1, player_c-1);
		 }
	  }
   }

   //SouthEast
   if(player_r<rows-1){
	  if(player_c<cols-1){
		 if(cave[player_r+1][player_c+1]!=0){
			print_msg(player_r+1, player_c+1);
		 }
	  }
   }

   //West
   if(player_c!=0){
	  if(cave[player_r][player_c-1]!=0){
		 print_msg(player_r, player_c-1);
	  }
   }

   //East
   if(player_c<cols-1){
	  if(cave[player_r][player_c+1]!=0){
		 print_msg(player_r, player_c+1);
	  }
   }
}

/******************************************************************************
 **Function: print_msg
 **Description: Prints hazard message based on what is in the cell
 **Parameters: row_pos, col_pos
 **Pre_Conditions: Board has been filled and check is called
 **Post_conditions: hazard message will be printed 
 ******************************************************************************/

void room::print_msg(int row_pos, int col_pos){
   wumpus w;
   bats b;
   gold g;
   pit p;

   if(cave[row_pos][col_pos] == 'W'){
	  cout<<w.other_events()<<endl;
   }
   else if(cave[row_pos][col_pos] == 'G'){
	  cout<<g.other_events()<<endl;
   }
   else if(cave[row_pos][col_pos] == 'B'){
	  cout<<b.other_events()<<endl;
   }
   else if(cave[row_pos][col_pos] == 'P'){
	  cout<<p.other_events()<<endl;
   }
}

/******************************************************************************
 **Function: game
 **Description: Holds the menu for the game
 **Parameters: None
 **Pre_Conditions: Classes have been constructed
 **Post_conditions: Game will have been played
 ******************************************************************************/

void room::game(){

   find_e_rope();
   int choice1, choice2;
   bool life = true;
   cout<<string(100, '\n');
   cout<<"Welcome to Hunt the Wumpus!"<<endl;
   

   while(life == true){
      check();
	  test();
	  cout<<"You have "<<arrows<<" arrows"<<endl;
	  cout<<"What would you like to do? Move(1) or shoot(2)"<<endl;
	  cin>>choice1;

	  if(choice1==1){
		 cout<<"Which way do you want to move?"<<endl;
		 cout<<"North(1), East(2), South(3), West(4)"<<endl;
		 cin >> choice2;

		 if(choice2 == 1){//If chose to move

			if(player_r-1 < 0){ //If player attempts to go out of bounds
			   cout<<string(100, '\n');
			   cout<<"You walked straight into a wall"<<endl;
			}
			else{//Pass turn for moving North
			   cout<<string(100, '\n');
			   cave[player_r][player_c] = '0';

			   if(cave[player_r-1][player_c] == 'B'){//If moved onto bats
				  life = conditions(player_r-1, player_c);
				  cave[player_r][player_c] = '*';
			   }

			   else{
				  life = conditions(player_r-1, player_c);
				  cave[player_r-1][player_c] = '*';
			   }
			}
		 }

		 else if(choice2 == 2){
			if(player_c+1 >= cols){//If player attempts to go out of bounds
			   cout<<string(100, '\n');
			   cout<<"You walked straight into a wall"<<endl;
			}
			else{//Pass turn for moving East
			   cout<<string(100, '\n');
			   cave[player_r][player_c] = '0';

			   if(cave[player_r][player_c+1] == 'B'){//If moved onto bats
				  life = conditions(player_r, player_c+1);
				  cave[player_r][player_c] = '*';
			   }

			   else{
				  life = conditions(player_r, player_c+1);
				  cave[player_r][player_c+1] = '*';
			   }
			}
		 }

		 else if(choice2 == 3){
			if(player_r+1 >= rows){//If player attempts to go out of bounds
			   cout<<string(100, '\n');
			   cout<<"You walked straight into a wall"<<endl;
			}
			else{//Pass turn for moving South
			   cout<<string(100, '\n');
			   cave[player_r][player_c] = '0';

			   if(cave[player_r+1][player_c] == 'B'){//If moved onto bats
				  life = conditions(player_r+1, player_c);
				  cave[player_r][player_c] = '*';
			   }

			   else{
				  life = conditions(player_r+1, player_c);
				  cave[player_r+1][player_c] = '*';
			   }
			}
		 }

		 else if(choice2 == 4){
			if(player_c-1 < 0){//If player attempts to go out of bounds
			   cout<<string(100, '\n');
			   cout<<"You walked straight into a wall"<<endl;
			}
			else{//Pass turn for moving West
			   cout<<string(100, '\n');
			   cave[player_r][player_c] = '0';

			   if(cave[player_r][player_c-1] == 'B'){//If moved onto bats
				  life = conditions(player_r, player_c-1);
				  cave[player_r][player_c] = '*';
			   }

			   else{
				  life = conditions(player_r, player_c-1);
				  cave[player_r][player_c-1] = '*';
			   }
			}
		 }
		 else{
			cout<<"Please enter a good number"<<endl;
		 }
	  }
	  else if(choice1 == 2){//If chose to shoot

		 if(arrows>0){
			int direction;
			cout<<"what direction would you like to shoot?"<<endl;
			cout<<"North(1), East(2), South(3), West(4)"<<endl;
			cin>>direction;
			shoot_arrow(direction);
			arrows--;
		 }
		 else{
			cout<<string(100, '\n');			
			cout<<"You are out of arrows!"<<endl;
		 }
	  }
	  if(w_dead == false && arrows==0){
		 cout<<string(100, '\n');
		 cout<<"You ran out of arrows without killing the Wumpus!"<<endl;
		 life = false;
	  }
	  find_player();
	  if(w_dead == true && has_gold == true && player_c == escape_c && player_r == escape_r){
		 cout<<string(100, '\n');
		 cout<<"You killed the Wumpus and found the exit with the gold!"<<endl;
		 cout<<"You win!"<<endl;
		 life = false;
	  }
   }
}

/******************************************************************************
 **Function: shoot_arrow
 **Description: Functionality for shooting an arrow
 **Parameters: direction
 **Pre_Conditions: player has arrows
 **Post_conditions: arrow will have been used
 ******************************************************************************/

void room::shoot_arrow(int direction){

   if(direction == 1){
	  for(int i=0;i<4;i++){
		 if(player_r-i == -1){
			cout<<string(100, '\n');
			cout<<"You hit a wall"<<endl;

			if(w_dead == false){
			   move_w();
			}
			break;
		 }
		 else if(cave[player_r-i][player_c] != 'W'){
			cout<<string(100, '\n');
			cout<<"The arrow didn't hit anything"<<endl;
			if(w_dead == false&& i==3){
			   move_w();
			}				
		 }
		 else if(cave[player_r-i][player_c] == 'W'){
			cout<<string(100, '\n');
			cout<<"You killed the Wumpus!"<<endl;
			w_dead = true;
			cave[player_r-i][player_c] = '0';
			break;
		 }
	  }
   }
   if(direction == 2){
	  for(int i=0;i<4;i++){
		 if(player_c+i == cols){
			cout<<string(100, '\n');
			cout<<"You hit a wall"<<endl;
			if(w_dead == false){
			   move_w();
			}
			break;
		 }
		 else if(cave[player_r][player_c+i] != 'W'){
			cout<<string(100, '\n');
			cout<<"The arrow didn't hit anything"<<endl;
			if(w_dead == false&& i==3){
			   move_w();
			}
		 }
		 else if(cave[player_r][player_c+i] == 'W'){
			cout<<string(100, '\n');
			cout<<"You killed the Wumpus!"<<endl;
			w_dead = true;
			cave[player_r][player_c+i] = '0';
			break;
		 }
	  }
   }
   if(direction == 3){
	  for(int i=0;i<4;i++){
		 if(player_r+i == rows){
			cout<<string(100, '\n');
			cout<<"You hit a wall"<<endl;
			if(w_dead == false){
			   move_w();
			}
			break;
		 }
		 else if(cave[player_r+i][player_c] != 'W'){
			cout<<string(100, '\n');
			cout<<"The arrow didn't hit anything"<<endl;
			if(w_dead == false && i==3){
			   move_w();
			}
		 }
		 else if(cave[player_r+i][player_c] == 'W'){
			cout<<string(100, '\n');
			cout<<"You killed the Wumpus!"<<endl;
			w_dead = true;
			cave[player_r+i][player_c] = '0';
			break;
		 }
	  }
   }
   if(direction == 4){
	  for(int i=0;i<4;i++){
		 if(player_c-i == -1){
			cout<<string(100, '\n');
			cout<<"You hit a wall"<<endl;
			if(w_dead == false){
			   move_w();
			}
			break;
		 }
		 else if(cave[player_r][player_c-i] != 'W'){
			cout<<string(100, '\n');
			cout<<"The arrow didn't hit anything"<<endl;
			if(w_dead == false&& i==3){
			   move_w();
			}
		 }
		 else if(cave[player_r][player_c-i] == 'W'){
			cout<<string(100, '\n');
			cout<<"You killed the Wumpus!"<<endl;
			w_dead = true;
			cave[player_r][player_c-i] = '0';
			break;
		 }
	  }
   }
}

/******************************************************************************
 **Function: move_w
 **Description: Moves the Wumpus 
 **Parameters: None
 **Pre_Conditions: The wumpus was woken up
 **Post_conditions: wumpus might be in a new location
 ******************************************************************************/

void room::move_w(){
   int chance;
   chance = rand()%4+1;

   if(chance!=1){
	  int r_num, c_num, w_num_r, w_num_c;
	  bool good = false;

	  for(int i=0; i<rows; i++){
		 for(int j=0; j<cols; j++){
			if(cave[i][j] == 'W'){
			   w_num_r=i;
			   w_num_c=j;
			}
		 }
	  }
	  cave[w_num_r][w_num_c] = '0';

	  while(good == false){
		 r_num = rand()%(rows);
		 c_num = rand()%(cols);

		 if(cave[r_num][c_num] == '0'){
			cave[r_num][c_num] = 'W';
			good = true;
		 }
	  }
   }
}

/******************************************************************************
 **Function: conditions
 **Description: Controls what happens when you move
 **Parameters: r, c
 **Pre_Conditions: Player has moved
 **Post_conditions: A hazard may happen, or nothing at all
 ******************************************************************************/

bool room::conditions(int r, int c){

   if(cave[r][c] == 'G'){
	  cout<<"You found gold!"<<endl;
	  has_gold = true;
	  return true;
   }

   else if(cave[r][c] == 'W'){
	  cout<<"You ran into the Wumpus and it ate you!"<<endl;
	  return false;
   }

   else if(cave[r][c] == 'B'){
	  cout<<"A group of bats picked you up and moved you!"<<endl;
	  bool empty = false;
	  player_r = rand()%(rows);
	  player_c = rand()%(cols);
	  conditions(player_r, player_c);
	  return true;
   }

   else if(cave[r][c] == 'P'){
	  cout<<"You fell into a bottomless pit!"<<endl;
	  return false;		
   }

   else if(cave[r][c] == '0'){
	  if(r==escape_r && c==escape_c){
		 if(w_dead == true && has_gold == true){
			return true;
		 }
		 else{
			cout<<"This where the escape rope is but you havn't killed"<<endl;
			cout<<"the Wumpus and found its gold yet"<<endl;
		 }
		 return true;	
	  }
	  else{
		 cout<<"You enter an empty room"<<endl;
		 return true;
	  }
	  return true;
   }
}
