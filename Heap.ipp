#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
	backingArray = new std::pair<Pri, T>[10];
	numItems = 0;
	arrSize = 10;
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
  backingArray[numItems+1] = toAdd;
  numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  //TODO
	/*int p = parent(index);
	while (index > 0 && compare(backingArray[index],backingArray[p]) < 0){
		backingArray.swap(index,p);
		index = p;
		p = parent(index);
	}*/
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  //TODO
  
  std::pair<Pri, T> x = backingArray[0];
	backingArray[0] = backingArray[numItems--];
  numItems--;
  return x;
  //std::pair<Pri,T> tmp;
  //return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  //TODO
  return numItems;
}
