/*********************************************************************
 * Program: Assignment5.cpp
 * Author: Jonathan Ropp
 * Date: 2/28/2016
 * Description: This program translates morse to text and text to 
 * 				morse. The user will choose which translation to 
 * 				do and then enter either a text sentence or a 
 * 				message in morse code to have translated. 
 * 				NOTE: There is currently no error handling.
 ********************************************************************/ 

#include <iostream>

using namespace std;

void dot_dash_dash_dot_5(char str[], int *k, bool *msg){
   if (str[*k+4] == '\0'){
	  cout << 'p';
	  *msg = false;
   }
   else{ //if (str[k+4] == ' '){
	  cout << 'p';
	  *k = *k+4;
   }
   }

   void dot_dash_dash_dash_5(char str[], int *k, bool *msg){
	  if (str[*k+4] == '\0'){
		 cout << 'j';
		 *msg = false;
	  }
	  else{ //(str[k+4] == ' '){
		 cout << 'j';
		 *k = *k+4;
	  }
	  }	


	  void dot_dash_dash_4(char str[], int *k, bool *msg){
		 if (str[*k+3] == '\0'){
			cout << 'w';
			*msg = false;
		 }
		 else if (str[*k+3] == ' '){
			cout << 'w';
			*k = *k+3;
		 }
		 else if (str[*k+3] == '.'){
			dot_dash_dash_dot_5(str, k, msg);
		 }
		 else if (str[*k+3] == '-'){
			dot_dash_dash_dash_5(str, k, msg);
		 }

	  }

	  void dot_dash_dot_dot_5(char str[], int *k, bool *msg){
		 if (str[*k+4] == '\0'){
			cout << 'l';
			*msg = false;
		 }
		 else{ 
			cout << 'l';
			*k = *k+4;
		 }
	  }
	  void dot_dash_dot_4(char str[], int *k, bool *msg){
		 if (str[*k+3] == '\0'){
			cout << 'r';
			*msg = false;
		 }
		 else if (str[*k+3] == '.'){
			dot_dash_dot_dot_5(str, k, msg);
		 }
		 else {
			cout << 'r';
			*k = *k+3;
		 }
	  }
	  void dot_dash_3(char str[], int *k, bool *msg){
		 if (str[*k+2] == '\0'){
			cout << 'a';
			*msg = false;
		 }
		 else if (str[*k+2] == ' '){
			cout << 'a';
			*k = *k+2;
		 }
		 else if (str[*k+2] == '-'){
			dot_dash_dash_4(str, k, msg);

		 }
		 else if (str[*k+2] == '.'){
			dot_dash_dot_4(str, k, msg);

		 }
	  }

	  void dot_dot_dot_dot_5(char str[], int *k, bool *msg){
		 if (str[*k+4] == '\0'){
			cout << 'h';
			*msg = false;
		 }
		 else{ //if(str[k+4] == ' '){
			cout << 'h';
			*k = *k+4;
		 }

		 }
		 void dot_dot_dot_dash_5(char str[], int *k, bool *msg){
			if (str[*k+4] == '\0'){
			   cout << 'v';
			   *msg = false;
			}
			else{ //if(str[k+4 == ' '){
			   cout << 'v';
			   *k = *k+4;
			}

			}
			void dot_dot_dot_4(char str[], int *k, bool *msg){
			   if (str[*k+3] == '\0'){
				  cout << 's';
				  *msg = false;
			   }
			   else if (str[*k+3] == ' '){
				  cout << 's';
				  *k = *k+3;
			   }
			   else if (str[*k+3] == '.'){
				  dot_dot_dot_dot_5(str, k, msg);
			   }
			   else if (str[*k+3] == '-'){
				  dot_dot_dot_dash_5(str, k, msg);
			   }
			}

			void dot_dot_dash_dot_5(char str[], int *k, bool *msg){
			   if (str[*k+4] == '\0'){
				  cout << 'f';
				  *msg = false;
			   }
			   else{ //if (str[k+4] == ' '){
				  cout << 'f';
				  *k = *k+4;
			   }
			   }
			   void dot_dot_dash_4(char str[], int *k, bool *msg){
				  if (str[*k+3] == '\0'){
					 cout << 'u';
					 *msg = false;
				  }
				  else if (str[*k+3] == '.'){
					 dot_dot_dash_dot_5(str, k, msg);
				  }
				  else{// if (str[k+3] == ' '){
					 cout << 'u';
					 *k = *k+3;
				  }

				  }
				  void dot_dot_3(char str[], int *k, bool *msg){
					 if (str[*k+2] == '\0'){
						cout << 'i';
						*msg = false;
					 }
					 else if (str[*k+2] == ' '){
						cout << 'i';
						*k = *k+2;
					 }
					 else if (str[*k+2] == '.'){
						dot_dot_dot_4(str, k, msg);
					 }
					 else if (str[*k+2] == '-'){
						dot_dot_dash_4(str, k, msg);
					 }
				  }


				  void dot_2(char str[], int *k, bool *msg){

					 if (str[*k+1] == '\0'){
						cout << 'e';
						*msg = false;
					 }
					 else if (str[*k+1] == ' '){
						cout << 'e';
						*k = *k+1;
					 }
					 else if (str[*k+1] == '-'){

						dot_dash_3(str, k, msg);
					 }
					 else if (str[*k+1] == '.'){

						dot_dot_3(str, k, msg);
					 }
				  }

				  void dash_dash_dash_4(char str[], int *k, bool *msg){
					 if (str[*k+3] == '\0'){
						cout << 'o';
						*msg = false;
					 }
					 else{// if (str[k+3] == ' '){
						cout << 'o';
						*k = *k+3;
					 }	
					 }

					 void dash_dash_dot_dot_5(char str[], int *k, bool *msg){
						if (str[*k+4] == '\0'){
						   cout << 'z';
						   *msg = false;
						}
						else{// if (str[k+4] == ' '){
						   cout << 'z';
						   *k = *k+4;
						}
						}

						void dash_dash_dot_dash_5(char str[], int *k, bool *msg){
						   if (str[*k+4] == '\0'){
							  cout << 'q';
							  *msg = false;
						   }
						   else{// if (str[k+4] == ' '){
							  cout << 'q';
							  *k = *k+4;
						   }
						   }

						   void dash_dash_dot_4(char str[], int *k, bool *msg){
							  if (str[*k+3] == '\0'){
								 cout << 'g';
								 *msg = false;
							  }
							  else if (str[*k+3] == ' '){
								 cout << 'g';
								 *k = *k+3;
							  }
							  else if (str[*k+3] == '.'){
								 dash_dash_dot_dot_5(str, k, msg);
							  }
							  else if (str[*k+3] == '-'){
								 dash_dash_dot_dash_5(str, k, msg);
							  }
						   }
						   void dash_dash_3(char str[], int *k, bool *msg){

							  if (str[*k+2] == '\0'){
								 cout << 'm';
								 *msg = false;
							  }
							  else if (str[*k+2] == ' '){
								 cout << 'm';
								 *k = *k+2;
							  }
							  else if (str[*k+2] == '-'){
								 dash_dash_dash_4(str, k, msg);
							  }
							  else if (str[*k+2] == '.'){
								 dash_dash_dot_4(str, k, msg);
							  }

						   }
						   void dash_dot_dot_dot_5(char str[], int *k, bool *msg){ 
							  if (str[*k+4] == '\0'){
								 cout << 'b';
								 *msg = false;
							  }
							  else{// if (str[k+4] == ' '){
								 cout << 'b';
								 *k = *k+4;
							  }
							  }
							  void dash_dot_dot_dash_5(char str[], int *k, bool *msg){
								 if (str[*k+4] == '\0'){
									cout << 'x';
									*msg = false;
								 }
								 else{// if (str[k+4] == ' '){
									cout << 'x';
									*k = *k+4;
								 }
								 }

								 void dash_dot_dot_4(char str[], int *k, bool *msg){
									if (str[*k+3] == '\0'){
									   cout << 'd';
									   *msg = false;
									}
									else if (str[*k+3] == ' '){
									   cout << 'd';
									   *k = *k+3;
									}
									else if (str[*k+3] == '.'){
									   dash_dot_dot_dot_5(str, k, msg);
									}
									else if (str[*k+3] == '-'){
									   dash_dot_dot_dash_5(str, k, msg);
									}
								 }

								 void dash_dot_dash_dot_5(char str[], int *k, bool *msg){
									if (str[*k+4] == '\0'){
									   cout << 'c';
									   *msg = false;
									}
									else{// if (str[k+4] == ' '){
									   cout << 'c';
									   *k = *k+4;
									}
									}

									void dash_dot_dash_dash_5(char str[], int *k, bool *msg){
									   if (str[*k+4] == '\0'){
										  cout << 'y';
										  *msg = false;
									   }
									   else{ //if (str[k+4] == ' '){
										  cout << 'y';
										  *k = *k+4;
									   }
									   }

									   void dash_dot_dash_4(char str[], int *k, bool *msg){
										  if (str[*k+3] == '\0'){
											 cout << 'k';
											 *msg = false;
										  }
										  else if (str[*k+3] == ' '){
											 cout << 'k';
											 *k = *k+3;
										  }
										  else if (str[*k+3] == '.'){
											 dash_dot_dash_dot_5(str, k, msg);
										  }
										  else if (str[*k+3] == '-'){
											 dash_dot_dash_dash_5(str, k, msg);
										  }
									   }
									   void dash_dot_3(char str[], int *k, bool *msg){
										  if (str[*k+2] == '\0'){
											 cout << 'n';
											 *msg = false;
										  }
										  else if (str[*k+2] == ' '){
											 cout << 'n';
											 *k = *k+2;
										  }

										  else if (str[*k+2] == '.'){
											 dash_dot_dot_4(str, k, msg);
										  }
										  else if (str[*k+2] == '-'){
											 dash_dot_dash_4(str, k, msg);
										  }

									   }
									   /******************************************************************************************************
										* Function : dash_2
										* Description : This will evaluate the second position of the incremented message after a dash
										* 				 and determine if it needs to go to a new function or print out the coorisponding char
										* Parameters : char str[], int *k, bool *msg
										* Pre-conditions : Parameters are good and there is not a null before this position in the message
										* Post-conditions : Parameters are still good 
										* ***************************************************************************************************/
									   void dash_2(char str[], int *k, bool *msg){
										  //If char is NULL, that means message is done so exit function
										  if (str[*k+1] == '\0'){
											 cout << 't';
											 *msg = false;
										  }
										  //If char is a space, that letter is done so increment k and run again
										  else if (str[*k+1] == ' '){
											 cout << 't';
											 *k = *k+1;
										  }
										  //If char is a dot, go to next function
										  else if (str[*k+1] == '-'){
											 dash_dash_3(str, k, msg);
										  }
										  else if (str[*k+1] == '.'){
											 //If char is a dash, go to next function
											 dash_dot_3(str, k, msg);
										  }
									   }

									   ////////////////////////////////////// NOTE ///////////////////////////////////////////
									   //////Comments and function header on dash_2 represent all functions above dash_2//////
									   ///////////////////////////////////////////////////////////////////////////////////////



									   /*************************************************************************************
										* Function : m_to_t
										* Description : Evaluates the fist position in the message to translate morse to text 
										* Parameters : char str[]
										* Pre-conditions : Parameter is good and user chose to translate morse to text
										* Post-conditions : Parameter is still good and text message will be printed
										* ***********************************************************************************/
									   void m_to_t(char str[]){

										  // Declare variables
										  int k = 0;
										  bool msg = true;

										  while(msg == true){
											 //If char at position k is NULL, exit function
											 if (str[k] == '\0'){
												msg = false;
											 }
											 //If char at position k is a space... 
											 else if(str[k] == ' '){

												int ex = k;
												int count = 1;
												//Count how many spaces
												while(str[ex] == ' '){
												   count++;
												   ex++;
												}

												//if there are at least 7 spaces, print out one space
												if(count >= 7){
												   cout<<' ';
												}
												//Increment k

												k = k+count-2;
											 }
											 //If char at position k is a . go to next function
											 else if(str[k] == '.'){
												dot_2(str, &k, &msg);
											 }
											 //If char at position k is a - go to next funciton
											 else if(str[k] == '-'){
												dash_2(str, &k, &msg);
											 }
											 //Increment k
											 k++;
										  }
										  cout<<endl;
									   }

									   /***********************************************************************************
										* Function : length
										* Description : Returns the length of inputted char array
										* Parameters : char str[]
										* Pre-conditions : Parameters are good
										* Post-conditions : Parameters are still good and length will be returned
										* *********************************************************************************/
									   int length(char str[]){

										  //Returns length of array (not including \0 character
										  int i;
										  for(i = 0; str[i] != '\0'; i++){
										  }
										  return i;
									   }


									   /*************************************************************************************
										* Function : copy
										* Description : Will copy the contents of orig into dest
										* Parameters : char dest[], char orig[]
										* Pre-conditions : Paramters are good
										* Post-conditions : Parameters are still good and dest will now have contents of orig
										* ***********************************************************************************/
									   void copy(char dest[], char orig[]){

										  //Copy contents of orig to dest
										  for(int i=0; i<length(orig)+1; i++){
											 dest[i] = orig[i];
										  }
									   }

									   /***********************************************************************************
										* Function : msg_to_int
										* Description : This reads user inputed message and will assign int value of each
										* 				 char into nstr[] that coorisponds to 2d array of text and morse
										* Parameters : char msg[], int *nstr, int slots
										* Pre-conditions : Paramters are good
										* Post-conditions : Parameters are still good and nstr will now have new contents
										* *********************************************************************************/
									   void msg_to_int(char msg[],int *nstr, int slots){

										  for(int i=0; i<slots; i++){
											 if(msg[i] == '\0'){
												i++;
											 }
											 //Get ascii value of each char and subtract 97 or 65 (depending on upper or lower case)
											 //to get numbers 0 - 26 to coorispond with array
											 else{
												int temp = msg[i];
												if(temp < 97){
												   temp = temp-65;
												   nstr[i] = temp;
												}
												else if(temp >= 97){{
												   temp = temp-97;
												   nstr[i] = temp;
												}
												}
											 }
										  }
									   }
									   /***********************************************************************************
										* Function : t_to_m
										* Description : Gets int value of each char that the user inputted, goes to that
										* 				 postition in the 2d array, and prints the morse code equivalent
										* Parameters : char st[], int slots, char *array[6]
										* Pre-conditions : Parameters are good and user chose to translate text to morse
										* Post-conditions : Parameters are still good and will print out morse message
										* *********************************************************************************/
									   void t_to_m(char str[], int slots, char *array[6]){

										  //Create array of length of user input
										  int nstr[slots];
										  //call function to convert characters to ints
										  msg_to_int(str, nstr, slots);
										  int k;

										  for (int i=0; i<slots; i++){
											 int r=1;
											 //If the int value of a char is negative, print a morse space
											 if(nstr[i] < 0){
												cout<<"       ";
											 }
											 //Else, read the 2d array and print out coorisponding morse code
											 else{
												k = nstr[i];
												while(array[k][r] != '\0'){

												   cout << array[k][r];
												   r++;
												}
												cout <<"   ";
											 }
										  }
										  cout<<endl;
									   }

									   /***********************************************************************************
										* Function : user_input
										* Description : This will get user inputted message and dynamically allocate memory 
										* 				 for an array exactly the length of the inputted message
										* Parameters : None
										* Pre-conditions : None
										* Post-conditions : returns user inputted message
										* *********************************************************************************/
									   char * user_input(){

										  //Define variables
										  char ch;
										  char *temp;
										  char *ui;
										  //Dynamically allocate memory for ui c-string
										  ui = new char[2];

										  cin.ignore();  
										  //Increase array size for each character until newline is read
										  while((ch = cin.get()) != '\n'){
											 ui[length(ui)] = ch;
											 temp = new char[length(ui)+2]; 
											 copy(temp, ui);	
											 delete ui;
											 ui = temp;
										  }											 
										  return ui;
									   }

									   /***********************************************************************************
										* Function : translator
										* Description : This will ask user for which way they want to translate and then
										* 				 get their message they want translated
										* Parameters : char *array[6]
										* Pre-conditions : Parameter is good
										* Post-conditions : Parameter is still good and message will have been translated
										* *********************************************************************************/
									   void translator(char *array[6]){

										  //Declare variables
										  char *ui;
										  bool prog = true;
										  int choice;

										  //Get user input for either text or morse
										  cout << "Would you like to translate morse to text(1) or text to morse(2)?" <<endl;
										  cin >> choice;

										  if(choice == 1){
											 cout << "Enter a morse message to translate:"<<endl;
											 //Get user input in morse
											 ui = user_input();
											 //Call function to translate
											 m_to_t(ui);
										  }
										  else if(choice == 2){
											 cout << "Enter a sentence to translate:"<<endl;
											 //Get user input in text
											 ui = user_input();
											 //Get length of input
											 int slots = length(ui);
											 //Call function to translate
											 t_to_m(ui, slots, array);
										  }
									   }

									   int main(){

										  //Make 2d array to hold alphabet and morse equivalent
										  char a[] = {'a','.','-','\0','\0'};
										  char b[] = {'b','-','.','.','.'};
										  char c[] = {'c','-','.','-','.'};
										  char d[] = {'d','-','.','.','\0'};
										  char e[] = {'e','.','\0','\0','\0'};
										  char f[] = {'f','.','.','-','.'};
										  char g[] = {'g','-','-','.','\0'};
										  char h[] = {'h','.','.','.','.'};
										  char i[] = {'i','.','.','\0','\0'};
										  char j[] = {'j','.','-','-','-'};
										  char k[] = {'k','-','.','-','\0'};
										  char l[] = {'l','.','-','.','.'};
										  char m[] = {'m','-','-','\0','\0'};
										  char n[] = {'n','-','.','\0','\0'};
										  char o[] = {'o','-','-','-','\0'};
										  char p[] = {'p','.','-','-','.'};
										  char q[] = {'q','-','-','.','-'};
										  char r[] = {'r','.','-','.','\0'};
										  char s[] = {'s','.','.','.','\0'};
										  char t[] = {'t','-','\0','\0','\0'};
										  char u[] = {'u','.','.','-','\0'};
										  char v[] = {'v','.','.','.','-'};
										  char w[] = {'w','.','-','-','\0'};
										  char x[] = {'x','-','.','.','-'};
										  char y[] = {'y','-','.','-','-'};
										  char z[] = {'z','-','-','.','.'};

										  char *array[] ={a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}; 

										  //Call translator function that holds most of program
										  translator(array);

										  return 0;
									   }
