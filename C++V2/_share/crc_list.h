/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "..\list\list.h"

template <typename T> void crc ( List<T> & L ) {  
   T crc = 0; L.traverse ( Crc<T> ( crc ) );  
   printf ( "CRC =" ); print ( crc ); printf ( "\n" );  
}