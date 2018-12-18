/*****************************************************************************
 ** Program Filename : Assignment4.cpp 
 ** Author : Jonathan Ropp
 ** Date : 2/17/2016
 ** Description :

	This program is a game similar to Wheel of Fortune.
 	This game is for 1-3 players.
 	There will need to be an owner of the game.
	This person will set up the game and input the hidden message for the players to guess and determine how many players and rounds.
	Players will take turns either spinning the wheel, buying a vowel, or trying to solve the puzzle.
 	After each round, the winner keeps their money and the others get set back to $0.
	After all rounds have been played, the winner is the one with the most money from all the rounds.  

 ** Input : 
 ** Output : 
 **************************************************************************/  

//Call libraries
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

/*****************************************************************************
 ** Function: win_cond
 ** Description: This will change the win condition to true
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 **************************************************************************/  
bool win_cond(){
   return true;
}

/*****************************************************************************
 ** Function: player_int
 ** Description: Gets user input for how many players are in the game
 ** Parameters: int *players
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
void player_int(int *players){

   //Declare variables
   bool good = false;

   cout <<"How many players are going to play? (Between 1 and 3)"<<endl;

   //Ask for number of players
   cin >> *players;

   while (good==false){
      //If the number is not between 1 and 3, keep asking for int
      if (*players<0 || *players>3){
	 cout << "Please enter a number between 1 and 3." <<endl;
	 cin >> *players;
      }
      //If good int, exit loop
      else{
	 good = true;
      }
   }
}

/*****************************************************************************
 ** Function: player_turn
 ** Description: Determines who's turn it is
 ** Parameters: int *players, int *k
 ** Pre-Conditions: Parameters are good 
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
int player_turn(int *players, int *k){

   //Declare variables
   int turn;  

   //If k <= number of players, turn = k
   if(*k<=*players){
      turn = *k;
   }
   //If k > number of players, set k back to 1
   else{
      *k = 1;
      turn = *k;
   }
   //Increment k by 1
   *k = *k+1;
   return turn;
}

/*****************************************************************************
 ** Function: rounds_int
 ** Description: Gets user input for how many rounds are going to be played
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *************************************************************************/  
int rounds_int(){

   //Declare variables
   bool good = false;
   int rounds;

   cout <<"How many rounds are you going to play?"<<endl;

   //Get user input for # of rounds
   cin >> rounds;
   while (good==false){

      //If input is negative, keep asking for int
      if (rounds<=0){
	 cout << "Please enter a positive number." <<endl;
	 cin >> rounds;
      }
      else{
	 //If input is good, exit loop
	 good = true;
	 return rounds;
      }
   }
}

/*****************************************************************************
 ** Function: convert_guess
 ** Description: Sets user input char to lowercase
 ** Parameters: char temp
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
char convert_guess(char temp){

   if (isupper(temp)){
      temp = tolower(temp);
   }
   return temp;
}

/*****************************************************************************
 ** Function: convert_str_guess
 ** Description: Sets user input string to lowercase
 ** Parameters: string temp_str
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
string convert_str_guess(string temp_str){

   char c;
   for(int i=0; i <=temp_str.length(); i++){
      c = temp_str[i];
      if (isupper(c)){
	 c = tolower(c);
	 temp_str[i]= c;      
      }
   }
   return temp_str; 
}
/*****************************************************************************
 ** Function: convert_h_msg
 ** Description: Sets user input hidden message string to lowercase
 ** Parameters: string *h_msg
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
void convert_h_msg(string *h_msg){

   string temp_h = *h_msg;
   char c;
   for(int i=0; i <=temp_h.length(); i++){
      c = temp_h[i];
      if (isupper(c)){
	 c = tolower(c);
	 temp_h[i]= c;      
      }
   }
   *h_msg = temp_h;
}
/*****************************************************************************
 ** Function: set_hmsg
 ** Description: Get user input for the secret message
 ** Parameters: string *h_msg
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
void set_hmsg(string *h_msg){

   cin.ignore();   
   cout << "Please have the owner enter the secret message." <<endl;

   //Get user input for hidden message
   getline(cin, *h_msg);
   convert_h_msg(h_msg);

}

/*****************************************************************************
 ** Function: message
 ** Description: Takes the hidden message and converts it to underscores
 ** Parameters: string *h_msg
 ** Pre-Conditions: h_msg is good string that can be pointed to 
 ** Post-Conditions: h_msg is good string that can be pointed to
 *************************************************************************/  
