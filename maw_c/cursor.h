typedef int DataType;
#define SpaceSize 100

/* START: fig3_28.txt */
#ifndef _Cursor_H
#define _Cursor_H

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace(void);

List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position Find(DataType X, const List L);
void Delete(DataType X, List L);
Position FindPrevious(DataType X, const List L);
void Insert(DataType X, List L, Position P);
void DeleteList(List L);
Position Header(const List L);
Position First(const List L);
Position Advance(const Position P);
DataType Retrieve(const Position P);

#endif /* _Cursor_H */

/* END */
