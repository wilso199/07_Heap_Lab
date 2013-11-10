Author
==========
"Bickley, Daniel", bickledb
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

1. Add and remove both take O(log n). Each one calls either bubbleUp() or trickleDown(), which take O(log n) time. BubbleUp and TrickleDown take O(log n) time because they look at, if viewed as a tree, down a series of edges,  which should take O(log n) time.
2. It does not leak memory, as in grow(), delete is called to delete the backingArray, as well as in the deconstructor. Because the std::pairs are not dymanically allocated, they do not leak memory and delete does not need to be called.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
	When 7 is added, it is added, at first, to the last open space in the heap. Then, if 7 is smaller than it's parent, it switches places with the parent, 

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

TODO