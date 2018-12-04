#pragma once

template <typename T>
Rank Vector<T>::search(T const &e, Rank lo, Rank hi) const
{
    return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}