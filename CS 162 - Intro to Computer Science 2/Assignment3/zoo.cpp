/******************************************************************************
 **Program:zoo.cpp
 **Author: Jonathan Ropp
 **Date:5/8/16
 **Description:Defines functions for the zoo class. Also holds almost all of the
 code to run Zoo Tycoon.
 **input:None
 **output:None
 ******************************************************************************/

#include "zoo.h"
/******************************************************************************
 **Function:zoo
 **Description:Default constructor for the zoo class
 **Parameters:None
 **Pre_Conditions:Is called
 **Post_conditions:A new zoo will be made
 ******************************************************************************/
zoo::zoo(){ // Default constructor
   total_money = 10000;
   daily_cost = 0;
   day = 0;
   //Dynamic arrays act as exhibits for animals
   t_exhibit = new tiger[1];
   p_exhibit = new penguin[1];
   pb_exhibit = new p_bear[1];
   m_exhibit = new monkey[1];
   //Ints to hold number of each animal
   t = 0;
   p = 0;
   pb = 0;	
   m = 0;
}
/*zoo::zoo(const zoo &other){ //Copy constructor
  total_money = other.total_money;
  daily_cost = other.daily_cost;
  day = other.day;
  t_exhibit = other.t_exhibit;
  p_exhibit = other.p_exhibit;
  pb_exhibit = other.pb_exhibit;
  x = other.x;
  y = other.y;
  z = other.z;
  t = other.t;
  p = other.p;
  pb = other.pb;
  }
  void zoo::operator=(const zoo &other){ //Operator overload
  total_money = other.total_money;
  daily_cost = other.daily_cost;
  day = other.day;
  t_exhibit = other.t_exhibit;
  p_exhibit = other.p_exhibit;
  pb_exhibit = other.pb_exhibit;
  x = other.x;
  y = other.y;
  z = other.z;
  t = other.t;
  p = other.p;
  pb = other.pb;
  }*/
/******************************************************************************
 **Function:~zoo
 **Description:Destructor for zoo class
 **Parameters:None
 **Pre_Conditions:zoo constructor has been called 
 **Post_conditions:The dynamic arrays for the exhibits will be deleted
 ******************************************************************************/
zoo::~zoo(){ 
   delete[] t_exhibit;
   delete[] p_exhibit;
   delete[] pb_exhibit;
   delete[] m_exhibit;
   cout<<"Thank you for playing!"<<endl;
}
/******************************************************************************
 **Function:get_t_money
 **Description:Returns total money from zoo class
 **Parameters:None
 **Pre_Conditions:Zoo has been constructred
 **Post_conditions:Total_money is returned
 ******************************************************************************/
int zoo::get_t_money(){
   return total_money;
}
/******************************************************************************
 **Function:get_d_cost
 **Description:Returns daily cost from zoo class
 **Parameters:None
 **Pre_Conditions:Zoo has been constructed
 **Post_conditions:daily_cost is returned
 ******************************************************************************/
int zoo::get_d_cost(){
   return daily_cost;
}
/******************************************************************************
 **Function:get_day
 **Description:returns the day from the zoo class
 **Parameters:None
 **Pre_Conditions:Zoo has been constructed
 **Post_conditions:day is returned
 ******************************************************************************/
int zoo::get_day(){
   return day;
}
/******************************************************************************
 **Function:increment_day
 **Description:increments day by one
 **Parameters:None
 **Pre_Conditions:zoo has been constructed
 **Post_conditions:day variable has been changed
 ******************************************************************************/
void zoo::increment_day(){
   day += 1;
}
/******************************************************************************
 **Function:refresh money
 **Description:Changes total_money based on parameter
 **Parameters:int money
 **Pre_Conditions:zoo has been constructed, parameters are good
 **Post_conditions:total_money will have been changed
 ******************************************************************************/
