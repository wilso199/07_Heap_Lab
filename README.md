Author
==========
"Turner, Chace", turnerce
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

1. Add and remove both should be operating in O(log n) time, except if grow is called.
2. The program does not appear to have memory leaks

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.1
	http://t.co/hvxNb5Uv1D
	http://t.co/UkK82ZPNCY
10.2
	http://t.co/yCjW4Uwvwb
	http://t.co/uj8F6YAWEc

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

For any d-ary tree:
Children :
	for (int x: [1, 2, 3…d]) {
	  child(i) = di + x;
Parent :
	parent(i) = floor((i-1)/d);

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I had a lot of trouble with trickleDown.  I suggest using a whiteboard to visualize the logic of the function while you write it out.  It helped me a lot to make decisions about the implementation