#pragma once

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{
    T *V = _elem + lo;
    for (Rank i = hi - lo; i > 0; i--)
        swap(V[i - 1], V[rand() % i]);
}