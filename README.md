Author
==========
"Gardner, Daniel", gardnedn
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

1. add, remove O(logn), grow O(n).
2. deconstructor deletes backingArray, I believe I am not leaking memory. (Do I need a delete call in the remove function to accomplish that?)

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1 The 7 would be the left child of the 16, switch places with the 16 and then be done. 3 would then start as the right child of the 7 and switch places with the 7, and then switch with the 6, and then the 4.

10.2 When the 6 is removed, 55 will take its place, then it will swap places with the 8 (trickling down) then switch places with the 16. Next when 8 is removed: 93 would take its place, swap with the 9, then the 17, then the 19.

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
//read http://en.wikipedia.org/wiki/D-ary_heap
the parent of an item at i, is floor((i − 1)/d), and for the children, they are at positions di+1 through di+d. 

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Drawing out what is supposed to happen for bubble and trickle can be useful.
