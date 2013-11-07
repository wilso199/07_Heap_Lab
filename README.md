Author
==========
"Kojs, Michelle", kojsmn
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

1. This requirement works. The tree is always a height of log n. add and remove have a running time of O(logn). grow has a running time of O(n) since each item is copied into a new array of twice the previous size.
2. This requirement works. Memory is not leaked.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1
	To add 7 to the end of the heap in 10.2, 7 is first added as a left child of 16. Since 16's priority is greater than 7's some updating in the tree needs to be done. 7 and 16 will be switched so that this heap has correct heap order. Then 7 will be compared to 6 and since 6 has a smaller priority than 7, this heap now has correct heap order.
	To add 3 to the end of the heap in 10.2, 3 is first added as a right child of 7. The priorities of 7 and 3 are compared. This is not correct heap order, since 7 has a greater priority than 3 and 7 is 3's current parent. These two are switched so that 3 is the parent of 7. Next the priority of 3 is compared to its new parent which has a priority of 6. Since this is not correct heap order 6 and 3 are switched. Finally 3 is compared to its new parent, which has a priority of 4. Since 4 is greater than 3, the two need to be switched. 3 is now the root and the heap has correct heap order.

10.2
	To remove 6 in 10.3, 6 is switched with the last node in the array. This node has a priority of 55. When 55 becomes the new root node, the heap no longer has correct heap order. In order to restore this heap order, changes need to be made. 55 is compared to its right child 8 and found to be bigger. Then 8 is compared to 55's left child 9. Since 8 is less than 9, 55 and 8 are swapped. Now 55 is compared to its right child of 16. Since 16 is smaller than 50, 55 and 16 are swapped and the heap now has correct heap order.
	To remove 8 in 10.3, 8 is switched with the last node in the array which is 93 and is removed. Now 93 is out of order. 93 is compared to its right child of 16 but since 93's left child of 9 is smaller than 16, 93 and 9 are swapped. Now 93's two children are 17 and 26. Since 17 is smaller than 26, 17 adn 93 are swapped. Now 93's two children are 19 and 69, since 19 is smaller than 69, 93 and 16 are swapped. Now the heap is in the correct heap order.

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
	left child = 2*parent + 1
	right child = 2*parent + 2
	parent = (child - 1)/2

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
One thing about this exercise that confused me was how to access the priority and T value. I would give the advice to students next semester that the way to access these is through .first and .second respectively