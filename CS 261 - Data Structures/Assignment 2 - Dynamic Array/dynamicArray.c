/* CS261- Assignment 2 - dynamicArray.c */
/* Name: Jonathan Ropp
 * Date: 1/230/2017
 */

/*	dynArr.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dynamicArray.h"


/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold capacity elements
	post:	v->data is not null
*/
void _initDynArr(DynArr *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;

}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.
*/
DynArr* createDynArr(int cap)
{
	DynArr *r;
	assert(cap > 0);
	r = malloc(sizeof( DynArr));
	assert(r != 0);
	_initDynArr(r,cap);
	return r;
}

/* Deallocate data array in dynamic array.

	param: 	v		pointer to the dynamic array
	pre:    v is not null
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	assert(v!=0);

	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure.

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	assert (v!= 0);
	freeDynArr(v);
	free(v);
}


/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int sizeDynArr(DynArr *v)
{
	assert(v!=0);
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void addDynArr(DynArr *v, TYPE val)
{
// TODO: Implement this function
	
	//Make sure value is good
	assert(v!=0);

 	//If resize is neeeded, double the capacity 
	if(v->size >= v->capacity){
		
		//Set up variables
		TYPE *old_array;
		int old_size = v->size;
		old_array = v->data;

		//Create new array with twice the capacity
		_initDynArr(v, (v->capacity * 2));

		//Copy old data to new array
		int i;
		for(i = 0; i < old_size; i++){
			v->data[i] = old_array[i];
		}
		v->size = old_size;
		
		//Free the old array
		free(old_array);
	} 

	//Put value at end, increase array size
	v->data[v->size] = val;
	v->size++;
}

/*	Get an element from the dynamic array from a specified position

	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/

TYPE getDynArr(DynArr *v, int pos)
{
// TODO: Please write this function, remember to return a value with the type TYPE

	//Make sure that values are good
	assert(v!=0);
	assert(pos < v->size);
	assert(pos >= 0);

	//Return value at given position
	return v->data[pos];
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
// TODO: Please write this function

	//Make sure values are good 
	assert(v!=0);
	assert(pos < v->size);
	assert(pos >= 0);

	//Write new value into array at given position
	v->data[pos] = val;
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *v, int i, int  j)
{
// TODO: Please write this function

	//Create temp variable for swap
	TYPE  temp;
	
	//Make sure values are good
	assert(v!=0);
	assert(i < v->size);
	assert(j < v->size);
	assert(i >= 0);
	assert(j >= 0);

	//Swap the two variables
	temp = v->data[i];
	v->data[i] = v->data[j];
	v->data[j] = temp;
}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void removeAtDynArr(DynArr *v, int idx){
	int i;
	assert(v!= 0);
	assert(idx < v->size);
	assert(idx >= 0);

   //Move all elements up

	/* My loop does not execute when idx == size-1
	 * so I don't have to worry about copying an element outside the array
	 * into that idx!
	 */
   for(i = idx; i < v->size-1; i++){
      v->data[i] = v->data[i+1];
   }

   v->size--;
   
/* // PART II: <I chose to make a brand new array with half capacity.
   This allowed me to reuse most of the code from resizing the array
   in the AddDynArr function. Another way that I could have done this
   is to keep the same array and just free what is needed and changes
   the variables as needed.>*/
	
	//If the size is 1/3 of the capacity or less, shrink array
	if(v->size <= (v->capacity / 3)){
		
		//Set up variables
		TYPE *old_array;
		int old_size = v->size;
		old_array = v->data;

		//Create new array with half the capacity
		_initDynArr(v, (v->capacity / 2));

		//Copy old data to new array
		int i;
		for(i = 0; i < old_size; i++){
			v->data[i] = old_array[i];
		}
		v->size = old_size;
		
		//Free the old array
		free(old_array);
	} 
}

/*	Returns boolean (encoded in an int) demonstrating whether or not the
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	>0  if empty, otherwise 0
*/
int isEmptyDynArr(DynArr *v)
{
	assert(v!= 0);
	return !(v->size);
	/* alternatively:

	if(v->size == 0)
		return 1;
	else return 0;

	*/

}

/*
   Print the dynamic array contents.  This requires that PRINT_STR be defined.
RAM: Fix this to take a printType function pointer!

*/
void printDynArr(DynArr *v)
{
  int i;

  printf("\nArray size = %d\n", v->size);
  printf("Array capacity  = %d\n", v->capacity);
  printf("Array Contents: \n ====================== \n");
  for(i=0; i < v->size; i++)
    {
      printf("DA[%d] == ",i);
      printf("%c", v->data[i]);
      printf("\n");
    }
}
