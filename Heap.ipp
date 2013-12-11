#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  arrSize = START_SIZE;
  numItems = 0;
  backingArray = new std::pair<Pri,T> [arrSize];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  delete[] backingArray;
}

//Grow the backingArray by making a new array of twice the size,
// and copying over the data
template<class Pri, class T>
void Heap<Pri,T>::grow(){
  //Creating a new array double the size of the original
        std::pair<Pri,T>* newBackingArray = new std::pair<Pri,T>[arrSize*2];

		for(int i = 0; i < numItems; i++) {
			newBackingArray[i] = backingArray[i];
		}

		arrSize = arrSize*2;
		delete[] backingArray;
		backingArray = newBackingArray;
}

//Add a new item
template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  
  //Using books method
  if(numItems == arrSize)
	grow();
  backingArray[numItems++] = toAdd;
  if(numItems > 1)
	 bubbleUp(numItems - 1);
}

//Check the item at index, and make sure it is in the right place.
// If not, swap it up the "tree" of the heap until you find the right
// place
template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  //Using book method
  int p = (index - 1)/2;

  while(index > 0 && (backingArray[index].first < backingArray[p].first)) {
	//Didn't realize this was possible, got this from both the book and mainly ZHONGM2
	std::swap(backingArray[index], backingArray[p]);
	int temp = p;
	p = index;
	index = temp;
  }
}

//Check the item at index, and make sure it is in the right place.
// If not, swap it down the "tree" of the heap until you find the right
// place
// **NOTE** was not able to implement most of this on my own, some code was used from the book and then I had to borrow logic and syntax from ZHONGM2
template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
	int p = index;
	int left;
	int right;

	do {
		int j = -1;
		right = 2*p + 2;

		if(right < numItems && backingArray[right].first < backingArray[p].first) {
			left = 2*index + 1;

			if(backingArray[left].first < backingArray[right].first)
				j = left;
			else
				j = right;
		}

		else {
			left = 2*p + 1;

			if(left < numItems && backingArray[left].first < backingArray[p].first)
				j = left;
		}

		if(j >= 0)
			std::swap(backingArray[p], backingArray[j]);
		p = j;
	} while (p >= 0);
	
}

//Remove the item with lowest priority, and return it
//If the queue is empty, throw a string exception
template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  //Throw error if empty
  if(numItems == NULL)
	throw std::string("The Queue is empty");
  
  //Using books method
  std::pair<Pri,T> temp = backingArray[0];
  backingArray[0] = backingArray[numItems -1];
  numItems--;
  trickleDown(0);
  return temp;
  
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