void zoo::refresh_money(int money){
   total_money = total_money + money;
}
/******************************************************************************
 **Function:choose_animal
 **Description:Asks user for an animal and how many to purchase, then changes
 variables as approopriate
 **Parameters:None
 **Pre_Conditions:zoo has been constructed
 **Post_conditions:User will have purchased 1 or more animals
 ******************************************************************************/
int zoo::choose_animal(){
   int choice = 0;
   int number;
   cout<<"What animal would you like to choose?"<<endl;
   cout<<"Tiger:1 ($"<<tiger().get_cost()<<")"<<endl;
   cout<<"Polar Bear:2 ($"<<p_bear().get_cost()<<")"<<endl;
   cout<<"Penguin:3 ($"<<penguin().get_cost()<<")"<<endl;
   cout<<"Monkey:4 ($"<<monkey().get_cost()<<")"<<endl;
   cin>>choice;
   if(choice == 1 || choice == 2 || choice == 3 || choice == 4){

	  cout<<"How many would you like to purchase?"<<endl;
	  cin>>number;
	  if(choice == 1){
		 if(number*tiger().get_cost()>total_money){
			cout<<string(100, '\n');
			cout<<"You don't have enough money to do that"<<endl;
		 }
		 else{
			t=t+number;	
			change_t_array(t+1);
			for(int i = 0; i<number-1; i++){			
			   t_exhibit[i] = tiger();

			}	
			cout<<string(100, '\n');
			cout<<"You just bought "<<number<<" tigers\nYou now have "<<t<<" tigers"<<endl;
			refresh_money(-(number*tiger().get_cost()));
		 }
	  }
	  else if(choice == 2){
		 if(number*p_bear().get_cost()>total_money){
			cout<<string(100, '\n');
			cout<<"You don't have enough money to do that"<<endl;
		 }
		 else{
			pb=pb+number;	
			change_pb_array(pb+1);
			for(int i = 0; i<number-1; i++){			
			   pb_exhibit[i] = p_bear();
			}
			cout<<string(100, '\n');
			cout<<"You just bought "<<number<<" polar bears\nYou now have "<<pb<<" polar bears"<<endl;
			refresh_money(-(number*p_bear().get_cost()));
		 }	

	  }

	  else if(choice == 3){
		 cout<<"in penguin"<<endl;
		 if(number*penguin().get_cost()>total_money){
			cout<<string(100, '\n');
			cout<<"You don't have enough money to do that"<<endl;
		 }
		 else{
			p=p+number;	
			change_p_array(p+1);
			for(int i = 0; i<number-1; i++){			
			   p_exhibit[i] = penguin();

			}
			cout<<string(100, '\n');
			cout<<"You just bought "<<number<<" penguins\nYou now have "<<p<<" penguins"<<endl;
			refresh_money(-(number*penguin().get_cost()));
		 }		
	  }
	  if(choice == 4){
		 if(number*monkey().get_cost()>total_money){
			cout<<string(100, '\n');
			cout<<"You don't have enough money to do that"<<endl;
		 }
		 else{
			m=m+number;	
			change_m_array(m+1);
			for(int i = 0; i<number-1; i++){			
			   m_exhibit[i] = monkey();

			}	
			cout<<string(100, '\n');
			cout<<"You just bought "<<number<<" monkeys\nYou now have "<<m<<" monkeys"<<endl;
			refresh_money(-(number*monkey().get_cost()));
		 }
	  }
   }
   else{
	  cout<<string(100, '\n');
	  cout<<"You did not enter a valid number"<<endl;
	  zoo::choose_animal();
   }
}
/******************************************************************************
 **Function:turn
 **Description:This is the menu for the game, letting the user choose what they
 want to do that day
 **Parameters:None
 **Pre_Conditions:zoo has been constructed
 **Post_conditions:Will be taken to a new function depending on choice
 ******************************************************************************/
