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
  std::pair<Pri,T>* temp = new std::pair<Pri, T>[arrSize];
  for(int i = 0;i<numItems;i++)
	temp[i]=backingArray[i];
  delete backingArray;
  backingArray= temp;
  arrSize*=2;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
 if(numItems+1>=arrSize)
	grow();
  backingArray[numItems]= toAdd;
  bubbleUp(numItems);
  numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  std::pair<Pri, T> p= backingArray[index];
  while (index>0){
	if(backingArray[index].first<backingArray[(index-1)/2].first){
		Pri tempPri = backingArray[index].first;
        T tempT = backingArray[index].second;
        backingArray[index].first = backingArray[(index-1)/2].first;
        backingArray[index].second = backingArray[(index-1)/2].second;
        backingArray[(index-1)/2].first = tempPri;
        backingArray[(index-1)/2].second = tempT;
        index=(index-1)/2;
    }
    else
		return;
	}
	
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  while((int)((index+1)*2) < numItems){
                if(backingArray[index*2 +1].first < backingArray[(index+1)*2].first){
                        if(backingArray[index].first > backingArray[index*2 +1].first){
                                Pri tempPri = backingArray[index].first;
                                T tempT = backingArray[index].second;
                                backingArray[index].first = backingArray[index*2 +1].first;
                                backingArray[index].second = backingArray[index*2 +1].second;
                                backingArray[index*2 +1].first = tempPri;
                                backingArray[index*2 +1].second = tempT;
                                index = index*2 +1;
                        }
                        else
                                return;
                }else{
                        if(backingArray[index].first > backingArray[(index+1) *2].first){
                                Pri tempPri = backingArray[index].first;
                                T tempT = backingArray[index].second;
                                backingArray[index].first = backingArray[(index+1) *2].first;
                                backingArray[index].second = backingArray[(index+1) *2].second;
                                backingArray[(index+1) *2].first = tempPri;
                                backingArray[(index+1) *2].second = tempT;
                                index = (index+1)*2;
                        }
                        else
                                return;
                }
        }

        if(!((int)index*2 +1 < numItems-1))
                return;
        if(backingArray[index].first > backingArray[index*2 +1].first){
                Pri tempPri = backingArray[index].first;
                T tempT = backingArray[index].second;
                backingArray[index].first = backingArray[index*2 +1].first;
                backingArray[index].second = backingArray[index*2 +1].second;
                backingArray[index*2 +1].first = tempPri;
                backingArray[index*2 +1].second = tempT;
        }
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  if(numItems==0)
	throw std::string("Can't remove from an empty array");
  std::pair<Pri, T> tmp;
  tmp.first= backingArray[0].first;
  tmp.second=backingArray[0].second;
  
  backingArray[0].first= backingArray[numItems-1].first;
  backingArray[0].second=backingArray[numItems-1].second;
  trickleDown(0);
  numItems--;
  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
