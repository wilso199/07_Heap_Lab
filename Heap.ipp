#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  //TODO

  numItems=0;
  arrSize=START_SIZE;
  backingArray=new std::pair<Pri,T>[arrSize];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  //TODO
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  //TODO
  if(numItems+1==arrSize)
	grow();
  backingArray[numItems]=toAdd;
  bubbleUp(numItems);
  numItems++;

}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  //TODO
  //keep in mind, parent(i)=(index-1)/2

}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  //TODO
  std::pair<Pri,T> tmp;

  numItems--;

  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  //TODO
  return numItems;
}
