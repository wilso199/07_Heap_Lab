#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  arrSize =10;
  numItems=0;
  backingArray= new std::pair<Pri, T>[10];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
delete[] backingArray;
}
// from book
template<class Pri, class T>
void Heap<Pri,T>::grow(){
 std::pair<Pri,T>* backingArray2= new std::pair<Pri, T>[arrSize*2];
  
  for(int i=0; i<=arrSize; i++){
  backingArray2[i]=backingArray[i];
  }
  
  arrSize=arrSize*2;
  delete[] backingArray;
  backingArray=backingArray2;
}
//from book
template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
 if (numItems  >= arrSize) grow();
    
    backingArray[numItems] = toAdd;
    bubbleUp(numItems);
    numItems++;
}
// from book
template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
  int p = (int)(index-1)/2;
    while (index > 0 &&  backingArray[index] <backingArray[p]) {
      backingArray[p].swap(backingArray[index]);
      index = p;
      p = (int)(index-1)/2;
    }

}
// from book
template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
 do {
      int j = -1;
      int r = (int)(2*index+2);
      if (r < numItems && backingArray[r]< backingArray[index]) {
        int l = (int)(2*index+1);
        if (backingArray[l]<backingArray[r]) {
          j = l;
        } else {
          j = r;
        }
      } else {
        int l = (int)(2*index+1);
        if (l < numItems && backingArray[l]< backingArray[index]) {
          j = l;
        }
      }
      if (j >= 0)       
       backingArray[j].swap(backingArray[index]);;
      index = j;
    } while (index >(int)(2*index+2)  && index>(int)(2*index+1));

}
// from book
template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
   std::pair<Pri,T> x = backingArray[0];
    backingArray[0] = backingArray[numItems-1];
    trickleDown(0);
    numItems--;
    return x;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
 return numItems
}
