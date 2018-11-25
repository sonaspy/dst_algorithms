// author - newguo@sonaspy.cn 
// coding - utf_8 
#ifndef _FUCTIONS_
#define _FUCTIONS_

#include<iostream>
#include "myExceptions.h"
using namespace std;

template <class T>
int sequentialSearch(T a[], int n, const T &x)
{   // Search the unordered list a[0:n-1] for x.
    // Return position if found; return -1 otherwise.
    int i;
    for (i = 0; i < n && a[i] != x; i++)
        ;
    if (i == n)
        return -1;
    else
        return i;
}

template <class T>
int rSequentialSearch(T a[], int n, const T &x)
{   // Search the unordered list a[0:n-1] for x.
    // Return position if found; return -1 otherwise.
    if (n < 1)
        return -1;
    if (a[n - 1] == x)
        return n - 1;
    return rSequentialSearch(a, n - 1, x);
}


template <class T>
T polyEval(T coeff[], int n, const T& x){
    T y = 1, value = coeff[0];
    for(int i = 1; i <= n; i++){
        y *= x;
        value += y * coeff[i];
    }
    return value;
}

template <class T>
T horner(T coeff[], int n, const T &x)
{   // Evaluate the degree n polynomial with
    // coefficients coeff[0:n] at the point x.
    T value = coeff[n];
    for (int i = 1; i <= n; i++)
        value = value * x + coeff[n - i];
    return value;
}

template <class T>
void Rank(T a[], int n, int r[]){
    int i, j;
    for(i = 0; i < n; i++)
        r[i] = 0;
    for(i = 1; i < n; i++)
        for(j = 0; j < i; j++){
            if(a[j] <= a[i])
                r[i]++;
            else
                r[j]++;
        }
}



template <class T>
void rearrange(T a[], int n, int r[])
{ // In-place rearrangement into sorted order.
    for (int i = 0; i < n; i++)
        // get proper element to a[i]
        while (r[i] != i)
        {
            int t = r[i];
            swap(a[i], a[t]);
            swap(r[i], r[t]);
        }
}

template <class T>
int indexOfMax(T a[], int n)
{
    if (n <= 0)
        throw illegalParameterValue("n must be > 0");

    int indexOfMax = 0;
    for (int i = 1; i < n; i++)
        if (a[indexOfMax] < a[i])
            indexOfMax = i;
    return indexOfMax;
}

template <class T>
void selectionSort(T a[], int n)
{ // Sort the n elements a[0:n-1].
    for (int size = n; size > 1; size--)
    {
        int j = indexOfMax(a, size);
        swap(a[j], a[size - 1]);
    }
}

template <class T>
void bubbleOnce(T a[], int n)
{ // Bubble largest element in a[0:n-1] to right.
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            swap(a[i], a[i + 1]);
}
template <class T>
void bubbleSort(T a[], int n)
{ // Sort a[0:n - 1] using bubble sort.
    for (int i = n; i > 1; i--)
        bubbleOnce(a, i);
}

template <class T>
void insert(T a[], int &n, const T &x)
{   // Insert x into the sorted array a[0:n-1].
    // Assume a is of size > n
    int i;
    for (i = n - 1; i >= 0 && x < a[i]; i--)
        a[i + 1] = a[i];
    a[i + 1] = x;
    n++; // one element added to a
}

template <class T>
void insertionSort(T a[], int n)
{ // Sort a[0:n-1] using the insertion sort method.
    for (int i = 1; i < n; i++)
    {
        T t = a[i];
        insert(a, i, t);
    }
}

template <class T>
void selectionSort_1(T a[], int n)
{ // Early-terminating version of selection sort.
    bool sorted = false;
    for (int size = n; !sorted && (size > 1); size--)
    {
        int indexOfMax = 0;
        sorted = true;
        // find largest
        for (int i = 1; i < size; i++)
            if (a[indexOfMax] <= a[i])
                indexOfMax = i;
            else
                sorted = false; // out of order
        swap(a[indexOfMax], a[size - 1]);
    }
}

template <class T>
bool bubble_(T a[], int n)
{                         // Bubble largest element in a[0:n-1] to right.
    bool swapped = false; // no swaps so far
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
            swapped = true; // swap was done
        }
    return swapped;
}

template <class T>
void bubbleSort_(T a[], int n)
{ // Early-terminating version of bubble sort.
    for (int i = n; i > 1 && bubble(a, i); i--)
        ;
}


template <class T>
T sum_stepcount(T a[], int n)
{ // Return sum of numbers a[0:n - 1].
    T theSum = 0;
    stepCount++; // for theSum = 0
    for (int i = 0; i < n; i++)
    {
        stepCount++; // for the for statement
        theSum += a[i];
        stepCount++; // for assignment
    }
    stepCount++; // for last execution of for statement
    stepCount++; // for return
    return theSum;
}

template <class T>
T rSum_stepcount(T a[], int n)
{                // Return sum of numbers a[0:n - 1].
    stepCount++; // for if conditional
    if (n > 0)
    {
        stepCount++; // for return and rSum invocation
        return rSum(a, n - 1) + a[n - 1];
    }
    stepCount++; // for return
    return 0;
}

template <class T>
void transpose_matrix(T **a, int rows)
{ // In-place transpose of matrix a[0:rows-1][0:rows-1].
    for (int i = 0; i < rows; i++)
        for (int j = i + 1; j < rows; j++)
            swap(a[i][j], a[j][i]);
}

template <class T>
void matrixAdd(T **a, T **b, T **c, int numberOfRows,
               int numberOfColumns)
{ // Add matrices a and b to obtain matrix c.
    for (int i = 0; i < numberOfRows; i++)
        for (int j = 0; j < numberOfColumns; j++)
            c[i][j] = a[i][j] + b[i][j];
}

template <class T>
void squareMatrixMultiply(T **a, T **b, T **c, int n)
{ // Multiply the n x n matrices a and b to get c.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            T sum = 0;
            for (int k = 0; k < n; k++)
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
}

template <class T>
void matrixMultiply(T **a, T **b, T **c, int m, int n, int p)
{   // Multiply the m x n matrix a and the n x p matrix b
    // to get c.
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
        {
            T sum = 0;
            for (int k = 0; k < n; k++)
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
}

void fastSquareMatrixMultiply(int **a, int **b, int **c, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
}

template <class T>
bool minmax(T a[], int n, int &indexOfMin, int &indexOfMax)
{   // Locate min and max elements in a[0:n-1].
    // Return false if less than one element.
    if (n < 1)
        return false;
    indexOfMin = indexOfMax = 0; // initial guess
    for (int i = 1; i < n; i++)
    {
        if (a[indexOfMin] > a[i])
            indexOfMin = i;
        if (a[indexOfMax] < a[i])
            indexOfMax = i;
    }
    return true;
}

template <class T>
bool minmax_(T a[], int n, int &indexOfMin, int &indexOfMax)
{   // Locate min and max elements in a[0:n-1].
    // Return false if less than one element.
    if (n < 1)
        return false;
    indexOfMin = indexOfMax = 0; // initial guess
    for (int i = 1; i < n; i++)
        if (a[indexOfMin] > a[i])
            indexOfMin = i;
        else if (a[indexOfMax] < a[i])
            indexOfMax = i;
    return true;
}

template <class T>
int sequentialSearch(T a[], int n, const T &x)
{             // Search the unordered list a[0:n-1] for x.
              // Return position if found; return -1 otherwise.
    a[n] = x; // assume extra position available
    int i;
    for (i = 0; a[i] != x; i++)
        ;
    if (i == n)
        return -1;
    return i;
}


#endif