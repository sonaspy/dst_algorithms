#pragma once

#include "Fib.h"

template <typename T>
static Rank fibSearch(T *A, T const &e, Rank lo, Rank hi)
{
    /*DSA*/ printf("FIB search (B)\n");
    Fib fib(hi - lo);
    while (lo < hi)
    {
        /*DSA*/ for (int i = 0; i < lo; i++)
            printf("     ");
        if (lo >= 0)
            for (int i = lo; i < hi; i++)
                printf("....^");
        else
            printf("<<<<|");
        printf("\n");
        while (hi - lo < fib.get())
            fib.prev();
        Rank mi = lo + fib.get() - 1;
        (e < A[mi]) ? hi = mi : lo = mi + 1;
    }
    /*DSA*/ for (int i = 0; i < lo - 1; i++)
        printf("     ");
    if (lo > 0)
        printf("....|\n");
    else
        printf("<<<<|\n");
    return --lo;
}
