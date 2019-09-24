typedef int DataType;
/* START: fig3_39.txt */
#ifndef _Stack_h
#define _Stack_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(DataType X, Stack S);
DataType Top(Stack S);
void Pop(Stack S);

#endif /* _Stack_h */

/* END */
