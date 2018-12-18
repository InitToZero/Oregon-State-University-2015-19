/* CS261- Assignment 1 - Q. 0*/
/* Name: Jonathan Ropp
 * Date: 1/21/2017
 * Solution description: Simple review of pointers
 */
 
#include <stdio.h>
#include <stdlib.h>

int fooB(int* a, int* b, int c) {
	
	c = *a + *b;
	*a = *b;
	*b = 2 * *b;
	
	/*testing for accuracy*/
	//printf("in fooB, c = %d \n",c);
	//printf("in fooB, *a = %d \n",*a);
	//printf("in fooB, *b = %d \n",*b);

	return c;
}


void fooA(int* iptr){
	
	printf("The value of the int pointed to by iptr is: %d \n",*iptr);
	
	printf("The address that iptr points to is: %p \n",iptr);
	
	printf("The address of iptr is: %p \n", &iptr);
	
}

int main(){
    
  /* declare an integer x */
  int x;
  
  /* print the address of x */
  printf("The address of int x is: %p \n",&x);
    
  /* Call fooA() with the address of x */
  fooA(&x);
  
  /* print the value of x */
  printf("The value of x is: %d \n",x);
  
  
  /*Testing for fooB*/
  //int a = 4;
  //int b = 20;
  //int c = 13;
  
  //fooB(&a, &b, c);  
    
  return 0;
}
