#include <stdlib.h>
#include "fatal.h"

typedef int DataType;

#ifndef _AATree_H
#define _AATree_H

struct AANode;
typedef struct AANode *Position;
typedef struct AANode *AATree;

AATree MakeEmpty(AATree T);
Position Find(DataType X, AATree T);
Position FindMin(AATree T);
Position FindMax(AATree T);
AATree Initialize(void);
AATree Insert(DataType X, AATree T);
AATree Remove(DataType X, AATree T);
DataType Retrieve(Position P);

extern Position NullNode;

#endif /* _AATree_H */

/* END */
