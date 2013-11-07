#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
	backingArray = new std::pair<Pri, T>[10];
	numItems = 0;
	arrSize = 10;
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
  if ((numItems + 1) > arrSize) {
	grow();
  }
  backingArray[numItems] = toAdd;
  numItems++;
  bubbleUp(numItems - 1);
 
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  //TODO
	int p = (index - 1)/2;
	
	while (index > 0 && (backingArray[index].first < backingArray[p].first)) {
		//swap i and p
		std::pair <Pri, T> temp = backingArray[index];
		backingArray[index].first = backingArray[p].first;
		backingArray[index].second = backingArray[p].second;
		backingArray[p].first = temp.first;
		backingArray[p].second = temp.second;
		index = p;
		p = (index - 1)/2;
	}
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO
  //do {

 // index = -1;

//  } while (index >= 0);
  /*
	int j = -1;
	int r = (2*index)+2;
	if (r < numItems && backingArray[r] > backingArray[index]) {
		int l = (2*index)+1;
		if (backingArray[l] > backingArray[r]) {
			j = 1;
		} else {
			j = r;
		}

		} 
	else {
		int l = (2*index)+1;
		if (l < numItems && backingArray[l] > backingArray[index]){
			j = l;
			}
		}
	if (j>=0){
		T temp = backingArray[index];
		backingArray[index] = j;
		j = temp;
		//backingArray.swap(index,j);
		}
	index = j;*/
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  //TODO
  
  std::pair<Pri, T> x = backingArray[0];
	backingArray[0] = backingArray[numItems-1];
	trickleDown(0);
  numItems--;
  return x;
  //std::pair<Pri,T> tmp;
  //return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  //TODO
  return numItems;
}
