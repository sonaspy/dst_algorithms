/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <stdlib.h>
#include <time.h>  

/******************************************************************************************
 * ��[0, range)���������һ����
 ******************************************************************************************/
static int dice ( int range ) { return rand() % range; }  
static int dice ( int lo, int hi ) { return lo + rand() % ( hi - lo ); }  
static float dice ( float range ) { return rand() % ( 1000 * ( int ) range ) / ( float ) 1000.; }
static double dice ( double range ) { return rand() % ( 1000 * ( int ) range ) / ( double ) 1000.; }
static char dice ( char range ) { return ( char ) ( 32 + rand() % 96 ); }