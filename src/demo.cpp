// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 100
#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)

using namespace std;
typedef int ElementType;
ElementType Qselect(ElementType A[], int K, int Left, int Right)
{
    ElementType Pivot = A[Left];
    int L = Left, R = Right + 1;

    while (1)
    {
        while (A[++L] < Pivot)
            ;
        while (A[--R] > Pivot)
            ;
        if (L < R)
            iter_swap(&A[L], &A[R]);
        else
            break;
    }
    iter_swap(&A[Left], &A[R]);
    if (K < (L - Left))
        return Qselect(A, K, Left, R - 1);
    else if (K > (L - Left))
        return Qselect(A, K - (L - Left), R + 1, Right);
    else
        return Pivot;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int b[SIZE];
    iota(b, b + SIZE, 1);
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(b, b + SIZE, default_random_engine(seed));
    cout << Qselect(b, 10, 0, SIZE - 1);
    return 0;
}