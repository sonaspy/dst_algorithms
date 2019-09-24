#include <stdlib.h>
#include "fatal.h"

typedef int DataType;
#define NegInfinity (-10000)

#ifndef _RedBlack_H
#define _RedBlack_H

struct RedBlackNode;
typedef struct RedBlackNode *Position;
typedef struct RedBlackNode *RedBlackTree;

RedBlackTree MakeEmpty( RedBlackTree T );
Position Find( DataType X, RedBlackTree T );
Position FindMin( RedBlackTree T );
Position FindMax( RedBlackTree T );
RedBlackTree Initialize( void );
RedBlackTree Insert( DataType X, RedBlackTree T );
RedBlackTree Remove( DataType X, RedBlackTree T );
DataType Retrieve( Position P );
void PrintTree( RedBlackTree T );

#endif  /* _RedBlack_H */

/* END */
