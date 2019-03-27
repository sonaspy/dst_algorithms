
typedef int DataType;

#ifndef _PairHeap_H
#define _PairHeap_H

struct PairNode;
typedef struct PairNode *PairHeap;
typedef struct PairNode *Position;

PairHeap Initialize( void );
void Destroy( PairHeap H );
PairHeap MakeEmpty( PairHeap H );
PairHeap Insert( DataType Item, PairHeap H, Position *Loc );
PairHeap DeleteMin( DataType *MinItem, PairHeap H );
DataType FindMin( PairHeap H );
PairHeap DecreaseKey( Position P,
                      DataType NewVal, PairHeap H );
int IsEmpty( PairHeap H );
int IsFull( PairHeap H );
#endif
