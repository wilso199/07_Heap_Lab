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
When you add 7 to the binary heap shown at the end of Figure 10.2, 7 will be stored at the end of the array at this moment. It is 
represented as the left of 16 in Figure. Since 7 is smaller than 16, you bubble up 7 by swapping it with 16. Now 7 should be at the 
right place because the mother of 7, 6, is smaller than 7. So, 7 will be stored at backingArray[6], where 16 was stored, and 16 will
be stored at backingArray[13], where 7 was stored at first, and the other items will remain the same places.

When you add 3 to the binary head that just added 7, 3 will be stored at the end of the array at this moment. It is represented as
the right of 7 in Figure. Since 3 is smaller than 7, you bubble up 3 by swapping it with 7. The same strategy applies: you keep 
bubbling up 3 util it is store where 4 was, which is backingArray[0]. In that case, 3 will be stored at backingArray[0], and 4 will
be stored at backingArray[2], where 6 was stored, and 6 will be stored at backingArray[6], where 7 was stored, and 7 will be stored
at backingArray[14], where 3 was stored at first, and other items will remain the same places.

Answer for 10.2:
When you remove 6 from the binary heap shown at the end of Figure 10.3, 6 will be swapped with 55, which means 6 will be stored at
backingArray[11] and 55 will be stored at backingArray[0]. Remove 6 from the binary heap and do trickleDown for 55: Since 55 is 
bigger than 8 and 9, its kids, 55 will be swapped with the smaller kid, 8, and 55 is still bigger than its kids, 50 and 16, 55 will
be swapped with the smaller kid, 16. In that case, 8 will be stored at backingArray[0], where 6 was stored, and 16 will be stored at 
backingArray[2], where 8 was stored, and 55 will be stored at backingArray[6], where 16 was stored, and other iterms except 6 will
remain the same places.

When you remove 8 after you just removed 6. The same strategy applies: you swap 8 with 93 and remove 8, and do tricleDown for 93 similar
to what I did right above. In that case, 9 will be stored at backingArray[0], where 8 was stored, and 17 will be stored at backingArray[1],
where 9 was stored, and 19 will be stored at backingArray[3], where 17 was stored, and 93 will be stored at backingArray[7], where 19 
was stored, and the other items except 8 will remain the same places. 
 
#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
Children = n * i + range[1, n] 
Mother = (i - 1) / n

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
Right now what I want to say is do not wait a few days before the lab is due to start it, because it is more complicated and time consuming
than what you expected. 