/******************************************************************************
 ** Program: test_list.c
 ** Author: Jonathan Ropp
 ** Date: 06/04/2016
 ** Description: Holds the main function for creating a doubly linked list 
 and manipulating it.
 ** Input: None
 ** Output: None
 *******************************************************************************/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main (){

   char filename[20];//Array of characters for file name
   struct list l;//Linked list struct
   initialize(&l);//Set list's values to NULL
   FILE *fileptr;//Pointer to read through file
   char num[3]; //We will read positive integers 0-99
   int u_int_i, u_int_p, u_int_r;//User inputed numbers for later functions

   //Get file name and open file
   printf("Enter filename: ");
   scanf("%s", filename);
   fileptr = fopen (filename,"r");

   //Continue reading until we are at the end of the file
   while (fscanf(fileptr, "%s", num)!=EOF)
   {
	  printf("number is: %d\n", atoi(num));
	  push_front(&l, atoi(num)); //push to front of list
	  push_back(&l, atoi(num)); //push to back of list
   }

   int size = length(l); //return number of nodes in list
   print(l);//Print the values in list

   sort_ascending(&l);
   print(l);//Print the values in list

   sort_descending(&l);
   print(l);//Print the values in list

   //Get number to remove from list
   printf("What number would you like to remove?\n");
   scanf("%d", &u_int_r);
   printf("%d\n",u_int_r);

   remove_val(&l, u_int_r);//Remove number from list
   print(l);//Print the values in list

   //Get number to insert into list
   printf("What number would you like to insert?\n");
   scanf("%d", &u_int_i);
   //Get position to place number
   printf("What position do you want that number?(0 for front)\n");
   scanf("%d", &u_int_p);

   insert(&l, u_int_i, u_int_p);//Insert number in list
   print(l);//Print the values in list

   clear(&l);//Frees all nodes

   fclose (fileptr);//Close file
   return 0;
}
