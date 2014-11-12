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

1. works, add and remove are log n time and grow is O(n) because it has to copy over elements from the original array. 
2. works, no memory is leaked. At least I don’t believe it is. 

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.1)

add 7)	
	7 becomes left child of 16
	7 and 16 swap, 6 becomes new parent of 7

add 3)	
	3 becomes right child of 7
	3 swaps with 7, 6 is new parent of 3
	3 and 6 swap, 4 is new parent of 3
	3 and 4 swap 

10.2)

remove 6)
	
	6 is removed and 55 becomes root
	55 swaps with 8 because 8 < 9
	55 swaps with 16

remove 8)
	
	8 is removed and 93 becomes root
	93 swaps with 9 because 9 < 16
	93 swaps with 17 because 17 < 26
	93 swaps with 19 because 19 < 69
	

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

children would be represented as d*index + n where ’n’ is equal to the position of the child 

parents would be represented as (index-1)/d

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I wasn’t really confused about this data structure. I feel like I have a pretty good grasp on the methods and how the data structure is organized. Advice for students next semester: Enjoy this lab. It is fun, and you get to bubbleUp. 