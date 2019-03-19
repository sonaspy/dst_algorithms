// delete a two-dimensional array
#ifndef delete2dArray_
#define delete2dArray_


template <class T>
void delete2dArray(T ** & Arr, int numOfRows)
{
    for(int i = 0; i < numOfRows; i++)
        delete [] Arr[i];
    delete [] Arr;
    Arr = 0;
}


#endif