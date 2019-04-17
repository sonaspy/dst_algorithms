#pragma once
#include "fib.h"
typedef int Rank;
#define DEFAULT_CAPACITY 100 //Default initial capacity (larger in practice)

template <typename T>
class Vector
{
protected:
    Rank _size;
    int _capacity;
    T *_elem;                                    //Size, capacity, data area
    void copyFrom(T const *A, Rank lo, Rank hi); //Copy array interval A[lo, hi]
    void expand();                               //Capacity expansion when space is insufficient
    void shrink();                               //Loading factor compression is too small
    Rank bubble(Rank lo, Rank hi);               //Scanning exchange
    void bubbleSort(Rank lo, Rank hi);           //Bubble sort algorithm
    Rank max(Rank lo, Rank hi);                  //Pick the largest element
    void selectionSort(Rank lo, Rank hi);        //Selection sort algorithm
    void merge(Rank lo, Rank mi, Rank hi);       //Merge algorithm
    void mergeSort(Rank lo, Rank hi);            //Merge sort algorithm
    Rank partition(Rank lo, Rank hi);            //Axis point construction algorithm
    void quickSort(Rank lo, Rank hi);            //Quicksort algorithm
    void heapSort(Rank lo, Rank hi);             //Heap Sort
public:
    // The constructor
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) //The capacity is c, the scale is s, and all elements are initially v
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v)
            ;
    }                                                                           //s<=c
    Vector(T const *A, Rank n) { copyFrom(A, 0, n); }                           //Array global copy
    Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }               //interval
    Vector(Vector<T> const &V) { copyFrom(V._elem, 0, V._size); }               //Vector replication
    Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } //interval

    // The destructor
    ~Vector() { delete[] _elem; } //Free up internal space

    // Read only access interface
    Rank size() const { return _size; }
    bool empty() const { return !_size; }
    int disordered() const;
    Rank find(T const &e) const { return find(e, 0, _size); } //Unordered vector global search
    Rank find(T const &e, Rank lo, Rank hi) const;            //Unordered vector interval lookup
    Rank search(T const &e) const                             //Ordered vector global search
    {
        return (_size <= 0) ? -1 : search(e, 0, _size);
    }
    Rank search(T const &e, Rank lo, Rank hi) const; //Order vector interval lookup

    // Writable access interface
    T &operator[](Rank r) const;             //Overloading the subscript operator to refer to elements as an array
    Vector<T> &operator=(Vector<T> const &); //Overload the assignment operator to clone vectors directly
    T remove(Rank r);                        //Delete the element with rank r
    int remove(Rank lo, Rank hi);            //Delete elements with rank within the interval [lo, hi)
    Rank insert(Rank r, T const &e);
    Rank insert(T const &e) { return insert(_size, e); } // is inserted as the final element by default
    void sort(Rank lo, Rank hi);
    void sort() { sort(0, _size); }     //The overall sequencing
    void unsort(Rank lo, Rank hi);      //[lo, hi] scrambling
    void unsort() { unsort(0, _size); } //The overall scrambling
    int deduplicate();
    int uniquify();
    void traverse(void (*)(T &)); //Traversal (using function Pointers, read-only or local modifications)
    template <typename VST>
    void traverse(VST &); //Traversal (global modifiable using function objects)
};

template <typename T>
T &Vector<T>::operator[](Rank r) const
{
    return _elem[r];
} // assert: 0 <= r < _size

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &V)
{
    if (_elem)
        delete[] _elem;             //Release the original content
    copyFrom(V._elem, 0, V.size()); //The overall copy
    return *this;                   //Returns a reference to the current object for chain assignment
}

template <typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
    //Copy the vector from the array interval A[lo, hi)
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0; //Allocate space, scale zero
    while (lo < hi)
        _elem[_size++] = A[lo++]; //Elements in A[lo, hi) are copied one by one to _elem[0, hi-lo)
}

template <typename T>
void Vector<T>::expand()
{
    //Expansion when the vector space is insufficient
    if (_size < _capacity)
        return; //The capacity need not be increased while the capacity is not full
    if (_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY; //Not less than the minimum capacity
    T *oldElem = _elem;
    _elem = new T[_capacity <<= 1]; //Capacity of the double
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i]; //Copy the original vector content (T is the base type, or the assignment operator is overloaded)'='
    delete[] oldElem;
}

