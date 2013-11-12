Author
==========
"Proctor, Patrick", proctopj
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

1. Add and remove are O(log(n)) based on the trickleDown and bubbleUp methods
2. At this point memory should not be leaked. If I'm leaking memory in the setting of an array, I have a problem. 

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1) 7 begins as the left child of 16, and then it is bubbled up to the place of 16, putting 16 where 7 began.
Upon adding 3, it is bubbled up through 7,6 and 4, making it the root of the implicit tree with 9 and 4 as children.
4 now has 8 and 6 as children, and 6 has 16 and 7 as children.

10.2) 6 and 55 switch positions before 6 is deleted, and then 55 trickles down to the right, swapping with 8 and again with 16.
8 and 93 switch positions before 8 is deleted, and then 93 switches with 9, 17, and 19.


#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
The nth (n is between 1 and d inclusive) child of a node at index i is at index (d*i + n).

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Carefully watch the logic between remove() and trickleDown(). There are multiple boundaries you have to watch for with the implicit children.
It's easy to go beyond the bounds of numItems if you don't keep track with the debugger.

Why not add this as a possible data structure which can be used to satisfy Zeitgeist? You can certainly use this sturcture to store
rank while the hashtable stores words.