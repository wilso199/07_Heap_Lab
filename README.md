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
2. TODO

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
Answer for 10.1:
When you add 7 to the binary heap shown at Figure 10.2, 7 will be stored at the end of the array at this moment. It is represented
as the left of 16 in Figure. Since 7 is smaller than 16, you bubble up 7 by swapping it with 16. Now 7 should be at the 
right place because the mother of 7, 6, is smaller than 7. So, 7 is stored at backingArray[6] and 16 is stored at backingArray[13].
The other items remain the same places.

When you add 3 to the binary head that just added 7, 3 will be stored at the end of the array at this moment. It is represented as
the right of 7 in Figure. Since 3 is smaller than 7, you bubble up 3 by swapping it with 7. The same strategy applies: you keep 
bubbling up 3 util it is store where 4 was, which is backingArray[0]. Now    

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

TODO