#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
	arrSize = START_SIZE;
	numItems = 0;
	backingArray = new std::pair<Pri, T> [arrSize];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
	delete [] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
	std::pair<Pri, T>* newBackingArray = new std::pair<Pri, T> [arrSize*2];

	for (unsigned long i = 0; i < numItems; i++) {
		newBackingArray[i] = backingArray[i];
	}
	arrSize = arrSize * 2;
	delete [] backingArray;
	backingArray = newBackingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
	if (numItems == arrSize) {
		grow();
	}
	else {
		backingArray[numItems] = toAdd;
		numItems++;
		if (numItems > 1) {
			bubbleUp(numItems - 1);
		}
	}
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
	std::pair<Pri,T> tempParent = backingArray[0]; 
	int count = 0;
	int parent = (index-1)/2;
	int leftChild = ((2 * parent) + 1);
	int rightChild = ((2 * parent) + 2);
	for (int i = 0; i < numItems; i++) {
		if (backingArray[parent] > backingArray[index]) {
			backingArray[parent] = backingArray[index];
			backingArray[leftChild] = tempParent;
		}
		else if (numItems > 3) {
			if (backingArray[parent] > backingArray[index]) {
				tempParent = backingArray[parent];
				backingArray[parent] = backingArray[index];
				backingArray[index] = tempParent;
			}   
		}
	}
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
	std::pair<Pri,T> tempChild = backingArray[0];
	int parent = 0;
	int leftChild = ((2 * parent) + 1);
	int rightChild = ((2 * parent) + 2);
	for (int i = 0; i < numItems; i++) {
		if (backingArray[leftChild] < backingArray[parent]) {
			tempChild = backingArray[leftChild];
			backingArray[leftChild] = backingArray[parent];
			backingArray[parent] = tempChild;
		}
		else if (backingArray[rightChild] < backingArray[parent]) {
			tempChild = backingArray[rightChild]; 
			backingArray[rightChild] = backingArray[parent];
			backingArray[parent] = tempChild;
			rightChild++;

		}
		parent = parent++;
	}
}


template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
	if (numItems == NULL) {
		throw std::string("No items in queue to remove!");
	}
	std::pair<Pri,T> temp = backingArray[0]; 
	backingArray[0] = backingArray[numItems-1];
	numItems--;
	trickleDown(0);
	return temp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
	return numItems; 
}