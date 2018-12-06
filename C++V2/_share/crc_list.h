



#include "..\list\list.h"

template <class T> void crc ( List<T> & L ) {  
   T crc = 0; L.traverse ( Crc<T> ( crc ) );  
   printf ( "CRC =" ); print ( crc ); printf ( "\n" );  
}