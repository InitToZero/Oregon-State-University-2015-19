#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>


struct Link* listInsertionSort(struct Link* head) {
 
	if(head == NULL || head->next==NULL){
		return head;
	}
	struct Link* sorted = NULL;
	while(head != NULL){
		struct Link* current = head;
		head = head->next;
		if(sorted == NULL || current->value < sorted->value){
			current->next = sorted;
			sorted = current;
		}
		else{
			struct Link* x = sorted;
			while(x != NULL){
				if(x->next == NULL || current->value < x->next->value){
					current->next = x->next;
					x->next = current;
					break;
				}
				x = x->next;
			}
		}
	}

  return sorted; //I hope it was ok to change the name of this :)
  
  /*
   * This function should perform an insertion sort on the list whose head is
   * provided as the function's argument, so that the values in the list are
   * sorted in ascending order, starting at the head.
   *
   * The sort should be done without allocating any new Link structs or any
   * other auxiliary data structures.
   *
   * Return a pointer to the new head of the list.
   */
}


struct Link* reverseList(struct Link* head) {

   struct Link *temp;
   struct Link *prev = NULL;
   while(head != NULL){
	   temp = head->next;
	   head->next = prev;
	   prev = head;
	   head = temp;
   }

  return prev; //I hope it was ok to change the name of this :)
  
  /*
   * This function should iteratively reverse the list whose head is provided
   * as the function's argument.
   *
   * The reversal must be done totally in place, i.e. you may not allocate any
   * new Link structs or any other auxiliary data structures.
   *
   * Return a pointer to the new head of the list.
   */
}


struct Link* reverseListRecursive(struct Link* head){

  
	if(head == NULL){
		return NULL;
	}
	if(head->next==NULL){
		return head;
	}
	struct Link *other= reverseListRecursive(head->next);
	head->next->next = head;
	head->next = NULL;
	
	return other; //I hope it was ok to change the name of this :)

  
  /*
   * Write this function for extra credit.  It should do the exact same thing
   * as reverseList() above, except it should do it recursively instead of
   * iteratively (i.e. no loops allowed).
   *
   * Again, you may not allocate any new Link structs or any other auxiliary
   * data structures.  You may, however, define an auxiliary function to help
   * you do the recursion.
   *
   * Return a pointer to the new head of the list.
   */
}