string message(string *h_msg){

   //Declare variable and set equal to h_msg
   string msg = *h_msg;

   //Check each character in the string
   for(int i=0; i<msg.length(); ++i)
   {
      //If character is a letter, change it to a '_'
      if(isalpha(msg[i])){
	 msg[i] ='-';
      }
   } 
   //Print message as underscores
   cout << msg << endl;
   return msg;
}

/*****************************************************************************
 ** Function: moneyf
 ** Description: Changes player money ammonut
 ** Parameters: int *whos_turn, int dol, int *money_1, int *money_2, int *money_3
 ** Pre-Conditions: Parameters are good ints
 ** Post-Conditions: Player money balances are good ints
 *************************************************************************/  
void moneyf(int *whos_turn, int dol, int *money_1, int *money_2, int *money_3){

   //If it is player 1's turn, change their money and print out new value
   if (*whos_turn == 1){
      *money_1 = *money_1 + dol;
      cout<<"You have $"<<*money_1<<endl;
   }
   //If it is player 2's turn, change their money and print out new value
   if (*whos_turn == 2){
      *money_2 = *money_2 + dol;
      cout<<"You have $"<<*money_2<<endl;
   }
   //If it is player 3's turn, change their money and print out new value
   if (*whos_turn == 3){
      *money_3 = *money_3 + dol;
      cout<<"You have $"<<*money_3<<endl;
   }
}

