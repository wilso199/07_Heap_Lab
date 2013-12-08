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

	backingArray[numItems] = toAdd;


	//Bubble up the item we just added!
	bubbleUp(numItems-1);

	//Increase the amount of items
	numItems++;

}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  //To find the previous index, we will use (index-1)/2

  int prev = (index-1)/2;

  //Check to see if the index is 0 or the prev is less than 0
  if(index == 0 || prev < 0) return;

  //If we should bubble up at least once, then go! If the item is less than it's previous, we need to swap as well!
  while(index > 0 && prev >= 0 && backingArray[index].first < backingArray[prev].first){
	
	//Swap the two indices
	std::pair<Pri, T> temp = backingArray[index];
	backingArray[index] = backingArray[prev];
	backingArray[prev] = temp;

	//Set the index to the previous entry, and get the previous entry for that one as well!
	index = prev;
	prev = (index-1)/2;


  } 

}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //As mentioned in the link given, left is 2i+1 and right is 2i+2!

  //I'll do a quick check to see if we need to even perform the function!
  //If there is no left child, then we don't need to continue!
  if(2*index+1 >= numItems) return;

  //Use variabled to store right/left members
  int left = 2*index+1;
  int right = 2*index+2;

  //Just continue going while the left is in bounds, I'll have a small check to see if any changes are present inside the loop.
  while(left < numItems){

	//Temp value to help with swapping!
	std::pair<Pri, T> temp;

	
	//If the index on the right is smaller than the current index, swap!
	if(backingArray[index].first > backingArray[right].first && backingArray[right].first < backingArray[left].first){

		//Perform the swap!
		temp = backingArray[index];
		backingArray[index] = backingArray[right];
		backingArray[right] = temp;

		//We have to recalculate the next index based on the right!
		index = 2*index + 2;

	//If the index on the right was not smaller, but the one on the left it, swap!
	}else if(backingArray[index].first > backingArray[left].first && backingArray[right].first > backingArray[left].first){

		//Perform the swap!
		temp = backingArray[index];
		backingArray[index] = backingArray[left];
		backingArray[left] = temp;

		//We have to recalculate the next index based on the left!
		index = 2*index + 1;


	}else{
		return;
	}


	

	//We have to recalculate the left/right if this loops more than once!
	left = 2*index+1;
	right = 2*index+2;

	//If there is no left index, we stop!
	if(2*index+1 >= numItems) return;

  }

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
