/******************************************************************************
 ** Program: list.h
 ** Author: Jonathan Ropp
 ** Date: 06/04/2016
 ** Description: Header file to hold structs and function declarations
 ** Input:
 ** Output:
 *******************************************************************************/

//Single node in list
struct node {
   int val;
   struct node *next;
   struct node *prev;
};
//Linked list
struct list {
   struct node *head;
   struct node *tail;
};

void initialize(struct list *); //Sets members to NULL
int length(struct list); //Return number of nodes in list
void print(struct list); //Print the values in list
void push_front(struct list *, int);//Push to front of list
void push_back(struct list *, int); //Push to end of list
void clear(struct list *); //Remove all nodes from list
void remove_val(struct list *, int); //Remove nodes w/ int as val
void sort_ascending(struct list *); //Sorts list in ascending order
void sort_descending(struct list *); //Sorts list in descending order
void insert(struct list *, int, int);//Insert into a location in the list, start at 0 for front

