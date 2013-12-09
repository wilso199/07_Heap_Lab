#include <string>

/*
Please note that I've gotten help from watching youTube videos, particularly from Paul Prgramming
http://www.youtube.com/watch?v=c1TpLRyQJ4w
*/

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  backingArray = new std::pair<Pri,T>[START_SIZE];
  numItems = 0;
  arrSize = START_SIZE;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  std::pair<Pri,T>* newArr = new std::pair<Pri, T> [arrSize*2];
  for(int i = 0; i < numItems; i++){
	newArr[i] = backingArray[i];
  } //end of for loop

  delete[] backingArray;
  backingArray = newArr;
  arrSize = arrSize*2;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  if(numItems == arrSize)
	grow();
  backingArray[numItems] = toAdd;
  bubbleUp(numItems);
  numItems++;

}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  //So if the newest value added is greater than any 
  //value above it must bubble up.
  //Given in class that left child = 2*parent+1
  //right child = 2*parent+2 ... parent = floor((child-1)/2)

  
  if((index-1)/2 >= 0 && backingArray[index].first < backingArray[(index-1)/2].first && index > 0){
		backingArray[index].swap(backingArray[(index-1)/2]);

		//This keeps switching until it is in the right place.
		if(((index-1)/2 > 0))
			bubbleUp((index-1)/2);
	}
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){

//Got general idea from http://www.youtube.com/watch?v=ijfPvX2qYOQ 
	int right = 2*index+2;
	int left = 2*index+1;	
		//If right is smaller
		if(backingArray[right].first < backingArray[left].first && backingArray[right].first < backingArray[index].first){
			backingArray[index].swap(backingArray[right]);
			
		}

		//If left is smaller
		if(backingArray[right].first > backingArray[left].first && backingArray[left].first < backingArray[index].first){
			backingArray[left].swap(backingArray[index]);
			
		}


}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  
  std::pair<Pri,T> tmp = backingArray[0];
  backingArray[0] = backingArray[--numItems];
  trickleDown(0);
  
  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
