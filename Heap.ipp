#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  backingArray = new std::pair<Pri,T>[START_SIZE];
  arrSize = START_SIZE;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  delete backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
	replacement = new std::pair<Pri,T>[arrSize*2];
	if(replacement==NULL)
          throw std::string("You have run out of memory, sorry.");

	for (unsigned long i=0; i<numItems; i++)
          replacement[i] = backingArray[i];

	        delete[] backingArray;
        backingArray = replacement;  
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  //TODO
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
  //TODO
  return 0;
}
