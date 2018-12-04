
#pragma once

template <typename T>  
Posii(T) List<T>::selectMax ( Posii(T) p, int n ) {
   Posii(T) max = p;  
   for ( Posii(T) cur = p; 1 < n; n-- )  
      if ( !lt ( ( cur = cur->succ )->data, max->data ) )  
         max = cur;  
   return max;  
}