/*****************************************************************************
 ** Function: update_message
 ** Description: Change underscores from message to their coorisponding letters in h_msg if they were guessed by player during spin
 ** Parameters: char cons, string *msg, string h_msg
 ** Pre-Conditions: Parameters are good 
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
void update_message(char cons, string *msg, string h_msg){

   //Create dummy variable and set equal to msg
   string chng_msg = *msg;

   //Check every character in msg string
   for(int i=0; i<h_msg.length(); ++i)
   {
      //If a char in h_msg == guessed char, set them equal in chng_msg
      if(h_msg[i]== cons){
	 chng_msg[i] = cons;
      }
   } 
   //Set msg to new message string
   *msg = chng_msg;
}
/*****************************************************************************
 ** Function: guess_cons
 ** Description: Gets user guess for a consonant, checks if guess is in the hidden message. If it was, award money, update message, continue player turn. If not, go to next player
 ** Parameters: int *whos_turn, string h_msg, int rnum, int *money_1, int *money_2, int *money_3, string *msg, int *players, int *k
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
void guess_cons(int *whos_turn, string h_msg, int rnum, int *money_1, int *money_2, int *money_3, string *msg, int *players, int *k){

   //Declare variables
   char cons;
   int letters = 0, dol;

   //Get user guess
   cout << "Please guess a consonant: ";
   cin >> cons;
   cons = convert_guess(cons);

   //Check to see if guess is in the hidden message and log how many times
   for(int i=0; i<h_msg.length(); ++i)
   {
      if(cons == h_msg[i]){
	 letters = letters+1;
      }
   }
   cout << "There were "<<letters<<" letters revealed!"<<endl;
   //Dollar amount = letters found * what number they spun
   dol = letters*rnum;
   moneyf(whos_turn, dol, money_1, money_2, money_3);
   if (letters>=1){
      //Print out earnings and update message
      cout << "You have earned $"<< letters*rnum <<endl;
      update_message(cons, msg, h_msg);
   }
   else if (letters == 0){
      //Go to next players turn
      cout << "Im sorry, that is the end of your turn." <<endl;
      *whos_turn = player_turn(players, k);
   }
}
/*****************************************************************************
 ** Function: bankrupt
 ** Description: Sets current player's money to 0
 ** Parameters: int *whos_turn, int *money_1, int *money_2, int *money_3
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
void bankrupt(int *whos_turn, int *money_1, int *money_2, int *money_3){
   if (*whos_turn == 1){
      *money_1 = 0;
      cout<<"You have $"<<*money_1<<endl;
   }
   else if(*whos_turn == 2){
      *money_2 = 0;
      cout<<"You have $"<<*money_1<<endl;
   }
   else if(*whos_turn == 3){
      *money_3 = 0;
      cout<<"You have $"<<*money_1<<endl;
   }
}
/*****************************************************************************
 ** Function: spin
 ** Description: Determines random number when player spins. If the number is 0 or 21, bankrupt player or they lsoe their turn repectivly
 ** Parameters: string h_msg, int *whos_turn, int *money_1, int *money_2, int *money_3, string *msg, int *players, int *k
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
void spin(string h_msg, int *whos_turn, int *money_1, int *money_2, int *money_3, string *msg, int *players, int *k){

   //Declare variables
   int rnum, dol; 

   //Get a random number between 0 and 21
   srand(time(NULL));
   rnum = rand()%22;

   cout << "You spun the wheel. It landed on " << rnum << "." <<endl;
   if (rnum==0){
      //If number was 0, bankrupt player and go to next turn
      cout << "You have gone bankrupt!" << endl;
      bankrupt(whos_turn, money_1, money_2, money_3);
      *whos_turn = player_turn(players, k);

   }
   else if (rnum==21){
      //If number was 21, go to next player turn
      cout << "You have lost your turn!"<<endl;
      *whos_turn = player_turn(players, k);
   }
   else{
      //Call function to have player guess consonant
      guess_cons(whos_turn, h_msg,rnum, money_1, money_2, money_3, msg, players, k);

   }
}

/*****************************************************************************
 ** Function: turn_choice
 ** Description: Prints whos turn it is and their money. then asks what they would like to do on their turn (no input)
 ** Parameters: int *whos_turn, int *money_1, int *money_2, int *money_3, string *msg
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
int turn_choice(int *whos_turn, int *money_1, int *money_2, int *money_3, string *msg){

   //Declare variables
   int choice;
   //Print out whos turn it is and how much money they have
   cout << "\n\n"<<*msg <<endl;
   cout << "Player "<< *whos_turn <<", it is your turn."<<endl;
   if (*whos_turn == 1){
      cout << "You have $"<<*money_1 <<endl;
   }
   if (*whos_turn == 2){
      cout << "You have $"<<*money_2 <<endl;
   }
   if (*whos_turn == 3){
      cout << "You have $"<<*money_3 <<endl;
   }
   //Ask user what they want to do and get input
   cout << "\nWhat would you like to do on your turn?"<<endl;
   cout << "Type 1 to spin, 2 to buy a vowel($10), or 3 to solve."<<endl;
   cin >> choice;
   return choice;
}
/*****************************************************************************
 ** Function: whos_money
 ** Description: Determine whos money is going to be changed by whos turn it is
 ** Parameters: int *whos_turn, int *money_1, int *money_2, int *money_3
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
int whos_money(int *whos_turn, int *money_1, int *money_2, int *money_3){

   //Declare temp variable
   int temp;
   //If it is player 1's turn, return their money variable
   if (*whos_turn == 1){
      temp = *money_1;
   }
   //If it is player 1's turn, return their money variable
   if (*whos_turn == 2){
      temp = *money_2;
   }
   //If it is player 1's turn, return their money variable
   if (*whos_turn == 3){
      temp = *money_3;
   }
   return temp;
}
/*****************************************************************************
 ** Function: check_money
 ** Description: Make sure that the player has enough money to buy a vowel ($10)
 ** Parameters: int player_money
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
bool check_money(int player_money){

   //If the player has at least $10, return true
   if (player_money >= 10){
      return true;
   }
   else{
      return false;
   }
}
/*****************************************************************************
 ** Function: guess_vowel
 ** Description: Asks user to input their guess for a vowel and then updates message
 ** Parameters: string h_msg, string *msg, update_message()
 ** Pre-Conditions: Parameters are good and update_message is good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
void guess_vowel(string h_msg, string *msg){

   //Create variable to store guess
   char v;
   int letters = 0;
   cout<<"Please guess a vowel:";
   //Get user guess 
   cin >> v;
   v = convert_guess(v);
   //Run update_message function
   update_message(v, msg, h_msg);
   //Check to see if guess is in the hidden message and log how many times
   for(int i=0; i<h_msg.length(); ++i)
   {
      if(v == h_msg[i]){
	 letters = letters+1;
      }
   }
   cout << "There were "<<letters<<" letters revealed!"<<endl;
}
/*****************************************************************************
 ** Function: buy_vowel
 ** Description: Buy vowel option for the player
 ** Parameters: int *whos_turn, string h_msg, int *money_1, int *money_2, int *money_3, string *msg, int *players, int *k, whos_money(), check_money(), moneyf(), guess_vowel()
 ** Pre-Conditions: Parameters and functions are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
void buy_vowel(int *whos_turn, string h_msg, int *money_1, int *money_2, int *money_3, string *msg, int *players, int *k){

   //Declare variables
   int dol;
   int temp =  whos_money(whos_turn, money_1, money_2, money_3);
   bool money = check_money(temp);

   //If the player doesnt have enough money, print message
   if (money==false){
      cout << "I am sorry, you dont have enough money to buy a vowel."<<endl;

   }
   //If the player does have enough money, subtract $10 and have them guess
   else if (money==true){
      dol = -10; 
      moneyf(whos_turn, dol, money_1, money_2, money_3);
      guess_vowel(h_msg, msg);
   }  
}
/*****************************************************************************
 ** Function: end_round 
 ** Description: Lets the winner of the round keep their money in total money but sets all round money pools to 0
 ** Parameters: int *whos_turn, int *money_1, int *money_2, int *money_3, int *total_money_1, int *total_money_2, int *total_money_3
 ** Pre-Conditions: Parameters and functions are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
void end_round(int *whos_turn, int *money_1, int *money_2, int *money_3, int *total_money_1, int *total_money_2, int *total_money_3){

   //If it is player 1's turn, keep their money
   if (*whos_turn == 1){
      *total_money_1 = *total_money_1 + *money_1;
      *money_1 = 0;
      *money_2 = 0;
      *money_3 = 0;
   }
   //If it is player 2's turn, keep their money
   if (*whos_turn == 2){
      *total_money_2 = *total_money_2 + *money_2;
      *money_1 = 0;
      *money_2 = 0;
      *money_3 = 0;
   }
   //If it is player 3's turn, keep their money
   if (*whos_turn == 3){
      *total_money_3 = *total_money_3 + *money_3;
      *money_1 = 0;
      *money_2 = 0;
      *money_3 = 0;
   }
}
/*****************************************************************************
 ** Function: solve
 ** Description: Ask for user's guess for message and either end their turn or end the round with the as the winner
 ** Parameters: string h_msg, in *whos_turn, int *players, int *k, whos_turn()
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: parameters are still good
 *************************************************************************/  
