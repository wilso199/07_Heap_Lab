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
	  bubbleUp(numItems);
  }
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  //TODO
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
