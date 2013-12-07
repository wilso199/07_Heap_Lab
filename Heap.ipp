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
	
	if(numItems+1 > arrSize) grow();  //If the amount of items is at it's max!

	backingArray[numItems+1] = toAdd;


	//TODO
	bubbleUp(numItems-1);

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
  
  //If the array is empty, we can't remove anything!
  if(numItems == 0) throw (std::string) "There is nothing to remove!";

  //Here we swap the root with the last item in the array, keeping heap order and making the remove easy!
  std::pair<Pri,T> tmp = backingArray[0];
  backingArray[0] = backingArray[numItems-1];
  numItems--;

  //Trickle down the item that is now at the root, as it will most likely need to be restructured!
  trickleDown(0);


  //Return the item!
  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
