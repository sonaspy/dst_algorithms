



template <class T> static bool lt ( T* a, T* b ) { return lt ( *a, *b ); }  
template <class T> static bool lt ( T& a, T& b ) { return a < b; }  
template <class T> static bool eq ( T* a, T* b ) { return eq ( *a, *b ); }  
template <class T> static bool eq ( T& a, T& b ) { return a == b; }  