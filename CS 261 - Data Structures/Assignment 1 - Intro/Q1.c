/* CS261- Assignment 1 - Q.1*/
/* Name: Jonathan Ropp
 * Date: 1/21/2017
 * Solution description: Used previous knowlege of C and 
	lecture slides to make program.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate() {
	
    /* Allocate memory for ten students */
   	struct student* mem = malloc(10 * sizeof(struct student));;

    /* return the pointer */
  	return mem;
}


void generate(struct student* students) {
	
	int i;

	for(i=0; i<10; i++){
		students[i].id = i;
		students[i].score = (10 * i) % 50;
	}

}

void output(struct student* students) {
	/*
	* Output information about the ten students in the format:
	*
	*   ID0 Score0
	*   ID1 score1
	*   ID2 score2
	*   ...
	*   ID9 score9
	*/
   
    int i;
    for(i=0; i<10; i++){
		printf("ID%d Score%d\n", students[i].id, students[i].score);
    }
   
}

int min(struct student* students) {
	
	/* return the minimum score */
	int i;
	int min = students[0].score;
	  
	for(i=1; i<10; i++){
		if(students[i].score < min){
			min = students[i].score;
		}
	}  
	  
	return min;
}

float avg(struct student* students) {
	
    /* return the average score */ 
	int i;
	float sum;
	
	for(i=0; i<10; i++){
		sum = sum + students[i].score;
	}
	
	float avg = sum/10;
	
	return avg;
}

void sort(struct student* students){ 

	/* sort students */  
	int i,j;
	
    for (i = 0; i < 10; ++i){
		for (j = i + 1; j < 10; ++j){
			/*if the inititial score is less than the next, swap*/
            if (students[i].score < students[j].score){
				/*temp variables to hold info of initial*/
                int a = students[i].score;
				int b = students[i].id;
				/*set initial info = to next*/
                students[i].score = students[j].score;
				students[i].id = students[j].id;
				/*set next = to initial*/
                students[j].score = a;
				students[j].id = b;
            }
        }
    }
	
	/*extra sorting so that if two students have the same score, their ID's are decending order*/
	for (i = 0; i < 10; ++i){
		for (j = i + 1; j < 10; ++j){
			if (students[i].score == students[j].score && students[i].id < students[j].id){
				int c = students[i].id;
				students[i].id = students[j].id;
				students[j].id = c;
			}
		}
	}
	
}

void deallocate(struct student* stud) {
	
    /* Deallocate memory from stud */
    if(stud == NULL){
		printf("No memory to free");
    }
    else{
		free(stud);
    }
  
}

int main(){
	
	struct student* stud = allocate();
 
	generate(stud);
	output(stud);
	sort(stud);
  
	for (int i=0; i<10; i++) {
		printf("%d %d\n", stud[i].id, stud[i].score);
	} 
  
	printf("Avg: %f \n", avg(stud));
	printf("Min: %d \n", min(stud));
	
	deallocate(stud);
  
	return 0;
}