bool solve(string h_msg, int *whos_turn, int *players, int *k, int *money_1, int *money_2, int *money_3, int *total_money_1, int *total_money_2, int *total_money_3){

   //Delclare variables
   string guess;

   //Get user guess
   cin.ignore();
   cout<< "Please enter your guess." << endl; 
   getline(cin, guess);
   guess = convert_str_guess(guess);

   //If guess was coreect, congratulate and set win condition to true
   if (guess == h_msg){
      cout<< "Congratulations player "<<*whos_turn<<", you win the round!"<<endl;
      end_round(whos_turn, money_1, money_2, money_3, total_money_1, total_money_2, total_money_3);
      return win_cond();
   }
   //If incorrect, end their turn.
   else{
      cout<< "I am sorry, that is incorrect."<<endl;
      *whos_turn = player_turn(players, k);
   }
}
/*****************************************************************************
 ** Function: turn
 ** Description: Based on user input, either run spin, buy_vowel, or solve
 ** Parameters: int *whos_turn, string h_msg, int *money_1, int *money_2, int *money_3, string *msg, int *players, int *k, turn_choice(), spin(), buy_vowel(), solve()
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
bool turn(int *whos_turn, string h_msg, int *money_1, int *money_2, int *money_3, string *msg, int *players, int *k, int *total_money_1, int *total_money_2, int *total_money_3){

   //Declare variable = to turn_choice output
   int turnc = turn_choice(whos_turn, money_1, money_2, money_3,  msg);
   //If user chose 1, run spin function
   if (turnc==1){
      spin(h_msg, whos_turn, money_1, money_2, money_3, msg, players, k);
   }
   //If user chose 2, run buy_vowel function
   else if (turnc==2){
      buy_vowel(whos_turn, h_msg, money_1, money_2, money_3, msg, players, k);
   }
   //If user chose 3, run solve function
   else if (turnc==3){
      return solve(h_msg,whos_turn, players, k,  money_1, money_2, money_3, total_money_1, total_money_2, total_money_3);
   }
   //Else, get new input
   else{
      cout << "Please enter either 1, 2, or 3."<<endl;
      cin >> turnc;
   }
}

/*****************************************************************************
 ** Function: print_message
 ** Description: Prints the visable message to players
 ** Parameters: string current_msg
 ** Pre-Conditions: Paramters are good
 ** Post-Conditions: Parameters are still good
 *************************************************************************/  
