#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  arrSize = START_SIZE;
  numItems == 0;
  backingArray = new std::pair<Pri,T> [arrSize];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  delete[] backingArray;
}

//Grow the backingArray by making a new array of twice the size,
// and copying over the data
template<class Pri, class T>
void Heap<Pri,T>::grow(){
  //Creating a new array double the size of the original
        std::pair<Pri,T>* newBackingArray = new std::pair<Pri,T>[arrSize*2];

		for(int i = 0; i < numItems; i++) {
			newBackingArray[i] = backingArray[i];
		}

		arrSize = arrSize*2;
		delete[] backingArray;
		backingArray = newBackingArray;
}

//Add a new item
template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  
  //Using books method
  if(numItems == arrSize)
	grow();
  backingArray[numItems++] = toAdd;
  bubbleUp(numItems - 1);

}

//Check the item at index, and make sure it is in the right place.
// If not, swap it up the "tree" of the heap until you find the right
// place
template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  
  int p = (index-1)/2;
    while (i > 0 && compare(a[i], a[p]) < 0) {
      a.swap(i,p);
      i = p;
      p = parent(i);
    }
}

//Check the item at index, and make sure it is in the right place.
// If not, swap it down the "tree" of the heap until you find the right
// place
template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //Using books method
  do {
      int j = -1;
      int r = right(i);
      if (r < n && compare(a[r], a[i]) < 0) {
        int l = left(i);
        if (compare(a[l], a[r]) < 0) {
          j = l;
        } else {
          j = r;
        }
      } else {
        int l = left(i);
        if (l < n && compare(a[l], a[i]) < 0) {
          j = l;
        }
      }
      if (j >= 0)  a.swap(i, j);
      i = j;
    } while (i >= 0);
}

//Remove the item with lowest priority, and return it
//If the queue is empty, throw a string exception
template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  //Throw error if empty
  if(numItems == 0)
	throw std::string("The Queue is empty");
  
  //Using books method
  std::pair<Pri,T> tmp = backingArray[0];
  backingArray[0] = backingArray[numItems -1];
  numItems--;
  trickledown(0);
  return temp;
  
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  //TODO
  return 0;
}
