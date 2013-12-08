Author
==========
"Zirkle, Andrew", zirkleac
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

1. Add and remove should work because of bubbling and trickling speed
2. I'm pretty sure I deleted all my recreated arrays

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
   16          7         4       3
   /     ->   /    and  /   ->   / \
  7         16          6       4    9
                       /       / \
					  7       6   8
					 /       / \
					3       16   7
#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
6 and 55 are swapped, 6 is deleted, 55 trickles down right, passed 16.
8 and 93 swap, 8 deleted, 93 trickles down 9,17,19
#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

It didn't have a due date. Which means I didn't do it until the last second