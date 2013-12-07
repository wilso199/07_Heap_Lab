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
TODO

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
TODO

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The trickleDown and (to a lesser extent) bubbleUp methods were definitely the most challenging part about this lab, so my question is how to best create the trickleDown method, and what I could do with my specific trickleDown method to make it as efficient as possible.