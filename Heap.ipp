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
	  bubbleUp(numItems);
	  numItems++;
	  
  }
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  int parent = (index-1)/2;
  int leftChild = ((2 * index) + 1);
  int rightChild = ((2 * index) + 2);

  for (int i = 0; i < numItems; i++) {
	  if (parent > index) {
		  int temp = parent;
		  backingArray[parent] = backingArray[leftChild];
		  backingArray[leftChild] = backingArray[temp];
	  }
	  if (parent > rightChild) {
		  int temp = parent;
		  backingArray[parent] = backingArray[rightChild];
		  backingArray[rightChild] = backingArray[parent];
	  }
  }
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  //TODO
  std::pair<Pri,T> tmp;
  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems; 
}
