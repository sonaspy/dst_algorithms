// hash table using sorted chains and division
// implements all dictionary methods

#ifndef __HASHCHAIN__
#define __HASHCHAIN__

#include "hash.h" // mapping functions from K to nonnegative integer
#include "sortedchain.h"

template <class K, class E>
class hashChains : public dictionary<K, E>
{
public:
    hashChains(int theDivisor = 11)
    {
        divisor = theDivisor;
        dSize = 0;

        // allocate and initialize hash table array
        table = new sortedChain<K, E>[divisor];
    }

    ~hashChains() { delete[] table; }

    bool empty() { return dSize == 0; }
    int size() { return dSize; }

    pair<K, E> *find(K &theKey)
    {
        return table[hash(theKey) % divisor].find(theKey);
    }

    void insert(pair<K, E> &thePair)
    {
        int homeBucket = (int)hash(thePair.first) % divisor;
        int homeSize = table[homeBucket].size();
        table[homeBucket].insert(thePair);
        if (table[homeBucket].size() > homeSize)
            dSize++;
    }

    void erase(K &theKey)
    {
        table[hash(theKey) % divisor].erase(theKey);
    }

    void output(ostream &out)
    {
        for (int i = 0; i < divisor; i++)
            if (table[i].size() == 0)
                cout << "NULL" << endl;
            else
                cout << table[i] << endl;
    }

protected:
    sortedChain<K, E> *table; // hash table
    hash<K> hash;             // maps type K to nonnegative integer
    int dSize;                // number of elements in list
    int divisor;              // hash function divisor
};

// overload <<
template <class K, class E>
ostream &operator<<(ostream &out, hashChains<K, E> &x)
{
    x.output(out);
    return out;
}

#endif