int zoo::turn(){
   int choice;
   while(true){
	  cout<<string(100, '\n');
	  while(true){
		 int count = 0;
		 int i = 0;

		 cout<<"\n\nToday is day "<<zoo::get_day()<<"\nYou have:\n"
			"You have $"<<total_money<<"\n"
			"\t"<<t<<" Tigers\n"
			"\t"<<pb<<" Polar Bears\n"
			"\t"<<p<<" Penguins\n"
			"\t"<<m<<" Monkeys\n"
			"\nWhat would you like to do?"<<endl;
		 cout<<"\nBuy animals:1\nEnd day:2\nEnd game:0"<<endl;
		 cin>>choice;
		 if(choice == 1){
			zoo::choose_animal();
		 }
		 else if(choice == 2){
			int bankrupt = zoo::end_of_day();
			if (bankrupt == 0){
			   cout<<string(100, '\n');
			   cout<<"You ran out of money!"<<endl;
			   return 0;
			}
		 }
		 else if(choice == 0){
			cout<<string(100, '\n');
			return 0;
		 }
		 else{
			cout<<string(100, '\n');

			cout<<"Please enter a valid number"<<endl;
		 }
	  }
   }
}
/******************************************************************************
 **Function:day_cost
 **Description:Calculates the daily cost of feeding the animals
 **Parameters:None
 **Pre_Conditions:zoo has been constructed
 **Post_conditions:Total_cost will be returned with a new value
 ******************************************************************************/
int zoo::day_cost(){
   int total_cost=0;
   for(int i=0; i<t; i++){
	  total_cost += t_exhibit[i].get_food_cost();
   }
   for(int i=0; i<pb; i++){
	  total_cost += pb_exhibit[i].get_food_cost();
   }
   for(int i=0; i<p; i++){
	  total_cost += p_exhibit[i].get_food_cost();
   }
   for(int i=0; i<m; i++){
	  total_cost += m_exhibit[i].get_food_cost();
   }
   return total_cost;
}
/******************************************************************************
 **Function:day_income
 **Description:Calculates the daily income for the zoo
 **Parameters:None
 **Pre_Conditions:zoo has been constructed
 **Post_conditions:Returns day_prof with new value
 ******************************************************************************/
int zoo::day_income(){
   int day_prof = 0;
   for(int i=0; i<t; i++){
	  day_prof += t_exhibit[i].get_payoff();
   }
   for(int i=0; i<pb; i++){
	  day_prof += pb_exhibit[i].get_payoff();
   }
   for(int i=0; i<p; i++){
	  day_prof += p_exhibit[i].get_payoff();
   }	
   for(int i=0; i<m; i++){
	  day_prof += m_exhibit[i].get_payoff();
   }	
   return day_prof;
}
/******************************************************************************
 **Function:sickness
 **Description:The user will have to choose an animal to die b/c of sickness and
 then the appropriate variables are changed
 **Parameters:None
 **Pre_Conditions:zoo has been constructed and this is chosen as random event
 **Post_conditions:An animal will be subtracted from total
 ******************************************************************************/
void zoo::sickness(){
   int choice = 0;
   if(t>0||pb>0||p>0||m>0){
	  cout<<"A sickness as occured in the zoo!"<<endl;
	  cout<<"You have to choose an animal to die"<<endl;
	  cout<<"Pick a tiger (1), polar bear (2), penguin (3), or monkey (4)"<<endl;
	  cin>>choice;
	  if(choice == 1){
		 if(t<1){
			cout<<string(100, '\n');
			cout<<"You don't have any tigers"<<endl;
			sickness();
		 }
		 else{
			t--;
			change_t_array(t);
			cout<<"You now have "<<t<<" tigers"<<endl;
		 }

	  }
	  else if(choice == 2){
		 if(pb<1){
			cout<<string(100, '\n');
			cout<<"You don't have any polar bears"<<endl;
			sickness();
		 }
		 else{
			pb--;
			change_pb_array(pb);
			cout<<"You now have "<<pb<<" polar bears"<<endl;
		 }
	  }
	  else if(choice == 3){
		 if(p<1){
			cout<<string(100, '\n');
			cout<<"You don't have any penguins"<<endl;
			sickness();
		 }
		 else{
			p--;
			change_p_array(p);
			cout<<"You now have "<<p<<" penguins"<<endl;
		 }
	  }
	  else if(choice == 4){
		 if(m<1){
			cout<<string(100, '\n');
			cout<<"You don't have any monkeys"<<endl;
			sickness();
		 }
		 else{
			m--;
			change_m_array(m);
			cout<<"You now have "<<m<<" monkeys"<<endl;
		 }
	  }
   }
}
/******************************************************************************
 **Function:boom
 **Description:Boom in attendence means that tigers bring in more money today
 **Parameters:None
 **Pre_Conditions:zoo is constructed and this is chosen as random event
 **Post_conditions:total money will have changed(if user owns tigers)
 ******************************************************************************/
