
typedef int DataType;

/* START: fig6_4.txt */
#ifndef _BinHeap_H
#define _BinHeap_H

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(DataType X, PriorityQueue H);
DataType DeleteMin(PriorityQueue H);
DataType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif

/* END */
