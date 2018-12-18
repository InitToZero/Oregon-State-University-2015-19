#include "linkedListQueue.h"
#include "assert.h"
#include <stdlib.h>



struct Link {
	TYPE          val;
	struct Link *next;
};


/* Singly Linked List with Head and Tail */
struct ListQueue {
   struct Link *head;
   struct Link *tail;
};



/* List queue with a sentinel at the front */

void initListQueue (struct ListQueue *q) {
/* FIXME: You will have to write this */

	//This sets up the queue and the sentinel
	struct Link *newList = (struct Link *) malloc(sizeof(struct Link)); 
	newList->next = 0;
	q->head = q->tail = newList;
}




struct ListQueue *createListQueue()
{
	struct ListQueue *newList = malloc(sizeof(struct ListQueue));
	initListQueue(newList);
	return newList;
}

void _freeListQueue(struct ListQueue *l) {
  while (!isEmptyListQueue(l))
  {
     removeFrontListQueue(l);
  }
}

void deleteListQueue(struct ListQueue *l)
{
	_freeListQueue(l);
	free(l);
	l = 0;
}



void addBackListQueue (struct ListQueue *q, TYPE e) {
/* FIXME: You will have to write this */

	//Makes a new link at the back of the queue and gives it the passed value
	struct Link *newList = (struct Link *) malloc(sizeof(struct Link));
	newList->val = e;
	newList->next = 0;
	q->tail->next = newList;
	q->tail = newList;

}


TYPE frontListQueue (struct ListQueue *q) {
/* FIXME: You will have to write this */

	//Returns front of queue
	return q->head->next->val;
return 0;
}


void removeFrontListQueue (struct ListQueue *q) {
/* FIXME: You will have to write this */

	//Moves pointers so the front is removed, and then frees that link.
	struct Link *newList = q->head->next;
	q->head->next = newList->next;
	if(q->head->next == 0)
		q->tail = q->head;
	free (newList);
}

int isEmptyListQueue (struct ListQueue *q) {
/* FIXME: You will have to write this */
	if(q->head == q->tail){
		return 1;
	}
	else{
		return 0;
	}
}