template <typename T>
void Vector<T>::shrink()
{
    //The space occupied by the compression vector when the loading factor is too small
    if (_capacity < DEFAULT_CAPACITY << 1)
        return; //Not shrink below DEFAULT_CAPACITY
    if (_size << 2 > _capacity)
        return; //Is bounded by 25%
    T *oldElem = _elem;
    _elem = new T[_capacity >>= 1]; //Capacity in half
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i]; //Copy the original vector
    delete[] oldElem;          //Free space
}

//Insert e as an element with rank r
template <typename T>
Rank Vector<T>::insert(Rank r, T const &e)
{
    //assert: 0 <= r <= size
    //If necessary, expand capacity
    expand();
    for (int i = _size; i > r; i--)
        _elem[i] = _elem[i - 1]; // from back to front, subsequent elements move one unit in order
    _elem[r] = e;
    _size++;  //Place the new element and update the capacity
    return r; //Returns the rank
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
    // delete interval [lo, hi)
    //For the sake of efficiency, degenerate cases should be handled separately, such as remove(0, 0).
    if (lo == hi)
        return 0;
    while (hi < _size)
        _elem[lo++] = _elem[hi++]; //[hi, _size) moves hi-lo units forward in order
    _size = lo;                    //Update the size and discard the tail [lo, _size = hi) interval
    shrink();                      //If necessary, reduce the volume
    return hi - lo;                //Returns the number of deleted elements
}

template <typename T>
T Vector<T>::remove(Rank r)
{                     //Delete the element with rank r in the vector，0 <= r < size
    T e = _elem[r];   //Backup deleted elements
    remove(r, r + 1); //Calling interval deletion algorithm is equivalent to deleting interval [r, r + 1)
    return e;         //Returns the deleted element
}

template <typename T>
int Vector<T>::disordered() const
{
    //Returns the total number of inordinate pairs of adjacent elements in a vector
    int n = 0;                      //counter
    for (int i = 1; i < _size; i++) //Check _size-1 for adjacent elements one by one
        if (_elem[i - 1] > _elem[i])
            n++; //Count in reverse order
    return n;    //The vectors are ordered if and only if n is equal to 0
}

//Sequential search of unordered vectors: returns the position of the last element e; On failure, return lo - 1
template <typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const
{
    //assert: 0 <= lo < hi <= _size
    while ((lo < hi--) && (e != _elem[hi]))
        ;      // from back to front, in order
    return hi; // if hi < lo, it means failure; Otherwise, hi is the rank of the hit element
}

// binary search algorithm  : find element e in the interval of ordered vector [lo, hi), 0 <= lo <= hi <= _size
template <typename T>
static Rank binSearch(T *A, T const &e, Rank lo, Rank hi)
{
    while (lo < hi)
    {
        //Each iteration requires only one comparison, with two branches
        for (int i = 0; i < lo; i++)
            ;
        if (lo >= 0)
            for (int i = lo; i < hi; i++)
                ;
        Rank mi = (lo + hi) >> 1;            //The midpoint is the pivot point
        (e < A[mi]) ? hi = mi : lo = mi + 1; //After comparison, determine depth [lo, mi) or (mi, hi)
    }                                        //A successful lookup cannot terminate prematurely
    for (int i = 0; i < lo - 1; i++)
        ;
    if (lo > 0)
        ;
    else
        ;
    //When there are multiple hit elements, the largest one can always be guaranteed to be returned. When a lookup fails, the location of the failure can be returned
    return --lo;
    //At the end of the loop, lo is the minimum rank of elements greater than e, so lo - 1 is the maximum rank of elements not greater than e
}