void zoo::boom(){
   cout<<"A lot of people wanted to see tigers today!"<<endl;
   int bonus = rand()%250+250;
   refresh_money(bonus*t);
   if(t>0){
	  cout<<"Each tiger has earned an extra $"<<bonus<<" today plus "<<endl;
   }
   else{
	  cout<<"Unfortunatly, you don't have any tigers for a bonus."<<endl;
   }
}
/******************************************************************************
 **Function:baby
 **Description:The user chooses an animal to have babies, then the appropriate
 variables will be changed
 **Parameters:None
 **Pre_Conditions:zoo has been constructed and this is the chosen random event
 **Post_conditions:The user will have new baby animals
 ******************************************************************************/
void zoo::baby(){
   int choice = 0;
   if(t>0||pb>0||p>0||m>0){
	  cout<<"An animal is going to have babies and you get to pick which type!"<<endl;
	  cout<<"Pick a tiger (1), polar bear (2), penguin (3), or monkey (4)"<<endl;
	  cin>>choice;
	  if(choice == 1){
		 if(t<1){
			cout<<string(100, '\n');
			cout<<"You don't have any tigers"<<endl;
			baby();
		 }
		 else{
			int check = 0;
			int i = 0;
			for(i; i<t; i++){
			   check = t_exhibit[i].get_age();
			   if(check>2){
				  i = t;
			   }
			}
			if(check>2){
			   int num_babies = t_exhibit[0].get_babies();
			   int x = t+num_babies;
			   change_t_array(x);
			   for(int i=t; i<x; i++){
				  t_exhibit[i].set_age(0);
				  t_exhibit[i].set_payoff(t_exhibit[0].get_cost()*.2);
				  t_exhibit[i].set_food_cost(t_exhibit[0].get_food_cost()*2);
			   }
			   cout<<"The tiger had "<<num_babies<<" babies and now you have "<<x<<" tigers!"<<endl;
			   t = t+num_babies;
			}
			else{
			   cout<<"You do not have an adult tiger"<<endl;
			   baby();
			}
		 }
	  }
	  else if(choice == 2){
		 if(pb<1){
			cout<<string(100, '\n');
			cout<<"You don't have any polar bears"<<endl;
			baby();
		 }
		 else{
			int check = 0;
			int i = 0;
			for(i; i<pb; i++){
			   check = pb_exhibit[i].get_age();
			   if(check>2){
				  i = pb;
			   }
			}
			if(check>2){
			   int num_babies = pb_exhibit[0].get_babies();
			   int x = pb+num_babies;
			   change_pb_array(x);
			   for(int i=pb; i<x; i++){
				  pb_exhibit[i].set_age(0);
				  pb_exhibit[i].set_payoff(pb_exhibit[0].get_cost()*.1);
				  pb_exhibit[i].set_food_cost(pb_exhibit[0].get_food_cost()*2);
			   }
			   cout<<"The polar bear had "<<num_babies<<" babies and now you have "<<x<<" polar bears!"<<endl;
			   pb = pb+num_babies;
			}
			else{
			   cout<<"You do not have an adult polar bear"<<endl;
			   baby();
			}
		 }
	  }
	  else if(choice == 3){
		 if(p<1){
			cout<<string(100, '\n');
			cout<<"You don't have any penguins"<<endl;
			baby();
		 }
		 else{
			int check = 0;
			int i = 0;
			for(i; i<p; i++){
			   check = p_exhibit[i].get_age();
			   if(check>2){
				  i = p;
			   }
			}
			if(check>2){
			   int num_babies = p_exhibit[0].get_babies();
			   int x = p+num_babies;
			   change_p_array(x);
			   for(int i=p; i<x; i++){
				  p_exhibit[i].set_age(0);
				  p_exhibit[i].set_payoff(p_exhibit[0].get_cost()*.1);
				  p_exhibit[i].set_food_cost(p_exhibit[0].get_food_cost()*2);
			   }
			   cout<<"The penguin had "<<num_babies<<" babies and now you have "<<x<<" penguins!"<<endl;
			   p = p+num_babies;
			}
			else{
			   cout<<"You do not have an adult penguin"<<endl;
			   baby();
			}
		 }
	  }
	  else if(choice == 4){
		 if(m<1){
			cout<<string(100, '\n');
			cout<<"You don't have any monkeys"<<endl;
			baby();
		 }
		 else{
			int check = 0;
			int i = 0;
			for(i; i<m; i++){
			   check = m_exhibit[i].get_age();
			   if(check>2){
				  i = m;
			   }
			}
			if(check>2){
			   int num_babies = m_exhibit[0].get_babies();
			   int x = m+num_babies;
			   change_m_array(x);
			   for(int i=m; i<x; i++){
				  m_exhibit[i].set_age(0);
				  m_exhibit[i].set_payoff(m_exhibit[0].get_cost()*.16);
				  m_exhibit[i].set_food_cost(m_exhibit[0].get_food_cost()*2);
			   }
			   cout<<"The monkey had "<<num_babies<<" babies and now you have "<<x<<" monkeys!"<<endl;
			   m = m+num_babies;
			}
			else{
			   cout<<"You do not have an adult monkey"<<endl;
			   baby();
			}
		 }
	  }
	  else{
		 cout<<string(100, '\n');
		 cout<<"Please enter a valid number"<<endl;
		 baby();
	  }
   }
}
/******************************************************************************
 **Function:rand_event
 **Description:Gets a random number (1-4) and chooses an event to happen 
 **Parameters:None
 **Pre_Conditions:zoo has been constructed
 **Post_conditions:Another function will be entered depending on randome number
 ******************************************************************************/
