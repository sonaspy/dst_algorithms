// bubble sort

#include <iostream>
#include <algorithm> // has copy

using namespace std;

template <class T>
void bubbleSort(T a[], int n)
{ // Bubble largest element in a[0:n-1] to right.
    for (int k = n; k > 1; k--)
        for (int i = 0; i < k - 1; i++)
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
}
