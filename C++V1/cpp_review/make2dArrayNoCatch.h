// create a 2D array but do not catch exception thrown
// when new fails to allocate sufficient memory

#ifndef make2dArrayNoCatch_
#define make2dArrayNoCatch_


using namespace std;

template <class T>
void make2dArrayNoCatch(T ** &x, int numOfRows, int numOfColumns)
{
    x = new T *[numOfRows];
    for(int i = 0; i < numOfRows; i++)
        x[i] = new T [numOfColumns];
}




#endif