void zoo::rand_event(){
   srand(time(NULL));
   int event = rand()%4+1;
   cout<<"\n\n";
   if(event == 1){
	  sickness();
   }
   else if(event == 2){
	  boom();
   }
   else if(event == 3){
	  baby();
   }	
}
/******************************************************************************
 **Function:increment_age
 **Description:Increases all animal's ages by 1 at end of the day
 **Parameters:None
 **Pre_Conditions:zoo has been constructed
 **Post_conditions:age will be incremented for each animal
 ******************************************************************************/
void zoo::increment_age(){
   for(int i=0; i<t; i++){
	  t_exhibit[i].set_age(t_exhibit[i].get_age()+1);
	  if(t_exhibit[i].get_age() == 3){
		 t_exhibit[i].set_payoff(t_exhibit[0].get_cost()*.1);
		 t_exhibit[i].set_food_cost(t_exhibit[0].get_food_cost());
	  }
   }
   for(int i=0; i<pb; i++){
	  pb_exhibit[i].set_age(pb_exhibit[i].get_age()+1);
	  if(pb_exhibit[i].get_age() == 3){
		 pb_exhibit[i].set_payoff(pb_exhibit[0].get_cost()*.1);
		 pb_exhibit[i].set_food_cost(pb_exhibit[0].get_food_cost());
	  }
   }
   for(int i=0; i<p; i++){
	  p_exhibit[i].set_age(p_exhibit[i].get_age()+1);
	  if(p_exhibit[i].get_age() == 3){
		 p_exhibit[i].set_payoff(p_exhibit[0].get_cost()*.1);
		 p_exhibit[i].set_food_cost(p_exhibit[0].get_food_cost());
	  }
   }
   for(int i=0; i<m; i++){
	  m_exhibit[i].set_age(m_exhibit[i].get_age()+1);
	  if(m_exhibit[i].get_age() == 3){
		 m_exhibit[i].set_payoff(m_exhibit[0].get_cost()*.1);
		 m_exhibit[i].set_food_cost(m_exhibit[0].get_food_cost());
	  }
   }
}
/******************************************************************************
 **Function:end_of_day
 **Description:calculates/displays end of day stats and starts random event 
 **Parameters:None
 **Pre_Conditions:zoo is constructed
 **Post_conditions:Lots of variables are changed
 ******************************************************************************/
