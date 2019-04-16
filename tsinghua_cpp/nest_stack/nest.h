/******************************************************************************************

 ******************************************************************************************/

#pragma once

#include<iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../UniPrint/print.h"

#include "../stack/stack.h"

bool paren ( const char exp[], int lo, int hi );
void displaySubstring ( const char exp[], int lo, int hi );
void displayProgress ( const char exp[], int i, Stack<char> S );
