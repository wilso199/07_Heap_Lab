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
    std::pair<Pri, T>* newArr = new std::pair<Pri, T>[arrSize*2];
    for (int i=0; i<numItems; i++) {
        newArr[i] = backingArray[i];
    }
        delete[] backingArray;
        backingArray = newArr;
        arrSize=arrSize*2;
        
    
    
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
    
   // int newIndex= index;
    //int p = (newIndex-1)/2;
//    while (newIndex > 0 && backingArray[newIndex].first < backingArray[p].first && p>=0) {
//   // while (index > 0 && compare(backingArray[index].first, backingArray[p].first) <0) {
//            
//        backingArray[newIndex].swap(backingArray[p]);
//        
//       // int tempT = backingArray[index].T;
//        
//        
//        newIndex = p;
//        p = (newIndex-1)/2;
//    
//    
//    }
    int p = (index-1)/2;

    while (index > 0 && backingArray[index].first < backingArray[p].first && p>=0) {
        // while (index > 0 && compare(backingArray[index].first, backingArray[p].first) <0) {
        
        backingArray[index].swap(backingArray[p]);
        
        // int tempT = backingArray[index].T;
        
        
        index = p;
        p = (index-1)/2;
        
        
    }
    
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO
    //left 2*i + 1
    //right 2*i+2
    
    
    int right = 2*index+2;
    int left = 2*index+1;

    bool parentSmallest = false;
    //do {
    //bigger than right child and right child is smallest child
    if (backingArray[index].first > backingArray[right].first && backingArray[right]<backingArray[left]) {
        //swap with right child
        backingArray[index].swap(backingArray[right]);
    }
    //bigger than left child and left child is smallest child
    else if (backingArray[index].first > backingArray[left].first && backingArray[right]>backingArray[left]) {
        backingArray[index].swap(backingArray[left]);
    }
//    //Attempt to have it quit when smaller than both its children.
//        if (backingArray[index].first < backingArray[right].first && backingArray[index].first < backingArray[left].first)
//            parentSmallest=true;
//    
    //}while (parentSmallest==false);
        
    
//    do {
//        int j = -1;
//        int r = 2*index+2;
//        if (r < numItems && backingArray[r].first < backingArray[index].first) {
//            int l = 2*index+1;
//            if (backingArray[l].first< backingArray[r].first) {
//                j = l;
//            } else {
//                j = r;
//            }
//        }
//        else {
//            int l = 2*index+1;
//            if (l < numItems && backingArray[l].first < backingArray[index].first) {
//                j = l;
//            }
//        }
//        if (j >= 0) backingArray(index).swap(backingArray[j]);
//        index = j;
//    } while (index >= 0);
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
