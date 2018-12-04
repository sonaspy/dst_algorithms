
#pragma once

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