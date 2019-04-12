#include "binheap.h"
#include "fatal.h"
#include <stdlib.h>

#define MinPQSize (10)
#define MinData (-32767)
typedef int Position;
struct HeapStruct
{
    int Capacity;
    int Size;
    DataType *Elements;
};

/* START: fig6_0.txt */
PriorityQueue
Initialize(int MaxElements)
{
    PriorityQueue H;
    /* 1*/ if (MaxElements < MinPQSize)
        /* 2*/ Error("Priority queue size is too small");
    /* 3*/ H = malloc(sizeof(struct HeapStruct));
    /* 4*/ if (H == NULL)
        /* 5*/ FatalError("Out of space!!!");
    /* Allocate the array plus one extra for sentinel */
    /* 6*/ H->Elements = malloc((MaxElements + 1) * sizeof(DataType));
    /* 7*/ if (H->Elements == NULL)
        /* 8*/ FatalError("Out of space!!!");
    /* 9*/ H->Capacity = MaxElements;
    /*10*/ H->Size = 0;
    /*11*/ H->Elements[0] = MinData;
    /*12*/ return H;
}
/* END */

void MakeEmpty(PriorityQueue H)
{
    H->Size = 0;
}

/* START: fig6_8.txt */
/* H->Element[ 0 ] is a sentinel */

void percolateUP(Position k, PriorityQueue H)
{
    int X = H->Elements[k];
    for (; H->Elements[k / 2] > X; k /= 2)
        H->Elements[k] = H->Elements[k / 2];
    H->Elements[k] = X;
}

void percolateDown(Position k, PriorityQueue H)
{
    int Child, i;
    DataType LastElement = H->Elements[H->Size];
    for (i = k; i * 2 <= H->Size; i = Child)
    {
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;
        if (LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
}

void Insert(DataType X, PriorityQueue H)
{
    if (IsFull(H))
    {
        Error("Priority queue is full");
        return;
    }
    H->Elements[++H->Size] = X;
    percolateUP(H->Size, H);
}
/* END */

PriorityQueue BuildHeap(int h_size, DataType* Arr){
    PriorityQueue newH = Initialize(10 * h_size);
    newH->Elements = Arr;
    newH->Size = h_size;
    for(int i = h_size / 2; i > 0; i--)
        percolateDown(i, newH);
    return newH;
}

/* START: fig6_12.txt */
DataType
DeleteMin(PriorityQueue H)
{
    /* 1*/ if (IsEmpty(H))
    {
        /* 2*/ Error("Priority queue is empty");
        /* 3*/ return H->Elements[0];
    }
    DataType MinElement;
    MinElement = H->Elements[1];
    H->Size--;
    percolateDown(1, H);
    return MinElement;
}
/* END */

DataType
FindMin(PriorityQueue H)
{
    if (!IsEmpty(H))
        return H->Elements[1];
    Error("Priority Queue is Empty");
    return H->Elements[0];
}

int IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}

int IsFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}

void Destroy(PriorityQueue H)
{
    free(H->Elements);
    free(H);
}

#if 0
/* START: fig6_14.txt */
for( i = N / 2; i > 0; i-- )
    PercolateDown( i );
/* END */
#endif
