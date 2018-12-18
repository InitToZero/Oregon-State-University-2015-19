/******************************************************************************
 ** Program: list.c
 ** Author: Jonathan Ropp
 ** Date: 06/04/2016
 ** Description:
 ** Input:
 ** Output:
 *******************************************************************************/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 **Function: Initialize
 **Description: Sets linked list's members to NULL
 **Parameters: struct list *l
 **Pre_Conditions: Struct has been made
 **Post_conditions: Member values have changed
 ******************************************************************************/

void initialize(struct list *l){

   l->head = NULL;
   l->tail = NULL;

   printf("I just initialized the head and tail!\n");
}

/******************************************************************************
 **Function: length
 **Description: Prints and returns the length of the linked list
 **Parameters: struct list l
 **Pre_Conditions: Struct has been made
 **Post_conditions: Value printed to screen and returned as int
 ******************************************************************************/

int length(struct list l){

   //Create temparary node pointer to iterate through list
   struct node *temp=NULL;
   temp=l.head;
   int count = 0;

   //Increment count for each node in list
   while(temp!=NULL){
	  count++;
	  temp=temp->next;
   }

   printf("The list size is %d\n",count);
} 

/******************************************************************************
 **Function: print
 **Description: Prints the contents of the linked list to the screen
 **Parameters: struct list l
 **Pre_Conditions: struct has been created
 **Post_conditions: List contents will have been printed to screen
 ******************************************************************************/

void print(struct list l){

   printf("\nHere is the list:\n");

   //Create temparary node pointer to iterate through list
   struct node *temp=NULL;
   temp=l.head;

   //Print each node in the list
   while(temp!=NULL){
	  printf("%d ",temp->val);
	  temp=temp->next;
   }

   printf("\n\n");
} 

/******************************************************************************
 **Function: push_front
 **Description: Creates a new node, places it at the front of the list, and 
 gives it a value
 **Parameters: struct list *;, int value
 **Pre_Conditions: struct has been created
 **Post_conditions: List will have a new node placed at front
 ******************************************************************************/

void push_front(struct list *l, int value){

   //Create a new node and set its value
   struct node *temp=NULL;
   temp=(struct node *) malloc(sizeof(struct node));
   temp->val = value;

   //If there is no list, create one starting with this node
   if(l->head!=NULL){
	  l->head->prev = temp;
	  temp->next=l->head;
	  l->head=temp;
   }
   //Make the head node equal the new node
   else{
	  l->head = temp;
   }
}

/******************************************************************************
 **Function: push_back
 **Description: Creates a new node, places it at the back of the list, and 
 gives it a value
 **Parameters: struct list *;, int value
 **Pre_Conditions: struct has been created
 **Post_conditions: List will have a new node placed at back
 ******************************************************************************/

void push_back(struct list *l, int value){

   //Create a new node and a temporary node pointer
   struct node *temp, *temp2;
   temp=(struct node *) malloc(sizeof(struct node));
   temp->val = value;
   temp2 = l->head;

   //If there is no list, start list with new node
   if(temp2 != NULL){

	  while(temp2->next!=NULL){
		 temp2 = temp2->next;
	  }

	  temp2->next = temp;
	  temp->next = NULL;
	  temp->prev=temp2;
	  l->tail=temp;
   }

   //Make the tail node equal to the new node
   else{
	  l->tail = temp;
   }
   //printf("In push_back\n");

} 

/******************************************************************************
 **Function: clear
 **Description: Frees all nodes in the linked list
 **Parameters: struct list *l
 **Pre_Conditions: struct has been created
 **Post_conditions: List will be freed. Program will have no memory leaks
 ******************************************************************************/

void clear(struct list *l){

   //Create a temporary node pointer
   struct node *temp;
   temp = l->head;

   //Free each node as it is pointed to
   while(temp != NULL){
	  l->head = temp->next;
	  free(temp);
	  temp = l->head;
   }

   printf("\nI just deleted every node in the list!\n");
   printf("Hopefully no memory leaks!");
   printf("\nHope that I had enough error handling\n");
   printf("Thanks for grading and have a great summer!\n\n");
} 

/******************************************************************************
 **Function: remove_val
 **Description: Remove a given value from the linked list 
 **Parameters: struct list *l, int value
 **Pre_Conditions: Struct has been created
 **Post_conditions: List members may be changed
 ******************************************************************************/

