/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> struct Hailstone {  
   virtual void operator() ( T& e ) {  
      int step = 0;  
      while ( 1 != e ) {  
         ( e % 2 ) ? e = 3 * e + 1 : e /= 2;
         step++;
      }
      e = step;  
   }
};