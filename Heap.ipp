#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
	
	//Initialize the backing array, the size of the array, and the number of items present
	backingArray = new std::pair<Pri, T>[START_SIZE];
	arrSize = START_SIZE;

	numItems=0;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
	//Delete the backing array.
	delete [] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  
  //When the heap grows, increase the size to 2*n (Where n is the size of the original array)

  std::pair<Pri, T>* temp = new std::pair<Pri, T>[arrSize*2];

  //Put the items in the new array. Since they are sorted (according to how a heap is stored that is), we don't need to worry about the order.
  for(int i = 0; i < numItems; i++){
	temp[i] = backingArray[i];
  }

  //Delete the old array and set the pointer to the new array
  delete[] backingArray;
  backingArray = temp;
  arrSize *= 2;

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
