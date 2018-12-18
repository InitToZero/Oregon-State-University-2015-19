/***************************************************************
 * Program: state_facts.cpp
 * Author: Jonathan Ropp
 * Date: 4/10/2016
 * Input: txt file with state/county information, given by user
 * Output:
 ***************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "./state_facts.h"

/*************************************************************************************
 * Function : is_valid_arguments 
 * Description : Checks input arguments to see if good
 * Parameters : char **argv, int argc
 * Pre-conditions : None
 * Post-conditions : Will return bool for if args are good 
 * ***********************************************************************************/

bool is_valid_arguments(char **argv, int argc){

   int s = -1, f = -1;

   //If there are not 5 arguments, error msg and end program
   if(argc != 5){
	  cout<<"You did not enter the right number of arguments"<<endl;
	  return false;
   }
   //If user did not supply -s and -f, error msg and end program
   for(int i=1; i<argc; i+=2){
	  if(argv[i][0] == '-' && argv[i][1] == 's'){
		 if(s == 1){
			cout<<"Usage error"<<endl;
			return false;
		 }
		 s = 1;
	  }
	  else if(argv[i][0] == '-' && argv[i][1] == 'f'){
		 if(f == 1){
			cout<<"Usage error"<<endl;
			return false;
		 }
		 f = 1;
	  }
	  else{
		 cout<<"Usage error"<<endl;
		 return false;
	  }
   }

   //If input arguments are good, return true
   return true;
}
/*************************************************************************************
 * Function : create_states
 * Description : Dynamically create a 1-d array on the heap for state info
 * Parameters : int num
 * Pre-conditions : Paramters are good
 * Post-conditions : Will return the array made
 * ***********************************************************************************/
state * create_states(int num){

   //Make 1-d array on heap
   state *t;
   t = new state[num];

   //Return array
   return t;
}
/*************************************************************************************
 * Function : get_state_data
 * Description : Will read in state data and create county arrays based on input
 * Parameters : state *s, int num_state, ifstream &input
 * Pre-conditions : Paramters are good
 * Post-conditions : After funciton, state will have all info needed
 * ***********************************************************************************/
void get_state_data(state *s, int num_state, ifstream &input){

   //Input data for state struct
   input >> s[num_state].name;
   input >> s[num_state].population;
   input >> s[num_state].counties;

   //Create county array
   s[num_state].c = create_counties(s[num_state].counties);

   //Fill county array with data
   for(int i=0; i<s[num_state].counties; i++){
	  get_county_data(s[num_state].c, i, input);
   }
}
/*************************************************************************************
 * Function : create_counties
 * Description : Will dynamically create a 1-d array on the heap for county info
 * Parameters : int num
 * Pre-conditions : Paramters are good
 * Post-conditions : Will return array made
 * ***********************************************************************************/
county * create_counties(int num){

   //Create 1-d array
   county *o;
   o = new county[num];

   //Return array
   return o;
}
/*************************************************************************************
 * Function : get_county_data
 * Description : Will fill the county array and city string with data read in from file
 * Parameters : county *o, int num, ifstream & input
 * Pre-conditions : Paramters are good
 * Post-conditions : After this, city and county info will be done for this state
 * ***********************************************************************************/

void get_county_data(county *o, int num, ifstream & input){

   //Input data for county struct
   input >> o[num]. name;
   input >> o[num]. population;
   input >> o[num]. avg_income;
   input >> o[num]. avg_house;
   input >> o[num]. cities;

   //Create city array
   o[num].city=new string[o[num].cities];

   //Fill city array with data
   for(int j=0; j<(o[num].cities); j++){ 			 
	  input >> o[num].city[j];
   }
}
/*************************************************************************************
 * Function : delete_info
 * Description : Will delete allocated memory from heap
 * Parameters : state *s, int num
 * Pre-conditions : Paramters are good
 * Post-conditions : All memory should be freed
 * ***********************************************************************************/
void delete_info(state *s, int num){

   //Delete each city array

   for(int i=0; i<num; i++){
	  for(int j=0; j<s[i].counties; j++){
		 delete []s[i].c[j].city;
	  }
   }
   //Delete each county array
   for(int i=0; i<num; i++){
	  delete []s[i].c;
   }
   //Delete state array
   delete []s;   
}

