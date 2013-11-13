Author
==========
"Blase, Douglas", blasedd
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

1. Both `add` and `remove` are at most O(log n) because both add and remove access one item in the array, which is constant time, and, if needed, will call `trickleDown` and `bubbleUp`, which will work only on one subtree of the Heap, which is log n time.
2. Memory is not leaked, as the only data created with `new` is the backing array, which is deleted in the destructor.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.1 - When 7 is first added, it will be placed at index 13 of the Heap, which is the left child of 16, or index 6. Then, the heap will be out of order, as 16, the parent, is greater than 7, the child. The positions of the 7 and 16 will be swapped, which will reestablish heap order.

Then, when 3 is added, it will be the right child of 7, meaning 3 will be at index 14 of the array. This violates heap order again, so position swapping will occur. First, the 3 and 7 will switch spots, then, 3 and 6 will switch spots, and finally, 3 and four will switch spots, which puts 3 and the root of Heap, which is also the front of the array.

10.2 - When 6 is removed, the last item in the heap, in this case, 55, will be placed in at the root of the Heap. This will violate the heap order, so 55 will need to trickle down the list. First, the left and right children of 55 need to be compared to see which one is smallest, as that one will trade spots with 55. In this case, the answer is 8, the right child, and so those two swap places. Following the same logic, 16 and 55 will swap places, which reestablishes Heap order.

When 8 is removed the last item in the heap that will be moved to the root position is 93. Again, this violates Heap order, so the 93 will need to trickle down. When comparing the two children, 9 is smaller than 16, so the 9 and 93 will swap places. Similarly, 17 and 93 will swap places, and then 19 and 93 will swap places, which reestablishes Heap order.

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

Given an index, `i`, and a `d`-ary tree the index of its parent is (i-1)/d. The children of `i` would be determined as follows: i*d + (a range of 1 to d, for each child).

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Be careful when you get to <=3 items in a Heap (in other words, just the root and its two children left), as you have to handle that case somewhat differently at times.