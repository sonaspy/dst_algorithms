#pragma once

template <typename T>
void Vector<T>::heapSort(Rank lo, Rank hi)
{
    /*DSA*/ printf("\tHEAPsort [%3d, %3d)\n", lo, hi);
    PQ_ComplHeap<T> H(_elem + lo, hi - lo);
    while (!H.empty())
    /*DSA*/ {
        _elem[--hi] = H.delMax();
        /*DSA*/ for (int i = lo; i < hi; i++)
            print(H[i]);
        print(_elem[hi]);
        printf("\n");
/*DSA*/}
}