/*************************************************************************************
 * Function : menu
 * Description : This prints menu and gets user input with error handling
 * Parameters : None
 * Pre-conditions : None
 * Post-conditions : Returns user choice for menu
 * ***********************************************************************************/
int menu(){

   int num;
   bool good=false;
   string input;

   //While the user wants to use the menu
   while(good == false){
	  cout<<"What would you like to see?"<<endl;
	  cout<<"(1) State with largest population"<<endl
		 <<"(2) County with largest population"<<endl
		 <<"(3) County with income above ___"<<endl
		 <<"(4) Average household income for all counties in each state"<<endl
		 <<"(5) States ordered by name"<<endl
		 <<"(6) States ordered by population"<<endl
		 <<"(7) Counties within states sorted by population"<<endl
		 <<"(8) Counties within states sorted by name"<<endl;

	  //Gets user input and makes sure it is a valid int; if not, print error and ask again
	  cin >> input;
	  for(int i=0; i<input.length();i++){
		 if(!(input.at(i)>='1'&&input.at(i)<='8')){
			cout << "Please enter a valid number. : ";
			cin >> input;
			i=-1;
		 }
	  }
	  num = atoi(input.c_str());
	  while (num > 8 || num < 1){
		 cout << "Please enter a valid number. : ";
		 cin >> num;
	  }
	  //Return the valid int to main
	  return num;
   }
}

/*************************************************************************************
 * Function : op1
 * Description : Will dispay the state with the largest population
 * Parameters : state *s, int num
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good 
 * ***********************************************************************************/
void op1(state *s, int num){

   int big_pop = s[0].population;
   int name_place = 0;
   //Cycle through states to find one with largest pop
   for(int i=1; i<num; i++){
	  if(s[i].population>big_pop){
		 big_pop = s[i].population;
	  }
	  name_place = i-1;
   }
   cout<<s[name_place].name<<" has the largest population: "<<big_pop<<endl;

}
/*************************************************************************************
 * Function : op2
 * Description : Will display county with largest population
 * Parameters : state *s, int num
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good 
 * ***********************************************************************************/
void op2(state *s, int num){

   int big_pop = s[0].c[0].population;
   int s_name_place = 0, c_name_place = 0;
   //Cycle through counties to find largest pop
   for(int i=0; i<num; i++){
	  for(int j=0; j<num; j++){
		 if(s[i].c[j].population>big_pop){
			big_pop = s[i].c[j].population;
			s_name_place = i;
			c_name_place = j;
		 }
	  }
   }
   cout<<s[s_name_place].c[c_name_place].name<<" county in "<<s[s_name_place].name<< " has the largest population: "<<big_pop<<endl;

}
/*************************************************************************************
 * Function : op3
 * Description : Displays counties with income above user input
 * Parameters : state *s, int num
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good 
 * ***********************************************************************************/
void op3(state *s, int num){

   string income;
   //Get input for income level
   cout<<"What income level would you like to set?"<<endl;
   cin >> income;

   //Make sure number is good
   for(int i=0; i<income.length();i++){
	  if(!(income.at(i)>='0'&&income.at(i)<='9')){
		 cout << "Please enter a valid number. : ";
		 cin >> income;
		 i=-1;
	  }
   }

   int v_num = atoi(income.c_str());
   while (v_num > 10000000 || v_num < 0){
	  cout<<"Please enter a valid number: ";
	  cin >> income;
   }


   for(int i=0; i<num; i++){
	  for(int j=0; j<s[i].counties; j++){
		 if(s[i].c[j].avg_income > v_num){
			//Print counties with income above set level
			cout<<s[i].c[j].name<<" with income of "<<s[i].c[j].avg_income<<endl;
		 }
	  }
   }
}
/*************************************************************************************
 * Function : op4
 * Description : Displays average houshold cost for all counties
 * Parameters : state *s, int num
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good 
 * ***********************************************************************************/
void op4(state *s, int num){
   cout<<"Average houseshould costs: "<<endl<<endl;
   for(int i=0; i<num; i++){
	  cout<<"State: "<<s[i].name<<endl<<endl;
	  for(int j=0; j<s[i].counties; j++){
		 cout<<s[i].c[j].name<<": "<<s[i].c[j].avg_house<<endl;
	  }
	  cout<<endl<<endl;
   }
}
/*************************************************************************************
 * Function : op5
 * Description : This function sorts and prints the states by name
 * Parameters : state *s, int num
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good 
 * ***********************************************************************************/
