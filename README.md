Author
==========
"Zhong, Mingwei", zhongm2
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

1.`add()` and `remove()` take O(log n) time. `grow()` can be O(n).
2.Memory is not leaking. 

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

*******************************************************************************
10.1:

Inserting 7

1.Place 7 at location a[n], and increment n.

4,9,6,17,26,8,16,19,69,32,93,55,50,`7`

2.Compare 7 with its parent 16, 7 < 16. Swap 7 and 16.

4,9,6,17,26,8,`7`,19,69,32,93,55,50,16

3.Compare 7 with its current parent 6, 7 > 6. Done.

At the end of Figure is:

4,9,6,17,26,8,`7`,19,69,32,93,55,50,16


Inserting 3

1.place 3 at location a[n] and increment n.

4,9,6,17,26,8,7,19,69,32,93,55,50,16,`3`

2.Compare 3 with its parent 7, 3 < 7. Swap 3 and 7.

4,9,6,17,26,8,`3`,19,69,32,93,55,50,16,7

3.Compare 3 with its current parent 6, 3 < 6. Swap.

4,9,`3`,17,26,8,6,18,69,32,93,55,50,16,7

4.Compare 3 with its current parent 4, 3 < 4. Swap.

`3`,9,4,17,26,8,6,18,69,32,93,55,50,16,7   Done.

********************************************************************************

10.2:

                      Removing 6:
 
                    55,9,8,17,26,50,16,19,69,32,93

                                 
                               ->
                                 

                    8,9,55,17,26,50,16,19,69,32,93

                                 
	                       ->

                    8,9,16,17,26,50,55,19,69,32,93


                     Removing 8:

                    93,9,16,17,26,50,55,19,69,32

                                 
                               ->

                    9,93,16,17,26,50,55,19,69,32

                                 
	                       ->

                    9,17,16,93,26,50,55,19,69,32

                                 
	                       ->

                    9,17,16,19,26,50,55,63,69,32


********************************************************************************

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

********************************************************************************

Index of i's parent is: (i-1)/d

Index of each of i's d children: 2*i + k (k = 1,2,3,...,d)

********************************************************************************

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

In `remove()` method, I have to decrement `numItems` before calling `trickDown()`. It took me more than one hours to find this bug.






