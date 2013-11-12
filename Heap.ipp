#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  backingArray = new std::pair<Pri,T>[10];
  arrSize = START_SIZE;
  numItems = 0;
  
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  int newSize = 2*arrSize;
  std::pair<Pri, T>* newArray;
  newArray = new std::pair<Pri,T>[newSize];
  for (int i = 0; i < numItems; i++) {
    newArray[i] = backingArray[i];
  }
  arrSize = newSize;
  delete[] backingArray;
  backingArray = newArray;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  if(numItems == arrSize)
   grow();
  backingArray[numItems] = toAdd;
  bubbleUp(numItems);
  numItems++;
 
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  if (numItems < 1) {
    return;
  }
  int d = 0;

  while (backingArray[index].first < backingArray[(index-1)/2].first) {
	Pri copy = backingArray[index].first;
	T temp = backingArray[index].second;
	backingArray[index].first = backingArray[(index-1)/2].first;
	backingArray[index].second = backingArray[(index-1)/2].second;
	backingArray[(index-1)/2].first = copy;
	backingArray[(index-1)/2].second = temp;
	index = (index-1)/2;
	if (index <= 0)
	  return;
	}

}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
    if (numItems < 1) {
    return;
  }
   Pri copy;
   T temp;
  while (backingArray[index].first > backingArray[2*index+1].first || backingArray[index].first > backingArray[2*index+2].first ) {
    if (2*index+1 >= numItems && 2*index+2 >= numItems)
	  return;

	
	if (backingArray[2*index+1].first < backingArray[2*index+2].first) {
	 copy = backingArray[index].first;
	 temp = backingArray[index].second;
	 backingArray[index].first = backingArray[2*index+1].first;
	 backingArray[index].second = backingArray[2*index+1].second;
	 backingArray[2*index+1].first = copy;
	 backingArray[2*index+1].second = temp;
	 index = 2*index+1;
	 if (index >= numItems)
	   return;
	
	} else if (numItems != 2*index+2){
	copy = backingArray[index].first;
	temp = backingArray[index].second;
	backingArray[index].first = backingArray[2*index+2].first;
	backingArray[index].second = backingArray[2*index+2].second;
	backingArray[2*index+2].first = copy;
	backingArray[2*index+2].second = temp;
	index = 2*index+2;
	if (index >= numItems)
	  return;
	} else {
	     copy = backingArray[index].first;
	 temp = backingArray[index].second;
	 backingArray[index].first = backingArray[2*index+1].first;
	 backingArray[index].second = backingArray[2*index+1].second;
	 backingArray[2*index+1].first = copy;
	 backingArray[2*index+1].second = temp;
	 return;
	  }
  }

}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
	Pri copy = backingArray[0].first;
	T temp = backingArray[0].second;
	backingArray[0].first = backingArray[numItems-1].first;
	backingArray[0].second = backingArray[numItems-1].second;
	backingArray[numItems-1].first = copy;
	backingArray[numItems-1].second = temp;
	numItems--;
 
  trickleDown(0);
  return backingArray[numItems];
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
