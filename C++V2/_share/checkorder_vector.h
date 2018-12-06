



#include "..\vector\vector.h"

template <typename T> void checkOrder ( Vector<T> & V ) {  
   int unsorted = 0;  
   V.traverse ( CheckOrder<T> ( unsorted, V[0] ) );  
   if ( 0 < unsorted )
      printf ( "Unsorted with %d adjacent disordered pair(s)\n", unsorted );
   else
      printf ( "Sorted\n" );
}

 
 
 
 
 
 