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
  int p = (index-1)/2;
  int l = (2*index)+1;
  int r = (2*index)+2;

  // taken straight from the book, modified without the use of compare()
  do{
	  int j = -1;
	  if(r<numItems && (backingArray[r].first < backingArray[index].first)){
		if(backingArray[l].first < backingArray[r].first)
			j=l;
		else
			j=r;

	  }else{
		if(l<numItems && (backingArray[l].first < backingArray[index].first)){
			j=l;
		}
		if(j>=0)
			backingArray[j].swap(backingArray[index]);
		index=j;
	  }
	}while(index >=0);



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