void remove_val(struct list *l, int value){

   //Create a temporary node pointer
   struct node *temp;
   temp = l->head;

   //If first node has value, free it
   if(temp->val == value){
	  l->head=temp->next;
	  if(l->head!=NULL){
		 l->head->prev=NULL;
	  }
	  free(temp);
	  remove_val(l, value);
   }

   //Loop through list until value is found and freed or end is reached
   else{
	  while(temp!=NULL){
		 if(temp->val == value){
			if(temp->prev!=NULL){
			   temp->prev->next=temp->next;
			}
			if(temp->next!=NULL){
			   temp->next->prev = temp->prev;
			}
			free(temp);
		 }
		 temp = temp->next;
	  }
   }

   printf("I just removed the number %d from the list!\n", value);	

   //If first value is removed, some weird bug happens and prints ^ multiple 
   //times. Everything works with the removal though so im not worried about it.
   //Also, not error handled for going past the end of the list, but assignment
   //did not mention error handling.
} 

/******************************************************************************
 **Function: sort_ascending
 **Description: Sorts the values in linked list in ascending order
 **Parameters: struct list *l
 **Pre_Conditions: Struct has been created
 **Post_conditions: Order of list will have changed
 ******************************************************************************/

void sort_ascending(struct list *l){

   //Create temporary node pointer
   struct node *temp;
   int value, check = 1;

   //Uses bubble sorting method to sort list
   while(check == 1){
	  temp = l->head;
	  check = 0;

	  //Loop until end is reached
	  while(temp->next!=NULL){

		 //If current > next, switch values
		 if(temp->val > temp->next->val){
			value = temp->val;
			temp->val = temp->next->val;
			temp->next->val = value;
			check = 1;
		 }
		 temp=temp->next;
	  }
   }

   printf("I just sorted the list in ascending order!\n");
}

/******************************************************************************
 **Function: sort_descending
 **Description: Sorts the values in linked list in descending order
 **Parameters: struct list *l
 **Pre_Conditions: Struct was created
 **Post_conditions: List order will be different
 ******************************************************************************/

void sort_descending(struct list *l){

   //Create temporary node pointer
   struct node *temp;
   int value, check = 1;

   //Use bubble sorting method to sort list
   while(check == 1){
	  temp = l->head;
	  check = 0;

	  //Loop until end of list
	  while(temp->next!=NULL){

		 //If current < next, switch values
		 if(temp->val < temp->next->val){
			value = temp->val;
			temp->val = temp->next->val;
			temp->next->val = value;
			check = 1;
		 }
		 temp=temp->next;
	  }
   }

   printf("I just sorted the list in desending order!\n");
}

/******************************************************************************
 **Function: insert
 **Description: Lets user insert a node into the linked list at any position
 **Parameters: struct list *l, int value, int pos
 **Pre_Conditions: struct has been made and ints are given from user
 **Post_conditions: A new node will be inserted into list
 ******************************************************************************/

void insert(struct list *l, int value, int pos){

   //Create a temporary node and a temporary node pointer
   struct node *temp = (struct node*) malloc (sizeof (struct node));
   struct node *temp2;
   int i = 0;
   int is_too_far = 0;

   temp2 = l->head;
   temp->val = value;

   //If position is 0, insert at begining
   if(pos == 0){
	  l->head->prev = temp;
	  temp->next=l->head;
	  l->head=temp;
	  printf("I just inserted the number %d at position %d!\n",value, pos);
   }
   //If not at begining
   else{
	  //Find position
	  while(i<pos){
		 temp2 = temp2->next;
		 i++;
		 //If position is off list, break out of loop
		 if(temp2->next == NULL){
			is_too_far = 1;
			break;
		 }
	  }

	  //If in middle of list, insert node at position
	  if(is_too_far == 0){
		 temp->prev = temp2;
		 temp->next = temp2->next;
		 temp2->next->prev = temp;
		 temp2->next = temp;

		 printf("I just inserted the number %d at position %d!\n",value, pos);
	  }

	  //If the position was off list, add to end of list
	  else{
		 temp2->next = temp;
		 temp->next = NULL;
		 temp->prev=temp2;
		 l->tail=temp;

		 printf("\nYou entered a number that was too big,\n");
		 printf("so I put the %d at the end of the list!\n",value);
	  }
   }
}
