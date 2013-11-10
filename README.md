Author
==========
"Bickley, Daniel", bickledb
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

1. Add and remove both take O(log n). Each one calls either bubbleUp() or trickleDown(), which take O(log n) time. BubbleUp and TrickleDown take O(log n) time because they look at, if viewed as a tree, down a series of edges,  which should take O(log n) time.
2. It does not leak memory, as in grow(), delete is called to delete the backingArray, as well as in the deconstructor. Because the std::pairs are not dymanically allocated, they do not leak memory and delete does not need to be called.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
	
	10.1
	When 7 is added, it is added, at first, to the last open space in the heap. Then, if 7 is smaller than it's parent, it switches places with the parent, in the given example, 7 would swap with 16. Then, it would check it's parent again, this time checking 6. 
	Because 7 is larger than 6, it is in heap order, and does not have to swap places.
	When 3 is added, it is added to the last spot in the heap, index 14. Then, it would check to see if it is smaller than it's parent. It's parent would be 7, and 3 is smaller than 7, so they swap places. Then, 3's new parent, 6, would be checked to see if it is 
	larger than three. Because it is, it is swapped with 3. Finally, 3 checks to see if it's parent, now 4, is smaller than 3. Because 4 is larger, 3 swaps places with it. Now, three is at the first point in the heap, so there cannot be any number that is smaller 
	than it. Therefore, it is now in heap order once again.

	10.2
	In the removal of 6, 6 is swapped with the last spot in the heap that has data. Now, 55 is at the top of the heap, with 6 at the bottom. Then, 6 is simply deleted, while 55 trickles down. It checks it's children nodes, and swaps places with the smallest, in this
	case 8. Eight is now at the top of the heap, with it's left child as 9 and right child as 55. 55 then tries to trickle down again, and swaps with 16, as 16 is the smallest of 55's children. Now, 55 is the last item in the second to last row, preserving the heap
	quality.
	Now, 8 can be removed. When 8 is removed, it swaps with the last item in the heap, 93. 8 is then promptly deleted while 93 trickles down. Because 93's left child (9) is smaller than it's right child (16), 93 swaps with 9. The process occurs again, swapping 93 with
	17, as 17 is smaller than 26. Finally, the 93 swaps with it's left child, now 19, placing 93 back on the last row. This preserves the heap order.
	
#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

TODO