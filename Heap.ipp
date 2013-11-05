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
	backingArray[(index-1)/2].swap(backingArray[index]);
	if((index-1)/2 > 0)
	  bubbleUp((index-1)/2);
  }
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  if(index*2 + 2 == numItems && backingArray[index].first > backingArray[index*2+1].first){
	backingArray[index].swap(backingArray[index*2+1]);
  }
  else if(index*2+1 < numItems && index*2+1 < numItems){
	if(backingArray[index].first > backingArray[index*2+1].first && backingArray[index*2+2].first > backingArray[index*2+1].first){
		backingArray[index].swap(backingArray[index*2+1]);
	}
	else if(backingArray[index].first > backingArray[index*2+2].first && backingArray[index*2+1].first > backingArray[index*2+2].first){
		backingArray[index].swap(backingArray[index*2+2]);
	}
  }
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  std::pair<Pri,T> tmp = backingArray[0];
  backingArray[0]=backingArray[numItems-1];
  numItems--;
  trickleDown(0);
  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
