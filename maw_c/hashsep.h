/* Interface for separate chaining hash table */
typedef int DataType;

/* START: fig5_2.txt */
typedef unsigned int Index;
/* END */

/* START: fig5_7.txt */
#ifndef _HashSep_H
#define _HashSep_H

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( DataType Key, HashTable H );
void Insert( DataType Key, HashTable H );
DataType Retrieve( Position P );
/* Routines such as Delete are MakeEmpty are omitted */

#endif  /* _HashSep_H */
/* END */
