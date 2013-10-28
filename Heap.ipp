#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  
  arrSize = START_SIZE;
  numItems = 0;
  backingArray = new std::pair<Pri, T>[arrSize];

}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  
  delete[] backingArray;

}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  
  unsigned long newArrSize = arrSize+START_SIZE;
  std::pair<Pri, T>* original = backingArray;
  std::pair<Pri, T>* updated = new std::pair<Pri, T>[newArrSize];
  backingArray = updated;
  arrSize = newArrSize;
  numItems = 0;
  
  for (int index = 0; index < arrSize-START_SIZE; index++)
    add (original[index]);
  delete[] original;

}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  
  if (numItems+1 > arrSize)
    grow();
  backingArray[numItems+1] = toAdd;
  bubbleUp(numItems);      //numItems-1...?
  numItems++;

}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  
  unsigned long parent = (index-1)/2;
  while (index > 0 && backingArray[index] > backingArray[parent]){
    std::pair<Pri, T> temp = backingArray[index];
	backingArray[index] = backingArray[parent];
	backingArray[parent] = temp;
	index = parent;
	parent = (parent-1)/2;
  }

}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  
  std::pair<Pri, T> temp = backingArray[0];
  backingArray[0] = backingArray[numItems-1];
  trickleDown(0);
  return temp;
  
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  
  return numItems;

}
