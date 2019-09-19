#include <bits/stdc++.h>
using namespace std;

#ifndef __HASH_TABLE__
#define __HASH_TABLE__

template <typename K, typename V>
class hashtable
{
protected:
    int _size;

public:
    bool insert(K &x) {}
    bool count(K &x) {}
    bool erase(K &x) {}
    int size() {}
    V *get(K &k) {}
};

#endif
