#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  //TODO
  arrSize = START_SIZE;
  numItems = 0;
  backingArray = new std::pair<Pri, T>[arrSize]();

}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  //TODO
  while(numItems>0)
	remove();
  delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  //TODO
    std::pair<Pri, T>* newBackingArray = new std::pair<Pri, T>[arrSize*2];
        if(newBackingArray == NULL)
                throw (std::string) "Unable to add input item. Your computer may out of memory ";
        for(int i =0; i<arrSize; i++){
                newBackingArray[i] = backingArray[i];
        }
        arrSize = arrSize*2;
        delete[] backingArray;
        backingArray = newBackingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  //TODO

  if(numItems + 1>arrSize)
	grow();
  backingArray[numItems+1]= toAdd;
  bubbleUp(numItems-1);
  numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  //TODO
  unsigned long parent = (index-1)%2;
  while(true){
	Pri temp = backingArray[index];
	backingArray[index] = backingArray[parent];
	backingArray[parent] = temp;
	index = parent;
	parent = (index-1)%2;
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
  //TODO
  return numItems;
}