int zoo::end_of_day(){
   cout<<string(100, '\n');
   zoo::increment_day();
   zoo::increment_age();
   int total_cost = day_cost();
   int upkeep_cost = (t*150 + pb*100 + p*50 + m*75 +100);

   cout<<"You had to pay $"<<total_cost<<" to feed your animals"<<endl;
   cout<<"You had to pay $"<<upkeep_cost<<" in upkeep costs for your zoo"<<endl;
   refresh_money(-total_cost - upkeep_cost);
   cout<<"You have $"<<total_money<<endl;

   rand_event();

   int day_prof = day_income();

   cout<<"You earned $"<<day_prof<<" from people visiting the zoo"<<endl;
   refresh_money(day_prof);
   cout<<"You have $"<<total_money<<endl;
}	
/******************************************************************************
 **Function:change_pb_array
 **Description:changes the size of pb_exhibit
 **Parameters:int size
 **Pre_Conditions:zoo is constructed and parameters are good
 **Post_conditions:pb_exhibit is a new size
 ******************************************************************************/
void zoo::change_pb_array(int size){	
   p_bear *temp_pb = new p_bear[size];
   for(int i=1; i<size; i++){
	  temp_pb[i] = p_bear();
   }
   delete[] pb_exhibit;
   pb_exhibit = new p_bear[size];
   for(int i=1; i<size; i++){
	  pb_exhibit[i] = temp_pb[i];
   }
   delete[] temp_pb;
}
/******************************************************************************
 **Function:change_p_array
 **Description:Changes the size of p_exhibit
 **Parameters:int size
 **Pre_Conditions:oo is constructed and parameters are good
 **Post_conditions:p_exhibit is a new size
 ******************************************************************************/
void zoo::change_p_array(int size){

   penguin *temp_p = new penguin[size];
   for(int i=1; i<size; i++){
	  temp_p[i] = penguin();
   }
   delete[] p_exhibit;
   p_exhibit = new penguin[size];
   for(int i=1; i<size; i++){
	  p_exhibit[i] = temp_p[i];
   }
   delete[] temp_p;
}
/******************************************************************************
 **Function:change_t_array
 **Description:Changes the size of t_exhibit
 **Parameters:int size
 **Pre_Conditions:zoo is constructed and parameters are good
 **Post_conditions:t_exhibit is a new size
 ******************************************************************************/
void zoo::change_t_array(int size){	
   tiger *temp_t = new tiger[size];
   for(int i=1; i<size; i++){
	  temp_t[i] = tiger();
   }
   delete[] t_exhibit;
   t_exhibit = new tiger[size];
   for(int i=1; i<size; i++){
	  t_exhibit[i] = temp_t[i];
   }
   delete[] temp_t;

}
/******************************************************************************
 **Function:change_m_array
 **Description:Changes the size of m_exhibit
 **Parameters:int size
 **Pre_Conditions:zoo is constructed and parameters are good
 **Post_conditions:m_exhibit is a new size
 ******************************************************************************/
void zoo::change_m_array(int size){
   monkey *temp_m = new monkey[size];
   for(int i=1; i<size; i++){
	  temp_m[i] = monkey();
   }
   delete[] m_exhibit;
   m_exhibit = new monkey[size];
   for(int i=1; i<size; i++){
	  m_exhibit[i] = temp_m[i];
   }
   delete[] temp_m;
}