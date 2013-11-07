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
TODO

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
One thing about this exercise that confused me was how to access the priority and T value. I would give the advice to students next semester that the way to access these is through .first and .second respectively