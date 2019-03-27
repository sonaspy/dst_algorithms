typedef int DataType;
/* START: fig3_45.txt */
#ifndef _Stack_h
#define _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty( Stack S );
int IsFull( Stack S );
Stack CreateStack( int MaxElements );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( DataType X, Stack S );
DataType Top( Stack S );
void Pop( Stack S );
DataType TopAndPop( Stack S );

#endif  /* _Stack_h */

/* END */
