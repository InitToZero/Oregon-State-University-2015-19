/***************************************************************
 * Program: run_facts.cpp
 * Author: Jonathan Ropp
 * Date: 4/10/2016
 * Input: txt file with state/county information, given by user
 * Output:
 ***************************************************************/

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "./state_facts.h"

int main(int argc, char** argv){

   //Check if good args
   bool good_arg = is_valid_arguments(argv, argc);
   if (good_arg == false){
	  return 0;
   }

   //Create variables
   int num_states;
   state *s;
   ifstream input;
   string filename;
   num_states = atoi(argv[2]);
   bool again = true;

   //If bad number of states, ask for new number
   if(num_states<1||num_states>50){
	  num_states = atoi(argv[4]);
	  if(num_states<1||num_states>50){


		 bool bad_num = true;
		 while(bad_num==true){

			cout<<"You entered a bad number"<<endl;
			cout<<"Please enter a new number: ";
			cin >> num_states;

			if(num_states<1||num_states>50)
			   bad_num = true;

			else
			   bad_num = false;
		 }
	  }
   }

   //Open file
   input.open(argv[2]);
   filename = argv[2];
   if(input.fail()){
	  input.close();
	  input.open(argv[4]);
	  filename = argv[4];
   }
   //If no file, ask for new file
   while(input.fail()){
	  input.close();
	  cout<<"No file"<<endl;
	  cout<<"Please enter a new file: ";
	  cin >> filename;
	  input.open(filename.c_str());
   }

   //Read in file
   s = create_states(num_states);
   for(int i=0; i<num_states; i++){
	  get_state_data(s,i,input); 
   }

   //Close file
   input.close();

   //While user wants to use menu
   while(again == true){

	  //Print menu and get user choice
	  int choice = menu();

	  if(choice == 1){
		 op1(s,num_states);
	  }
	  else if(choice == 2){
		 op2(s, num_states);
	  }
	  else if(choice == 3){
		 op3(s, num_states);
	  }
	  else if(choice == 4){
		 op4(s, num_states);
	  }
	  else if(choice == 5){
		 op5(s, num_states);
	  }
	  else if(choice == 6){
		 op6(s, num_states);
		 //Reset info
		 input.open(filename.c_str());
		 for(int i=0; i<num_states; i++){
			get_state_data(s,i,input);
		 } 
		 input.close();
	  }
	  else if(choice == 7){
		 op7(s, num_states);
		 //Reset info
		 input.open(filename.c_str());
		 for(int i=0; i<num_states; i++){
			get_state_data(s,i,input);
		 } 
		 input.close();
	  }
	  else if(choice == 8){
		 op8(s, num_states);
	  }
	  //Asks user if they want to use again
	  again = run_again();
   }   
   //Delete allocated memory
   delete_info(s, num_states);
   return 0;
}
