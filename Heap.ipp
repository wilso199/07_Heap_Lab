#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  backingArray = new std::pair<Pri,T>[START_SIZE];
  numItems=0;
  arrSize=START_SIZE;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  std::pair<Pri,T>* newArr = new std::pair<Pri,T>[arrSize*2];
  for(int i = 0; i < arrSize; i++)
	newArr[i]=backingArray[i];
  delete[] backingArray;
  backingArray = newArr;
  arrSize = arrSize*2;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  if(arrSize == numItems)
	grow();
  backingArray[numItems] = toAdd;
  bubbleUp(numItems);
  numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  if((index-1)/2 >= 0 && backingArray[(index-1)/2].first > backingArray[index].first && index > 0){
	std::pair<Pri,T> swapper = backingArray[(index-1)/2];
	backingArray[(index-1)/2] = backingArray[index];
	backingArray[index] = swapper;
	if((index-1)/2 > 0)
	  bubbleUp((index-1)/2);
  }
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  if(2*index + 2 >= numItems && 2*index + 1 < numItems)
	backingArray[index]=backingArray[2*index+1];
  else if(2*index+2 < numItems){
    if(backingArray[2*index+1].first <= backingArray[2*index+2].first){
	  backingArray[index] = backingArray[2*index+1];
	  trickleDown(2*index+1);
    }
    else if(backingArray[2*index+1].first > backingArray[2*index+2].first){
  	  backingArray[index] = backingArray[2*index+2];
	  trickleDown(2*index+2);
    }
  }
  else{
    for(int i = index; i < numItems; i++)
		backingArray[i] = backingArray[i+1];
  }
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  std::pair<Pri,T> tmp = backingArray[0];
  trickleDown(0);
  numItems--;
  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
