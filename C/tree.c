#include "tree.h"
#include <stdlib.h>
#include "fatal.h"

struct TreeNode
{
    DataType Element;
    SearchTree Left;
    SearchTree Right;
};

/* START: fig4_17.txt */
SearchTree
MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}
/* END */

/* START: fig4_18.txt */
Position
Find(DataType X, SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    else
        return T;
}
/* END */

/* START: fig4_19.txt */
Position
FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}
/* END */

/* START: fig4_20.txt */
Position
FindMax(SearchTree T)
{
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;
    return T;
}
/* END */

/* START: fig4_22.txt */
SearchTree
Insert(DataType X, SearchTree T)
{
    /* 1*/ if (T == NULL)
    {
        /* Create and return a one-node tree */
        /* 2*/ T = malloc(sizeof(struct TreeNode));
        /* 3*/ if (T == NULL)
            /* 4*/ FatalError("Out of space!!!");
        else
        {
            /* 5*/ T->Element = X;
            /* 6*/ T->Left = T->Right = NULL;
        }
    }
    else
        /* 7*/ if (X < T->Element)
        /* 8*/ T->Left = Insert(X, T->Left);
    else
        /* 9*/ if (X > T->Element)
        /*10*/ T->Right = Insert(X, T->Right);
    /* Else X is in the tree already; we'll do nothing */
    /*11*/ return T; /* Do not forget this line!! */
}
/* END */


SearchTree Delete(DataType X, SearchTree T)
{
    Position tmp_node;
    if (!T) Error("Element not found");
    else if (X < T->Element) /* Go left */
        T->Left = Delete(X, T->Left);
    else if (X > T->Element) /* Go right */
        T->Right = Delete(X, T->Right);
    else if (T->Left && T->Right) /* Two children */
    {
        tmp_node = FindMin(T->Right);
        T->Element = tmp_node->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else /* One or zero children */
    {
        tmp_node = T;
        T =( T->Left == NULL? T->Right : T->Left);
        free(tmp_node);
    }
    return T;
}

DataType
Retrieve(Position P)
{
    return P->Element;
}
