#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
	backingArray = new std::pair<Pri,T>[START_SIZE];
	arrSize = START_SIZE;
	numItems=0;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
	delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
	std::pair<Pri, T>* replacement = new std::pair<Pri,T>[arrSize*2];
	if(replacement==NULL)
          throw std::string("You have run out of memory, sorry.");

	for (int i=0; i<numItems; i++)
          replacement[i] = backingArray[i];

	delete[] backingArray;
    backingArray = replacement;  
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){//items are just added one by one in order.
	if(numItems==arrSize)
		grow();

	backingArray[numItems] = toAdd; //1st gets added at [0], 2nd gets added at [1], etc.
	bubbleUp(numItems); //because bubbleUp is called before numItems++, we can get away with not reducing the index by 1.
	numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){//yeah sorry I don't recurse unless it is a severely complicated case.
	while(index>0){
		if(backingArray[index].first < backingArray[(index-1)/2].first){ //compares internal priorities
			Pri tempPri = backingArray[index].first;
			T tempT = backingArray[index].second;
			backingArray[index].first = backingArray[(index-1)/2].first;
		    backingArray[index].second = backingArray[(index-1)/2].second;
			backingArray[(index-1)/2].first = tempPri;
			backingArray[(index-1)/2].second = tempT;
			index=(index-1)/2; //integer division allows this to work for both cases of x.0 and x.5 results due to rounding down.
		}
		else
			return;
	}
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){//yeah sorry I don't recurse unless it is a severely complicated case.
    while(index < (unsigned long)numItems){
		if((backingArray[index].first < backingArray[index*2 +1].first) && (backingArray[index].first < backingArray[(index+1)*2].first))
			return;
		if(backingArray[index*2 +1].first < backingArray[(index+1)*2].first){ //compare child priorities
			Pri tempPri = backingArray[index].first;
			T tempT = backingArray[index].second;
			backingArray[index].first = backingArray[index*2 +1].first;
			backingArray[index].second = backingArray[index*2 +1].second;
			backingArray[index*2 +1].first = tempPri;
			backingArray[index*2 +1].second = tempT;
			index=index*2 +1; //integer division allows this to work for both cases of x.0 and x.5 results due to rounding down.
		}else{
			Pri tempPri = backingArray[index].first;
			T tempT = backingArray[index].second;
			backingArray[index].first = backingArray[(index+1)*2].first;
			backingArray[index].second = backingArray[(index+1)*2].second;
			backingArray[(index+1)*2].first = tempPri;
			backingArray[(index+1)*2].second = tempT;
		}
	}//end while
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
	if(numItems==0)
		throw std::string("Please stop trying to remove from an empty heap.");

	std::pair<Pri,T> tmp;
	//Pri tempPri = backingArray[0].first;
	//T tempT = backingArray[0].second;
	tmp.first = backingArray[0].first;
	tmp.second = backingArray[0].second;
	backingArray[0].first = backingArray[numItems-1].first;//swap bottom priority contents to the top
	backingArray[0].second = backingArray[numItems-1].second;
	//backingArray[numItems-1].first = tempPri;
	//backingArray[numItems-1].second = tempT;
	//tmp.first = backingArray[numItems-1].first;
	//tmp.second = backingArray[numItems-1].second;
	backingArray[numItems-1].first = INT_MAX; //this prevents
	trickleDown(0);
	numItems--;
	return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
	return numItems;
}
