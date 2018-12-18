/*********************************************************************************
 ** Program Filename: Assignment1.cpp
 ** Author: Jonathan N Ropp
 ** Date: 1/11/2016
 ** Description: Homework assignment number 1
 ********************************************************************************/

#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;
int main(){

	float pi;
	int x;

	pi=3.14159;//Assigns variable "pi" the value 3.14159

	cout<< "cos of (2pi/3) in radians = " << cos(2*(pi)/3) <<endl;
	cout<< "2 sin of (2pi/3) in radians = " << 2*sin(2*(pi)/3) <<endl;
	cout<< "tan of (-3pi/4) in radians = " << tan(-3*(pi)/4) <<endl;
	cout<< "log base 10 of 55 = " << log10(55) <<endl;
	cout<< "The natural log of 60 = " << log(60) <<endl;	

	cout<< "log base 2 of 15 = " << (log(15))/(log(2)) << endl;
	cout<< "log base 4 of 40 = " << (log(40))/(log(4)) << endl;

	x=1;

	cout<< "3 to the power of sin(1) in radians = " << pow(3,sin(x)) <<endl;
	cout<< "log base 2 of 1^2 + 1 = " << (log(pow(x,2)+1))/log(2) <<endl;

	x=10;	

	cout<< "3 to the power of sin(10) in radians = " << pow(3,sin(x)) <<endl;
	cout<< "log base 2 of 10^2 + 1 = " << (log(pow(x,2)+1))/log(2) <<endl;

	x=100;

	cout<< "3 to the power of sin(100) in radians = " << pow(3,sin(x)) <<endl;
	cout<< "log base 2 of 100^2 + 1 = " << (log(pow(x,2)+1))/log(2) <<endl;


	//Macros for max and min ints, longs, and shorts
	cout<< "ULONG_MAX = " << ULONG_MAX <<endl;
	cout<< "LONG_MAX = " << LONG_MAX <<endl;
	cout<< "LONG_MIN = " << LONG_MIN <<endl;
	cout<< "UINT_MAX = " << UINT_MAX <<endl;
	cout<< "INT_MAX = " << INT_MAX <<endl;
	cout<< "INT_MIN = " << INT_MIN <<endl;
	cout<< "USHRT_MAX = " << USHRT_MAX <<endl;	
	cout<< "SHRT_MAX = " << SHRT_MAX <<endl;
	cout<< "SHRT_MIN = " << SHRT_MIN <<endl;	



	unsigned long num1 = ULONG_MAX;
	cout<< ULONG_MAX <<endl;	
	num1 = (unsigned long)pow(2, sizeof(unsigned long)*8);

	signed long num2 = LONG_MAX;
	cout<< LONG_MAX <<endl;
	num2 = (signed long)pow(2, sizeof(signed long)*8);

	signed long num3 = LONG_MIN;
	cout<< LONG_MIN <<endl;
	num3 = (signed long)pow(2, sizeof(signed long)*8);

	unsigned int num4 = UINT_MAX;
	cout<< UINT_MAX <<endl;
	num4 = (unsigned int)pow(2, sizeof(unsigned int)*8);

	signed int num5 = INT_MAX;
	cout<< INT_MAX <<endl;
	num5 = (signed int)pow(2, sizeof(signed int)*8);

	signed int num6 = INT_MIN;
	cout<< INT_MIN <<endl;
	num6 = (signed int)pow(2, sizeof(signed int)*8);

	unsigned short num7 = USHRT_MAX;
	cout<< USHRT_MAX <<endl;
	num7 = (unsigned short)pow(2, sizeof(unsigned short)*8);

	signed short num8 = SHRT_MAX;
	cout<< SHRT_MAX <<endl;
	num8 = (signed short)pow(2, sizeof(signed short)*8);
	
	signed short num9 = SHRT_MIN;
	cout<< SHRT_MIN <<endl;	
	num9 = (signed short)pow(2, sizeof(signed short)*8);
		

	return 0;
}
