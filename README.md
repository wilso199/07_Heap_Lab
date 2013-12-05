Author
==========
"Griffith, David", griffid5
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

1. TODO
2. Working. By calling delete [] backingArray (as I did) in both the grow and destructor methods there shouldn't be a memory leak.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1: 7 would become the left child of 16. After that we need to bubbleUp which means that 16 and 7 will swap places
since 16 is larger than 7. Now that those are switched we need to compare 7 to 6 and make sure 6 is the parent of 7 because
it is smaller, in which 6 is smaller, so we are done. For adding 3 it would become the right child of the 7 that we just added.
Again compare 3 to its parent of 7 and switch them since 3 is smaller. Next compare 3 to its new parent of 6 in which we need 
to swap them because 3 is lower than 6. Now we compare 3 to 4 and once again we swap since 3 is smaller than 4 and we are done. 

10.2: When removing 6 we replace the root to be 55 since it is the last item in the Heap. We then trickleDown 55 until it is in
its correct spot. We compare 55 to its children of 9 and 8 in which it swaps with 8 because 8 is the smaller of the two children.
Then 55 is swapped with 16 since it is smaller than 50 and done. When removing 8 we place 93 at the top of the Heap since it is the last
item in the heap. Once at the top we compare it with 9 and 8 in which we swap it with the 9 since it is larger than 8. Next compare 17 and 26
and swap with 17. Next compare 19 and 69 since 19 is smaller we swap 93 with it and done. 
 
#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
According to wikipedia for a D-ary heap the parent of index i can be found by floor((i-1)/d) and the children can be found by di + 1 through di + 2.

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
The part that was really confusing was the coding for bubbleUp and trickleDown methods. 