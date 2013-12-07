Author
==========
"Bailey, Sam", baileys2
07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. The remove, grow and add methods work as they should (with remove and add working in O(log(n)) time and grow working in O(n) time).
2. There should be no memory leakage in this program, as the destructor and remove function as they are supposed to.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.1

For each of the examples in this exercise (7 and 3), they would first be added to the last open slot in the heap. They would then be compared to their parent, and if they were lesser than their parent the two values would swap places. This would continue to happen until the recently added node was greater than its parent, in which case the process would end and the nodes would have found their final heap locations. This could be applied specifically to the examples given as well, as for 7 it would first be placed as the left child of 16, would swap places with 16, and would stay there because it is less than its parent of 6. Assuming 7 had already been placed in the heap, 3 would be initially inserted into the heap as the right child of 7, would swap places with 7, 6, and 4 (in that order), and finally come to rest at the head of the heap because there would be no parents left to compare it to.

10.2

For the next two removals in this exercise (6 and 8) the head of the tree would first be replaced with the last entry in the heap. The node at the head of the tree would then be compared to each of its children, and would be swapped with the lesser of the two children. This process would continue to happen until the node being moved down was greater than all of its children (or if it simply has no children). This could be applied specifically to the two examples in this exercise as well, as for 6 it would be replaced with 55, then 55 would be swapped with 8 and 16 (in that order) and come to rest as the right child of 16. For 8, it would first be replaced with 93, then 93 would swap places with 9, 17, and 19 (in that order) until it would finally come to rest as the left child of 19.

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.4

For this exercise, you would find the parent of any given node at index i by using the equation (i-1)/d, where d is the maximum number of children that any given node in the heap could have. To find the location(s) of the node at index i's children, you would use the equation (i*d)+n, where d is again the maximum number of children for any given node in the heap and n is the number of the specific child being searched for.  For example, to find the first child of a node you would use n=1, to find the second child you would use n=2, the third child would be n=3, and so on.

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The trickleDown and (to a lesser extent) bubbleUp methods were definitely the most challenging part about this lab, so my question is how to best create the trickleDown method, and what I could do with my specific trickleDown method to make it as efficient as possible.