
#pragma once

template <typename T> void List<T>::sort ( Posii(T) p, int n ) {  
   switch ( rand() % 3 ) {  
      case 1:  insertionSort ( p, n ); break;  
      case 2:  selectionSort ( p, n ); break;  
      default: mergeSort ( p, n ); break;  
   }
}