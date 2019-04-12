// insertion sort

#ifndef insertionSort_
#define insertionSort_

// optimize code for speed
#pragma optimize("t", on)

template<class T>
void insertionSort(T a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        T t = a[i];
        int j;
        for (j = i; 1 <= j && t < a[j - 1]; j -= 1)
            a[j] = a[j - 1];
        a[j] = t;
    }
}

#pragma optimize("t", off)
#endif
