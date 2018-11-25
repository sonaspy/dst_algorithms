// change the length of an 2D array
#ifndef changeLength2D_
#define changeLength2D_
#include<iostream>
#include "myExceptions.h"
using namespace std;

template <class T>
void changeLength2D(T**& a, int oldRows, int copyRows,
                    int copyColumns, int newRows, int newColumns)
{// Resize the two-dimensional array a that has oldRows number of rows.
 // The dimensions of the resized array are newRows x newColumns.
 // Copy the top left oldRows x newColumns sub array into the resized array.
   // make sure new dimensions are adequate
   if (copyRows > newRows || copyColumns > newColumns)
      throw illegalParameterValue("new dimensions are too small");

   T** temp = new T*[newRows];              // array for rows
   // create row arrays for temp
   for (int i = 0; i < newRows; i++)
      temp[i] = new T[newColumns];

   // copy from old space to new space, delete old space
   for (int i = 0; i < copyRows; i++)
   {
      copy(a[i], a[i] + copyColumns, temp[i]);
      delete [] a[i];                      // deallocate old memory
   }

   // delete remaining rows of a
   for (int i = copyRows; i < oldRows; i++)
     delete [] a[i];

   delete [] a;
   a = temp;
}

#endif