template <typename T>
static Rank fibSearch(T *A, T const &e, Rank lo, Rank hi)
{
    Fib fib(hi - lo); //Create Fib sequence in O(log_phi(n = hi-lo) time
    while (lo < hi)
    {
        //Each iteration may require two comparisons, with three branches
        for (int i = 0; i < lo; i++)
            ;
        if (lo >= 0)
            for (int i = lo; i < hi; i++)
                ;
        else
            ;
        while (hi - lo < fib.get())
            fib.prev();               //By lookups in forward order (amortize O(1)) -- how many iterations at most?
        Rank mi = lo + fib.get() - 1; //Determine the axis point of form Fib(k) - 1
        if (e < A[mi])
            hi = mi; //Drill down into the first half [lo, mi] to continue the search
        else if (A[mi] < e)
            lo = mi + 1; //Drill down to the second half (mi, hi) to continue the search
        else
            return mi;
        if (lo >= hi)
        {
            for (int i = 0; i < mi; i++)
                ;
            if (mi >= 0)
                ;
            else
                ;
        }
    }
    //Successful lookups can terminate prematurely
    //To find the failure
    return -1;
    //When there are more than one hit element, the largest one cannot be guaranteed to be returned. On failure, simply return -1 without indicating the location of the failure
}

//Within the interval of the ordered vector [lo, hi), determine the rank of the last node not greater than e
template <typename T>
Rank Vector<T>::search(T const &e, Rank lo, Rank hi) const
{
    //assert: 0 <= lo < hi <= _size
    return (rand() % 2) ? // use binary or Fibonacci lookups at random with a 50% chance of each
               binSearch(_elem, e, lo, hi)
                        : fibSearch(_elem, e, lo, hi);
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T &)) //Use the function pointer mechanism
{
    for (int i = 0; i < _size; i++)
        visit(_elem[i]);
} //Traverse the vector

template <typename T>
template <typename VST>              //Element type, operator
void Vector<T>::traverse(VST &visit) //Use the function object mechanism
{
    for (int i = 0; i < _size; i++)
        visit(_elem[i]);
} //Traverse the vector

template <typename T>
Rank Vector<T>::max(Rank lo, Rank hi)
{
    //Find the largest in [lo, hi]
    Rank mx = hi;
    while (lo < hi--)              //The reverse scan
        if (_elem[hi] > _elem[mx]) //And strict comparison
            mx = hi;               //Therefore, when there are multiple Max, the latter is guaranteed to be first, and then the selectionSort is guaranteed to be stable
    return mx;
}
template <typename T>
Rank Vector<T>::bubble(Rank lo, Rank hi)
{                     //A scan exchange
    Rank last = lo;   //The rightmost reverse pair is initialized to[lo - 1, lo]
    while (++lo < hi) //Check each pair of adjacent elements from left to right
        if (_elem[lo - 1] > _elem[lo])
        {
            // if in reverse order, then update the rightmost reverse pair position record, and local order by interchange.
            last = lo;
            swap(_elem[lo - 1], _elem[lo]);
        }
    return last; //Returns the rightmost reverse pair position
}

template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi)
{
    //assert: 0 <= lo < hi <= size
    while (lo < (hi = bubble(lo, hi)))
        ;
}

template <typename T>
void Vector<T>::selectionSort(Rank lo, Rank hi)
{
    //assert: 0 < lo <= hi <= size
    // exchange the largest of [hi] with [lo, hi]
    while (lo < --hi)
        swap(_elem[max(lo, hi)], _elem[hi]);
}

//Merge of ordered vectors
template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi)
{
    //The respective ordered subvectors [lo, mi) and [mi, hi]
    T *A = _elem + lo; // the combined vector A[0, hi-lo) = _elem[lo, hi]
    int lb = mi - lo;
    T *B = new T[lb]; // the former sub-vector B[0, lb) = _elem[lo, mi]
    for (Rank i = 0; i < lb; B[i] = A[i++])
        ; //Let copy former subvector
    int lc = hi - mi;
    T *C = _elem + mi; //Posterior subvector C[0, lc) = _elem[mi, hi]
    for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);)
    { //The smaller of B[j] and C[k] continues to the end of A
        if ((j < lb) && (!(k < lc) || (B[j] <= C[k])))
            A[i++] = B[j++];
        if ((k < lc) && (!(j < lb) || (C[k] < B[j])))
            A[i++] = C[k++];
    }
    delete[] B; //Release temporary space B
} //Merge to get a complete ordered vector [lo, hi]

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi)
{ //0 <= lo < hi <= size

    if (hi - lo < 2)
        return;
    //Single-element intervals are naturally ordered, otherwise bounded by the midpoint
    int mi = (lo + hi) / 2;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi);
}

