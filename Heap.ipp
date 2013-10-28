#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
    arrSize = START_SIZE;
    backingArray= new std::pair <Pri, T>[arrSize];
    numItems = 0;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
    delete [] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  //TODO
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
    backingArray[numItems] = toAdd;
    numItems++;
    //if() bubbleUp()
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
  std::pair<Pri,T> tmp;
    tmp = backingArray[0];
    backingArray[0] = backingArray[numItems-1];
    numItems--;
    
    for (unsigned long i = 0; backingArray[i].first > backingArray[(2 * i) + 1].first ; i = (i * 2) + 1){
        trickleDown(i);
    }
    
  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
