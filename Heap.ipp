#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  arrSize =10;
  numItems=0;
  backingArray= new std::pair<Pri, T>[10];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
delete[] backingArray;
}
// from book
template<class Pri, class T>
void Heap<Pri,T>::grow(){
 std::pair<Pri,T>* backingArray2= new std::pair<Pri, T>[arrSize*2];
  
  for(int i=0; i<=arrSize; i++){
  backingArray2[i]=backingArray[i];
  }
  
  arrSize=arrSize*2;
  delete[] backingArray;
  backingArray=backingArray2;
}
//from book
template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
 if (numItems  >= arrSize) grow();
    
    backingArray[numItems] = toAdd;
    bubbleUp(numItems);
    numItems++;
}
// from book
template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  //TODO
}
// from book
template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO
}
// from book
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
