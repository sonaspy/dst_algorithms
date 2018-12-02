// quick sort

#ifndef quicksort_
#define quicksort_

#include "indexOfMax.h"

using namespace std;

void __quickSort(int a[], int leftstart, int rightEnd)
{ // Sort a[leftstart:rightEnd], a[rightEnd+1] >= a[leftstart:rightEnd].
  if (leftstart >= rightEnd)
    return;

  int leftCursor = leftstart,       // left-to-right cursor
      rightCursor = rightEnd + 1; // right-to-left cursor
  int pivot = a[leftstart];

  // swap elements >= pivot on left side
  // with elements <= pivot on right side
  while (true)
  {
     while (a[++leftCursor] < pivot);
     while (a[--rightCursor] > pivot);

    if (leftCursor >= rightCursor)
      break; // swap pair not found
    swap(a[leftCursor], a[rightCursor]);
  }
  // place pivot
  swap(a[leftstart],a[rightCursor]);

  __quickSort(a, leftstart, rightCursor - 1);  // sort left segment
  __quickSort(a, rightCursor + 1, rightEnd); // sort right segment
}
void q_sort(int a[], int n)
{ // Sort a[0 : n - 1] using the quick sort method.
  if (n <= 1)
    return;
  // move largest element to right end
  int max = indexOfMax(a, n);
  swap(a[n - 1], a[max]);
  __quickSort(a, 0, n - 2);
}
#endif
