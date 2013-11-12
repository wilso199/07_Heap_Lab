#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
    backingArray = new std::pair<Pri, T> [START_SIZE];
    arrSize = START_SIZE;
    numItems = 0;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
    delete [] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
    std::pair<Pri, T>* largerArr = new std::pair<Pri, T> [arrSize*2];
    for (int i =0; i<numItems; i++) {
        largerArr[i] = backingArray[i];
    }
    
    arrSize *=2;
    
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
    backingArray[numItems] = toAdd;
    numItems++;
    if(numItems>1&& toAdd.first < backingArray[(numItems-1)/2].first)
        bubbleUp(numItems-1);

}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
    std::pair<Pri, T> toMove = backingArray[index];
    bool doneSwapping = false;
    while (!doneSwapping) {
        backingArray[index] = backingArray[(index-1)/2];
        backingArray[(index-1)/2] = toMove;
        index = (index-1)/2;
        if (index <=0 || backingArray[(index-1)/2].first < toMove.first) {
            doneSwapping = true;
        }
    }
    
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
    std::pair<Pri, T> toMove = backingArray[index];
    bool doneSwapping = false;
    backingArray[0] = toMove;
    index = 0;
    while (!doneSwapping) {
        
        
        if (backingArray[2*index+1].first< backingArray[2*index+2].first){
            if (toMove.first > backingArray[2*index+1].first) {
                backingArray[index] = backingArray[2*index+1];
                backingArray[2*index+1] = toMove;
                index = 2*index+1;
                if (numItems<= (2*index+1)) {
                    doneSwapping = true;
                }
            }
            else doneSwapping = true;
        }
        
        
        else if (backingArray[2*index+1].first>backingArray[2*index+2].first){
            if (toMove.first > backingArray[2*index+2].first ){
                backingArray[index] = backingArray[2*index+2];
                backingArray[2*index+2] = toMove;
                index = 2*index+2;
                if (numItems<= (2*index+1)) {
                    doneSwapping = true;
                }
            }
            else doneSwapping = true;
        }
        
        else doneSwapping = true;
        if (index>numItems-1) {
            doneSwapping = true;
            }
        
    }
    
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
    
    if (numItems==0) {
        throw (std::string) "No items in the heap";
    }

  std::pair<Pri,T> tmp = backingArray[0];
    if (numItems>1) {
        trickleDown(numItems-1);
    }
    
    numItems--;
  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
