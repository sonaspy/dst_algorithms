#pragma once

template <typename T>
Posi(T) List<T>::find(T const &e, int n, Posi(T) p) const
{
    while (0 < n--)
        if (e == (p = p->pred)->data)
            return p;
    return NULL;
}