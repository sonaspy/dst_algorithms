// author - sonaspy@outlook.com
// coding - utf_8
#ifndef __HEAP__
#define __HEAP__
#include "functions.h"
namespace dsa
{

template <typename T>
class pri_queue
{
    // data[1....n] data[0] = INT_MAX
protected:
    vector<T> data;
    int _size;
};
} // namespace dsa
#endif