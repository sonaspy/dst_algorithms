// change the length of an array
#ifndef changeLength1D_
#define changeLength1D_
#include<iostream>
#include "myExceptions.h"

using namespace std;

template <class T>
void changeLength1D(T* & a, int oldlen, int newlen){
    if(newlen < 0)
        throw illegalParameterValue("new length must be >= 0");
    T * tmp = new T[newlen];
    int number = min(oldlen, newlen);
    copy(a, a+number, tmp);
    delete [] a;
    a = tmp;
}

#endif
