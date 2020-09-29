// author - sonaspy@zju.edu.cn
// coding - utf_8

#include <iostream>

template <class T> T sum(const T data[], int size, T s = 0)
{
    for (int i = 0; i < size; ++i)
        s += data[i];
    return s;
}

int main(int argc, char const *argv[]) {}