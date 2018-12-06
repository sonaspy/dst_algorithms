



#include "..\list\list.h"

template <typename T> void checkOrder ( List<T> & L ) {  
   int unsorted = 0;  
   L.traverse ( CheckOrder<T> ( unsorted, L.first()->data ) );  
   if ( 0 < unsorted )
      printf ( "Unsorted with %d adjacent disordered pair(s)\n", unsorted );
   else
      printf ( "Sorted\n" );
   printf ( "DISORDERED = %d\n", L.disordered() );
}