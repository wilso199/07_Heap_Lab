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
 // numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  //TODO
  unsigned long parent = (index-1)%2;

  while(index > 0 && backingArray[index]>backingArray[parent]){
		std::pair<Pri, T> temp = backingArray[index];
		backingArray[index] = backingArray[parent];
        backingArray[parent] = temp;
        index = parent;
        parent = (index-1)%2;
  }
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO

  unsigned long leftChild = 2*index +1;
  unsigned long rightChild = 2*index+2;

  while(backingArray[index]>backingArray[leftChild] || backingArray[index]>backingArray[rightChild]){
	if(leftChild<=rightChild){
		std::pair<Pri, T> temp = backingArray[index];
		backingArray[index]=backingArray[leftChild];
		backingArray[leftChild]=temp;
		index = leftChild;
		leftChild = 2*index+1;
	}
	else{
		std::pair<Pri, T> temp1 = backingArray[index];
		backingArray[index]=backingArray[rightChild];
		backingArray[rightChild]=temp;
		index = rightChild;
		rightChild = 2*index+1;
	}
  }
  


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
