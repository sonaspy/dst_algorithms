// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

template <class T>
void insertionSort(T *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        T t = a[i];
        int j;
        for (j = i; 1 <= j && t < a[j - 1]; j -= 1)
            a[j] = a[j - 1];
        a[j] = t;
    }
}

const int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
template <class T>
inline void shellSort(T *a, int n)
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

template <class T>
inline void HeapSort(T *a, int n)
{
    for (int i = n; i > 1; --i)
    {
        make_heap(a, a + i);
        swap(a[0], a[i - 1]);
    }
}

template <class T>
void merge(T *c, T *d, int startOfFirst, int endOfFirst, int endOfSecond)
{                                // Merge two adjacent segments from c to d.
    int first = startOfFirst,    // cursor for first segment
        second = endOfFirst + 1, // cursor for second
        result = startOfFirst;   // cursor for result
    while ((first <= endOfFirst) && (second <= endOfSecond))
    {
        if (c[first] <= c[second])
            d[result++] = c[first++];
        else
            d[result++] = c[second++];
    }
    while (first <= endOfFirst)
        d[result++] = c[first++];
    while (second <= endOfSecond)
        d[result++] = c[second++];
}

template <class T>
void mergePass(T *x, T *y, int n, int seglen)
{              // Merge adjacent segments from x to y.
    int i = 0; // start of the next segment
    while (i <= n - 2 * seglen)
    { // merge two adjacent segments from x to y
        merge(x, y, i, i + seglen - 1, i + 2 * seglen - 1);
        i += 2 * seglen;
    }

    if (i + seglen < n)
        // 2 segments remain
        merge(x, y, i, i + seglen - 1, n - 1);
    else
        // 1 segment remains, copy to y
        for (int j = i; j < n; j++)
            y[j] = x[j];
}

template <class T>
void mergeSort(T *a, int n)
{ // Sort a[0 : n - 1] using the merge sort method.
    T *tmp = new T[n];
    int seglen = 1;
    while (seglen < n)
    {
        mergePass(a, tmp, n, seglen); // merge from a to tmp
        seglen *= 2;
        mergePass(tmp, a, n, seglen); // merge from tmp to a
        seglen *= 2;
    }
}

template <class T>
T Median3(T a[], int Left, int Right)
{
    int Center = (Left + Right) / 2;
    if (a[Left] > a[Center])
        swap(a[Left], a[Center]);
    if (a[Left] > a[Right])
        swap(a[Left], a[Right]);
    if (a[Center] > a[Right])
        swap(a[Center], a[Right]);
    swap(a[Center], a[Right - 1]);
    return a[Right - 1];
}

#define Cutoff (3)
template <class T>
void Qsort(T *a, int Left, int Right)
{
    int le_cur, ri_cur;
    T Pivot;
    if (Cutoff < Right - Left + 1)
    {
        Pivot = Median3(a, Left, Right);
        le_cur = Left;
        ri_cur = Right - 1;
        while (true)
        {
            while (a[++le_cur] < Pivot)
                ;
            while (a[--ri_cur] > Pivot)
                ;
            if (le_cur < ri_cur)
                swap(a[le_cur], a[ri_cur]);
            else
                break;
        }
        swap(a[le_cur], a[Right - 1]);
        Qsort(a, Left, le_cur - 1);
        Qsort(a, le_cur + 1, Right);
    }

    else
        insertionSort(a + Left, Right - Left + 1);
}

template <class T>
inline void quickSort(T *a, int n)
{
    Qsort(a, 0, n - 1);
}

template <class T>
inline vector<int> tableSort(T *a, int n)
{
    vector<int> table(n);
    int c = 0;
    generate(table.begin(), table.end(), [&]() { return c++; });
    for (int i = 1; i < n; i++)
    {
        int t = table[i];
        int j;
        for (j = i; 1 <= j && a[t] < a[table[j - 1]]; j -= 1)
            table[j] = table[j - 1];
        table[j] = t;
    }
    return table;
}

int vis[100] = {0};
char tmp;
char key[] = {'f', 'd', 'c', 'a', 'g', 'b', 'h', 'e'};
vector<int> table;
void DFS(int cur)
{
    vis[cur] = 1;
    if (vis[table[cur]])
    {
        key[cur] = tmp;
        return;
    }
    key[cur] = key[table[cur]];
    DFS(table[cur]);
}

inline int getdigit(int num, int d)
{
    while (--d)
        num /= 10;
    return num % 10;
}
inline void RadixSort(int *a, int n, int digit)
{
    vector<int> BUCKET[10], BUCKET1[10];
    int d = 1;
    for (int i = 0; i < n; i++)
    {
        int c = getdigit(a[i], d);
        BUCKET[c].push_back(a[i]);
    }
    cout << endl;
    while (--digit && d++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (auto j : BUCKET[i])
            {
                int c = getdigit(j, d);
                BUCKET1[c].push_back(j);
            }
        }
        for (int i = 0; i < 10; i++)
        {
            BUCKET[i].clear();
            swap(BUCKET1[i], BUCKET[i]);
        }
    }
    int cur = 0;
    for (int i = 0; i < 10; i++)
    {
        for (auto j : BUCKET[i])
            a[cur++] = j;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a[] = {64, 8, 216, 512, 27, 729, 0, 1, 343, 125};
    RadixSort(a, 9, 3);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
}