void op5(state *s, int num){

   string temp;
   for(int i=0; i<num; i++){
	  for (int j=0; j<num-1-i; j++){
		 if(s[j].name > s[j+1].name){
			temp = s[j].name;
			s[j].name = s[j+1].name;
			s[j+1].name = temp;
		 }
	  }
   }
   for(int k=0; k<num; k++){
	  cout<<s[k].name<<endl;
   }
}
/*************************************************************************************
 * Function : op6
 * Description : This function sorts and prints the states by population
 * Parameters : state *s, int num
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good 
 * ***********************************************************************************/
void op6(state *s, int num){


   int temp_i;
   string temp_s;
   for (int i=0; i<num; i++){
	  for (int j=0; j<num-1-i; j++){
		 if(s[j].population<s[j+1].population){
			temp_i = s[j].population;
			s[j].population = s[j+1].population;
			s[j+1].population = temp_i;

			temp_s = s[j].name;
			s[j].name = s[j+1].name;
			s[j+1].name = temp_s;

		 }
	  }
   }
   for(int k=0; k<num; k++){
	  cout<<s[k].name<<": "<<s[k].population<<endl;

   }
}
/*************************************************************************************
 * Function : op7
 * Description : This function sorts and prints the counties by population
 * Parameters : state *s, int num
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good 
 * ***********************************************************************************/
void op7(state *s, int num){
   /****NOT CORRECT******/
   int total_p =0;
   for(int i=0; i<num; i++){
	  total_p = total_p + s[i].counties;
   }
   float temp;
   float pop[total_p];
   int k = 0;
   while(k<total_p){
	  for(int i=0; i<num; i++){
		 for(int j=0; j<s[i].counties; j++){
		pop[k] = s[i].c[j].population;
			k++;
		 }
	  }
   }
   for(int y=0; y<total_p; y++){
	  if(pop[y]>pop[y+1]){
		 temp = pop[y];
		 pop[y] = pop[y+1];
		 pop[y+1] = temp;
		 y--;
	  }
   }
   for(int z=0; z<total_p; z++){
	  cout<<pop[z]<<"        "<<z<<endl; 
   }
}

/*************************************************************************************
 * Function : op8
 * Description : This function sorts and prints the counties by name
 * Parameters : state *s, int num
 * Pre-conditions : Paramters are good
 * Post-conditions : Parameters are still good 
 * ***********************************************************************************/
void op8(state *s, int num){
/**********NOT CORRECT***********/
   int total_c =0;
   for(int i=0; i<num; i++){
	  total_c = total_c + s[i].counties;
   }
   string temp;
   string counties[total_c];
   int k = 0;
   while(k<total_c){
	  for(int i=0; i<num; i++){
		 for(int j=0; j<s[i].counties; j++){
			counties[k] = s[i].c[j].name;
			k++;
		 }
	  }
   }
   for(int y=0; y<total_c; y++){
	  if(counties[y]>counties[y+1]){
		 temp = counties[y];
		 counties[y] = counties[y+1];
		 counties[y+1] = temp;
		 y--;
	  }
   }
   for(int z=0; z<total_c; z++){
	  cout<<counties[z]<<endl; 
   }
}

/*************************************************************************************
 * Function : run_again
 * Description : Asks user if they want to run through menu again
 * Parameters : none
 * Pre-conditions : none
 * Post-conditions : Parameters are still good 
 * ***********************************************************************************/
bool run_again(){

   bool good = false;
   cout<<"Would you like to run again? Yes(1) or no(2): ";
   //While the input is bad, keep asking
   while(good == false){  
	  string input;
	  int num;
	  cin >> input;

	  //If user did not input a 1 or 2, try again
	  for(int i=0; i<input.length();i++){
		 if(!(input.at(i)>='1'&&input.at(i)<='2')){
			cout << "Please enter a valid number : ";
			cin >> input;
			i=-1;
		 }
	  }
	  //Translate input to int
	  num = atoi(input.c_str());

	  //return true(1) or false(2)
	  if(num == 1){
		 return true;
	  }
	  else if(num == 2){
		 return false;
	  }
   }
}
