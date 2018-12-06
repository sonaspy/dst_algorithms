



#include "..\vector\vector.h"

template <typename T> void increase ( Vector<T> & V )  
{  V.traverse ( Increase<T>() ); }  