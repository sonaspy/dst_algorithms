// create a 2D array and catch exception thrown
// when new fails to allocate sufficient memory

#ifndef make2dArrayCatch_
#define make2dArrayCatch_

#include<exception>

using namespace std;

template <class T>
bool make2dArrayCatch(T ** &x, int numOfRows, int numOfColumns)
{
    try
        {
            x = new T *[numOfRows];
            for(int i = 0; i < numOfRows; i++)
                x[i] = new T [numOfColumns];
            return true;
        }
    catch (bad_alloc)
        {
            return false;
        }
}




#endif