/******************************************************************************
 ** Program Filename: Assignment2.cpp
 ** Author: Jonathan Ropp 
 ** Date: 1/18/2016
 ** Description: This is a financial calculator that can calculate:
			**Future loan balance
			**Continuously compouinded interest
			**Future value
 ** Input:
 ** Output:
****************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main(){

	float selection;//User input for calculation selection

	cout << "\nWelcome to Jonathan's Financial Calculator!" <<endl;
	cout << "What do you wanat to calculate?" <<endl;
	cout << "\n1 - Loan Balance" <<endl;
	cout << "2 - continuously Compounded Interest" <<endl;
	cout << "3 - Future Value" <<endl;
	cout << "\nPlease type the number coorisponding to your desired selection. " ;

	cin >> selection;
	
//**********************************************************************************SELECTION 1****************************************************************
	
	if (selection == 1) {

		float B;//Amount of the loan left 
		float A;//The initial investment
		float i;//Interest rate per period (months)
		float n;//Number of time periods elapsed at any given point
		float P;//Amount of each equal payment
		float b;//Loan goal amount

		cout << "\nYou have chosen to view your loan balance" <<endl;
	
		/* Request user input for variables to determine loan balance */
				
		cout << "What was the initial investment value? :  ";
		cin >> A ;
	
		//Error message
		if ((cin.fail()) || (A <= 0)){ 
			cout << "You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		cout << "What is the interest rate? (Please enter as a decimal value) : ";
		cin >> i ;

		//Error message
		if ((cin.fail()) || (i <= 0)){
			cout << "You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		cout << "What is the ammount of each monthly payment? : ";
		cin >> P ;
		
		//Error message
		if ((cin.fail()) || (P < 0)){
			cout <<"You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		cout << "How many payments have you made? (How many months have passed?) : ";
		cin >> n ;
		
		//Error message
		if ((cin.fail()) || (n <= 0)){
			cout <<"You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		cout << "What is your goal amount for your loan? : " ;
		cin >> b ;

		//Error message
		if ((cin.fail()) || (b < 0)){
			cout <<"You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		//Loan Balance equation
		B = A*pow((1+(i/12)),n)-(P/(i/12))*(pow((1+(i/12)),n)-1);

		/*Possible outcomes depending on loan balance and goals made*/

		if (B <= 0) {
			cout << "\nYou will have paid off your loan!\n"
			"You will have $" << abs(B) << "left over." <<endl;
		}

		else if(( B - b ) <= 0){
			cout << "\nYou will have met your goal amount for your loan!\n"
			"Your goal was $"<<b<<" and there is $"<<B<<" left to pay off on the loan." <<endl;
		}
		else{ 
			cout <<"\nThere is $"<<B<<" left to pay on your loan.\n"
			"You will need to pay $" <<B-b<< " to reach your goal amount for your loan." <<endl;
		}
				
	}

//*******************************************************************SELECTION 2*************************************************************************************
	
	else if (selection == 2) {
		float P;
		float r;
		float t;
		float A;
		float a;
		cout << "\nYou have chosen Continuously Compounded Interest" <<endl;		
		/*Request user imput to calculate continuosly compounded interest*/
		
		cout << "What is the principal investment? : ";
		cin >> P ;

		//Error message
		if ((cin.fail()) || (P <= 0)){
			cout <<"You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		cout << "What is the annual interest rate? : " ;
		cin >> r ;

		//Error message
		if ((cin.fail()) || (r <= 0)){
			cout <<"You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		cout << "What is the amount of time in years? : ";
		cin >> t ;
		
		//Error message
		if ((cin.fail()) || (t <= 0)){
			cout <<"You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		cout << "What is your goal amount? : ";
		cin >> a ;
	
		//Error message
		if ((cin.fail()) || (a < 0)){
			cout <<"You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		A = P*(exp(r*t));

		/*Possible outcomes based on investment value and goals set*/
	
		if (A < a){
			cout <<"\nYou did not meet your goal. Your investment will be worth $"<<A<<" and your goal was $"<<a<<".\n"
			"You are $"<<abs(A-a)<<" away from your goal." <<endl;
		}

		else if (A >= a){
			cout <<"\nYou will meet your goal! Your investment will be worth $"<<A<<" and your goal was $"<<a<<".\n"
			"You will have $"<<(A-a)<<" extra." <<endl;
		}

	}

//***************************************************************************SELECTION 3**************************************************************************

	else if (selection == 3) {
		float FV;
		float C;
		float r;
		float n;
		float f;
		cout << "\nYou have chosen Future Value" <<endl;				
		/*Request user input to calculate futre value*/

		cout << "What is the starting cash flow? : ";
		cin >> C ;
		
		//Error message
		if ((cin.fail()) || (C <= 0)){
			cout <<"You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		cout << "What is the rate of return? : ";
		cin >> r ;

		//Error message
		if ((cin.fail()) || (r < 0)){
			cout <<"You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		cout << "What is the number of periods? : ";
		cin >> n ;
		
		//Error message
		if ((cin.fail()) || (n <= 0)){
			cout <<"You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		cout << "What is your future value goal? : ";
		cin >> f ;

		//Error message
		if ((cin.fail()) || (f < 0)){
			cout <<"You did not enter a valid number, please try again." <<endl;
			return 0;
		}

		FV = C*pow((1+r),n);

		/*Possible outcomes based on future value and goals set*/

		if (FV < f){
			cout << "\nYou did not meet your goal. The value is $"<<FV<<" and your goal was $"<<f<<".\n"
			"The value is $"<<abs(FV-f)<<" away from your goal." <<endl;  
		}

		else if (FV >= f){
			cout << "\nYou have met your goal! The value is $"<<FV<<" and your goal was $"<<f<<".\n"
			"You will have $"<<abs(FV-f)<<" extra value." <<endl;
		}
		
	}

	// Error message
	else {
		cout << "You did not enter a valid number, please try again." <<endl;

	}

	return 0;
}
