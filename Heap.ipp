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
    if (numItems == arrSize) {
      std::pair<Pri, T>* tempArr = new std::pair<Pri, T>[arrSize * 2];
        for (int i = 0; i < arrSize; )
    }
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
    backingArray[numItems] = toAdd;
    bubbleUp(numItems);
    numItems++;
        
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
    
    while (backingArray[index].first < backingArray[(index - 1) / 2].first){
        backingArray[index].swap(backingArray[(index - 1) / 2]);
        //index = (index - 1) / 2;
    }
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  std::pair<Pri,T> temp;
    temp = backingArray[0];
    backingArray[0] = backingArray[numItems-1];
    //backingArray[numItems-1] = NULL;
    numItems--;
    
    for (unsigned long i = 0; backingArray[i].first > backingArray[(2 * i) + 1].first ; i = (i * 2) + 1){
        trickleDown(i);
    }
    
  return temp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
