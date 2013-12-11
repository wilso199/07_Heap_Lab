Author
==========
"Vutisalchavakul, Pob", vutisat
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

1. It should work as the process only look at branches and not the whole tree as it moves up/down the tree. froe only get called so often its )(n)
2. I don't detect anything that will cost memory leak.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1)When 7 is added it will be the left child of 16 then it will bubbleUp, when 3 is added, it will be the right child of 7 and then also bubbleUp.

10.2) when 6 is called to be remove, it swaps places with 55 and 6 gets removed then 55 trickles down.
When 8 is to be remove it will swap with 93, 8 gets removed and 93 gets trickled down.

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.4)  The parent of the item at position i is the item at position floor((i - 1)/d) and its children are the items at positions di + 1 through di + d. (I googled this though)

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
What are some of the best scenario uses for heaps?


This video explains things very well incase you didn't catch it all in class:

http://www.youtube.com/watch?v=fJORlbOGm9Y

I ran into error: "Failure during conversion to COFF: file invalid or corrupt"
I fixed it by:   Going to Project Properties :
      		 -> Configuration Properties 
           		-> Linker (General) 
              			-> Enable Incremental Linking -> "No (/INCREMENTAL:NO)"
