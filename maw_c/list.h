typedef int DataType;

/* START: fig3_6.txt */
#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(DataType X, List L);
void Delete(DataType X, List L);
Position FindPrevious(DataType X, List L);
void Insert(DataType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
DataType Retrieve(Position P);

#endif /* _List_H */
/* END */
