typedef int DataType;

/* START: fig4_16.txt */
#ifndef _Tree_H
#define _Tree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(DataType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(DataType X, SearchTree T);
SearchTree Delete(DataType X, SearchTree T);
DataType Retrieve(Position P);

#endif /* _Tree_H */

/* END */
