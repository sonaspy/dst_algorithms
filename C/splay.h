#include <stdlib.h>
#include "fatal.h"

typedef int DataType;
#define Infinity 30000
#define NegInfinity (-30000)

/* START: fig12_5.txt */
#ifndef _Splay_H
#define _Splay_H

struct SplayNode;
typedef struct SplayNode *SplayTree;

SplayTree MakeEmpty( SplayTree T );
SplayTree Find( DataType X, SplayTree T );
SplayTree FindMin( SplayTree T );
SplayTree FindMax( SplayTree T );
SplayTree Initialize( void );
SplayTree Insert( DataType X, SplayTree T );
SplayTree Remove( DataType X, SplayTree T );
DataType Retrieve( SplayTree T );  /* Gets root item */

#endif  /* _Splay_H */
/* END */
