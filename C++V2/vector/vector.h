#include "Fib.h"

#ifndef Vector_
#define Vector_

typedef int Rank;
#define DEFAULT_CAPACITY 3;

template <typename T>
class Vector{
    protected:
      Rank _size;
      int _capacity;
      T *_elem;
      void copyFrom(T const *A, Rank lo, Rank hi);
      void expand();
      void shrink();
      bool bubble(Rank lo, Rank hi);
      void bubbleSort(Rank lo, Rank hi);
      Rank max(Rank lo, Rank hi);
      void selectionSort(Rank lo, Rank hi);
      void merge(Rank lo, Rank mi, Rank hi);
      void mergeSort(Rank lo, Rank hi);
      Rank partition(Rank lo, Rank hi);
      void quickSort(Rank lo, Rank hi);
      void heapSort(Rank lo, Rank hi);
      Rank bubble_fast(Rank lo, Rank hi);
      void bubbleSort_fast(Rank lo, Rank hi);
      int disordered() const;


    public:
      Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0){
          _elem = new T[_capacity = c];
          for (_size = 0; _size < s; _elem[_size++] = v)
              ;
      }
      Vector(T const *A, Rank n) { copyFrom(A, 0, n); }
      Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }
      Vector(Vector<T> const &V) { copyFrom(V._elem, 0, V._size); }
      Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }
      ~Vector() { delete[] _elem; }
      Rank size() const { return _size; }
      bool empty() const { return !_size; }
      int disordered() const;
      Rank find(T const &e) const { return find(e, 0, _size); }
      Rank find(T const &e, Rank lo, Rank hi) const;
      Rank search(T const &e) const{
          return (0 >= _size) ? -1 : search(e, 0, _size);
      }
      Rank search(T const &e, Rank lo, Rank hi) const;
      T &operator[](Rank r) const;
      Vector<T> &operator=(Vector<T> const &);
      T remove(Rank r);
      int remove(Rank lo, Rank hi);
      Rank insert(Rank r, T const &e);
      Rank insert(T const &e) { return insert(_size, e); }
      void sort(Rank lo, Rank hi);
      void sort() { sort(0, _size); }
      void unsort(Rank lo, Rank hi);
      void unsort() { unsort(0, _size); }
      int deduplicate();
      int uniquify();
      void traverse(void (*)(T &));
      template <typename VST>
      void traverse(VST &);
};

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &V)
{
    if (_elem)
        delete[] _elem;
    copyFrom(V._elem, 0, V.size());
    return *this;
}

template <typename T>
T &Vector<T>::operator[](Rank r) const
{
    return _elem[r];
}

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{
    T *V = _elem + lo;
    for (Rank i = hi - lo; i > 0; i--)
        swap(V[i - 1], V[rand() % i]);
}

template <typename T>
int Vector<T>::uniquify()
{
    Rank i = 0, j = 0;
    while (++j < _size)
        if (_elem[i] != _elem[j])
            _elem[++i] = _elem[j];
    _size = ++i;
    shrink();
    return j - i;
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T &))
{
    for (int i = 0; i < _size; i++)
        visit(_elem[i]);
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST &visit)
{
    for (int i = 0; i < _size; i++)
        visit(_elem[i]);
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
    /*DSA*/
}

template <typename T>
void Vector<T>::shrink()
{
    if (_capacity < DEFAULT_CAPACITY << 1)
        return;
    if (_size << 2 > _capacity)
        return;
    T *oldElem = _elem;
    _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete[] oldElem;
}

template <typename T>
void Vector<T>::selectionSort(Rank lo, Rank hi)
{
    /*DSA*/ printf("\tSELECTIONsort [%3d, %3d)\n", lo, hi);
    while (lo < --hi)
        swap(_elem[max(lo, hi)], _elem[hi]);
}

template <typename T>
Rank Vector<T>::max(Rank lo, Rank hi)
{
    Rank mx = hi;
    while (lo < hi--)
        if (_elem[hi] > _elem[mx])
            mx = hi;
    return mx;
}

template <typename T>
void permute(Vector<T> &V)
{
    for (int i = V.size(); i > 0; i--)
        swap(V[i - 1], V[rand() % i]);
}



template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi)
{
    while (!bubble(lo, hi--))
        ;
}

template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi)
{
    bool sorted = true;
    while (++lo < hi)
        if (_elem[lo - 1] > _elem[lo])
        {
            sorted = false;
            swap(_elem[lo - 1], _elem[lo]);
        }
    return sorted;
}

template <typename T>
Rank Vector<T>::bubble_fast(Rank lo, Rank hi)
{
    Rank last_swap_p = lo;
    while (++lo < hi)
        if (_elem[lo - 1] > _elem[lo])
        {
            last_swap_p = lo;
            swap(_elem[lo - 1], _elem[lo]);
        }
    return last_swap_p;
}

template <typename T>
void Vector<T>::bubbleSort_fast(Rank lo, Rank hi)
{
    while (lo < (hi = bubble(lo, hi)))
        ;
}

template <typename T> 
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{ 
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;               
    while (lo < hi)             
        _elem[_size++] = A[lo++]; 
}

template <typename T>
int Vector<T>::deduplicate()
{
    int oldSize = _size;
    Rank i = 1;
    while (i < _size)
        (find(_elem[i], 0, i) < 0) ? i++ : remove(i);
    return oldSize - _size;
}

template <typename T>
int Vector<T>::disordered() const
{
    int n = 0;
    for (int i = 1; i < _size; i++)
        if (_elem[i - 1] > _elem[i])
            n++;
    return n;
}

template <typename T>
void Vector<T>::expand()
{  
    if (_size < _capacity)
        return;  
    if (_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY;  
    T *oldElem = _elem;
    _elem = new T[_capacity <<= 1];  
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];  
    /*DSA*/                     
    delete[] oldElem;           
}


template <typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const
{
    while ((hi-- > lo) && (e != _elem[hi]))
        ;
    return hi;
}   

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


template <typename T>
Rank Vector<T>::insert(Rank r, T const &e)
{
    expand();
    for (int i = _size; i > r; i--)
        _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _size++;
    return r;
}

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


template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi)
{
    if (hi - lo < 2)
        return;
    int mi = (lo + hi) >> 1;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi);
}

template <typename T>
Rank Vector<T>::partition(Rank lo, Rank hi)
{
    swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
    T pivot = _elem[lo];
    while (lo < hi)
    {
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
    _elem[lo] = pivot;
    return lo;
}

template <typename T>
void Vector<T>::quickSort(Rank lo, Rank hi)
{
    /*DSA*/ printf("\tQUICKsort [%3d, %3d)\n", lo, hi);
    if (hi - lo < 2)
        return;
    Rank mi = partition(lo, hi - 1);
    quickSort(lo, mi);
    quickSort(mi + 1, hi);
}


template <typename T>
T Vector<T>::remove(Rank r)
{
    T e = _elem[r];
    remove(r, r + 1);
    return e;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi)
        return 0;
    while (hi < _size)
        _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi - lo; // items num be removed
}

template <typename T>
Rank Vector<T>::search(T const &e, Rank lo, Rank hi) const
{
    return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}

template <typename T>
static Rank binSearch(T *A, T const &e, Rank lo, Rank hi)
{
    while (lo < hi)
    {
        Rank mi = (lo + hi) >> 1;
        (e < A[mi]) ? hi = mi : lo = mi + 1;
    }
    return --lo;
}


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


#endif