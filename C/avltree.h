typedef int DataType;

/* START: fig4_35.txt */
#ifndef _AvlTree_H
#define _AvlTree_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(DataType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(DataType X, AvlTree T);
AvlTree Delete(DataType X, AvlTree T);
DataType Retrieve(Position P);

#endif /* _AvlTree_H */
/* END */
