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
  //keep in mind, parent(i)=(index-1)/2, left=(2*index)+1, right=(2*index)+2

  int p = (index-1)/2;
  if(index>=0&&(backingArray[index].first < backingArray[p].first)){
	backingArray[p].swap(backingArray[index]);
	if(p>0)
		bubbleUp(p); 
  }
  
  	

}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO
  //keep in mind, parent(i)=(index-1)/2, left=(2*index)+1, right=(2*index)+2


}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  //TODO
  std::pair<Pri,T> tmp;

  tmp = backingArray[0];
  numItems--;
  trickleDown(0);

  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  //TODO
  return numItems;
}
