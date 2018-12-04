

#pragma once

template <typename T>  
Posi(T) List<T>::search ( T const& e, int n, Posi(T) p ) const {
 
   
   while ( 0 <= n-- )  
      
      if ( ( ( p = p->pred )->data ) <= e ) break;  
      
   return p;  
}  