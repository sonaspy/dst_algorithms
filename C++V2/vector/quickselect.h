
template <class T>
void quickSelect(Vector<T> &A, Rank k)
{
    for (Rank lo = 0, hi = A.size() - 1; lo < hi;)
        {
            Rank i = lo, j = hi;
            T pivot = A[lo];
            while (i < j)
                {
                    //O(hi - lo + 1) = O(n)
                    while ((i < j) && (pivot <= A[j]))
                        j--;
                    A[i] = A[j];
                    while ((i < j) && (A[i] <= pivot))
                        i++;
                    A[j] = A[i];
                } //assert: i == j
            A[i] = pivot;
            if (k <= i)
                hi = i - 1;
            if (i <= k)
                lo = i + 1;
        } //A[k] is now a pivot
}