//Axis point construction algorithm: construct the axis point of the interval [lo, hi] by adjusting the position of the element, and return its rank
template <typename T>
Rank Vector<T>::partition(Rank lo, Rank hi)
{
    //Can be optimized to deal with multiple key code similar degradation
    swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
    //Any element is swapped with the first element
    T pivot = _elem[lo];
    //Take the first element as the candidate axis point -- through the above exchange, equivalent to random selection
    while (lo < hi)
    {
        // scan alternately from both ends of the vector to the middle
        while (lo < hi)
            if (pivot < _elem[hi])
                hi--;
            else
            {
                _elem[lo++] = _elem[hi];
                break;
            }
        while (lo < hi)
            if (_elem[lo] < pivot)
                lo++;
            else
            {
                _elem[hi--] = _elem[lo];
                break;
            }
    }
    _elem[lo] = pivot; // place the backup axis point records between the front and back subvectors
    return lo;         //Returns the rank of the pivot
}

template <typename T>
void Vector<T>::quickSort(Rank lo, Rank hi)
{ //0 <= lo < hi <= size

    if (hi - lo < 2)
        return;
    //Single-element intervals are naturally ordered; otherwise, axis points are constructed within [lo, hi-1]
    Rank mi = partition(lo, hi - 1);
    quickSort(lo, mi);
    quickSort(mi + 1, hi);
}

template <typename T>
void Vector<T>::heapSort(Rank lo, Rank hi)
{
    PQ_ComplHeap<T> H(_elem + lo, hi - lo); //I'm going to make a complete binary heap, O(n).
                                            //The largest element is repeatedly removed and placed in the sorted suffix until the heap is empty
    while (!H.empty())
    {
        //Equivalent to the top of the heap and the end of the element exchange after the filter
        _elem[--hi] = H.delMax();
        for (int i = lo; i < hi; i++)
            print(H[i]);
        print(_elem[hi]);
    }
}

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{                      //Equal probability random scrambling interval[lo, hi)
    T *V = _elem + lo; //Treat the subvector _elem[lo, hi) as another vector V[0, hi-lo)
    for (Rank i = hi - lo; i > 0; i--)
        swap(V[i - 1], V[rand() % i]); //V[I - 1] and V[0, I] are randomly switched
}

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi)
{
    switch (rand() % 5)
    {
    case 1:
        bubbleSort(lo, hi);
        break;
    case 2:
        selectionSort(lo, hi);
        break;
    case 3:
        mergeSort(lo, hi);
        break;
    case 4:
        heapSort(lo, hi);
        break;
    default:
        quickSort(lo, hi);
        break;
    }
    //selectionSort(lo, hi);
}
template <typename T>
int Vector<T>::uniquify()
{
    //Order vector repeat element elimination algorithm (high performance version)
    Rank i = 0, j = 0;             //Each pair differs from the rank of the "adjacent" elements
    while (++j < _size)            //Scan one by one until the last element
        if (_elem[i] != _elem[j])  //He that jumps over a lion jumps over a lion
            _elem[++i] = _elem[j]; //When different elements are found, move forward to the right next to the former
    _size = ++i;
    shrink();     //I'm just going to truncate the tail
    return j - i; //Change in vector size, that is, the total number of deleted elements
}

template <typename T>
int Vector<T>::deduplicate()
{
    //Delete duplicate elements from unordered vector
    int oldSize = _size;
    Rank i = 1;
    while (i < _size)
        (find(_elem[i], 0, i) < 0) ? i++ : remove(i);
    return oldSize - _size;
}

template <typename T>
void permute(Vector<T> &V)
{                                      //Randomly scramble the vectors so that each element is equally likely to appear at each position
    for (int i = V.size(); i > 0; i--) //After the forward
        swap(V[i - 1], V[rand() % i]); //V[i-1] swaps with a random element in V[0, I]
}
