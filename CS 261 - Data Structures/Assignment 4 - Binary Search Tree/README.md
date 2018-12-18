# assignment-4

**Due 11:59pm on Monday, 2/27/2017** 

For this assignment, you will implement a binary search tree that can store any arbitrary struct in its nodes. You will complete the **recursive** implementation of the binary search tree (BST).

We are providing you with the following files (provided in this archive):

bst.c   :   is the file in which you'll finish implementing the unfinished BSTree. There is a main function in this file that you should modify thoroughly to exercise your BST. Because it is in the bst.c file, you can use it to test any internal as well as publicly accessible functions. Moreover, this file contains several test cases such as testAddNode(), testContainsBSTree(), testLeftMost(), testRemoveLeftMost(), and testRemoveNode(). Your implementation should pass all these test cases.

bst.h  :  should not be changed.

makefile  :  should not be changed.

**Grading Rubric**

Compile/Style = 20

struct Node *_addNode(struct Node *cur, TYPE val) = 15

int containsBSTree(struct BSTree *tree, TYPE val) = 15

TYPE _leftMost(struct Node *cur) = 15

struct Node *_removeLeftMost(struct Node *cur) = 15

struct Node *_removeNode(struct Node *cur, TYPE val) = 20
