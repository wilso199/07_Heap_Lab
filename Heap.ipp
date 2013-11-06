#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
    backingArray = new std::pair<Pri, T>[START_SIZE];
    arrSize = START_SIZE;

    numItems=0;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  //TODO
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  //TODO
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
    if (numItems + 1 > arrSize) {
        grow();
    }
    backingArray[numItems++] = toAdd;
    bubbleUp(numItems-1);
    
   // numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
    int p = (index-1)/2;
    while (index > 0 && compare(backingArray[index], backingArray[p]) < 0) {
        backingArray.swap(index, p);
        index = p;
        p = (index-1)/2;
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
