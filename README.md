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

1. Add and remove both work in O(logn) time, and grow runs as O(n) time as it simply has to move the indices to the new array! Luckily this will be called rarely!
2. Memory is not leaked! The only variable that uses dynamic allocation is the backing array, which is deleted within the destructor of the Heap implementation file!

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.1
For 10.1, 7 would be added originally as the left child of 16! It would then "bubble up" and swap places with 16, both in the backing array and the tree structure diagram, and it would remain in place as it is greater than 6! Then 3 would be added, which would go to the right child of 7! It would then swap with 7, swap with 6, and finally swap with 4 taking it's place as the root of the heap!


10.2
For 10.2, 6 would be first swapped with 55, similarly to the last example from Figure 10.3. 55 would then "trickle-down" the tree structure diagram/backing array, finally ending up where 16 originally was, moving 16 to where 8 originally was, and then finally moving 8 to the root of the graph. Next 8 would be removed by switching places with 93. 93 would then move down the right side of the graph, switching places with 16, and then 55!

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.4
For 10.4, a d-ary tree is very similar to how a binary tree works in an array. It uses the same functions, except 2 is replaced with "d", thus making it a general equation for finding the previous/next! For finding previous, you would use (i-1)/d, which works for binary as well using (i-1)/2, or by finding next using d*i+ 1 through d*i+ d. 

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I highly recommend thoroughly reading the opendatastructures page, as it really gives you everything you need to know to implement this data structure! My biggest issues were small bugs on my end, and the tests on this one are especially easy to fool, so I recommend walking through your code to see if you get the expected results!
