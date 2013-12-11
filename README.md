Author
==========
"Mullins, Harrison", mullingh
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

1. Working, add and remove both take O(log(n)), and grow which may be called in add takes O(n).
2. Working, the backingArray is being de-allocated in the destructor.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
TODO

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
Given an index i we can determine the index of i's parent by array[i], i > 1 is array[floor((i-2)/d)+1]. The children of array[i] are
array[d(i-1)+2], array[d(i-1)+3], …, array[d(i-1)+d], array[d(i-1)+d+1]. (Credit to Penn State CSE course slides)

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

bubbleUp and trickleDown were really difficult to implement and I was unable to do it on my own.