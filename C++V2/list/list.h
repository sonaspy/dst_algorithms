
#pragma once

#include "listNode.h"

template <typename T>
class List
{
  private:
    int _size;
    Posi(T) header;
    Posi(T) trailer;

  protected:
    void init();
    int clear();
    void copyNodes(Posi(T), int);
    void merge(Posi(T) &, int, List<T> &, Posi(T), int);
    void mergeSort(Posi(T) &, int);
    void selectionSort(Posi(T), int);
    void insertionSort(Posi(T), int);

  public:
    List() { init(); }
    List(List<T> const &L);
    List(List<T> const &L, Rank r, int n);
    List(Posi(T) p, int n);

    ~List();

    Rank size() const { return _size; }
    bool empty() const { return _size <= 0; }
    T &operator[](Rank r) const;
    Posi(T) first() const { return header->succ; }
    Posi(T) last() const { return trailer->pred; }
    bool valid(Posi(T) p)
    {
        return p && (trailer != p) && (header != p);
    }
    int disordered() const;
    Posi(T) find(T const &e) const
    {
        return find(e, _size, trailer);
    }
    Posi(T) find(T const &e, int n, Posi(T) p) const;
    Posi(T) search(T const &e) const
    {
        return search(e, _size, trailer);
    }
    Posi(T) search(T const &e, int n, Posi(T) p) const;
    Posi(T) selectMax(Posi(T) p, int n);
    Posi(T) selectMax() { return selectMax(header->succ, _size); }

    Posi(T) insertAsFirst(T const &e);
    Posi(T) insertAsLast(T const &e);
    Posi(T) insertA(Posi(T) p, T const &e);
    Posi(T) insertB(Posi(T) p, T const &e);
    T remove(Posi(T) p);
    void merge(List<T> &L) { merge(first(), size, L, L.first(), L._size); }
    void sort(Posi(T) p, int n);
    void sort() { sort(first(), _size); }
    int deduplicate();
    int uniquify();
    void reverse();

   void traverse ( void (
   template <typename VST>  
   void traverse ( VST& );
};

#include "List_implementation.h"
