# Assignment #2
**Due at 4:59pm on Monday, 1/30/2017**

The goal of this assignment is to have you start working with the dynamic array data structure.  There are three parts to the assignment, outlined below.  Follow the instructions listed in each part, filling in and augmenting the appropriate places in the provided code, as requested.

## Part I

You are given a partial dynamic array implementation in `dynamicArray.c`. Please implement the `addDynArr`, `getDynArr`, `putDynArr` and `swapDynArr` functions that are missing in this implementation.

## Part II

Currently, the array will never shrink.

Your task is to modify the given functions (do not modify the prototypes) to shrink the array to half its capacity when a remove causes the size to be 1/3rd of the capacity. Please modify `dynamicArray.c` so that it correctly resizes the array as described above. When you make a change to a function please put a comment like so

`// PART II: <description of change>`

There is an additional file called `testDynArray.c` you may use to test your solution, it is highly recommended that you do additional testing!

## Part III

Amortized Analysis of the Dynamic Array
Consider the push() operation for a Dynamic Array. In the best case, the operation is O(1). This corresponds to the case where there was room in the space we have already allocated for the array. However, in the worst case, this operation slows down to O(n). This corresponds to the case where the allocated space was full and we must copy each element of the array into a new (larger) array. This problem is designed to discover runtime bounds on the average case when various array expansion strategies are used, but first some information on how to perform an amortized analysis is necessary.

1.      
 Each time an item is added to the array without requiring reallocation, count 1 unit of cost. This cost will cover the assignment which
 actually puts the item in the array.
2.      
 Each time an item is added and requires reallocation, count X + 1 units of cost, where X is the number of items currently in the array. This cost will cover the X assignments which are necessary to copy the contents of the full array into a new (larger) array, and the additional assignment to put the item which did not fit originally
To make this more concrete, if the array has 8 spaces and is holding 5 items, adding the sixth will cost 1. However, if the array has 8 spaces and is holding 8 items, adding the ninth will cost 9 (8 to move the existing items + 1 to assign the ninth item once space is available).

When we can bound an average cost of an operation in this fashion, but not bound the worst case execution time, we call it amortized
 constant execution time, or average execution time. Amortized constant execution time is often written as O(1+), the plus sign indicating it is not a guaranteed execution time bound.

In a file called amortizedAnalysis.txt, please provide answers to the following questions:

1.        
 How many cost units are spent in the entire process of performing 16 consecutive push operations on an empty array which starts out at capacity 8, assuming that the array will double in capacity each time new item is added to an already full dynamic array? Now try it for 32 consecutive push operations. As N (ie. the number of pushes) grows large, under this strategy for resizing, what is the big-oh complexity for push?
2.        
 How many cost units are spent in the entire process of performing 16 consecutive push operations on an empty array which starts out at capacity 8, assuming that the array will grow by a constant 2 spaces each time new item is added to an already full dynamic array? Now try it for 32 consecutive push operations. As N (ie. the number of pushes) grows large, under this strategy for resizing, what is the big-oh complexity for push?
 
Finally, add, commit and push this file to the repository.

## Grading criteria

Your assignment will be graded by compiling it on `flip.engr.oregonstate.edu` using the provided `Makefile`, so make sure you have tested your work under those conditions.

Some other requirements:
* You may not change the function signatures (i.e. `void fooB(int k)`).
* You may not add or remove files beyond the instructions.

The assignment is worth 100 points total.

* Part I: 50 points
  * 20 points for addDynArr, 10 points for the other 3 functions.
* Part 2: 20 points
  * Correctly implements array shrinking as described above.
* Part III: 30 points
  * 15 points for each question.

## Submission

We'll be using GitHub Classroom for this assignment. You will submit your assignment via GitHub. Just make sure your completed files are committed and pushed by the assignment's deadline to the `master` branch of the GitHub repo that was created for you by GitHub Classroom.  A good way to check whether your files are safely submitted is to look at your assignment repo on the github.com (i.e. github.com/OSU-CS261-W17/assignment-2-YourGitHubUsername).  If your changes show up there, you can consider your files submitted.
