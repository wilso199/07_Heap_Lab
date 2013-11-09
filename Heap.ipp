#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  backingArray = new std::pair<Pri,T>[START_SIZE];
  arrSize = START_SIZE;
  numItems=0;
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
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){//items are just added one by one in order.
  backingArray[numItems] = toAdd; //1st gets added at [0], 2nd gets added at [1], etc.
  bubbleUp(numItems); //because bubbleUp is called before numItems++, we can get away with not reducing the index by 1.
  numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  while(index>0){
	  if(backingArray[index].first < backingArray[(index-1)/2].first){ //compares internal priorities
		  Pri tempPri = backingArray[index].first;
		  T tempT = backingArray[index].second;
		  backingArray[index].second = backingArray[(index-1)/2].second;
		  backingArray[index].first = backingArray[(index-1)/2].first;
		  backingArray[(index-1)/2].first = tempPri;
		  backingArray[(index-1)/2].second = tempT;
		  index=(index-1)/2; //integer division allows this to work for both cases of x.0 and x.5 results due to rounding down.
	  }
	  else
		  return;
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
