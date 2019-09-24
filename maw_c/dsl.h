#include <stdlib.h>
#include "fatal.h"

typedef int DataType;
#define Infinity (10000)

#ifndef _SkipList_H
#define _SkipList_H

struct SkipNode;
typedef struct SkipNode *Position;
typedef struct SkipNode *SkipList;

SkipList MakeEmpty(SkipList L);
Position Find(DataType X, SkipList L);
Position FindMin(SkipList L);
Position FindMax(SkipList L);
SkipList Initialize(void);
SkipList Insert(DataType X, SkipList L);
SkipList Remove(DataType X, SkipList L);
DataType Retrieve(Position P);

#endif /* _SkipList_H */

/* END */
