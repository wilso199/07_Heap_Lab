#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 * 
 */
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
  Heap();
  ~Heap();

  //Add a new item
  virtual void add(std::pair<Pri,T> toAdd);

  //Remove the item with lowest priority, and return it
  //If the queue is empty, throw a string exception
  virtual std::pair<Pri,T> remove();

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems();

private:
  int arrSize;
  int numItems;
  std::pair<Pri, T>* backingArray;

  //Grow the backingArray by making a new array of twice the size,
  // and copying over the data
  void grow();

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it up the "tree" of the heap until you find the right
  // place
  void bubbleUp(unsigned long index);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it down the "tree" of the heap until you find the right
  // place
  void trickleDown(unsigned long index);  
};

#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
    backingArray = new std::pair<Pri, T>[START_SIZE];
    arrSize = START_SIZE;
    numItems = 0;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
    delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
    
    int doubledSize = arrSize *2;
    
    std::pair<Pri, T>* newArray = new std::pair<Pri, T>[doubledSize];
    
    for(int i = 0; i < numItems; i++){
        newArray[i] = backingArray[i];
    }
    
    delete[] backingArray;
    backingArray = newArray;
    arrSize = doubledSize;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
    //TODO
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
    //TODO
    std::pair<Pri,T> tmp;
    return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
    
    return numItems;
}

