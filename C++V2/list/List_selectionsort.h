
#pragma once

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