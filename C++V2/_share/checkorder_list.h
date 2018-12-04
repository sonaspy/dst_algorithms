/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

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