
#include "ListNode.h"

#ifndef List_
#define List_

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

template <typename T>
T & List<T>::operator[](Rank r) const
{
    Posi(T) p = first();
    while (0 < r--)
        p = p->succ;
    return p->data;
}



template <typename T>
int List<T>::clear()
{
    int oldSize = _size;
    while (0 < _size)
        remove(header->succ);
    return oldSize;
}

template <typename T>
List<T>::List(Posi(T) p, int n) { copyNodes(p, n); }

template <typename T>
List<T>::List(List<T> const &L) { copyNodes(L.first(), L._size); }

template <typename T>
List<T>::List(List<T> const &L, int r, int n) { copyNodes(L[r], n); }



template <typename T>
void List<T>::copyNodes(Posi(T) p, int n)
{
    init();
    while (n--)
    {
        insertAsLast(p->data);
        p = p->succ;
    }
}


template <typename T> int List<T>::deduplicate() {  
   if ( _size < 2 ) return 0;  
   int oldSize = _size;  
   Posi(T) p = header; Rank r = 0;  
   while ( trailer != ( p = p->succ ) ) {  
      Posi(T) q = find ( p->data, r, p );  
      q ? remove ( q ) : r++;  
   }  
   return oldSize - _size;  
}

template <typename T>
List<T>::~List()
{
    clear();
    delete header;
    delete trailer;
}

template <typename T>
Posi(T) List<T>::find(T const &e, int n, Posi(T) p) const
{
    while (0 < n--)
        if (e == (p = p->pred)->data)
            return p;
    return NULL;
}

template <typename T>  
void List<T>::insertionSort ( Posii(T) p, int n ) {  
   
   for ( int r = 0; r < n; r++ ) {  
      insertA ( search ( p->data, r, p ), p->data );  
      p = p->succ; remove ( p->pred );  
   }
}

template <typename T>
void List<T>::init()
{
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = NULL;
    trailer->pred = header;
    trailer->succ = NULL;
    _size = 0;
}

template <typename T>
Posi(T) List<T>::insertAsFirst(T const &e)
{
    _size++;
    return header->insertAsSucc(e);
}

template <typename T>
Posi(T) List<T>::insertAsLast(T const &e)
{
    _size++;
    return trailer->insertAsPred(e);
}

template <typename T>
Posi(T) List<T>::insertA(Posi(T) p, T const &e)
{
    _size++;
    return p->insertAsSucc(e);
}

template <typename T>
Posi(T) List<T>::insertB(Posi(T) p, T const &e)
{
    _size++;
    return p->insertAsPred(e);
}



template <typename T>
T List<T>::remove(Posi(T) p)
{
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
}


template <typename T> void List<T>::reverse() {  
   if ( _size < 2 ) return;  
   Posi(T) p; Posi(T) q;
   for ( p = header, q = p->succ; p != trailer; p = q, q = p->succ )
      p->pred = q;  
   trailer->pred = NULL;  
   for ( p = header, q = p->pred; p != trailer; p = q, q = p->pred )
      q->succ = p;  
   header->succ = NULL;  
   swap ( header, trailer );  
}



template <typename T>  
Posi(T) List<T>::search ( T const& e, int n, Posi(T) p ) const {
 
   
   while ( 0 <= n-- )  
      
      if ( ( ( p = p->pred )->data ) <= e ) break;  
      
   return p;  
}  


template <typename T>  
void List<T>::selectionSort ( Posi(T) p, int n ) {  
   
   Posi(T) prewalk = p->pred; Posi(T) walk = p;
   for ( int i = 0; i < n; i++ ) walk = walk->succ;  
   while ( 1 < n ) {  
      Posi(T) max = selectMax ( prewalk->succ, n );  
      insertB ( walk, remove ( max ) );  
      
      walk = walk->pred; n--;
   }
}


template <typename T>  
Posii(T) List<T>::selectMax ( Posii(T) p, int n ) {
   Posii(T) max = p;  
   for ( Posii(T) cur = p; 1 < n; n-- )  
      if ( !lt ( ( cur = cur->succ )->data, max->data ) )  
         max = cur;  
   return max;  
}


template <typename T> void List<T>::sort ( Posii(T) p, int n ) {  
   switch ( rand() % 3 ) {  
      case 1:  insertionSort ( p, n ); break;  
      case 2:  selectionSort ( p, n ); break;  
      default: mergeSort ( p, n ); break;  
   }
}


template <typename T> void List<T>::traverse ( void ( 
{  for ( Posi(T) p = header->succ; p != trailer; p = p->succ ) visit ( p->data );  }

template <typename T> template <typename VST>  
void List<T>::traverse ( VST& visit )  
{  for ( Posi(T) p = header->succ; p != trailer; p = p->succ ) visit ( p->data );  }


template <typename T> 
int List<T>::uniquify() {  
   if ( _size < 2 ) return 0;  
   int oldSize = _size;  
   Posi(T) p = first(); Posi(T) q;  
   while ( trailer != ( q = p->succ ) )  
      if ( p->data != q->data ) p = q;  
      else remove ( q );  
   return oldSize - _size;  
}

#endif