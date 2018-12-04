#pragma once

template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi)
{
    T *A = _elem + lo;
    int lb = mi - lo;
    T *B = new T[lb];
    for (Rank i = 0; i < lb; B[i] = A[i++])
        ;
    int lc = hi - mi;
    T *C = _elem + mi;
    for (Rank i = 0, j = 0, k = 0; j < lb; )
    {
        if (!(k < lc) || B[j] <= C[k])
            A[i++] = B[j++];
        if (k < lc && C[k] < B[j])
            A[i++] = C[k++];
    }
    delete[] B;
}