void print_message(string current_msg){

   //Print current message
   cout << current_msg <<endl;
}

/*****************************************************************************
 ** Function: print_totals
 ** Description: This contains the entire program and declares some variables
 ** Parameters: int *total_money_1, int *total_money_2, int *total_money_3
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameter are still good
 **************************************************************************/  
void print_totals(int *total_money_1, int *total_money_2, int *total_money_3, int *players){

   //Print out player totals
   if (*players == 1){
   cout<<"Player 1 has $"<<*total_money_1<<endl;
   }
   else if (*players == 2){
   cout<<"Player 1 has $"<<*total_money_1<<endl;
   cout<<"Player 2 has $"<<*total_money_2<<endl;
   }
   else if (*players == 3){
   cout<<"Player 1 has $"<<*total_money_1<<endl;
   cout<<"Player 2 has $"<<*total_money_2<<endl;
   cout<<"Player 3 has $"<<*total_money_3<<endl;
   }
}
/*****************************************************************************
 ** Function: who_won
 ** Description: Compares total money values of players and prints out the winner
 ** Parameters: int *total_money_1, int *total_money_2, int *total_money_3
 ** Pre-Conditions: Parameters are good
 ** Post-Conditions: Parameters are good
 **************************************************************************/  
void who_won(int *total_money_1, int *total_money_2, int *total_money_3){

   if(*total_money_1 > *total_money_2 && *total_money_1 > *total_money_3){
      cout<<"\nPlayer 1 is the winner!"<<endl;	
   }
   else if(*total_money_2 > *total_money_1 && *total_money_1 > *total_money_3){
      cout<<"\nPlayer 2 is the winner!"<<endl;	
   }
   else if(*total_money_3 > *total_money_1 && *total_money_1 > *total_money_2){
      cout<<"\nPlayer 3 is the winner!"<<endl;	
   }
}
/*****************************************************************************
 ** Function: main
 ** Description: This contains the entire program and declares some variables
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 **************************************************************************/  
int main(){

   //Declare variables
   int money_1=0, money_2=0, money_3=0, k = 1, players, whos_turn, rounds, total_money_1=0, total_money_2=0, total_money_3=0;
   string h_msg, msg;

   //Get user input for #players, #rounds, and make sure that player 1 goes first
   player_int(&players);
   rounds = rounds_int();
   whos_turn = player_turn(&players, &k);

   for(int i=0; i<rounds; i++){
      bool win = false;
      if(i>=1){
	 cout<< "Please press enter." <<endl;
      }
      //Get hidden message from user
      set_hmsg(&h_msg);
      //Make hidden message underscores
      msg = message(&h_msg);
      system("clear");
      print_totals(&total_money_1, &total_money_2, &total_money_3, &players);

      while(win==false){
	 //While the win condition is false, play the round
	 win = turn(&whos_turn, h_msg, &money_1, &money_2, &money_3, &msg, &players, &k, &total_money_1, &total_money_2, &total_money_3);
      }
   }
   print_totals(&total_money_1, &total_money_2, &total_money_3, &players);
   who_won(&total_money_1, &total_money_2, &total_money_3);
   return 0;
}
