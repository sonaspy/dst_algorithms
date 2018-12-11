#pragma once

#include "../vector/vector.h"
#include "../compare.h"
#ifndef PQ_
#define PQ_

#define InHeap(n, i) (((-1) < (i)) && ((i) < (n)))  
#define LastInternal(n) Parent(n - 1)               
#define Parent(i) ((i - 1) >> 1)                    
#define LChild(i) (1 + ((i) << 1))                  
#define RChild(i) ((1 + (i)) << 1)                  
#define ParentValid(i) (0 < i)                      
#define LChildValid(n, i) InHeap(n, LChild(i))      
#define RChildValid(n, i) InHeap(n, RChild(i))      
#define Bigger(PQ, i, j) (lt(PQ[i], PQ[j]) ? j : i) 
#define ProperParent(PQ, n, i) \
    (RChildValid(n, i) ? Bigger(PQ, Bigger(PQ, i, LChild(i)), RChild(i)) : (LChildValid(n, i) ? Bigger(PQ, i, LChild(i)) : i)) 

template <class T>
struct PQ
{
    virtual void insert(T) = 0;
    virtual T getMax() = 0;
    virtual T delMax() = 0;
};

template <class T>
class PQ_ComplHeap : public PQ<T>, public Vector<T>
{
  protected:
    Rank percolateDown(Rank n, Rank i); 
    Rank percolateUp(Rank i);           
    void heapify(Rank n);               
  public:
    PQ_ComplHeap() {} 
    PQ_ComplHeap(T *A, Rank n)
    {
        copyFrom(A, 0, n);
        heapify(n);
    }               
    void insert(T); 
    T getMax();     
    T delMax();     
};

template <class T>
void PQ_ComplHeap<T>::heapify(Rank n)
{                                                    
    for (int i = LastInternal(n); InHeap(n, i); i--) 
        percolateDown(n, i);                         
}

template <class T>
T PQ_ComplHeap<T>::getMax() { return _elem[0]; } 

template <class T>
T PQ_ComplHeap<T>::delMax()
{ 
    T maxElem = _elem[0];
    _elem[0] = _elem[--_size]; 
    percolateDown(_size, 0);   
    return maxElem;            
}

template <class T>
void PQ_ComplHeap<T>::insert(T e)
{                           
    Vector<T>::insert(e);   
    percolateUp(_size - 1); 
}

template <class T>
Rank PQ_ComplHeap<T>::percolateDown(int n, Rank i)
{
    Rank j;            
    T tmp = _elem[i];                          
    while (i != (j = ProperParent(_elem, n, i))) 
    {
        _elem[i] = _elem[j];
        i = j;
    }
    _elem[i] = tmp;         
    return i; 
}

template <class T>
Rank PQ_ComplHeap<T>::percolateUp(Rank i)
{   
    T tmp = _elem[i];
    while (ParentValid(i))
    {                       
        Rank j = Parent(i); 
        if (lt(_elem[i], _elem[j]))
            break; 
        _elem[i] =  _elem[j];
        i = j; 
    }
    _elem[i] = tmp;         
    return i; 
}

#endif