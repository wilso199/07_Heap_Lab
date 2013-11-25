#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
    arrSize = START_SIZE;
    backingArray= new std::pair <Pri, T>[arrSize];
    numItems = 0;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
    //for (int i = 0; i < numItems; i++);
    delete [] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
    std::pair<Pri, T>* tempArr;
    if (numItems == arrSize) {
      tempArr = new std::pair<Pri, T>[arrSize * 2];
        for (int i = 0; i < arrSize; i++)
            tempArr[i] = backingArray[i];
    }
    delete [] backingArray;
    backingArray = tempArr;
    
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
    if (numItems == arrSize)
        grow();
    backingArray[numItems] = toAdd;
    numItems++;
    bubbleUp(numItems - 1);
        
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
    unsigned long p = (index - 1) / 2;
        while (index > 0 && backingArray[index].first < backingArray[p].first){
            backingArray[index].swap(backingArray[p]);
            index = p;
            p = (index - 1) / 2;
        }
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
    int left = (index * 2) + 1;
    int right = (index * 2) + 2;
    
    do {
        int j = -1;
        if (right < numItems && backingArray[right].first < backingArray[index].first){
            if (backingArray[left].first < backingArray[right].first)
                j = left;
            else j = right;
            }
        else{
            if (left < numItems && backingArray[left].first < backingArray[index].first)
                j = left;
                }
        if (j >= 0){
            backingArray[index].swap(backingArray[j]);
            index = j;
            left = (index * 2) + 1;
            right = (index * 2) + 2;
        }
}
    while (hasLessChild(index) == true);

    
}


template<class Pri, class T>
bool Heap<Pri,T>::hasLessChild(unsigned long index){
    unsigned long left = (index * 2) + 1;
    unsigned long right = (index * 2) + 2;
    
    if (backingArray[index].first > backingArray[left].first && left < numItems)
        return true;
    if (backingArray[index].first > backingArray[right].first && right < numItems)
        return true;
    
    return false;
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  std::pair<Pri,T> temp = backingArray[0];
    backingArray[0] = backingArray[numItems-1];
    numItems--;
    trickleDown(0);
    

  return temp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
