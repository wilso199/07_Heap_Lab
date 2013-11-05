Author
==========
"Contini, Nick", continnd
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

1. add and remove are both log(n), since at most each branches height is at most log(n), and the most values you would have to check in a Heap is all the values in a branch. grow is O(n) since you simply just visit each value once to copy the value to the new, bigger array.
2. The array is properly deleted in grow and the destructor.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
see Exercise10-2.png and Exercise10-3.png

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
descendents: 2*index+1, 2*index+2...2*index+d parent: index-1/d

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
Take notes when code is implemented in class.