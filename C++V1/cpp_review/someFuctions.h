// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>

using namespace std;

template <class T>
void fill(T *a, int start, int end, const T &value)
{ // Set a[start:end-1].
    for (int i = start; i < end; i++)
        a[i] = value;
}

template <class T>
void iota(T *a, int n, const T &value)
{ // Set a[i] = a[i] + value, 0 <= i < n.
    for (int i = 0; i < n; i++)
        a[i] += value;
}

template <class T>
int mismatch(T *a, T *b, int n)
{   // Return smallest i such that a[i] != b[i].
    // Return n if no such i.
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return i;

    // no mismatch
    return n;
}

template <class T>
int count(T a[], int n, const T &value)
{ // Return number of occurrences of value in a[0:n-1].
    if (n < 1)
        throw  "n must be >= 1";

    int theCount = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            theCount++;
    return theCount;
}


