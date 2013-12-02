#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  backingArray = new std::pair<Pri,T>[START_SIZE];
  arrSize = START_SIZE;
  numItems=0;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  std::pair<>* temp = new std::pair<>[arrSize];
  for(int i = 0;i<numItems;i++)
	temp[i]=backingArray[i];
  delete backingArray;
  backingArray= temp;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
 if(numItems+1=>arrSize)
	grow();
  backingArray[numItems++]= toAdd
  bubbleUp(n-1);
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  int p= backingArray[index];
  while (i>0 && )
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
  //TODO
  return numItems;
}
