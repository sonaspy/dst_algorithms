/* Interface for quadratic probing hash table */
typedef int DataType;

/* START: fig5_14.txt */
#ifndef _HashQuad_H
#define _HashQuad_H

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( DataType Key, HashTable H );
void Insert( DataType Key, HashTable H );
DataType Retrieve( Position P, HashTable H );
HashTable Rehash( HashTable H );
/* Routines such as Delete are MakeEmpty are omitted */

#endif  /* _HashQuad_H */

/* END */
