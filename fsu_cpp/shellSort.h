// shell sort

#ifndef shellSort_
#define shellSort_

// optimize code for speed
#pragma optimize("t", on)
const int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
template <class T>
void shellSort(T a[], int n)
{
    int i, j, si, step;
    for (si = 0; Sedgewick[si] >= n; ++si)
        ;

    for (step = Sedgewick[si]; step > 0; step = Sedgewick[++si])
        for (i = step; i < n; ++i)
        {
            T t = a[i];
            for (j = i; step <= j && t < a[j - step]; j -= step)
                a[j] = a[j - step];
            a[j] = t;
        }
}

#pragma optimize("t", off)
#endif
