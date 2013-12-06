#include <string>
#include <iostream>


//My implementation is base on reading: http://opendatastructures.org/ods-cpp/10_1_Implicit_Binary_Tree.html

template<class Pri, class T>
Heap<Pri,T>::Heap()
{
  arrSize = START_SIZE;

  numItems = 0;

  backingArray = new std::pair<Pri, T>[arrSize];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap()
{
  delete [] backingArray;

  backingArray = NULL;
}

template<class Pri, class T>
void Heap<Pri,T>::grow()
{
  std::pair<Pri, T>* newArray = new std::pair<Pri, T>[2*arrSize];

  for(int i = 0;i<numItems;i++)
  {
      newArray[i] = backingArray[i];
  }

  arrSize = 2 * arrSize;

  delete[]backingArray;

  backingArray = NULL;

  backingArray = newArray;

}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd)
{
    int i = numItems;

    if(numItems == arrSize)
    {
        grow();
    }

    backingArray[numItems] = toAdd;

    numItems++;

    bubbleUp(i-1);

}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index)
{

   int parent = (index-1)/2;

   while(index > 0 && (backingArray[index].first < backingArray[parent].first))
   {

      std :: swap(backingArray[index],backingArray[parent]);

      int tep = index;

      parent = tep;

      index = parent;
   }
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index)
{

int pos = index;

do{

    int j = -1;

    int right = 2 * pos + 2;

    if( (right < numItems ) && ( backingArray[right].first < backingArray[pos].first) )
    {

       int left = 2 * index + 1;

       if(backingArray[left].first < backingArray[right].first)
        {
            j = left;
        }
        else
        {
            j = right;
        }
    }
    else
    {
        int left = 2 * pos + 1;

        if( (left < numItems)  && (backingArray[left].first < backingArray[pos].first))
        {
            j = left;
        }
    }

    if(j >=0)
      {
        std :: swap(backingArray[pos],backingArray[j]);
      }

      pos = j;

  }while(pos >= 0);
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove()
{

  std::pair<Pri,T> remover;

  remover = backingArray[0];

  std :: swap(backingArray[0],backingArray[numItems-1]);

  numItems--;

  trickleDown(0);

  return remover;

}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems()
{
  return numItems;
}

