#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
    backingArray = new std::pair<Pri, T>[START_SIZE];
    arrSize = START_SIZE;

    numItems=0;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
    delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
    int oldNumItems=numItems;
    std::pair<Pri, T>* newArr = new std::pair<Pri, T>[arrSize*2];
    for (int i=0; i<numItems; i++) {
        newArr[i] = backingArray[i];
    }
        delete[] backingArray;
        backingArray = newArr;
        arrSize=arrSize*2;
        //not sure if needed.
    numItems=oldNumItems;
    
    
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
    //extrapolated from book.
    if (numItems + 1 > arrSize) {
        grow();
    }
    backingArray[numItems++] = toAdd;
    bubbleUp(numItems-1);
    
   // numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
    //http://www.cplusplus.com/reference/array/array/swap/ for reference to swapping.
    //and book for general idea.
    
    int p = (index-1)/2;

    while (index > 0 && backingArray[index].first < backingArray[p].first && p>=0) {
        
        backingArray[index].swap(backingArray[p]);
        
        
        index = p;
        p = (index-1)/2;
        
        
    }
    
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO
    //left 2*i + 1
    //right 2*i+2
    //no need to trickle down if there are no left or right children.
    if (2*index+1>=numItems && 2*index+2>=numItems){
        return;
    }
    int right = 2*index+2;
    int left = 2*index+1;

   // while (backingArray[index].first < backingArray[right].first && backingArray[index].first < backingArray[left].first) {
    while (backingArray[index].first > backingArray[2*index+1].first || backingArray[index].first > backingArray[2*index+2].first ) {

        if (2*index+1>=numItems && 2*index+2 >= numItems) {
            return;
        }
        
        
     right = 2*index+2;
     left = 2*index+1;

    //bigger than right child and right child is smallest child
    if (backingArray[index].first > backingArray[right].first &&
        backingArray[right].first<backingArray[left].first) {
        //swap with right child
        backingArray[index].swap(backingArray[right]);
    }
    //bigger than left child and left child is smallest child
    else if (backingArray[index].first > backingArray[left].first &&
             backingArray[right].first>backingArray[left].first) {
        backingArray[index].swap(backingArray[left]);
    }
    }
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
    //based off book version of remove. Don't need resize though as our grow function, works differently.
    if (numItems==0) {
        throw (std::string) "Array is empty";
    }
    
    std::pair<Pri,T>temp = backingArray[0];
    backingArray[0] = backingArray[--numItems]; //decreases numItems here.
    trickleDown(0);
    //if (3*numItems < arrSize) resize();
    //numItems--;
    return temp;
    
    //TODO
//  std::pair<Pri,T> tmp;
//  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
    return numItems;
}
