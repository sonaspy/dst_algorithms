



#include "..\vector\vector.h"

template <class T> void increase ( Vector<T> & V )  
{  V.traverse ( Increase<T>() ); }  